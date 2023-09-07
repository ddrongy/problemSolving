#include <iostream>

using namespace std;

int main(){
    int h,w,n,m;
    cin >> h >> w >> n >> m;

    int answer = 1;
    if (h%(1+n) == 0) answer*=h/(1+n);
    else answer *= (1+h/(1+n));
    if (w%(1+m) == 0) answer*=w/(1+m);
    else answer *= (1+w/(1+m));

    cout << answer << endl;
}