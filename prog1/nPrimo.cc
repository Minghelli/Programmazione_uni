#include <iostream>
#include <cmath>
using namespace std;

bool max(int n){
    int maxDiv;
    if(n>=0 && n<=3) return true;

    if(n%2 == 0) return false;
        
    maxDiv = static_cast<int>(sqrt(n));
    for(int i=3; i<=maxDiv; i+=2){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main(){
    int num1;
    cin>>num1;
    if(max(num1))
        cout<<"primo"<<endl;
    else
        cout<<"no"<<endl;
}