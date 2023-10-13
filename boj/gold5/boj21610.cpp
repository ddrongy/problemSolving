#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int n, m, d, s;
int map[51][51];
bool ch[51][51];

vector<pair<int, int>> clouds;

void input(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    clouds.push_back({n-1,0});
    clouds.push_back({n-1,1});
    clouds.push_back({n-2,0});
    clouds.push_back({n-2,1});
}

void moveClouds(int d, int s){
    s = s%n;
    for(int i=0; i<clouds.size(); i++){
        clouds[i].first = (clouds[i].first + s*dx[d] + n)%n;
        clouds[i].second = (clouds[i].second + s*dy[d] + n)%n;

        map[clouds[i].first][clouds[i].second]++;
        ch[clouds[i].first][clouds[i].second]=true;
    }
}

void copyWater(){
    for(int i=0; i<clouds.size(); i++){
        int cnt = 0;
        for(int d=2;d<=8;d+=2){
            int newX = clouds[i].first + dx[d];
            int newY = clouds[i].second +dy[d];

            if (newX <0 || newX >=n || newY<0||newY>=n) continue;

            if(map[newX][newY]) cnt++;
        }
        map[clouds[i].first][clouds[i].second] += cnt;
    }
}

void createNewCloud(){
    vector<pair<int, int>> newClouds;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (ch[i][j]) ch[i][j]=false;
            else if(map[i][j]<2) continue;
            else {
                newClouds.push_back({i,j});
                map[i][j] -=2;
            }
        }
    }

    clouds = newClouds;
}

void getTotalWater(){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n ;j++){
            cnt += map[i][j];
        }
    }

    cout << cnt << endl;
}

int main(){
    input();
    for(int i=0; i<m; i++){
        cin >> d >> s;
        moveClouds(d,s);
        copyWater();
        createNewCloud();
    }
    getTotalWater();

    return 0;
}