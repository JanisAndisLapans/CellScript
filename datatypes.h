#pragma once

#include <gmpxx.h>
#include <mpfr.h>
#include <string>
#include <string_view>
#include <memory>
#include <vector>
#include <utility>

#include <iostream>

using namespace std;
using namespace placeholders;


enum TypeLabel
{
    NUMBER, STRING, BOOLEAN, NULLTYPE, INF, FUNC
};

class DataType
{
    /*
        Datu tips parent klase
    */
public:
   virtual string_view type_name() const = 0; // Atgriež nosaukumu katram tipam
   virtual TypeLabel type() const  = 0; //Atgriež tipu kā TypeLabel enum vērtību
   virtual string_view to_str() const = 0;
   virtual shared_ptr<DataType> copy() const = 0;
};

typedef shared_ptr<DataType> Data;
typedef shared_ptr<Data> DataPtr;

class Number : public DataType
{
    /*
        Decimālskaitļa klase ar arbitrary precision (caur gmp mpfr)
    */

private:
    mpfr_t value;
    const static mpfr_rnd_t ROUND = MPFR_RNDN;
    const static int BASE = 10;
    const static mpfr_prec_t PRECISION = 512; //Maksimālais ciparu skaits aiz komata
    const static int DECIMAL_PLACES_TO_OUTPUT = -1; // Cik ciparus aiz komata izraksta. Ja <0, tad nevairāk kā desmit (noņemot nost liekas nulles), citādāk precīzu skaitu 

public:

    Number();
    Number(double value);
    Number(const string& value);
    Number(const Number& number);

    virtual string_view type_name() const override { return "Number";}
    virtual TypeLabel type() const override { return TypeLabel::NUMBER;}

    Number& operator=(double value);
    Number& operator=(const string& value);
    Number& operator=(const Number& number);

    Number operator+(const Number& operand) const;
    Number operator-(const Number& operand) const;
    Number operator/(const Number& operand) const;
    Number operator*(const Number& operand) const;
    Number operator%(const Number& operand) const;
    void operator+=(const Number& operand);
    void operator-=(const Number& operand);
    void operator*=(const Number& operand);
    void operator/=(const Number& operand);
    void operator%=(const Number& operand);
    Number& operator++();
    Number& operator--();
    Number exp(const Number& operand) const;
    Number ln() const;

    Number operator-() const;


    bool operator==(const Number& operand) const;
    bool operator!=(const Number& operand) const;
    bool operator<(const Number& operand) const;
    bool operator>(const Number& operand) const;
    bool operator>=(const Number& operand) const;
    bool operator<=(const Number& operand) const;
    
    virtual string_view to_str() const override;
    
    virtual shared_ptr<DataType> copy() const override {return make_shared<Number>(*this);}
    
    ~Number();
};

class String : public DataType, public std::string
{
public:
    String( const char* text ) : std::string( text ) { }
    String( std::string&& text ) : std::string( text ) { }
    String( const std::string_view text ) : std::string( text ) { }
    
    virtual string_view type_name() const override { return "String"; }
    virtual TypeLabel type() const override { return TypeLabel::STRING; }
    virtual string_view to_str() const override { return *this; }

    virtual shared_ptr<DataType> copy() const override {return make_shared<String>(*this);}

};

template<typename T>
class PrimitiveWrapper
{

    T object;
public:
    PrimitiveWrapper(T val) : object(val) { }
    operator T&(){return object;}
    operator const T&() const {return object;}
};

class Boolean : public DataType, public PrimitiveWrapper<bool>
{
public:
    Boolean(bool val) : PrimitiveWrapper(val)  { }
    
    virtual string_view type_name() const override { return "Boolean";}
    virtual TypeLabel type() const override { return TypeLabel::BOOLEAN;}
    virtual string_view to_str() const override { return *this ? "TRUE" : "FALSE" ;}

    virtual shared_ptr<DataType> copy() const override {return make_shared<Boolean>(*this);}

};

class NullType : public DataType
{
public:    
    virtual string_view type_name() const override { return "NullType";}
    virtual TypeLabel type() const override { return TypeLabel::NULLTYPE;}
    virtual string_view to_str() const override { return "NULL"; }

    virtual shared_ptr<DataType> copy() const override {return make_shared<NullType>(*this);}

};

class InfType : public DataType
{
private:
    int positivity = 1;
public:    
    virtual string_view type_name() const override { return "InfinityType";}
    virtual TypeLabel type() const override { return TypeLabel::INF;}
    virtual string_view to_str() const override { return positivity > 0 ? "INF" : "-INF" ; }

    virtual shared_ptr<DataType> copy() const override {return make_shared<InfType>(*this);}

    InfType() { }
    InfType(int positivity) : positivity(positivity) { }
    
    int getPositivity() const { return  positivity ;}
};

class Program;
class FunctionExpression;

class Function : public DataType
{
private: 
    vector<DataPtr> arguments;
    shared_ptr<Program> program;
public:    
    virtual string_view type_name() const override { return "Function";}
    virtual TypeLabel type() const override { return TypeLabel::FUNC;}
    virtual string_view to_str() const override { return "Function at: " + to_string((int)this); }

    virtual shared_ptr<DataType> copy() const override {return make_shared<Function>(*this);}

    Function(const vector<DataPtr>& arguments, shared_ptr<Program> program) : arguments(arguments), program(program) { }

    friend class FunctionExpression;
};