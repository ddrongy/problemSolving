#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
int ch[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
    int n;
    cin >> n;

    int total=0, divide=0;

    priority_queue<pair<char, pair<int, int>>> pq;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (ch[i][j] != 0) continue;

            pq.push({map[i][j], {i,j}});
            ch[i][j]=1;
            char nowColor = map[i][j];
            total+=1;
            cout << nowColor << endl;
            while(!pq.empty()) {
                char color = pq.top().first;
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop(); 


                for(int k =0; k<4; k++){
                    int newX=x+dx[i];
                    int newY=y+dy[i];

                    if (newX<0 || newY<0 || newX>=n || newY>=n) continue;
                    if (ch[newX][newY]==1 || color!=map[newX][newY])  continue;

                    pq.push({color,{newX,newY}});
                    ch[newX][newY]=1;

                    for(int a=0; a<n; a++){
                        for(int b=0; b<n; b++){
                            cout << ch[a][b] << " ";
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
    cout << total << " " << divide << endl;
}