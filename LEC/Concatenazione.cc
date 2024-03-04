#include <iostream>
using namespace std;

int main(int argc,char **argv){
    if(argc > 1){
        string str = argv[1];
        if(str.length() % 2 != 0){
            cout<<"Odd lenght!"<<endl;
            return 1;
        }

        string half1 = str.substr(0,str.length()/2);
        string half2 = str.substr(str.length()/2);

        if(half1 == half2){
            cout<<"Accept!"<<endl;
            return 0;
        }else{
            cout<<"Reject!"<<endl;
            return 1;
        }

    }else{
        cout<<"Missing argument!"<<endl;
        return 1;
    }
}