#include <iostream>
#include <string>
#include "fraction.hpp"

using namespace std;

int main(){

    Fraction frac1;
    cin >> frac1;
    Fraction frac2("1/2");
    cout << (frac2 * frac1 < (Fraction)2) << endl;
    //cout <<  frac1 + frac2 << endl;
    return 0;
}