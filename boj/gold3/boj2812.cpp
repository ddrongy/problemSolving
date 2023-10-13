// !!!! 시간 초과 ...,, !! 다시 풀기 ..


#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    stack<char> st;

    for (int pos = 0; pos < n; ++pos) {
        while (k > 0 && !st.empty() && st.top() < s[pos]) {
            st.pop();
            k--;
        }
        st.push(s[pos]);
    }

    // 남아있는 K만큼의 문자를 제거합니다.
    while (k--) {
        st.pop();
    }

    string answer = "";
    while (!st.empty()) {
        answer = st.top() + answer;
        st.pop();
    }

    cout << answer << endl;

    return 0;
}
