#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct Tree {
    int x, y, age;
};

deque<Tree> trees;

vector<Tree> dead_trees;
vector<Tree> breed_trees;

int nutrient[11][11];
int plus_nutrient[11][11];

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

// 봄
// 나무가 나이만큼 양분먹고 -> 나이 증가
// 나이가 어린 나무부터 양분을 먹음 -> 양분 부족하면 죽음
void spring(){
    deque<Tree> tmp_trees;

    while(!trees.empty()){
        Tree tree = trees.front();
        trees.pop_front();

        if (tree.age <= nutrient[tree.x][tree.y]){
            nutrient[tree.x][tree.y] -= tree.age;
            tmp_trees.push_back({tree.x, tree.y, tree.age+1});
            if ((tree.age+1) % 5 == 0){
                breed_trees.push_back({tree.x, tree.y, tree.age+1});
            }
        }
        else {
            dead_trees.push_back(tree);
        }
    }
    
    trees = tmp_trees;
}

// 여름 
// 봄에 죽은 나무가 양분으로 변함 
// 죽은 나무마다 나이/2 값이 원래 있던 칸에 양분으로 추가됨 
void summer(){
    for(int i=0; i<dead_trees.size(); i++){
        nutrient[dead_trees[i].x][dead_trees[i].y] += dead_trees[i].age/2;
    }
    dead_trees.clear();
}

// 가을
// 나이가 5의 배수인 나무가 번식함 
// 인접한 8개의 칸에 나이가 1인 나무가 새로 생김 
void fall(int n){
    for(int i=0; i<breed_trees.size(); i++){
        for(int j=0; j<8; j++){
            if (breed_trees[i].x+dx[j] < 1 || breed_trees[i].x+dx[j] > n || breed_trees[i].y+dy[j] < 1 || breed_trees[i].y+dy[j] > n) continue;
            trees.push_front({breed_trees[i].x+dx[j], breed_trees[i].y+dy[j], 1});
        }
    }
    
    breed_trees.clear();

}

// 겨울 
// 땅에 양분을 추가함 
void winter(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            nutrient[i][j] += plus_nutrient[i][j];
        }
    }
}


int main(){
    int n,m,k;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> plus_nutrient[i][j];
            // 처음엔 모든 칸에 영양분 5로 시작 
            nutrient[i][j] = 5;
        }
    }

    int x,y,z;

    for(int i=0; i<m; i++){
        cin >> x >> y >> z;
        trees.push_back({x,y,z});
    }

    while(k>0) {
        spring();
        summer();
        fall(n);
        winter(n);
        k--;
    }

    cout << trees.size() << endl;
}