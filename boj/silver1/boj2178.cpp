#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int ch[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct Info {
    int  cnt;
    int  x;
    int  y;

};
struct compare{
    bool operator()(const Info a, const Info b){
        return a.cnt > b.cnt;
    }
};

int main(){
    int n, m;
    string line;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> line;
        for(int j=0; j<m; j++){
            map[i][j] = line[j] - '0';
        }
    }

    priority_queue<Info, vector<Info>, compare> pq;
    
    pq.push({1, 0, 0});
    ch[0][0] = 1;

    while(!pq.empty()){
        int nowCnt = pq.top().cnt;
        int nowX = pq.top().x;
        int nowY = pq.top().y;

        pq.pop();

        if (nowX == n-1 &&  nowY ==m-1) {
            cout << nowCnt << endl;
            return 0;
        }

        for(int i=0; i<4; i++){
            int newX = nowX+dx[i];
            int newY = nowY+dy[i];

            if (newX <0 || newY <0||  newX >=n || newY >=m) continue;
            if (ch[newX][newY] == 1 || map[newX][newY] == 0) continue;

            pq.push({nowCnt+1, newX, newY});
            ch[newX][newY] = 1;
        }
    }
}