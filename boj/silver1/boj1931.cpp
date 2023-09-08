#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, end, start;
    cin >> n;
    vector<pair<int, int>> schedule;

    for(int i=0; i<n; i++){
        cin >> start >> end;
        schedule.push_back({end, start});
    }

    sort(schedule.begin(), schedule.end()); //끝나는 시간 빠른순 정렬

    int answer = 1;
    int nowEnd = schedule[0].first;
    for(int i=1; i<n; i++){
        if (schedule[i].second >= nowEnd){
            answer++;
            nowEnd = schedule[i].first;
        }
    }

    cout << answer << endl;
}