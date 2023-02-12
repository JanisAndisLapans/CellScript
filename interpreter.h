#pragma once

#include <map>
#include "datatypes.h"
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include <cassert>

class Interpreter
{
    /*
        Interpretora objekts uzglabā informāciju par programmu interpretēšanas brīdī
    */
public:

    struct Variable
    {
        DataPtr mem_location;
        bool is_const;
    };

    bool is_in_loop = false;

    Variable declare_variable(const string& name, bool set_const);
    Variable get_variable(const string& name, bool& non_declared_error);
    void make_new_scope();
    void pop_scope();
    void mark_is_in_loop(bool val) { is_in_loop = val; }
    bool in_loop() { return is_in_loop; }
    int get_scope_number() { return scopes.size()-1; };


private:

     // mainīgā nosaukums -> Info
    vector<map<string, Variable>> scopes; // Katra scope mainīgo atsevišķās vārdnīcas, sarakstu lieto kā steku    


};