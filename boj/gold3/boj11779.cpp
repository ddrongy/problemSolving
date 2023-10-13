#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, e;
int INF = 100000001;
int d[1001];
int ans[1001];

vector<int> v[1001];
vector<pair<int, int>> city[1001];

int main(){
    int n, m;
    cin >> n >> m;

    int start, end, cost;
    for(int i=0; i<m; i++){
        cin >> start >> end >> cost;
        city[start].push_back({end, cost});
    }

    cin >> s >> e;

    
    queue<pair<int, int>> q; // index, distance

    for(int i= 1; i<=n; i++){
        d[i] = INF;
    }

    // start 에서 시작
    q.push({s,0});

    v[s].push_back(s);
    while(!q.empty()){
        int cur = q.front().first;
        int distance = q.front().second;
        q.pop();

        if (d[cur] < distance) continue;
        for(int i=0; i<city[cur].size(); i++){
            int next = city[cur][i].first;
            int nextDis = distance+city[cur][i].second;

            if (nextDis < d[next]) {
                ans[next] = cur;
                d[next] = nextDis;
                q.push({next, nextDis});
            }
        }
    }
    int temp=e;
    vector<int> st;
    st.push_back(e);
    while(temp!=s) {
        temp = ans[temp];
        st.push_back(temp);
    }
    cout << d[e] << endl;
    cout << st.size() << endl;

    for(int i=st.size()-1; i>=0; i--){
        cout << st[i] << " ";
    }
    cout << endl;
}