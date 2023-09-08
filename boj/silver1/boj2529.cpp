#include <iostream>
#include <vector>

using namespace std;

int ch[10];
int n;
long ansMin=9999999999, ansMax=0;
string strMin, strMax;

vector<char> line;

void bfs(int step, long sum, string sumStr){
    if (step == n+1) {
        if (sum > ansMax) {ansMax = sum; strMax = sumStr;}
        if (sum < ansMin) {ansMin = sum; strMin = sumStr;}
    }
    else {
        for(int i=0; i<10; i++){
            if (ch[i]) continue;
            if (step != 0){
                if (line[step-1] == '>') {
                    if (sum%10 <= i) continue; 
                }
                else {
                    if (sum%10 >= i) continue;
                }
            }
            ch[i] = 1;
            bfs(step+1, sum*10+i, sumStr+to_string(i));
            ch[i] = 0;
        }
    }
}
int main(){
    cin >> n;
    char tmp;
    
    for(int i =0; i<n; i++){
        cin >> tmp;
        line.push_back(tmp);
    }
    bfs(0, 0, "");
    cout << strMax << endl;
    cout << strMin << endl;
}