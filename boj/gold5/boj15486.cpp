#include <iostream>
#include  <vector>
#include <algorithm>
using namespace std;

int dp[1500001];

int main(){
    vector<int> time;
    vector<int> profit;
    int answer=0;
    int n, t, p;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t >> p;
        time.push_back(t);
        profit.push_back(p);
    }

    for(int i=0; i<n; i++){
        if (i+time[i] <= n) {
            dp[i+time[i]] = max(dp[i+time[i]], dp[i]+profit[i]);
        }  
        dp[i+1] = max(dp[i], dp[i+1]); 
    }
    cout << dp[n] << endl;
}