#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool alpha[30];
char map[21][21];

int answer= -1, n, m;

int dx[4] =  {0,0,-1,1};
int dy[4] =  {1,-1,0,0};

void dfs(int x, int  y,int cnt){
    if (cnt>answer) answer =cnt;
    for(int i=0; i<4; i++){
        int newX = x+dx[i];
        int newY = y+dy[i];

        if (newX <0 || newY <0|| newX>=n || newY >=m) continue;
        int newAlpha = map[newX][newY];
        if (alpha[newAlpha-'A']) continue;

        alpha[newAlpha-'A']=true;
        dfs(newX, newY, cnt+1);
        alpha[newAlpha-'A']=false;
    }

}
int main(){
    string line; 
    cin  >> n >> m;
    for(int i=0; i<n; i++){
        cin >> line;
        for(int j=0; j<line.size(); j++){
            map[i][j] = line[j];
        }
    }
    
    alpha[map[0][0]-'A'] = true;
    dfs(0, 0, 1);

    cout << answer << endl;
}