#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, start = 1;
    while(1) {
        cin >> n;
        if (n == 0) break;
        if (!start) cout << endl;
        else start = 0;

        vector<int> v(n);
        vector<bool> use(n);

        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        for(int i=0; i<6; i++) {
            use[i] = 1;
        }
        sort(v.begin(), v.end());
        do{
            for(int i=0; i<v.size(); i++){
                if (use[i]) cout << v[i] << " ";
            }cout << endl;
        }while(prev_permutation(use.begin(), use.end()));
    }
}