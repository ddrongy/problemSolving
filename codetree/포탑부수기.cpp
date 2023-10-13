#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, k;

int power[11][11];
int attackTime[11][11];

int visited[11][11]; // 공격관련 여부 확인

pair<int, pair<int, int>> attacker;
pair<int, pair<int, int>> victim;

struct info{
    int x,y;
    vector<pair<int, int>> history; //공격 기록
};

int nowTime = 1;
int dx[] = {0, 1, 0, -1}; // 우 하 좌 상
int dy[] = {1, 0, -1, 0};

int dx8[] = {0,-1,0,1,-1,1,-1,1}; 
int dy8[] = {1,0,-1,0,1,1,-1,-1};

void input(){

    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> power[i][j];
        }
    }
}

int checkTop(){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(power[i][j]>0) cnt++;
        }
    }
    if(cnt<=1) return 0;
    else return 1;
}

void chooseAttacker(){
    memset(visited, 0, sizeof(visited));

    attacker.first = 10000;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (power[i][j] == 0) continue;

            bool change = false;

            if(attacker.first > power[i][j]) change=true;
            else if(attacker.first == power[i][j]){
                if(attackTime[attacker.second.first][attacker.second.second] < attackTime[i][j]) change=true;
                else if(attackTime[attacker.second.first][attacker.second.second] == attackTime[i][j]){
                    if ((attacker.second.first+attacker.second.second) < (i+j)) change=true;
                    else if ((attacker.second.first+attacker.second.second) == (i+j)){
                        if(attacker.second.second < j) change=true;
                    }
                }
            }
            if (change){
                attacker.second ={i,j};
                attacker.first = power[i][j];
            }
        }
    }

    power[attacker.second.first][attacker.second.second] += (n+m);
    visited[attacker.second.first][attacker.second.second] = 1;
    attackTime[attacker.second.first][attacker.second.second] = nowTime;

}

int raser(){
    queue<info> q;
    vector<pair<int, int>> history;

    int ch[11][11];
    memset(ch, 0, sizeof(ch));

    q.push({attacker.second.first, attacker.second.second, history});
    ch[attacker.second.first][attacker.second.second] = 1;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;

        vector<pair<int, int>> tmp = q.front().history;

        if(x==victim.second.first && y==victim.second.second){

            int minusPower = power[attacker.second.first][attacker.second.second];

            power[x][y] -= minusPower;
            if (power[x][y]<0) power[x][y] = 0;
            visited[x][y] = 1;

            for(int i=0; i<tmp.size()-1; i++){

                power[tmp[i].first][tmp[i].second] -= minusPower/2;
                if (power[tmp[i].first][tmp[i].second]<0) power[tmp[i].first][tmp[i].second] = 0;
                visited[tmp[i].first][tmp[i].second] = 1;
            }

            return 1;
        }

        q.pop();
        vector<pair<int, int>> temp;
        for(int i=0; i<4; i++){
            int newX = (x + dx[i] + n) % n;
            int newY = (y + dy[i] + m) % m;

            if (ch[newX][newY]) continue;
            if (power[newX][newY] == 0) continue;
            
            temp = tmp;
            temp.push_back({newX, newY});
            q.push({newX, newY, temp});
            ch[newX][newY] = 1;
        }
    }
    return 0;
}
void bomb(){
    int minusPower = power[attacker.second.first][attacker.second.second];
    power[victim.second.first][victim.second.second] -= minusPower;
    if (power[victim.second.first][victim.second.second]<0) power[victim.second.first][victim.second.second] = 0;
    visited[victim.second.first][victim.second.second] = 1;
    
   
    for(int i=0; i<8;i++){
        int newX = (victim.second.first+dx8[i]+n)%n;
        int newY = (victim.second.second+dy8[i]+m)%m;

        if(newX == attacker.second.first && newY == attacker.second.second) continue;
        if(power[newX][newY] == 0) continue;

        power[newX][newY] -= minusPower/2;
        if (power[newX][newY]<0) power[newX][newY] = 0;
        visited[newX][newY] = 1;
    }
}

void attack(){
    victim.first = -1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (power[i][j] == 0) continue;
            if (i == attacker.second.first  && j == attacker.second.second) continue;
            bool change = false;

            if(victim.first < power[i][j]) change=true;
            else if(victim.first == power[i][j]){
                if(attackTime[victim.second.first][victim.second.second] > attackTime[i][j]) change=true;
                else if(attackTime[victim.second.first][victim.second.second] == attackTime[i][j]){
                    if ((victim.second.first+victim.second.second) > (i+j)) change=true;
                    else if ((victim.second.first+victim.second.second) == (i+j)){
                        if(victim.second.second > j) change=true;
                    }
                }
            }
            if (change){
                victim.second ={i,j};
                victim.first = power[i][j];
            }
        }
    }

    visited[victim.second.first][victim.second.second] = 1;
    // attackTime[victim.second.first][victim.second.second] = nowTime;

    // 공격 시도
    if (!raser()) bomb();

}

void rearrange(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (visited[i][j]) continue;
            if (power[i][j] == 0) continue;
            power[i][j]+=1;
        }
    }
    nowTime++;
}

int main(){

    input();
    while(k--){
        if (!checkTop()) break;
        chooseAttacker();
        attack();
        rearrange();

    }

    
    //가장 강한 포탑의 공격력 출력
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (power[i][j] > answer) answer = power[i][j];
        }
    }
    cout << answer << endl;
}