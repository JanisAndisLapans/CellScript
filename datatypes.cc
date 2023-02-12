#include "datatypes.h"

Number::Number()
{
    mpfr_init(this->value);
}

Number::Number(const Number& number)
{
    mpfr_init(this->value);
    mpfr_set(this->value, number.value, ROUND);
}

Number::Number(double value)
{
    /*
        Inicializē ar vērtību value 
    */
    mpfr_init2(this->value, PRECISION);
    mpfr_set_d(this->value, value, ROUND);
}

Number::Number(const string& value)
{
    /*
        Inicializē ar value vērtību pārverstu par
        peldošā punkta skaitli 
    */
    mpfr_init2(this->value, PRECISION);
    mpfr_set_str(this->value, value.c_str(), BASE, ROUND);
}

Number& Number::operator=(double value)
{   
    mpfr_clear(this->value);
    mpfr_init2(this->value, PRECISION);
    mpfr_set_d(this->value, value, ROUND);
    return *this;
}

Number& Number::operator=(const string& value)
{
    mpfr_clear(this->value);
    mpfr_init2(this->value, PRECISION);
    mpfr_set_str(this->value, value.c_str(), BASE, ROUND);
    return *this;
}

Number& Number::operator=(const Number& number)
{
    mpfr_clear(this->value);
    mpfr_init(this->value);
    mpfr_set(this->value, number.value, ROUND);
    return *this;
}

Number Number::operator+(const Number& operand) const
{
    Number res;
    mpfr_add(res.value, this->value, operand.value, ROUND);
    return res;
}

Number Number::operator-(const Number& operand) const
{
    Number res;
    mpfr_sub(res.value, this->value, operand.value, ROUND);
    return res;
}

Number Number::operator*(const Number& operand) const 
{
    Number res;
    mpfr_mul(res.value, this->value, operand.value, ROUND);
    return res;
}

Number Number::operator/(const Number& operand) const
{
    Number res;
    mpfr_div(res.value, this->value, operand.value, ROUND);
    return res;
}

Number Number::operator%(const Number& operand) const
{
    Number res;
    mpfr_fmod(res.value, this->value, operand.value, ROUND);
    return res;
}

void Number::operator+=(const Number& operand)
{
    mpfr_add(this->value, this->value, operand.value, ROUND);
}

void Number::operator-=(const Number& operand)
{
    mpfr_sub(this->value, this->value, operand.value, ROUND);
}

void Number::operator*=(const Number& operand)
{
    mpfr_mul(this->value, this->value, operand.value, ROUND);
}

void Number::operator/=(const Number& operand)
{
    mpfr_div(this->value, this->value, operand.value, ROUND);
}

void Number::operator%=(const Number& operand)
{
    mpfr_fmod(this->value, this->value, operand.value, ROUND);
}

Number& Number::operator++()
{
    static const Number one(1.0);
    mpfr_add(this->value, this->value, one.value, ROUND);
    return *this;
}

Number& Number::operator--()
{
    static const Number one(1.0);
    mpfr_sub(this->value, this->value, one.value, ROUND);
    return *this;
}

Number Number::exp(const Number& operand) const
{
    //Šis skaitlis pakāpē operand

    Number res;
    mpfr_pow(res.value, this->value, operand.value, ROUND);
    return res;
}

Number Number::ln() const
{
    //Naturālais logaritms

    Number res;
    mpfr_log(res.value, this->value, ROUND);
    return res;
}

string_view Number::to_str() const
{
    const mpfr_prec_t DEFAULT_PREC_MAX = 10; 

    //Skaitlis pārvērsts par virkni decimālajā formātā ar DECIMAL_PLACES_TO_OUTPUT cipariem aiz komata
    //Ja DECIMAL_PLACES_TO_OUTPUT < 0, tad parāda līdz 10 skaitļiem aiz komata, ja nav tad mazāk
    //Ja DECIMAL_PLACES_TO_OUTPUT >= 0, tad parāda tieši decimal places skaitļus aiz komata. Ja trūkst pievieno papildus 0

    char* c_str;
    
    if(DECIMAL_PLACES_TO_OUTPUT < 0)
    { 
        mpfr_asprintf(&c_str, "%.*Rf", DEFAULT_PREC_MAX, this->value);

        //atrod garumu c_str, kas neiekļauj beigu nulles
        int i;
        char c;
        bool dot_found = false;
        int dot_pos;
        int last_zero_start = -1; //Pēdējās nuļļu virknes sākums, -1 - neatrodas nuļļu virknē
        for(i = 0; (c = c_str[i]) != '\0'; i++)
        {
            if(c == '0')
            {
                if(dot_found && last_zero_start == -1)
                    last_zero_start = i;
            }
            else
            {
                last_zero_start = -1;
            }
            if(c == '.')
            {
                dot_found = true;
                dot_pos = i;
            }
        }
        size_t len;
        if(last_zero_start == dot_pos+1)
        {
            len = dot_pos;
        }
        else if(last_zero_start != -1) //beidzas ar nullēm
        {
            len = last_zero_start;
        }
        else
        {
            len = i+1;
        }
        return string_view(c_str, len);
    } 
    else
    {
        mpfr_asprintf(&c_str, "%.*Rf", DECIMAL_PLACES_TO_OUTPUT, this->value);
        return string_view(c_str);
    }
}

bool Number::operator==(const Number& operand) const
{
    return mpfr_cmp(this->value, operand.value) == 0;
}

bool Number::operator!=(const Number& operand) const
{
    return !(*this==operand);
}

bool Number::operator<(const Number& operand) const
{
    return mpfr_cmp(this->value, operand.value) < 0;
}

bool Number::operator>(const Number& operand) const
{
    return mpfr_cmp(this->value, operand.value) > 0;
}

bool Number::operator>=(const Number& operand) const
{
    return *this == operand || *this > operand;
}

bool Number::operator<=(const Number& operand) const
{
    return *this == operand || *this < operand;
}

Number Number::operator-() const
{
    Number res;
    mpfr_neg(res.value, this->value, ROUND);
    return res;
}


Number::~Number()
{
    mpfr_clear(this->value);
}