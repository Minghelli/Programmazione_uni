#include <iostream>
#include <cstring>
using namespace std;

int main(int argc,char **argv){
    if(argc > 1){
        char *str = argv[1];
        
        char prev = '\0';
        for(int i=0;i<strlen(str);i++){
            if(prev == '0')
                if(str[i] != '1'){
                    cout<<"Reject!"<<endl;
                    return 1;
                }

            prev = str[i];
        }

        cout<<"Accept!"<<endl;
        return 0;
    }else{
        cout<<"Missing argument!"<<endl;
        return 1;
    }
}