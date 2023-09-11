#include <iostream>
#include <vector>

using namespace std;

int main() {
    long n, m;
    cin >> n >> m;
    
    vector<long> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int left=0, right=0;
    long sum =v[0], answer=0;
    while(left<=right && right < n && left < n){
        if (sum <= m) {
            if (sum == m) {
                answer++;
            }
            right++;
            if (right >= n) break;
            sum += v[right];
        }
        else {
            sum-=v[left];
            left++;
            if (left > right){
                right =left;
                sum = v[left];
            }
        }
    }
    cout << answer << endl;
}