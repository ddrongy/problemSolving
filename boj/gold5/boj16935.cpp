#include <iostream>
#include <vector>

using namespace std;

int n, m;

void type1(vector<vector<int>> &v){
    vector<vector<int>> tmp(v.size(), vector<int>(v[0].size()));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[i][j] = v[n-i-1][j];
        }
    }
    v = tmp;
}
void type2(vector<vector<int>> &v){
    vector<vector<int>> tmp(v.size(), vector<int>(v[0].size()));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[i][j] = v[i][m-j-1];
        }
    }
    v = tmp;
    
}
void type3(vector<vector<int>> &v){
    vector<vector<int>> tmp(v[0].size(), vector<int>(v.size()));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[j][n-i-1] = v[i][j];
        }
    }
    v = tmp;
    swap(n, m); // n과 m 값 갱신
}
void type4(vector<vector<int>> &v){
    vector<vector<int>> tmp(v[0].size(), vector<int>(v.size()));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[m - j - 1][i] = v[i][j];
        }
    }
    v = tmp;
    swap(n, m); // n과 m 값 갱신
}
void type5(vector<vector<int>> &v){
    vector<vector<int>> tmp(v.size(), vector<int>(v[0].size()));
    //1->2
    for(int i=0; i<v.size()/2; i++){
        for(int j=0; j<v[0].size()/2; j++){
            tmp[i][v[0].size()/2+j] = v[i][j];
        }
    }
    //2->3
    for(int i=0; i<v.size()/2; i++){
        for(int j=v[0].size()/2; j<v[0].size(); j++){
            tmp[v.size()/2+i][j] = v[i][j];
        }
    }
    //3->4
    for(int i=v.size()/2; i<v.size(); i++){
        for(int j=v[0].size()/2; j<v[0].size(); j++){
            tmp[i][j-v[0].size()/2] = v[i][j];
        }
    }
    //4->1
    for(int i=v.size()/2; i<v.size(); i++){
        for(int j=0; j<v[0].size()/2; j++){
            tmp[i-v.size()/2][j] = v[i][j];
        }
    }
    v = tmp;
}
void type6(vector<vector<int>> &v){
    vector<vector<int>> tmp(v.size(), vector<int>(v[0].size()));
    //1->4
    for(int i=0; i<v.size()/2; i++){
        for(int j=0; j<v[0].size()/2; j++){
            tmp[i+v.size()/2][j] = v[i][j];
        }
    }
    //2->1
    for(int i=0; i<v.size()/2; i++){
        for(int j=v[0].size()/2; j<v[0].size(); j++){
            tmp[i][j-v[0].size()/2] = v[i][j];
        }
    }
    //3->2
    for(int i=v.size()/2; i<v.size(); i++){
        for(int j=v[0].size()/2; j<v[0].size(); j++){
            tmp[i-v.size()/2][j] = v[i][j];
        }
    }
    //4->3
    for(int i=v.size()/2; i<v.size(); i++){
        for(int j=0; j<v[0].size()/2; j++){
            tmp[i][j+v[0].size()/2] = v[i][j];
        }
    }
    v = tmp;
    
}
int main(){
    int r, type;
    
    cin >> n >> m >> r;

    vector<vector<int>> v(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }

    for(int i=0; i<r; i++){
        cin >> type;
        if (type == 1) type1(v);
        else if (type == 2) type2(v);
        else if (type == 3) type3(v);
        else if (type == 4) type4(v);
        else if (type == 5) type5(v);
        else if (type == 6) type6(v);
    }

    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

}