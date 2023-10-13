#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Group{
    int color;
    int allCnt, rainCnt;
    int sX, sY;
    vector<pair<int, int>> pos;
};
struct compare{
    bool operator()(Group a, Group b){
        if (a.allCnt != b.allCnt){
            return a.allCnt<b.allCnt;
        }
        else if (a.rainCnt!=b.rainCnt){
            return a.rainCnt<b.rainCnt;
        }
        else if (a.sX != b.sX) {
            return a.sX<b.sX;
        }
        else return a.sY<b.sY;
    }
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int map[21][21];
int n, m;
int groupCnt;

priority_queue<Group, vector<Group>, compare> groups;
queue<pair<int, int>> q;

bool ch[21][21];

void findGroup(){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < n; j++) 
                    ch[i][j] = false;
            if (ch[i][j]) continue;
            if (map[i][j] == 0 || map[i][j] == -1 || map[i][j] == -2) continue; // 무지개면 continue;

            int color = map[i][j]; //기준 color
            int rainCnt =0 ;
            int allCnt = 0;
            int sX = 30, sY = 30; //기준값 최대 값으로 설정 

            vector<pair<int, int>> pos;

            q = {};
            q.push({i, j});
            ch[i][j] = true;
            pos.push_back({i, j});
            allCnt++;

            if (sX > i) sX = i;
            if (sY > j) sY = j;

            while(!q.empty()){
                int nowX = q.front().first;
                int nowY = q.front().second;

                q.pop();

                for(int k=0; k<4; k++){
                    int newX = nowX+dx[k];
                    int newY = nowY+dy[k];

                    if (newX<0 || newX >=n || newY <0 || newY>=n) continue;
                    if (map[newX][newY]==-1 || map[newX][newY]== -2) continue;
                    if (map[newX][newY] != 0 && map[newX][newY] != color) continue;
                    if (ch[newX][newY]) continue;

                    if(map[newX][newY] == 0) rainCnt++;
                    else {
                        if (sX > newX) sX = newX;
                        if (sY > newY) sY = newY;
                    }
                    allCnt++;

                    q.push({newX, newY});
                    pos.push_back({newX, newY});
                    ch[newX][newY] = true;
                }
            }

            if (allCnt > 1){
                groups.push({color, allCnt, rainCnt, sX, sY, pos});
            }
        }
    }
}

void down(){
    for (int i = n - 2; i >= 0; --i) { // N-2부터 0까지 탐색(마지막 행으로부터 첫번째의 행부터 줄여가며)
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == -2 || map[i][j] == -1) continue; // 비어있거나 검정 블록인 경우 continue
 
            // 현재행(i)의 다음행 부터 탐색하여 EMPTY가 아닐때 가지 행간 블록데이터 교환
            for (int k = i + 1; k < n; ++k) {
                if (map[k][j] == -2) { // (k, j)가 빈 좌표인 경우
                    map[k][j] = map[k-1][j]; // (k, j)에 (k-1, j)의 값 전달
                    map[k-1][j] = -2; // (k-1, j)는 EMPTY로 변경
                }
                else // (k, j)가 빈 좌표가 아닌 경우
                    break;
            }
        }
    }
}

void print(){
    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(){
    int tmp[21][21];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j] = map[j][n-i-1];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            map[i][j] = tmp[i][j];
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n ;j++){
            cin >> map[i][j];
        }
    }

    int answer = 0;

    while(1){
        groups={};

        findGroup();
        if(groups.empty()) {
            cout << answer << endl;
            return 0;
        }

        answer += (groups.top().allCnt * groups.top().allCnt);
        // cout << answer << endl;
        
        vector<pair<int, int>> pos = groups.top().pos;

        // 빈칸
        for(int i=0; i<pos.size(); i++){
            int dX = pos[i].first;
            int dY = pos[i].second;

            map[dX][dY] = -2;
        }
        // print();

        down();
        // print();
        rotate();
        // print();
        down();
        // print();
    }
}