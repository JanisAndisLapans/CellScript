#include "interpreter.h"

Interpreter::Variable Interpreter::declare_variable(const string&name, bool set_const)
{
    /*
        Izveido mainīgo ar nosaukumu name, const vērtību, kas atkarīga no set_const vērtības.
        Atgriež informāciju par jauno mainīgo

        Piezīme:
        Metode pieņem, ka mainīgais nav jau deklarēts (mērķa scope), un nav definēta pretējā gadījumā
        Metode arī pieņem, ka eksistē vismaz viens scope
    */
    Variable variable;
    variable.mem_location = make_shared<Data>();
    variable.is_const = set_const;
    auto& currScope = scopes[scopes.size()-1];
    currScope[name] = variable;
    return variable;
}


Interpreter::Variable Interpreter::get_variable(const string&name, bool& non_declared)
{
    /*
        Atgriež informāciju par mainīgo ar nosaukumu name.
        Meklē augšējā scope
        Ja tāds neeksistē atgriež tukšu objektu un uzstāda non_declared = true, citādāk false
    */

    auto& currScope = scopes[scopes.size()-1];

    if(currScope.count(name))
    {
        non_declared = false;
        return currScope[name];
    }
    //Nav scope deklarēts mainīgais
    non_declared = true;
    return Variable();
}

void Interpreter::make_new_scope()
{
    scopes.push_back(map<string, Variable>());
}
void Interpreter::pop_scope()
{
    assert(scopes.size() > 0);

    scopes.pop_back();
}