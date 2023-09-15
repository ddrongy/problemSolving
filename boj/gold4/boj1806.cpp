#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, s, answer=100001;
    cin >> n >> s;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int left=0, right=0;
    int sum=v[0];
    while(left<=right && right<n){
        if (sum < s){
            right++;
            sum+= v[right];
        }
        else if(sum >= s){
            if (right-left+1 < answer) answer = right-left+1;
            if (right==left) {
                right++; 
                sum+= v[right];
            }
            else {
                sum-=v[left];
                left++;
            }
        }
    }
    if (answer == 100001) cout << 0 << endl;
    else cout  << answer  << endl;
}