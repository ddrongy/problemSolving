#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, s, answer=0;
    cin >> n >> s;

    vector<int> v(n);
    vector<bool> ch(n);

    for(int i=0; i<n ;i++){
        cin >> v[i];
    }

    for(int i=0; i<n; i++) {
        ch[i] = 1;
        do{
            int sum =0;
            for(int i=0; i<n; i++){
                if (ch[i]) sum+=v[i];
            }
            if (sum == s) answer+=1;
        }while(prev_permutation(ch.begin(), ch.end()));
    }

    cout << answer << endl;
}