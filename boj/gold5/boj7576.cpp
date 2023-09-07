#include <iostream>
#include <queue>

using namespace std;

int box[1001][1001];
int dx[4] = {0,1,-1,0};
int dy[4] = {-1,0,0,1};

int main(){
    int n, m, tmp;
    int originCnt=0, maxCnt=0, tryCount=0;
    int answer = 0;

    queue<pair<pair<int, int>, int>> q; //{x,y} , day

    cin >> m >> n; //m=가로,n=세로

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            cin >> tmp;
            if (tmp != -1) maxCnt++;
            if (tmp == 1) {
                originCnt++;
                q.push({{i, j}, 1});
            }
            box[i][j] = tmp;
        }
    }

    if (maxCnt == originCnt) {
        cout << 0 << endl;
        return 0;
    }

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int day = q.front().second;

        q.pop();

        tryCount=0;
        for(int i=0; i<4;i++){
            int newX = x+dx[i];
            int newY = y+dy[i];

            if (newX<0 || newY<0 || newX >= n || newY >= m) continue;
            if (box[newX][newY] != 0) continue;

            // 0인 토마토 1로 전파
            box[newX][newY] = 1;
            
            tryCount+=1;
            q.push({{newX, newY}, day+1});
        }

        if (tryCount > 0 ) {
            answer+=1;
            originCnt+=tryCount;
        }
        
        if (originCnt == maxCnt) {
            cout << day << endl;
            return 0;
        };

    }

    cout << -1 << endl;
    return 0;
    
}