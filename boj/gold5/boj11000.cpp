#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n, start, end;
    vector<pair<int, int>> v;
    cin >> n;

    // 시간이 젤 작은거 부터 나오게 
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        cin >> start >> end;
        v.push_back({start,end});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        start = v[i].first; end = v[i].second;
        if(pq.empty()){
            pq.push(end);
        }
        else {
            if(pq.top()>start) pq.push(end);
            else {
                pq.pop();
                pq.push(end);
            }
        }
    }  
    cout << pq.size() << endl;  
}