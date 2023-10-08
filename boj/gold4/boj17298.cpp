#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> answer(n);
    stack<int> s;

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int now;
    for(int i=n-1; i>=0; i--){
        now = v[i];

        if (s.empty()) answer[i] = -1;
        else {
            while(!s.empty()){
                if (s.top()>now) {
                    answer[i] = s.top();
                    break;
                }
                else s.pop();
            }
            if (s.empty()) answer[i] = -1;
        }
        s.push(now);
    }

    for(int i=0; i<n; i++){
        cout << answer[i] << " ";
    }
    cout << endl;


}