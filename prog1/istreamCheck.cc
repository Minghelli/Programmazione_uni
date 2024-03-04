#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int a;
    while(!(cin>>a)){
        cin.clear();
        cin.ignore() ;
    }
    cout<<a<<endl;
}