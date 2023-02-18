#include "program.h"

BinaryExpression::BinaryExpression(shared_ptr<Expression> e1, shared_ptr<Expression> e2, BinaryOperationFlag op)
: sub_expression1(e1), sub_expression2(e2)
{
    switch(op)
    {
        case ADD:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::add), _1, _2);
            break;
        case SUB:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::subtract), _1, _2);
            break;      
        case MULT:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::multiply), _1, _2);
            break;      
        case DIV:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::divide), _1, _2);
            break;       
        case MOD:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::modulo), _1, _2);
            break;      
        case POW:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::pow), _1, _2);
            break;      
        case GT:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::greater_than), _1, _2);
            break;      
        case LT:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::less_than), _1, _2);
            break;      
        case EQ_GT:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::equals_greater_than), _1, _2);
            break;      
        case EQ_LT:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::equals_less_than), _1, _2);
            break;      
        case EQ:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::equals), _1, _2);
            break;      
        case NEQ:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::not_equals), _1, _2);
            break;
        case AND:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::logical_and), _1, _2);
            break;
        case OR:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::logical_or), _1, _2);
            break;
        case XOR:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::logical_xor), _1, _2);
            break;      
        case NEITHER:
            this->operation = bind(static_cast<Data(*)(const Data, const Data)>
            (&BinaryExpression::logical_neither), _1, _2);
            break;                                        
        default:
            throw "Unexpected operation flag";
            break;
    }
}

UnaryExpression::UnaryExpression(shared_ptr<Expression> e, UnaryOperationFlag op)
    : sub_expression(e)
{
    switch(op)
    {
        case INV:
            this->operation = bind(static_cast<Data(*)(const Data)>
            (&UnaryExpression::invert), _1);
            break;
        case NOT:
            this->operation = bind(static_cast<Data(*)(const Data)>
            (&UnaryExpression::logical_not), _1);
            break;
        default:
            throw "Unexpected operation flag";
            break;
    }
}

VariableExpression::VariableExpression(int var_ind, string variable_name)
    : var_ind(var_ind), variable_name(variable_name)
{    
}

LiteralExpression::LiteralExpression(DataPtr value)
    : value(value)
{
}


StatementExpression::StatementExpression(shared_ptr<Statement> statement)
    : statement(statement)
{
}

Data BinaryExpression::eval(vector<Data>& callstack)
{
    return operation(sub_expression1->eval(callstack), sub_expression2->eval(callstack));
}

Data UnaryExpression::eval(vector<Data>& callstack)
{
    return operation(sub_expression->eval(callstack));
}

Data VariableExpression::eval(vector<Data>& callstack)
{
    if(callstack[var_ind] == nullptr)
    {
        cout << "Variable " << variable_name << " was never inititialized" << endl;
    }
    return callstack[var_ind];
}

Data LiteralExpression::eval(vector<Data>& callstack)
{
    if(*value == nullptr)
    {
        cout << "May not use same CONST variable to initialize itself" << endl;
        throw "EXCEPTION";
    }
    return *value;
}

Data StatementExpression::eval(vector<Data>& callstack)
{
    auto res = statement->exec(callstack);
    if(res.flag != GIVE && res.flag != ASSIGN_RES)
    {
        return make_shared<NullType>();
    }
    else
    {
        return res.value;
    }
}

void BinaryExpression::assert_types(const Data op1, const Data op2, TypeLabel op1_type, TypeLabel op2_type, string_view op_name)
{
    if(op1->type() != op1_type || op2->type() != op2_type)
    {
        cout << "Type " << op1->type_name() <<" not compatible with " << op2->type_name() << " for operator '" << op_name << "'" << endl;
        throw "EXCEPTION";
    }
}

void BinaryExpression::assert_types_multiple(const Data op1, const Data op2, TypeLabel op1_type, const vector<TypeLabel>& op2_types, string_view op_name)
{
    if(op1->type() == op1_type)
    {
        for(auto allowed_type: op2_types)
        { 
            if(op2->type() == allowed_type)
            {
                return;
            }
        }
    }
    cout << "Type " << op1->type_name() <<" not compatible with " << op2->type_name() << " for operator '" << op_name << "'" << endl;
    throw "EXCEPTION";
}


void UnaryExpression::assert_type(const Data op, const vector<TypeLabel>& op_types, string_view op_name)
{ 
    for(auto allowed_type: op_types)
    { 
        if(op->type() == allowed_type)
        {
            return;
        }
    }
    cout << "Type " << op->type_name() <<" not compatible with operator '" << op_name << "'" << endl;
    throw "EXCEPTION";
}

Data BinaryExpression::add(const Data op1, const Data op2)
{
    if(op1->type() == STRING)
    {
        BinaryExpression::assert_types(op1, op2, STRING, STRING, "+");
        return make_shared<String>(static_cast<const String&>(*op1) + static_cast<const String&>(*op2));
    }
    else if(op1->type() == INF)
    {
        BinaryExpression::assert_types_multiple(op1, op2, INF, {NUMBER, INF}, "+");
        if(op2->type() == INF)
        {
            if(static_cast<const InfType&>(*op1).getPositivity() != static_cast<const InfType&>(*op2).getPositivity())
            {
                cout << "Addition (+) of inifinity (INF) with two different signs is undefined" << endl;
                throw "EXCEPTION";
            }
        }
        return op1->copy();
    }
    else //Number
    {
        BinaryExpression::assert_types_multiple(op1, op2, NUMBER, {NUMBER, INF}, "+");
        if(op2->type() == INF)
        {
            return op2->copy();
        }
        return make_shared<Number>(static_cast<const Number&>(*op1) + static_cast<const Number&>(*op2));
    }
}

Data BinaryExpression::subtract(const Data op1, const Data op2)
{

    if(op1->type() == INF)
    {
        BinaryExpression::assert_types_multiple(op1, op2, INF, {NUMBER, INF}, "+");
        if(op2->type() == INF)
        {
            if(static_cast<const InfType&>(*op1).getPositivity() == static_cast<const InfType&>(*op2).getPositivity())
            {
                cout << "Addition (+) of inifinity (INF) with two different signs is undefined" << endl;
                throw "EXCEPTION";
            }
        }
        return op1->copy();
    }
    else //Number
    {
        BinaryExpression::assert_types_multiple(op1, op2, NUMBER, {NUMBER, INF}, "+");
        if(op2->type() == INF)
        {
            return make_shared<InfType>(-static_cast<const InfType&>(*op2).getPositivity());
        }
        return make_shared<Number>(static_cast<const Number&>(*op1) - static_cast<const Number&>(*op2));
    }
}

Data BinaryExpression::multiply(const Data op1, const Data op2)
{
    if(op1->type() == STRING)
    {    
        BinaryExpression::assert_types(op1, op2, STRING, NUMBER, "*");
        auto op2_ind = static_cast<const Number&>(*op2);
        if(op2_ind < 0 || op2_ind % 1 != 0)
        {
            cout << "String repeat mulitipier can only be a non-negative integer. (Illegal value: " << op2_ind.to_str() << endl;
            throw "Exception";
        }
        auto s = make_shared<String>(""); 
        for(auto i = 0; op2_ind > i; i++)
        {
            *s += static_cast<const String&>(*op1);
        }
        return s;
    }
    else if(op1->type() == INF)
    {
        BinaryExpression::assert_types(op1, op2, INF, NUMBER, "*");
        if(static_cast<const Number&>(*op2) > 0)
        {
            return make_shared<InfType>(static_cast<const InfType&>(*op1).getPositivity());
        }
        else
        {
            return make_shared<InfType>(-static_cast<const InfType&>(*op1).getPositivity());
        }
    }
    else //Number 
    {
        BinaryExpression::assert_types_multiple(op1, op2, NUMBER, {NUMBER, STRING, INF}, "*");
        if(op2->type() == STRING)
        {
            auto op1_ind = static_cast<const Number&>(*op1);
            if(op1_ind < 0 || op1_ind % 1 != 0)
            {
                cout << "String repeat mulitipier can only be a non-negative integer. (Illegal value: " << op1_ind.to_str() << endl;
                throw "Exception";
            }
            auto s = make_shared<String>(""); 
            for(auto i = 0; op1_ind > i; i++)
            {
                *s += static_cast<const String&>(*op2);
            }
            return s;
        }
        else if(op2->type() == INF)
        {
            if(static_cast<const Number&>(*op1) > 0)
            {
                return make_shared<InfType>(static_cast<const InfType&>(*op2).getPositivity());
            }
            else
            {
                return make_shared<InfType>(-static_cast<const InfType&>(*op2).getPositivity());
            }
        }

        return make_shared<Number>(static_cast<const Number&>(*op1) * static_cast<const Number&>(*op2));
    }
}

Data BinaryExpression::divide(const Data op1, const Data op2)
{
    BinaryExpression::assert_types(op1, op2, NUMBER, NUMBER, "/");
    auto op2_ind = static_cast<const Number&>(*op2);
    if(op2_ind == 0)
    {
        cout << "Divison by zero" << endl;
        throw "Exception";
    }
    return make_shared<Number>(static_cast<const Number&>(*op1) / op2_ind);
}

Data BinaryExpression::modulo(const Data op1, const Data op2)
{
    BinaryExpression::assert_types(op1, op2, NUMBER, NUMBER, "/");
    auto op2_ind = static_cast<const Number&>(*op2);
    if(op2_ind == 0)
    {
        cout << "Divison by zero" << endl;
        throw "Exception";
    }
    return make_shared<Number>(static_cast<const Number&>(*op1) % op2_ind);
}

Data BinaryExpression::pow(const Data op1, const Data op2)
{
    BinaryExpression::assert_types(op1, op2, NUMBER, NUMBER, "power of (^)");
    return make_shared<Number>(static_cast<const Number&>(*op1).exp(static_cast<const Number&>(*op2)));
}

Data BinaryExpression::equals(const Data op1, const Data op2)
{
    if(op1->type() == NULLTYPE)
    {
        return make_shared<Boolean>(op2->type() == NULLTYPE);
    }
    else if(op2->type() == NULLTYPE)
    {
        return make_shared<Boolean>(op1->type() == NULLTYPE);
    }
    else if(op1->type() == BOOLEAN)
    { 
        BinaryExpression::assert_types(op1, op2, BOOLEAN, BOOLEAN, "==");
        return make_shared<Boolean>(static_cast<const Boolean&>(*op1) == static_cast<const Boolean&>(*op2));    
    }
    else if(op1->type() == NUMBER)
    {
        BinaryExpression::assert_types_multiple(op1, op2, NUMBER, {NUMBER, INF}, "==");
        if(op2->type() == INF)
        {
            return make_shared<Boolean>(false);
        }
        return make_shared<Boolean>(static_cast<const Number&>(*op1) == static_cast<const Number&>(*op2));
    }
    else if(op1->type() == INF)
    {
        BinaryExpression::assert_types_multiple(op1, op2, INF, {NUMBER, INF}, "==");
        bool ret = op2->type() == INF && static_cast<const InfType&>(*op2).getPositivity() == static_cast<const InfType&>(*op1).getPositivity();
        return make_shared<Boolean>(ret);
    }
    else // STRING
    {
        BinaryExpression::assert_types(op1, op2, STRING, STRING, "==");
        return make_shared<Boolean>(static_cast<const String&>(*op1).compare(static_cast<const String&>(*op2)) == 0);
    }
}

Data BinaryExpression::not_equals(const Data op1, const Data op2)
{
    if(op1->type() == NULLTYPE)
    {
        return make_shared<Boolean>(op2->type() == NULLTYPE);
    }
    else if(op2->type() != NULLTYPE)
    {
        return make_shared<Boolean>(op1->type() == NULLTYPE);
    }
    else if(op1->type() != BOOLEAN)
    { 
        BinaryExpression::assert_types(op1, op2, BOOLEAN, BOOLEAN, "!=");
        return make_shared<Boolean>(static_cast<const Boolean&>(*op1) != static_cast<const Boolean&>(*op2));    
    }
    else if(op1->type() == NUMBER)
    {
        BinaryExpression::assert_types_multiple(op1, op2, NUMBER, {NUMBER, INF}, "!=");
        if(op2->type() == INF)
        {
            return make_shared<Boolean>(true);
        }
        return make_shared<Boolean>(static_cast<const Number&>(*op1) != static_cast<const Number&>(*op2));
    }
    else if(op1->type() == INF)
    {
        BinaryExpression::assert_types_multiple(op1, op2, INF, {NUMBER, INF}, "!=");
        bool ret = op2->type() != INF || static_cast<const InfType&>(*op2).getPositivity() != static_cast<const InfType&>(*op1).getPositivity();
        return make_shared<Boolean>(ret);
    }
    else // STRING
    {
        BinaryExpression::assert_types(op1, op2, STRING, STRING, "!=");
        return make_shared<Boolean>(static_cast<const String&>(*op1).compare(static_cast<const String&>(*op2)) != 0);
    }
}

Data BinaryExpression::greater_than(const Data op1, const Data op2)
{
    if(op1->type() == INF)
    {
        BinaryExpression::assert_types_multiple(op1, op2, INF, {NUMBER, INF}, ">");
        if(op2->type() == NUMBER)
        {
            return make_shared<Boolean>(static_cast<const InfType&>(*op1).getPositivity() > 0);
        }
        
        return make_shared<Boolean>(static_cast<const InfType&>(*op1).getPositivity() > static_cast<const InfType&>(*op2).getPositivity());
    }
    else // Number
    {
        BinaryExpression::assert_types_multiple(op1, op2, NUMBER, {NUMBER, INF}, ">");
        if(op2->type() == INF)
        {
            return make_shared<Boolean>(static_cast<const InfType&>(*op2).getPositivity() > 0);
        }

        return make_shared<Boolean>(static_cast<const Number&>(*op1) > static_cast<const Number&>(*op2));
    }
}

Data BinaryExpression::less_than(const Data op1, const Data op2)
{
    if(op1->type() == INF)
    {
        BinaryExpression::assert_types_multiple(op1, op2, INF, {NUMBER, INF}, "<");
        if(op2->type() == NUMBER)
        {
            return make_shared<Boolean>(static_cast<const InfType&>(*op1).getPositivity() < 0);
        }
        
        return make_shared<Boolean>(static_cast<const InfType&>(*op1).getPositivity() < static_cast<const InfType&>(*op2).getPositivity());
    }
    else // Number
    {
        BinaryExpression::assert_types_multiple(op1, op2, NUMBER, {NUMBER, INF}, "<");
        if(op2->type() == INF)
        {
            return make_shared<Boolean>(static_cast<const InfType&>(*op2).getPositivity() < 0);
        }

        return make_shared<Boolean>(static_cast<const Number&>(*op1) < static_cast<const Number&>(*op2));
    }
}

Data BinaryExpression::equals_greater_than(const Data op1, const Data op2)
{
    if(op1->type() == INF)
    {
        BinaryExpression::assert_types_multiple(op1, op2, INF, {NUMBER, INF}, ">=");
        if(op2->type() == NUMBER)
        {
            return make_shared<Boolean>(static_cast<const InfType&>(*op1).getPositivity() > 0);
        }
        
        return make_shared<Boolean>(static_cast<const InfType&>(*op1).getPositivity() >= static_cast<const InfType&>(*op2).getPositivity());
    }
    else // Number
    {
        BinaryExpression::assert_types_multiple(op1, op2, NUMBER, {NUMBER, INF}, ">=");
        if(op2->type() == INF)
        {
            return make_shared<Boolean>(static_cast<const InfType&>(*op2).getPositivity() > 0);
        }

        return make_shared<Boolean>(static_cast<const Number&>(*op1) >= static_cast<const Number&>(*op2));
    }
}

Data BinaryExpression::equals_less_than(const Data op1, const Data op2)
{
    if(op1->type() == INF)
    {
        BinaryExpression::assert_types_multiple(op1, op2, INF, {NUMBER, INF}, "<=");
        if(op2->type() == NUMBER)
        {
            return make_shared<Boolean>(static_cast<const InfType&>(*op1).getPositivity() < 0);
        }
        
        return make_shared<Boolean>(static_cast<const InfType&>(*op1).getPositivity() <= static_cast<const InfType&>(*op2).getPositivity());
    }
    else // Number
    {
        BinaryExpression::assert_types_multiple(op1, op2, NUMBER, {NUMBER, INF}, "<=");
        if(op2->type() == INF)
        {
            return make_shared<Boolean>(static_cast<const InfType&>(*op2).getPositivity() < 0);
        }

        return make_shared<Boolean>(static_cast<const Number&>(*op1) <= static_cast<const Number&>(*op2));
    }
}

Data BinaryExpression::logical_and(const Data op1, const Data op2)
{
    BinaryExpression::assert_types(op1, op2, BOOLEAN, BOOLEAN, "AND");
    return make_shared<Boolean>(static_cast<const Boolean&>(*op1) && static_cast<const Boolean&>(*op2));
}

Data BinaryExpression::logical_or(const Data op1, const Data op2)
{
    BinaryExpression::assert_types(op1, op2, BOOLEAN, BOOLEAN, "OR");
    return make_shared<Boolean>(static_cast<const Boolean&>(*op1) || static_cast<const Boolean&>(*op2));
}

Data BinaryExpression::logical_xor(const Data op1, const Data op2)
{
    BinaryExpression::assert_types(op1, op2, BOOLEAN, BOOLEAN, "XOR");
    return make_shared<Boolean>(static_cast<const Boolean&>(*op1) ^ static_cast<const Boolean&>(*op2));
}

Data BinaryExpression::logical_neither(const Data op1, const Data op2)
{
    //NOR

    BinaryExpression::assert_types(op1, op2, BOOLEAN, BOOLEAN, "NEITHER (NOR)");
    return make_shared<Boolean>(!(static_cast<const Boolean&>(*op1) || static_cast<const Boolean&>(*op2)));
}

Data UnaryExpression::invert(const Data op)
{
    UnaryExpression::assert_type(op, {NUMBER, INF}, "- (invert)");
    if(op->type() == INF)
    {
        return make_shared<InfType>(-static_cast<const InfType&>(*op).getPositivity());
    }

    return make_shared<Number>(-static_cast<const Number&>(*op));
}

Data UnaryExpression::logical_not(const Data op)
{
    UnaryExpression::assert_type(op, {BOOLEAN}, "NOT");
    return make_shared<Boolean>(!static_cast<const Boolean&>(*op));
}

void Program::attach_statement(shared_ptr<Statement> statement)
{
    statements.push_back(statement);
}

ExecutionResult Program::run(vector<Data>& callstack)
{
    int i = 0;
    for(auto& statement : statements)
    {
        auto res = statement->exec(callstack);
        if(res.flag != NONE && res.flag != ASSIGN_RES && (res.original_scope == -1 || res.original_scope == scope))
        {
            if(res.flag == GIVE && res.original_scope != -1)
            {
                //GIVE attiecas tikai uz vienu koda bloku (program) (neatkarīgi no scope, ja jau ir uzstādīts scope, tad GIVE jau ir apturējis vienu programmu)
                continue;
            }
            res.original_scope = scope;
            return res;
        }
        i++;
    }
    return ExecutionResult(NONE);
}

ExecutionResult Program::run(const vector<pair<int, Data>>& init_vars)
{
    vector<Data> callstack(callstack_size, nullptr);
    for(auto [ind, data] : init_vars)
    {
        callstack[ind] = data;
    }
    return run(callstack);
}

ExecutionResult Program::run()
{
    vector<Data> callstack(callstack_size, nullptr);
    return run(callstack);
}


ExecutionResult PrintStatement::exec(vector<Data>& callstack)
{
    cout << data->eval(callstack)->to_str() << endl;
    return ExecutionResult(NONE);
}

ExecutionResult AssignStatement::exec(vector<Data>& callstack)
{

    callstack[variable_ind] = data->eval(callstack);
    return ExecutionResult(ASSIGN_RES, callstack[variable_ind]);
}

ExecutionResult IfStatement::exec(vector<Data>& callstack)
{
    for(auto riter = branches.rbegin(); riter!=branches.rend(); riter++)
    {
        auto& [expr, to_do] = *riter;
        auto test_val = expr->eval(callstack);
        
        //Pārbauda bai ir būla tips
        shared_ptr<Boolean> test_val_bool;
        if(!(test_val_bool = dynamic_pointer_cast<Boolean>(test_val)))
        {
            cout <<"Value " <<test_val->to_str() <<" of type " << test_val->type_name() << " is of wrong type! BOOLEAN required." <<endl;
            throw "Exception";
        }

        //Pārbauda, vai bool_val == true
        if(*test_val_bool)
        {    
            return to_do->run(callstack);
        }
    }

    //Ja ir else izpilda
    if(else_prog != nullptr)
        return else_prog->run(callstack);

    return ExecutionResult(NONE);
}

ExecutionResult ForCounterLoop::exec(vector<Data>& callstack)
{
    if(dynamic_pointer_cast<VariableExpression>(start) || dynamic_pointer_cast<LiteralExpression>(start))
    {
        callstack[counter_ind] = start->eval(callstack)->copy();
    }
    else
    {
        callstack[counter_ind] = start->eval(callstack);
    }

    shared_ptr<Number> counter_num;

    if(!(counter_num = dynamic_pointer_cast<Number>(callstack[counter_ind])))
    {
        cout << "Counter must be of type Number, " << (callstack[counter_ind])->type_name() << " is invalid" << endl;
        throw "Exception";        
    }

    while(true)
    {
        auto end_val = end->eval(callstack);

        shared_ptr<Number> end_val_num;
        shared_ptr<InfType> end_val_inf;


        bool end_val_is_inf = false;


        if((end_val_inf = dynamic_pointer_cast<InfType>(end_val)))
        {
            end_val_is_inf = true;
        }
        else if(!(end_val_num = dynamic_pointer_cast<Number>(end_val)))
        {
            cout << "Loop end must be of type Number or InfinityType, " << end_val->type_name() << " is invalid" << endl;
            throw "Exception";    
        }

        auto jump_val = jump_amount->eval(callstack);

        shared_ptr<Number> jump_val_num;

        if(!(jump_val_num = dynamic_pointer_cast<Number>(jump_val)))
        {
            cout << "Jump amount (BY) must be of type Number, " << end_val->type_name() << " is invalid" << endl;
            throw "Exception";    
        }

        //noskaidro vai lēciens pārnesīs uz pozitīvo vai negatīvo pusi
        
        auto next_counter_pos = *counter_num + *jump_val_num;
        auto positive = (next_counter_pos - *counter_num) >= 0;
        //Pārbauda vai end_val_num nav pārsniegts. Pēc principa, ja nākamais lēciens pārnesīs uz pozitīvo pusi, tad
        //end_val_num jābūt lielākam, ja uz negatīvo, tad mazākam
        if((end_val_is_inf && (end_val_inf->getPositivity() > 0) == positive) 
        || (positive && *counter_num < *end_val_num) || (!positive && *counter_num > *end_val_num))
        {
            //Palaiž programmu cikla sākumā
            auto res = loop_program->run(callstack);
            
            if(res.flag == ADVANCE)
            {
                //Izmaina counter pēc cikla darbības ar jaunu vērtību atkarībā no advance
                *counter_num += *jump_val_num * (*static_pointer_cast<Number>(res.value));
            }
            else if(res.flag != NONE)
            {
                if(res.flag == BREAK)
                {
                    //BREAK attiecas tikai uz vienu ciklu
                    return ExecutionResult(NONE);
                }
                else
                {
                    return res;
                }
            }
            else
            {
                //Izmaina counter pēc cikla darbības ar jauno vērtību
                *counter_num = next_counter_pos; 
            }
        }
        else
        {
            //ciklu beigas
            break;
        }
    }
    return ExecutionResult(NONE);
}

ExecutionResult BreakStatement::exec(vector<Data>& callstack)
{
    return ExecutionResult(BREAK);
}

ExecutionResult BreakAll::exec(vector<Data>& callstack)
{
    return ExecutionResult(BREAK_ALL);
}

ExecutionResult Advance::exec(vector<Data>& callstack)
{
    auto advance_amount = amount->eval(callstack);
    if(advance_amount->type() != NUMBER)
    {
        cout << "ADVANCE parameter must be a Number, " << advance_amount->type_name() << " provided"<<endl;
        throw "EXCEPTION";
    }
    return ExecutionResult(ADVANCE, advance_amount);
}

ExecutionResult Return::exec(vector<Data>& callstack)
{   
    return ExecutionResult(RETURN, value->eval(callstack));
}

ExecutionResult Give::exec(vector<Data>& callstack)
{
    return ExecutionResult(GIVE, value->eval(callstack));
}

ExecutionResult FunctionStatement::exec(vector<Data>& callstack)
{
    auto function_data = function_expr->eval(callstack);
    shared_ptr<Function> function; 
    if(!(function = dynamic_pointer_cast<Function>(function_data)))
    {
        cout << "Attempt to call a non callable object of type " << function_data->type_name() << endl;
        throw "EXCEPTION";
    }

    if(arg_vals.size() != function->arg_variables.size())
    {
        cout << arg_vals.size() << " arguemnts provided to function but " << function->arg_variables.size() << " required.";
    }

    vector<pair<int, Data>> args;

    for(auto i = 0; i<function->arg_variables.size(); i++)
    {
        args.push_back(make_pair(function->arg_variables[i], arg_vals[i]->eval(callstack)));         
    }

    auto res = function->program->run(args);
    if(res.flag != RETURN)
    {
        return ExecutionResult(NONE);
    }
    else
    {
        return ExecutionResult(GIVE, res.value);
    }

}