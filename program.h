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
    virtual Data eval() = 0;
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

    virtual Data eval() override;
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

    virtual Data eval() override;
};

class FunctionExpression : public Expression
{
    /*
        Funkcijas izteiksme izsauc piesaistīto funkciju ar arg_vals un atgriež
        tās rezultātu (ja tāda nav, tad NULL)
    */
    
private:
    vector<shared_ptr<Expression>> arg_vals;
    shared_ptr<Expression> function_expr;

public:

    FunctionExpression(const vector<shared_ptr<Expression>>& arg_vals, shared_ptr<Expression> function_expr);
    virtual Data eval() override;
};

class ValueExpression : public Expression
{

/*
    Vērtības izteiksme ir wrapper klase DataPtr, lai tā vērtību izmantotu kā izteiksmi
*/

private:
    DataPtr value_ref;
    string variable_name; //Ja piesaistīts mainīgais, tad jāzina tā vērtība priekš kļūdu paziņojumiem

public:
    ValueExpression(DataPtr value_ref, string variable_name="");
    virtual Data eval() override;

};

enum ExecutionFlag
{
    NONE, ADVANCE, BREAK, BREAK_ALL, RETURN
};

struct ExecutionResult{
    //Saņemot ExecutionResult no Statement ar flag, kas nav NONE
    //Programma (objekts) astādina darbību un atgriež rezultātu tālāk  

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
   virtual ExecutionResult exec() = 0;
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

    virtual ExecutionResult exec() override;
};

class AssignStatement : public Statement
{
    /*
        Ievieto mem_location data->eval() vērtību 
    */
private:
    DataPtr mem_location;
    shared_ptr<Expression> data;  
public:
    AssignStatement(DataPtr mem_location, shared_ptr<Expression> data) : mem_location(mem_location) , data(data) {}

    virtual ExecutionResult exec() override;
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

    virtual ExecutionResult exec() override;
};

class ForCounterLoop : public Statement
{
    /*
        for loop ar skaitītāju, tā sākumvērtību, būla izteiksmi līdz, kura ir patiesa turpina atkārtot loop_program un
        lēciena attālumu katrā ciklā
    */

private:
    DataPtr counter_mem; // Skaitītāja atrašanās vieta
    shared_ptr<Expression> start, end, jump_amount;
    shared_ptr<Program> loop_program;
public:
    ForCounterLoop(DataPtr counter_mem, shared_ptr<Expression> start, shared_ptr<Expression> end, shared_ptr<Expression> jump_amount, shared_ptr<Program> loop_program) : counter_mem(counter_mem), start(start), end(end), jump_amount(jump_amount), loop_program(loop_program) {};
    
    virtual ExecutionResult exec() override;

};

class BreakStatement : public Statement
{

    //Standarta break priekš cikliem
public:
    virtual ExecutionResult exec() override;
};

class BreakAll : public Statement
{
    //Līdzīgi kā break, bet visisem cikliem iekš scope

public:
    virtual ExecutionResult exec() override;
};

class Advance : public Statement
{
    //Līdzīgi kā continue, bet pārvieto iterator par noteiktu vērtību
    //Piemēram, ADVANCE 1 ir ekvivalents CONTINUE
private:
    shared_ptr<Expression> amount;
public:
    Advance(shared_ptr<Expression> amount) : amount(amount) {}
    virtual ExecutionResult exec() override;
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

public:
    Program(int scope) : scope(scope) {};
    Program(shared_ptr<Statement> first_statement, int scope)  : scope(scope) { statements.push_back(first_statement); }

    void attach_statement(shared_ptr<Statement> statement);

    ExecutionResult run();
};