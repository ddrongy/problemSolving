#include <iostream>
#include <cstring>

using namespace std;

char map[51][51];
bool ch[51][51];
int startX, startY, n, m;
bool isFind=false;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

void dfs(int x, int y, int depth){
    if (depth>=4 && x==startX && y==startY){
        isFind=true;
        return;
    }

    for(int i=0; i<4; i++){
        int newX = x+dx[i];
        int newY = y+dy[i];

        if (newX <0 || newY <0 || newX >= n || newY >= m) continue;

        if(map[newX][newY]==map[x][y] && !ch[newX][newY]){
            ch[newX][newY] = true;
            dfs(newX, newY, depth+1);
            ch[newX][newY] = false;
        }
    }
}

int main(){
    string s;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            memset(ch, 0, sizeof(ch));
            startX=i;startY=j;

            dfs(i, j, 1);

            if (isFind) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;

}