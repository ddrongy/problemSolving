#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int x,y,z;
    vector<int> v(3);
    while(1){
        cin >> v[0] >> v[1]  >> v[2];
        if (v[0]==0 && v[1]==0 && v[2]==0) return 0;
        sort(v.begin(), v.end());
        if (v[0]==v[1] && v[1]==v[2]) cout << "Equilateral" << endl;
        else if (v[0]+v[1] <= v[2]) cout << "Invalid" << endl;
        else if (v[0]==v[1] || v[1]==v[2] || v[2]==v[3]) cout << "Isosceles" << endl;
        else cout << "Scalene" << endl;

    }
}