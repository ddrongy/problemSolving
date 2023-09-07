#include <iostream>

using namespace std;

int map[1001];
int dp[1001];

int main(){
    int n;
    cin >> n;
    fill(dp, dp+1001, 999);
    for(int i=0; i<n; i++){
        cin >> map[i];
    }
    dp[0]=0;
    for(int i=0; i<n-1;i++){
        for(int j=1; j<=map[i]; j++){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }

    if (dp[n-1] == 999) cout << -1 << endl;
    else cout << dp[n-1] << endl;
}