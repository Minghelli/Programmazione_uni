#include <iostream>
#include <cstring>
using namespace std;

int main(int argc,char **argv){
    char *str = argv[1];

    int cont = 0;
    for(int i=0;i<strlen(str);i++){
        if(str[i] == '1')
            cont++;
    }

    int half = strlen(str)/2;
    if(cont >= half){
        cout<<"Accept!"<<endl;
        return 0;
    }else{
        cout<<"Reject!"<<endl;
        return 1;
    }
}