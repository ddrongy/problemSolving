#include <iostream>
#include <vector>

using namespace std;

int r, c, t;
int map[51][51];
int add[51][51];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int up_row, down_row; // 공기청정기 윗부분과 아랫부분의 행

void spread(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int cnt = 0;
            int val = map[i][j]/5;

            if(map[i][j]<=0) continue;

            for(int k=0; k<4; k++){
                int newX=i+dx[k];
                int newY=j+dy[k];
                if(newX<0||newX>=r||newY<0||newY>=c) continue;
                if(map[newX][newY]==-1) continue;
                add[newX][newY] += val;
                cnt++;
            }
            add[i][j] -= cnt*val;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            map[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}
void airclean(){

    // 위의 공기 순환 (반시계)
    // 1. 왼쪽줄
    for (int i = up_row - 1; i > 0; i--)
        map[i][0] = map[i - 1][0];
    // 2. 윗줄
    for (int i = 0; i < c - 1; i++)
        map[0][i] = map[0][i + 1];
    // 3. 오른쪽줄
    for (int i = 1; i <= up_row; i++)
        map[i - 1][c - 1] = map[i][c - 1];
    // 4. 아랫줄
    for (int i = c - 1; i > 1; i--)
        map[up_row][i] = map[up_row][i - 1];
    map[up_row][1] = 0;

    // 아래공기 순환 (시계)
    // 1. 왼쪽줄
    for (int i = down_row + 1; i < r - 1; i++)
        map[i][0] = map[i + 1][0];
    // 2. 아랫줄
    for (int i = 0; i < c - 1; i++)
        map[r - 1][i] = map[r - 1][i + 1];
    // 3. 오른쪽줄
    for (int i = r - 1; i >= down_row; i--)
        map[i][c - 1] = map[i - 1][c - 1];
    // 4. 윗줄
    for (int i = c - 1; i > 1; i--)
        map[down_row][i] = map[down_row][i - 1];
    map[down_row][1] = 0;

}
int main(){
    cin >> r >> c >> t;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
            if (map[i][j] == -1){
                if (up_row == 0) up_row=i;
                else down_row=i;
            }
        }
    }

    while(t--){
        spread();
        airclean();
    }
    int total = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if (map[i][j] == -1) continue;
            total+=map[i][j];
        }
    }
    cout << total << endl;

}