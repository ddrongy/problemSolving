#include <iostream>

using namespace std;

int main(){
    string all = "011111111111111111111";
    string empty = "000000000000000000000";
    string str = "000000000000000000000";

    int n;
    cin >> n;

    int num;
    string type;
    for(int i=0; i<n; i++){
        cin >> type ;
        if (type == "add"){
            cin >> num;
            if ('0'==str[num]) str[num] = '1';
        }
        else if (type == "remove"){
            cin >> num;
            if ('1'==str[num]) str[num] = '0';
        }
        else if (type == "check"){
            cin >> num;
            cout << str[num] << endl;
        }
        else if (type == "toggle"){
            cin >> num;
            if ('1'==str[num]) str[num] = '0';
            else str[num]= '1';
        }
        else if (type == "all"){
            str=all;

        }
        else if (type == "empty"){
            str=empty;
        }
    }
}