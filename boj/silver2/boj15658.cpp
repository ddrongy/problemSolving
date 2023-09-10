#include <iostream>
#include <vector>

using namespace std;

int ch[4], n;
vector<int> v;
long ansMin=1000000000, ansMax=-1000000000;

void bfs(int step, int sum){
    if (step==n){
        if (sum < ansMin) ansMin=sum;
        if (sum > ansMax) ansMax=sum;
    }
    else {
        if (ch[0] > 0){
            ch[0]--;
            bfs(step+1, sum+v[step]);
            ch[0]++;
        }
        
        if (ch[1] > 0){
            ch[1]--;
            bfs(step+1, sum-v[step]);
            ch[1]++;
        }

        if (ch[2] > 0){
            ch[2]--;
            bfs(step+1, sum*v[step]);
            ch[2]++;
        }

        if (ch[3] > 0){
            ch[3]--;
            if (sum<0) bfs(step+1,-((-sum)/v[step]));
            else bfs(step+1,sum/v[step]);
            ch[3]++;
        }
    }
}
int main(){
    int tmp;
    cin >> n;


    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i=0; i<4; i++){
        cin >> ch[i];
    }

    bfs(1,v[0]);

    cout << ansMax << endl;
    cout << ansMin << endl;
}