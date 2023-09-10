#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

char map[21][21];

vector<pair<int, int>> ch[21][21];

struct Info{
    int x1,y1;
    int x2,y2;
    int cnt;
};

struct compare{
    bool operator()(const Info a, const Info b){
        return a.cnt>b.cnt;
    }   
};

int main(){
    int n, m;
    string line;
    cin >> n >> m;
    vector<pair<int, int>> start;
    for(int i=0; i<n; i++){
        cin >> line;
        for(int j=0; j<m; j++){
            if (line[j] == 'o') {
                start.push_back({i,j});
                line[j] = '.';
            }
            map[i][j] = line[j];
        }
    }

    priority_queue<Info, vector<Info>, compare> pq;

    pq.push({start[0].first, start[0].second, start[1].first, start[1].second, 0});

    while(!pq.empty()){
        int drop = 0;
        int x1 = pq.top().x1;
        int y1 = pq.top().y1;
        int x2 = pq.top().x2;
        int y2 = pq.top().y2; 
        int cnt = pq.top().cnt;

        pq.pop();
        if (cnt>=10) continue;

        for(int i=0; i<4; i++){
            drop  = 0;
            int newX1 = x1+dx[i];
            int newY1 = y1+dy[i];
            int newX2 = x2+dx[i];
            int newY2 = y2+dy[i];

            if (newX1<0||newX1>=n||newY1<0||newY1>=m) drop++;
            if (newX2<0||newX2>=n||newY2<0||newY2>=m) drop++;

            if (drop == 2) continue;
            else if (drop == 1) {
                if (cnt >= 10) cout << -1 << endl;
                else cout << cnt+1 << endl;
                return 0;
            }

            // 벽이면 제자리 
            if (map[newX1][newY1] == '#') {
                newX1 = x1; newY1 = y1;
            }
            if (map[newX2][newY2] == '#'){
                newX2 = x2; newY2 = y2;
            }

            // 이전에 갔었나 확인 
            int flag = 0;
            for(int i=0; i<ch[newX1][newY1].size(); i++){
                if (ch[newX1][newY1][i].first == newX2 && ch[newX1][newY1][i].second == newY2) {
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;

            pq.push({newX1, newY1, newX2, newY2, cnt+1});
            ch[newX1][newY1].push_back({newX2, newY2});
        }
    }

    cout << -1 << endl;
    return 0;
}