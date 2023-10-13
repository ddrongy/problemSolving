#include <iostream>
#include <vector>
#include <queue>


// deque 공부하기 !! 

using namespace std;

int n, m, k;

int map[12][12];
int robot[12][12];

priority_queue<int, vector<int>, greater<int>> tree[12][12];
priority_queue<int, vector<int>, greater<int>> die[12][12];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void spring(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if (tree[i][j].empty()) continue;


            priority_queue<int, vector<int>, greater<int>> tmp;

            while(!tree[i][j].empty()){
                int nowAge = tree[i][j].top();
                tree[i][j].pop();

                if (map[i][j] < nowAge) {
                    die[i][j].push(nowAge);
                    // map[i][j] = 0;
                }
                else {
                    map[i][j] -= nowAge;
                    nowAge++;
                    tmp.push(nowAge);
                }
            }

            tree[i][j] = tmp;
        }
    }
}
void summer(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if (die[i][j].empty()) continue;

            while(!die[i][j].empty()){
                map[i][j] += die[i][j].top()/2;
                die[i][j].pop();
            }
        }
    }
}
void fall(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(tree[i][j].empty()) continue;

            priority_queue<int, vector<int>, greater<int>> tmp = tree[i][j];

            while(!tree[i][j].empty()){
                int age = tree[i][j].top();
                tree[i][j].pop();

                if (age%5 == 0){
                    for(int k=0; k<8;k++){
                        int newX = i+dx[k];
                        int newY = j+dy[k];

                        if (newX <1 || newX >n || newY <1||newY>n) continue;
                        tree[newX][newY].push(1);
                    }
                }
            }
            tree[i][j] = tmp;
        }
    }

}
void winter(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            map[i][j] += robot[i][j];
        }
    }
}

void treeCnt(){
    int cnt = 0;
    for(int i=0; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(tree[i][j].empty()) continue;

            cnt += tree[i][j].size();
        }
    }

    cout << cnt << endl;
}
int main(){
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> robot[i][j];
            map[i][j] = 5;
        }
    }
    
    int x, y, z;
    for(int i=0; i<m; i++){
        cin >> x >> y >> z;
        tree[x][y].push(z);
    }

    while(k--){
        spring();
        summer();
        fall();
        winter();
        
    }
    treeCnt();
}