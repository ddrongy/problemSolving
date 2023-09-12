#include <iostream>
#include <vector>
using namespace std;

int v[1000][1000];

int main(){
    int n, m;
    cin >> n >> m;

    int x= n/2, y= n/2, cnt = 1, dir = 0;   
    int num = 1, ansX, ansY;

    v[x][y] = num++;
    x--; cnt++;

    while(num < n*n) {
        if (dir == 0){
            for(int i=0; i<cnt; i++){
                v[x][y++]=num++;

            }
            y--; x++; dir=1;
        }
        else if (dir==1) {
            for(int i=0; i<cnt; i++){
                v[x++][y]=num++;
            }
            x--; y--; dir=2;
        }
        else if (dir==2){
            for(int i=0; i<cnt; i++){
                v[x][y--]=num++;
            }
            y++; x--; dir=3;
        }
        else if (dir==3){
            for(int i=0; i<cnt;i++){
                v[x--][y]=num++;
            }
            dir=0; cnt+=2;
        }

    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cout << v[i][j] << " ";
            if (v[i][j] == m) {ansX = i+1;ansY=j+1;}
        }
        cout << endl;
    }
    cout << ansX << " " << ansY << endl;
}