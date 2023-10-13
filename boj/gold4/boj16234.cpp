#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, l, r;
int map[51][51];
bool ch[51][51];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    cin >> n >> l >> r;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    int day = 0;
    while(1){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ch[i][j] = false;
        
        bool change = false;

        for(int i=0;i<n;i++){
            for(int j=0; j<n; j++){
                if(ch[i][j]) continue;

                vector<pair<int, int>> group;
                queue<pair<int, int>> groupQ;
                int groupSum = 0;

                group.push_back({i,j});
                groupSum += map[i][j];

                groupQ.push({i,j});
                ch[i][j] = true;

                while(!groupQ.empty()){
                    int x = groupQ.front().first;
                    int y = groupQ.front().second;
                    int size1 = map[x][y];

                    groupQ.pop();

                    for(int k=0; k<4; k++){
                        int newX = x+dx[k];
                        int newY = y+dy[k];
               
                        if (newX<0 || newX>=n || newY<0 || newY>=n) continue;
                        if (ch[newX][newY]) continue;
                        int size2= map[newX][newY];

                        int size = abs(size1-size2);
                 
                        if (size>r || size<l) continue;
                
                        group.push_back({newX, newY});
                        groupSum+=map[newX][newY];
                        groupQ.push({newX, newY});
                        ch[newX][newY] = true;
                    }
                }
      
                if (group.size()>1) {
                    change = true;
                    int renum = groupSum/group.size();

                    for(int i=0; i<group.size(); i++){
                        map[group[i].first][group[i].second] = renum;
                    }
                }

            }
        }

        if (!change) {
            cout << day << endl;
            return 0;
        }
        else day++;
    }
}