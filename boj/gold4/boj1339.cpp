#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v(30, 0); 
    int n;
    string line;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> line;
        int now = 1;
        for(int i=line.size()-1; i>=0; i--){
            v[line[i]-'A'] += now;
            now*=10;
        }
    }

    sort(v.begin(), v.end(), greater<int>());

    int answer = 0;
    int num = 9;
    for(int i=0; i<v.size(); i++){
        if (v[i] == 0) break;
        answer += v[i]*num;
        num--;
    }
    cout  << answer << endl;
}