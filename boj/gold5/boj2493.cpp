#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, top;
    cin >> n;

    stack<pair<int, int>> s; // 층, index
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> top;

        if (s.empty()) {
            v.push_back(0);
            s.push({top, i+1});
        }
        else {
            while(!s.empty()){
                if (s.top().first < top) s.pop();
                else {
                    v.push_back(s.top().second);
                    s.push({top, i+1});
                    break;
                }
            }
            if (s.empty()) {
                v.push_back(0);
                s.push({top, i+1});
            }
        }
    }

    for(int i=0; i<n; i++){
        if (i!=0) cout <<" ";
        cout << v[i];
    }

}