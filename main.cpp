/*
아이디어 :


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int T;
int N;
vector<char> v;

void DFS(int cnt) {
    if (cnt == N-1) {
        /*
        for (int i = 0; i < v.size(); i ++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        */
        stack<int> s;
        s.push(1);
        for (int i = 0; i < N-1; i ++) {
            // i + 1이 수열의 값.
            if (v[i] == '+') {
                s.push(i+2);
            }
            else if (v[i] == '-') {
                s.push(-(i+2));
            }
            else if (v[i] == ' ') {
                int temp = s.top();
                if (temp < 0) {
                    temp = (-temp)*10 + i + 2;
                    temp = -temp;
                }
                else {
                    temp = temp*10 + i + 2;
                }
                s.pop();
                s.push(temp);
            }
        }
        int sum = 0;
        while(!s.empty()) {
            sum += s.top();
            s.pop();
        }

        // 정답.
        if (sum == 0) {
            cout << '1';
            for (int i = 0; i < N-1; i ++) {
                cout << v[i] << i+2;
            }
            cout << '\n';
        }
        
        return;
    }

    v.push_back(' ');
    DFS(cnt + 1);
    v.pop_back();

    v.push_back('+');
    DFS(cnt + 1);
    v.pop_back();

    v.push_back('-');
    DFS(cnt + 1);
    v.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> N;
        DFS(0);
        cout << '\n';
    }
}
