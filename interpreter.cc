#include "interpreter.h"

int Interpreter::declare_variable(const string& name)
{
    /*
        Izveido mainīgo ar nosaukumu name iekš šobrīdēja scope (funckijas vai globālā)
        Tam var piekļūt tikai no ši scope
        Atgriež mainīgā kārtas numuru callstack
    */
    int var_num;

    auto& curr_scope = scopes[scopes.size()-1];
    var_num = curr_scope.size();
    curr_scope[name] = var_num;

    return var_num;
}

DataPtr Interpreter::declare_const_variable(const string& name)
{
    /*
        Izveido konstantu mainīgo ar nosaukumu name iekš šī scope (tam varēs piekļūt arī zemāki scope)
        Atgriež tā atmiņas adresi
    */

    auto& curr_scope = const_scopes[const_scopes.size()-1];
    
    curr_scope[name] = make_shared<Data>(nullptr);

    return curr_scope[name];
}

int Interpreter::get_variable(const string& name, bool& non_declared)
{
    /*
        Atgriež kārtas numuru mainīgajam ar nosaukumu name
        Akarībā no tā vai tas ir deklarēts uzstāda non_declared
    */

    auto& curr_scope = scopes[scopes.size()-1];

    if(curr_scope.count(name))
    {
        non_declared = false;
        return curr_scope[name];
    }

    //Nav scope deklarēts mainīgais
    non_declared = true;
    return -1;
}

DataPtr Interpreter::get_const_val(const string& name, bool& non_declared)
{
    /*
        Atgriež atmiņas adresi konstantam mainīgajam ar nosaukumu name
        Akarībā no tā vai tas ir deklarēts uzstāda non_declared
    */

    for(auto riter = const_scopes.rbegin(); riter != const_scopes.rend(); riter++)
    {
        auto& scope = *riter;
        if(scope.count(name))
        {
            non_declared = false;
            return scope[name];
        }
    }
    
    //Nav scope vai augstākā deklarēts mainīgais
    non_declared = true;
    return nullptr;
}

void Interpreter::make_new_scope()
{
    scopes.push_back(map<string, int>());
    const_scopes.push_back(map<string, DataPtr>());
    sep_scope = true;
}
void Interpreter::pop_scope()
{
    assert(scopes.size() > 0);

    scopes.pop_back();
    sep_scope = false; 
}
bool Interpreter::is_const(const string& name)
{
    // Vai mainīgas ar nosaukumu name ir konstants ?

    bool non_declared;
    get_const_val(name, non_declared);
    return !non_declared;
}

shared_ptr<Function> Interpreter::get_curr_function()
{
    // Atgriež funckiju, kuru šobrīd būvē parseris

    if(curr_functions.size() == 0)
    {
        return nullptr;
    }

    return curr_functions.top(); 
}