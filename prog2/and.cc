#include <iostream>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n;

    if((x & (1<<n)) != 0)
        cout<<"Bit settato."<<endl;
    else
        cout<<"Bit non settato."<<endl;
}