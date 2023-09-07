#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> pq1; // 내림차(큰거 우선), 중앙 앞부분
    priority_queue<int, vector<int>, greater<int>> pq2; //오름차(작은거우선), 중앙 뒷부분
    int n, num;
    scanf("%d", &n);
    scanf("%d", &num);
    pq1.push(num);
    printf("%d\n", num);

    for(int i=1; i<n; i++){
        scanf("%d", &num);

        //크기 맞춰주기, p1우선
        if(pq1.size()>pq2.size()) pq2.push(num);
        else pq1.push(num);

        if(!pq1.empty() && !pq2.empty()){
            if (pq1.top()>pq2.top()) {
                int a=pq1.top(); pq1.pop();
                int b=pq2.top(); pq2.pop();

                pq1.push(b);
                pq2.push(a);
            }
        }
        //짝수든 홀수든 항상 앞쪽에서 cout
        printf("%d\n", pq1.top());
    }
}
