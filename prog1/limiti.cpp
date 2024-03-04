#include <iostream>
#include <limits>
using namespace std;
int main(){
    cout<<"Numero minimo: "<<numeric_limits<int>::min()<<endl;
    cout<<"Numero massimo: "<<numeric_limits<int>::max()<<endl;
    cout<<"Numero cifre in base 2: "<<numeric_limits<int>::digits<<endl;
    cout<<"Numero cifre in base 10: "<<numeric_limits<int>::digits10<<endl;
    cout<<"Signed: "<<numeric_limits<int>::is_signed<<endl;
    cout<<"Tipo discreto: "<<numeric_limits<int>::is_integer<<endl;
    cout<<"Valore mimimo arrotondamento: "<<numeric_limits<int>::epsilon()<<endl;
    cout<<"Troncamento: "<<numeric_limits<int>::round_error()<<endl;
    cout<<"Esponente base 2: "<<numeric_limits<int>::min_exponent<<endl;
    cout<<"Esponente base 10: "<<numeric_limits<int>::min_exponent10<<endl<<endl;

    cout<<"Numero minimo: "<<numeric_limits<double>::min()<<endl;
    cout<<"Numero massimo: "<<numeric_limits<double>::max()<<endl;
    cout<<"Numero cifre in base 2: "<<numeric_limits<double>::digits<<endl;
    cout<<"Numero cifre in base 10: "<<numeric_limits<double>::digits10<<endl;
    cout<<"Signed: "<<numeric_limits<double>::is_signed<<endl;
    cout<<"Tipo discreto: "<<numeric_limits<double>::is_integer<<endl;
    cout<<"Valore mimimo arrotondamento: "<<numeric_limits<double>::epsilon()<<endl;
    cout<<"Troncamento: "<<numeric_limits<double>::round_error()<<endl;
    cout<<"Esponente base 2: "<<numeric_limits<double>::min_exponent<<endl;
    cout<<"Esponente base 10: "<<numeric_limits<double>::min_exponent10<<endl;
}