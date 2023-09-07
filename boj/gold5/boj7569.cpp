#include <iostream>
#include <queue>

using namespace std;

int box[101][101][101];
int dx[6] = {0,1,-1,0,0,0};
int dy[6] = {-1,0,0,1,0,0};
int dz[6] = {0,0,0,0,1,-1};
struct Info{
    int x,y,z;
    int day;
};

int main(){
    int n, m, h, tmp;
    int originCnt=0, maxCnt=0, tryCount=0;
    int answer = 0;

    queue<Info> q; 

    cin >> m >> n >> h; 
    for(int k=0; k<h; k++) { 
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++){
                cin >> tmp;
                if (tmp != -1) maxCnt++;
                if (tmp == 1) {
                    originCnt++;
                    q.push({i,j,k,1});
                }
                box[k][i][j] = tmp;
            }
        }
    }

    if (maxCnt == originCnt) {
        cout << 0 << endl;
        return 0;
    }

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int day = q.front().day;

        q.pop();

        tryCount=0;
        for(int i=0; i<6;i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            int newZ = z+dz[i];
            
            if (newX<0 || newY<0 || newX >= n || newY >= m || newZ < 0 || newZ >= h) continue;
            if (box[newZ][newX][newY] != 0) continue;

            // 0인 토마토 1로 전파
            box[newZ][newX][newY] = 1;
            
            tryCount+=1;
            q.push({newX, newY, newZ, day+1});
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