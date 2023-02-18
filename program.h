#pragma once

#include <memory>
#include <functional>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <string_view>
#include "datatypes.h"

class Expression
{
/*
    Izteiksmes rezultātu iegūst ar eval()

    Darbības princips ir balstīts uz izteiksmju parsing koku, kas implementēts rekursīvi
*/

public:
    virtual Data eval(vector<Data>& callstack) = 0;
};

class BinaryExpression : public Expression
{
    /*
        Divu darbību izteiksme sastāv no divām apakšizteiksmēm un darbības, ko ar tām veikt
    */
private:

    function<Data(const Data, const Data)> operation; 
    shared_ptr<Expression> sub_expression1, sub_expression2; 
    

    static void assert_types(const Data op1, const Data op2, TypeLabel op1_type, TypeLabel op2_type, string_view op_name);
    static void assert_types_multiple(const Data op1, const Data op2, TypeLabel op1_type, const vector<TypeLabel>& op2_types, string_view op_name)
;

    static Data add(const Data op1, const Data op2);
    static Data subtract(const Data op1, const Data op2);
    static Data multiply(const Data op1, const Data op2);
    static Data divide(const Data op1, const Data op2);
    static Data modulo(const Data op1, const Data op2);
    static Data pow(const Data op1, const Data op2);
    static Data equals(const Data op1, const Data op2);
    static Data greater_than(const Data op1, const Data op2);
    static Data less_than(const Data op1, const Data op2);
    static Data equals_greater_than(const Data op1, const Data op2);
    static Data equals_less_than(const Data op1, const Data op2);
    static Data not_equals(const Data op1, const Data op2);
    static Data logical_and(const Data op1, const Data op2);
    static Data logical_or(const Data op1, const Data op2);
    static Data logical_xor(const Data op1, const Data op2);
    static Data logical_neither(const Data op1, const Data op2);

public:

    enum BinaryOperationFlag
    {
        ADD, SUB, MULT, DIV, MOD, POW, GT, LT, EQ_GT, EQ_LT, EQ, NEQ, AND, OR, XOR, NEITHER
    };
 
    BinaryExpression(shared_ptr<Expression> e1, shared_ptr<Expression> e2, BinaryOperationFlag op);

    virtual Data eval(vector<Data>& callstack) override;
};

class UnaryExpression : public Expression
{
    /*
        Vienas darbības izteiksme sastāv no vienas apakšizteiksmes un darbības, ko ar to veikt
    */

private:
    function<Data(const Data)> operation; 
    shared_ptr<Expression> sub_expression; 

    static void assert_type(const Data op, const vector<TypeLabel>& op_types, string_view op_name);
    static Data invert(const Data op);
    static Data logical_not(const Data op);

public:

    enum UnaryOperationFlag
    {
        NOT, INV
    };

    UnaryExpression(shared_ptr<Expression> e, UnaryOperationFlag op);

    virtual Data eval(vector<Data>& callstack) override;
};

class Statement;

class StatementExpression : public Expression
{
    /*
        Statement izteiksmes rodas, kad statement kā IF, FOR vai vērtības piešķiršana (=)
        atgriež vērtību.

        eval() dod statement rezultātu vai NULL, ja tas neko neatgrieza
    */

private:
    shared_ptr<Statement> statement;

public:
    StatementExpression(shared_ptr<Statement> statement);
    virtual Data eval(vector<Data>& callstack) override;
};

class LiteralExpression : public Expression
{
    /*
        Izteiksme, kam piesaistīta jau aprēķināta vērtība kā literālis (5, 3.14, "test") vai CONST mainīgais.
    */

private:
    DataPtr value;
public:
    LiteralExpression(DataPtr value);
    virtual Data eval(vector<Data>& callstack) override;
};

class VariableExpression : public Expression
{

/*
    Mainīgā izteiksme atgriež ar eval() var_ind pozīcijas vērtību callstack 
*/

private:
    int var_ind;
    string variable_name; // priekš kļūdu paziņojumiem

public:
    VariableExpression(int var_ind, string variable_name="");
    virtual Data eval(vector<Data>& callstack) override;

};

enum ExecutionFlag
{
    NONE //Nav rezultāts, par kuru tālāk ziņot 
    , ADVANCE // Cikls paiet uz priekšu par piesaistīto vērtību
    , BREAK // Cikls apstājas
    , BREAK_ALL // Cikls un visi apkārtējie cikli iekš scope apstājas
    , RETURN // Atgriež vērtību, kas tiek padota uz zemāku scope, apstādina šobrīdējo scope
    , GIVE // Atgriež vērtību, bet apstādina tikai šobrīdējo Program un neatgriež rezultātu zemākiem scope 
    , ASSIGN_RES // Neaptura darbību, bet atgriež vērtību, izmantošana piemērs a = b = 5 (ekvivalents b = 5 EOL a = b)
};

struct ExecutionResult{
    //Saņemot ExecutionResult no Statement ar flag, kas nav NONE
    //Programma (objekts) apstādina darbību un atgriež rezultātu tālāk  

    ExecutionFlag flag;
    Data value;
    int original_scope = -1; //Sākumā scope ir -1, kas nozīme, ka rezultātu vēl nav saņēmusi neviena Programma, lai piešķirtu scope 

    ExecutionResult(ExecutionFlag flag) : flag(flag) {}
    ExecutionResult(ExecutionFlag flag, Data value) : flag(flag), value(value) {}
};

class Statement
{
    /*
        Apraksta vienu kommandu programmā

        Izsaucot exec() tā tiek izpildīta
    */

public:
   virtual ExecutionResult exec(vector<Data>& callstack) = 0;
};

class PrintStatement : public Statement
{
    /*
        Izvada data->eval() + '\n'
    */
private:
    shared_ptr<Expression> data;  
public:
    PrintStatement(shared_ptr<Expression> data) : data(data) {}

    virtual ExecutionResult exec(vector<Data>& callstack) override;
};

class AssignStatement : public Statement
{
    /*
        Ievieto variable_ind pozīcijā iekš callstack data->eval() vērtību 
    */
private:
    int variable_ind;
    shared_ptr<Expression> data;  
public:
    AssignStatement(int variable_ind, shared_ptr<Expression> data) : variable_ind(variable_ind) , data(data) {}

    virtual ExecutionResult exec(vector<Data>& callstack) override;
};

class Program;

class IfStatement : public Statement
{
    /*
        if->elif->elif->...->else komandu virkne, ko izpilda pretēji branches secībai
    */

private:
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> branches;
    shared_ptr<Program> else_prog;
public:
    IfStatement(vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>&& branches, shared_ptr<Program> else_prog=nullptr) : branches(branches), else_prog(else_prog) {}

    virtual ExecutionResult exec(vector<Data>& callstack) override;
};

class ForCounterLoop : public Statement
{
    /*
        for loop ar skaitītāju, tā sākumvērtību, būla izteiksmi līdz, kura ir patiesa turpina atkārtot loop_program un
        lēciena attālumu katrā ciklā
    */

private:
    int counter_ind; // Skaitītāja atrašanās vieta callstack
    shared_ptr<Expression> start, end, jump_amount;
    shared_ptr<Program> loop_program;
public:
    ForCounterLoop(int counter_ind, shared_ptr<Expression> start, shared_ptr<Expression> end, shared_ptr<Expression> jump_amount, shared_ptr<Program> loop_program) : counter_ind(counter_ind), start(start), end(end), jump_amount(jump_amount), loop_program(loop_program) {};
    
    virtual ExecutionResult exec(vector<Data>& callstack) override;

};

class BreakStatement : public Statement
{
    //Standarta break priekš cikliem

public:
    virtual ExecutionResult exec(vector<Data>& callstack) override;
};

class BreakAll : public Statement
{
    //Līdzīgi kā break, bet visisem cikliem iekš scope

public:
    virtual ExecutionResult exec(vector<Data>& callstack) override;
};

class Advance : public Statement
{
    //Līdzīgi kā continue, bet pārvieto iterator par noteiktu vērtību
    //Piemēram, ADVANCE 1 ir ekvivalents CONTINUE
private:
    shared_ptr<Expression> amount;
public:
    Advance(shared_ptr<Expression> amount) : amount(amount) {}
    virtual ExecutionResult exec(vector<Data>& callstack) override;
};

class Return : public Statement
{
    /*
        Return lai izietu no funkcijas un/vai atgrieztu vērtību
    */

private:
    shared_ptr<Expression> value;
public:
    Return(shared_ptr<Expression> value) : value(value) {}
    virtual ExecutionResult exec(vector<Data>& callstack) override;
};

class FunctionStatement : public Statement
{
    /*
        Statement funkcijas izsaukšanai
    */

private:
    vector<shared_ptr<Expression>> arg_vals; // izteiksmes vērtībām, ko padod funkcijas mainīgajiem 
    shared_ptr<Expression> function_expr; // Izteiksme, kuras rezultātam ir jābūt izsaucamai funkcijai
public:
    FunctionStatement(const vector<shared_ptr<Expression>>& arg_vals, shared_ptr<Expression> function_expr) 
    : arg_vals(arg_vals), function_expr(function_expr) {}
    virtual ExecutionResult exec(vector<Data>& callstack) override;
};

class Give : public Statement
{
    /*
        Statement, kas atgriež rezultātu no statement (nevis funckijas)
    */

private:
    shared_ptr<Expression> value;
public:
    Give(shared_ptr<Expression> value) : value(value) {}
    virtual ExecutionResult exec(vector<Data>& callstack) override;
};

class Program
{
    /*
        Programma ir virkne ar Statement, kas tiek izpildīti pēc kārtas (pievienošanas kārtībā)
    
        Statement pievieno ar attach_statement()
        Programmu izpilda ar run()
    */

private:
    vector<shared_ptr<Statement>> statements;
    int scope; // 0 - globālais , u.t.t.
    int callstack_size;

public:
    Program(int scope, int callstack_size=-1) : scope(scope), callstack_size (callstack_size)  {};
    Program(shared_ptr<Statement> first_statement, int scope, int callstack_size=-1) 
     : scope(scope), callstack_size (callstack_size)
    { statements.push_back(first_statement); }

    void attach_statement(shared_ptr<Statement> statement);

    ExecutionResult run();
    ExecutionResult run(const vector<pair<int, Data>>& init_vars);
    ExecutionResult run(vector<Data>& callstack);

    void set_callstack_size(int size) {callstack_size = size;}
};