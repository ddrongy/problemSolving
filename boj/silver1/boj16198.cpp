#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int ansMax = -1, n;

void bfs(int step, int sum){
    if (step == n-2) {
        if (sum > ansMax) ansMax = sum;
    }
    else {
        for(int i=1; i<v.size()-1; i++){
            int tmp = v[i];
            int tmpSum = sum + v[i-1]*v[i+1];
            v.erase(v.begin()+i);
            bfs(step+1, tmpSum);
            v.insert(v.begin()+i, tmp);
        }
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

    cout << ansMax << endl;
}