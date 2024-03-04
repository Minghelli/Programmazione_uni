#include <iostream>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n;

    n = 1<<n;
    x |= n;
    cout<<x<<endl;
}