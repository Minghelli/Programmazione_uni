#include <iostream>
using namespace std;

void f1(int p[]){
    while(true){
        cout<<*p++<<endl;
        if(*p == -1)
            break;
    }
}

void f2(int p[]){
    for(int i=0;*(p + i) != -1;i++)
        cout<<*(p+i)<<endl;
}

int main(){
    int v[5] = {0,5,3,2,-1};
    f1(v);
    cout<<endl;
    f2(v);
}