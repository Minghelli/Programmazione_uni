#include <iostream>
using namespace std;

double fAbs(double);
double cell(double);
double floor(double);

int main(){
    double num;
    cin>>num;

    cout<<"Abs: "<<fAbs(num)<<endl;
    cout<<"Cell: "<<cell(num)<<endl;
    cout<<"Floor: "<<floor(num)<<endl;
}

double fAbs(double n){
    if(n > 0)
        return n;
    return -n;
}

double cell(double n){
    return static_cast<int>(n)+1;
}

double floor(double n){
    return static_cast<int>(n);
}