#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ch[2000000];
int n;
vector<int> v;

void bfs(int step, int sum){
    if (step == n) {
        if (!ch[sum]) ch[sum] = 1;
    }
    else {
        bfs(step+1, sum+v[step]);
        bfs(step+1, sum);
    }
}
int main(){
    int tmp;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    bfs(0, 0);
    int answer  = 1;
    while(1) {
        if (!ch[answer]) {
            cout << answer <<  endl;
            return 0;
        }
        else answer++;
    }
}