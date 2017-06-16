#include <string>
#include <stdexcept>
using namespace std;

class Fraction{
        long numerator;
        long denominator;
        long gcd(long num1, long num2);
        long lcm(long num1, long num2);
    public:
        Fraction();
        Fraction(string fracStr);
        Fraction(long num, long den);
        Fraction(int num);
        Fraction(long num);
        Fraction(double num);
    	friend ostream& operator<<(ostream& os, const Fraction& fracNumber);
		void setNumerator(long Numerator);
		void setDenominator(long Denominator);
		long getNumerator();
		long getDenominator();
        void reduce();
        void convert_int_to_fraction(int num); 
        void convert_double_to_fraction(double num);
        double convert_fraction_to_double();
        long convert_fraction_to_long();
        int convert_fraction_to_int();
    	
    // 	//overloading functions
    	operator double();
    	operator int();
    	operator long();
		bool operator<(Fraction fraction);
		bool operator<=(Fraction fraction);
		bool operator>(Fraction fraction);
		bool operator>=(Fraction fraction);
		bool operator==(Fraction fraction);
		bool operator!=(Fraction fraction);
        Fraction operator+(Fraction fraction);
        Fraction operator-(Fraction fraction);
        Fraction operator*(Fraction fraction);
        Fraction operator/(Fraction fraction);
    	friend istream& operator>>(istream& in, Fraction& fracNumber);
        bool convert_string_to_fraction(string str); 

};

class InputFail: public exception {
	public: 
	virtual const char* what() const throw(){
	    return "Incorrect Input";
	}
};