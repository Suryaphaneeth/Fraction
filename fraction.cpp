#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "fraction.hpp"

using namespace std;

//Math function to compute GCD
long Fraction::gcd(long num1, long num2){
    if(num1 == 0)
        return num2;
    else
        return (gcd(num2 % num1, num1));
}

//Math function to calculate LCM
long Fraction::lcm(long num1,  long num2){
    long great_Divisor = gcd(num1, num2);
    return ((num1/great_Divisor) * num2);
}

//Reduce fraction to its minimal
void Fraction::reduce(){
    if(denominator!=0){
        long great_Divisor = gcd(numerator, denominator);
        numerator /= great_Divisor;
        denominator /= great_Divisor;
        if(denominator < 0 && numerator > 0){
            denominator = -denominator;
            numerator = -numerator;
        }
    }
}

//constructors
Fraction::Fraction(){
    denominator = 0;
    numerator = 0;
}

Fraction::Fraction(long num, long den):numerator(num), denominator(den){
    reduce();
}

Fraction::Fraction(string fracStr){
    convert_string_to_fraction(fracStr);
}

Fraction::Fraction(int num){
    convert_int_to_fraction(num);
}

Fraction::Fraction(double num){
    convert_double_to_fraction(num);
}
//typecast helper conversion functions
void Fraction::convert_int_to_fraction(int num){
    denominator = 1;
    numerator = long(num);
    reduce();
}

void Fraction::convert_double_to_fraction(double num){
    denominator = 1;
    while((double)(long)num != num){
        num = num * 10;
        denominator = denominator * 10;
    }
    numerator = (long)num;
    reduce();
}

int Fraction::convert_fraction_to_int(){
    return ((int)(numerator/denominator));
}

double Fraction::convert_fraction_to_double(){
    return ((double)numerator/(double)denominator);
}

long Fraction::convert_fraction_to_long(){
    return (long)((double)numerator/(double)denominator);
}
//setter Functions
void Fraction::setNumerator(long num){
    numerator = num;
}

void Fraction::setDenominator(long den){
    denominator = den;
}

//getter Functions
long Fraction::getNumerator(){
    return numerator;
}

long Fraction::getDenominator(){
    return denominator;
}


//ostream overload
ostream& operator<<(ostream& os, const Fraction& fracNumber){
    os << fracNumber.numerator << "/" << fracNumber.denominator ;
    return os;
}


//overload operator functions

Fraction::operator double(){
    return convert_fraction_to_double();
}

Fraction::operator long(){
    return convert_fraction_to_long();
}

Fraction::operator int(){
    return convert_fraction_to_int();
}

bool Fraction::operator<(Fraction fraction){
    long least_Multiple = lcm(denominator, fraction.getDenominator());
    return ((numerator *  (least_Multiple/denominator)) < 
            (fraction.getNumerator() * (least_Multiple/fraction.getDenominator())));
}

bool Fraction::operator>(Fraction fraction){
    long least_Multiple = lcm(denominator, fraction.getDenominator());
    return ((numerator *  (least_Multiple/denominator)) > 
            (fraction.getNumerator() * (least_Multiple/fraction.getDenominator())));
}

bool Fraction::operator<=(Fraction fraction){
    long least_Multiple = lcm(denominator, fraction.getDenominator());
    return ((numerator *  (least_Multiple/denominator)) <= 
            (fraction.getNumerator() * (least_Multiple/fraction.getDenominator())));
}

bool Fraction::operator>=(Fraction fraction){
    long least_Multiple = lcm(denominator, fraction.getDenominator());
    return ((numerator *  (least_Multiple/denominator)) >= 
            (fraction.getNumerator() * (least_Multiple/fraction.getDenominator())));
}


bool Fraction::operator==(Fraction fraction){
    long least_Multiple = lcm(denominator, fraction.getDenominator());
    return ((numerator *  (least_Multiple/denominator)) == 
            (fraction.getNumerator() * (least_Multiple/fraction.getDenominator())));
}


bool Fraction::operator!=(Fraction fraction){
    long least_Multiple = lcm(denominator, fraction.getDenominator());
    return ((numerator *  (least_Multiple/denominator)) != 
            (fraction.getNumerator() * (least_Multiple/fraction.getDenominator())));
}

Fraction Fraction::operator+(Fraction fraction){
    Fraction result;
    long least_Multiple = lcm(denominator, fraction.getDenominator());
    result.setDenominator(least_Multiple);
    long result_Numerator = ((numerator * (least_Multiple/denominator)) + 
                                (fraction.getNumerator()* (least_Multiple/fraction.getDenominator())));
    result.setNumerator(result_Numerator);
    result.reduce();
    return result;
}

Fraction Fraction::operator-(Fraction fraction){
    Fraction result;
    long least_Multiple = lcm(denominator, fraction.getDenominator());
    result.setDenominator(least_Multiple);
    long result_Numerator = ((numerator * (least_Multiple/denominator)) - 
                                (fraction.getNumerator()* (least_Multiple/fraction.getDenominator())));
    result.setNumerator(result_Numerator);
    result.reduce();
    return result;
}

Fraction Fraction::operator*(Fraction fraction){
    Fraction result;
    result.setNumerator(numerator * fraction.getNumerator());
    result.setDenominator(denominator * fraction.getDenominator());
    result.reduce();
    return result;
}

Fraction Fraction::operator/(Fraction fraction){
    Fraction result;
    result.setNumerator(numerator * fraction.getDenominator());
    result.setDenominator(denominator * fraction.getNumerator());
    result.reduce();
    return result;
}


bool Fraction::convert_string_to_fraction(string fracStr){
    size_t pos = fracStr.find('/');
    if(pos < fracStr.size()){
        try{
            numerator = stol(fracStr.substr(0, pos));
            denominator = stol(fracStr.substr(pos+1));
            reduce();
        }
        catch(...){
            cout << "Invalid characters entered\n";
            return false;
        }
        if(denominator == 0){
            return false;
        }
        else 
            return true;
        
    }
    return false;
}
//Overload istream
istream& operator>>(istream& in, Fraction& fracNumber){
    string input;
    in >> input;
    if (!fracNumber.convert_string_to_fraction(input)) {
		throw InputFail();
	}
	return in;
}

