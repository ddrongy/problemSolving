#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int map[25][25];

struct space{
    int x,y;
    int likes;
    int blanks;
};
struct compare{
    bool operator()(space a, space b){
        if (a.likes!= b.likes){
            return a.likes < b.likes;
        }
        else if (a.blanks!= b.blanks){
            return a.blanks < b.blanks;
        }
        else if (a.x != b.x) {
            return a.x > b.x;
        }
        else return a.y > b.y;
    }
};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void findBlank(int index, int like1, int like2, int like3, int like4){

    priority_queue<space, vector<space>, compare> pq;
    int bCnt, lCnt, nx, ny;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (map[i][j]!=0) continue;
            bCnt=0;lCnt=0;

            for(int k=0;k<4;k++){
                nx = i+dx[k];
                ny = j+dy[k];

                if (nx<0||ny<0||nx>=n||ny>=n) continue;

                if (map[nx][ny] == 0) bCnt++;
                else if(map[nx][ny] == like1 ||
                        map[nx][ny] == like2 ||
                        map[nx][ny] == like3 ||
                        map[nx][ny] == like4) lCnt++;
            }

            pq.push({i,j,lCnt,bCnt}); 
        }
    }
    map[pq.top().x][pq.top().y] = index;

}
int main(){
    cin >> n;
    int index, like1, like2, like3, like4;

    vector<int> v[500];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> index >> like1 >> like2 >> like3 >> like4;

            findBlank(index, like1, like2, like3, like4);
            v[index].push_back(like1);
            v[index].push_back(like2);
            v[index].push_back(like3);
            v[index].push_back(like4);
        }
    }

    int nx, ny, lCnt;
    int answer =0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            lCnt = 0;
            index = map[i][j];

            like1 = v[index][0];
            like2 = v[index][1];
            like3 = v[index][2];
            like4 = v[index][3];

            for(int k=0;k<4;k++){
                nx = i+dx[k];
                ny = j+dy[k];

                if (nx<0||ny<0||nx>=n||ny>=n) continue;

                if(map[nx][ny] == like1 ||
                    map[nx][ny] == like2 ||
                    map[nx][ny] == like3 ||
                    map[nx][ny] == like4) lCnt++;
            }

            if (lCnt == 1) answer+=1;
            else if(lCnt == 2) answer+=10;
            else if(lCnt == 3) answer+=100;
            else if(lCnt == 4) answer+=1000;
        }
    }

    cout << answer << endl;

}

