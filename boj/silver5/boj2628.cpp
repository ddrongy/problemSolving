#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, count;
    cin >> m >> n;

    cin >> count;
    int maxX=0, maxY = 0;
    
    vector<int> cutX;
    vector<int> cutY;
    int type, pos;
    for(int i=0; i<count; i++){
        cin >> type >> pos;

        if (type==0) cutX.push_back(pos);
        else cutY.push_back(pos);
    }

    sort(cutX.begin(), cutX.end());
    sort(cutY.begin(), cutY.end());

    int now=0;
    for(int i=0; i<cutX.size(); i++){
        if ((cutX[i]-now)>maxX) maxX=cutX[i]-now;
        now = cutX[i];
    }
    if (n-now > maxX) maxX = n-now;

    now=0;
    for(int i=0; i<cutY.size(); i++){
        if ((cutY[i]-now)>maxY) maxY=cutY[i]-now;
        now = cutY[i];
    }
    if (m-now > maxY) maxY = m-now;

    cout << maxX*maxY << endl;

}