#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int field[25][25];
int visited[25][25];

int n;
int up_time=0;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

pair<int, int> nowShark;
int sharkSize = 2;
int eat_cnt=0;
struct pos{
    int x,y;
    int dist;
};
struct compare{
    bool operator()(pos a, pos b){
        if(a.dist!= b.dist) return a.dist>b.dist;
        else if (a.x!= b.x) return a.x>b.x;
        else return a.y>b.y;
    }
};
priority_queue<pos, vector<pos>, compare> foodDir;

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> field[i][j];
            if(field[i][j] == 9){
                nowShark = {i,j};
                field[i][j] = 0;
            }
        }
    }
}

void find_food(){
    foodDir = {};
    queue<pair<int, int>> q;
    q.push({nowShark.first, nowShark.second});
    visited[nowShark.first][nowShark.second] = 1;

    while(!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;

        q.pop();
        for(int i=0; i<4; i++){
            int newX = nowX+dx[i];
            int newY = nowY+dy[i];

            if(newX<0||newX>=n||newY<0||newY>=n) continue;
            if(visited[newX][newY]) continue;
            if(field[newX][newY]>sharkSize) continue;

            if(field[newX][newY] == sharkSize || field[newX][newY]==0){
                q.push({newX, newY});
                visited[newX][newY] = visited[nowX][nowY]+1;
            }
            else if(field[newX][newY] < sharkSize){
                foodDir.push({newX, newY, visited[nowX][nowY]});
            }
        }
    }

}

int eatFood(){
    if (foodDir.empty()) {
        cout << up_time;
        return 0;
    }

    up_time += foodDir.top().dist;
    eat_cnt++;
    if(eat_cnt == sharkSize){
        eat_cnt = 0;
        sharkSize++;
    }
    field[nowShark.first][nowShark.second] = 0;
    nowShark = {foodDir.top().x, foodDir.top().y};
    field[nowShark.first][nowShark.second] = 0;
    return 1;
}

int main(){
    input();
    while(1){
        memset(visited, 0, sizeof(visited));

        find_food();
        if(eatFood() ==0) break;
        
    }
}