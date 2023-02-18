#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include <cassert>
#include <stack>
#include "datatypes.h"

class Interpreter
{
    /*
        Interpretora objekts uzglabā informāciju par programmu interpretēšanas brīdī
    */
public:


    int declare_variable(const string& name);
    DataPtr declare_const_variable(const string& name);
    int get_variable(const string& name, bool& non_declared_error);
    DataPtr get_const_val(const string& name, bool& non_declared);
    void make_new_scope();
    void pop_scope();
    void mark_is_in_loop(bool val) { is_in_loop = val; }
    bool in_loop() { return is_in_loop; }
    int get_scope_number() { return scopes.size()-1; };
    bool is_const(const string& name);
    int get_top_scope_size() { return scopes[scopes.size()-1].size(); };
    bool is_sep_scope() { auto ret = sep_scope; sep_scope = false; return ret; };
    void push_function(shared_ptr<Function> func) { curr_functions.push(func); }
    shared_ptr<Function> get_curr_function();
    void pop_function() { curr_functions.pop(); }
    


private:

     // mainīgā nosaukums -> Info
    vector<map<string, int>> scopes; // Katra scope mainīgo atsevišķās vārdnīcas, sarakstu lieto kā steku    
    vector<map<string, DataPtr>> const_scopes;
    stack<shared_ptr<Function>> curr_functions;
    bool is_in_loop = false;
    bool sep_scope;
};