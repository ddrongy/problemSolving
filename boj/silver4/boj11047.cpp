#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coin[11];

int main(){
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> coin[i];
    }
    int answer= 0;

    for(int i=n-1; i>=0; i--){ 
        answer += k/coin[i];
        k %= coin[i];
    }
    cout << answer << endl;
    
}