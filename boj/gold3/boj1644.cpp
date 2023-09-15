#include <iostream>
#include <vector>

using namespace std;
int ch[4000001];

int main(){
    int n; 
    cin >> n;
    vector<int> prime;
    for(int i=2; i<=n; i++){
        if(!ch[i]){
            prime.push_back(i);
            for(int j=2; i*j<=n; j++){
                ch[i*j]=1;
            }
        }
    }

    prime.push_back(4000001);

    int left=0, right=0, sum=0, answer=0;
    while(left<=right && right<prime.size()){
        if (sum>=n || prime[right]>n){
            sum-=prime[left];
            left++;
        }
        else {
            sum+=prime[right];
            right++;
        }
        if (sum==n) answer++;
    }
    cout  << answer << endl;
}