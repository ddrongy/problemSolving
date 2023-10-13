#include <iostream>

using namespace std;

int map[51][51];
bool clean[51][51];
int n, m;

// 0 북쪽, 1 동쪽, 2 남쪽, 3 서쪽
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int r, int c, int d, int sum){

    for(int i=0; i<4; i++){
        int newD = (d+3-i)%4;
        int newX = r+dx[newD];
        int newY = c+dy[newD];

        if (newX<0 || newX >= n|| newY<0 || newY>=m) continue;
        if (map[newX][newY]) continue;

        if (clean[newX][newY] == 0 && map[newX][newY]==0){
            clean[newX][newY] = 1;
            dfs(newX, newY, newD, sum+1);
        }
    }

    int backIdx = d+2 < 4 ? d+2 : d-2;
    int backR = r+dx[backIdx];
    int backC = c+dy[backIdx];

    if(0<backR || backR<=n || backC >0 || backC <=m){
        if (map[backR][backC]==0) dfs(backR, backC, d, sum);
        else  {
            cout << sum << endl;
            exit(0);
        }
    }

}
int main(){
    int r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    clean[r][c] = true;
    dfs(r,c,d,1);
}