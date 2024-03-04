#include <iostream>
using namespace std;

int main(int argc,char **argv){
    if(argc > 1){
        string str = argv[1];

        for(int i=0;i<str.length();i++){
            if(str[i] != str.rbegin()[i]){
                cout<<"Reject!"<<endl;
                return 1;
            }
        }

        cout<<"Accept!"<<endl;
        return 0;
    }else{
        cout<<"Missing argument!"<<endl;
        return 1;
    }
}