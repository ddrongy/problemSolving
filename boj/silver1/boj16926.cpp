#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, r;
    cin >> n >> m >> r;

    int level = min(n,m)/2;

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> tmp(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }

    tmp = v;

    for(int step = 0; step < r; step++){
        for(int l = 0; l < level; l++){
            // 윗변
            for(int i = l; i < m - l - 1; i++) 
                tmp[l][i] = v[l][i + 1];

            // 오른변
            for(int i = l; i < n - l - 1; i++) 
                tmp[i][m - l - 1] = v[i + 1][m - l - 1];

            // 아랫변
            for(int i = m - l - 1; i > l; i--) 
                tmp[n - l - 1][i] = v[n - l - 1][i - 1];

            // 왼변
            for(int i = n - l - 1; i > l; i--) 
                tmp[i][l] = v[i - 1][l];

            // 왼쪽 위 모서리
            tmp[l + 1][l] = v[l][l];

            // 오른쪽 위 모서리
            tmp[l][m - l - 2] = v[l][m - l - 1];

            // 오른쪽 아래 모서리
            tmp[n - l - 2][m - l - 1] = v[n - l - 1][m - l - 1];

            // 왼쪽 아래 모서리
            tmp[n - l - 1][l + 1] = v[n - l - 1][l];
        }
        v = tmp;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }


}