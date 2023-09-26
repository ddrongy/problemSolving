#include <iostream>
#include <vector>

using namespace std;
int map[102][102];

int main(){
    int n, m, sum;
    cin >> n >> m;
    sum = n*m*2;

    for(int i=1;i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }    

    for(int i=1;i<=n; i++){
        for(int j=1; j<=m; j++){
            if (map[i][j]>map[i-1][j]) sum += map[i][j]-map[i-1][j];
            if (map[i][j]>map[i+1][j]) sum += map[i][j]-map[i+1][j];
            if (map[i][j]>map[i][j+1]) sum += map[i][j]-map[i][j+1];
            if (map[i][j]>map[i][j-1]) sum += map[i][j]-map[i][j-1];
        }
    }   

    cout << sum << endl;
}