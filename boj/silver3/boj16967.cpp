#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, x, y;

    cin >> h >> w >> x >> y;
    vector<vector<int>> b(h+x, vector<int>(w+y));

    for(int i=0; i<b.size(); i++){
        for(int j=0; j<b[0].size(); j++){
            cin >> b[i][j];
        }
    }

    for(int i=x; i<h; i++){
        for(int j=y; j<w; j++){
            b[i][j] -= b[i-x][j-y];
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }


}