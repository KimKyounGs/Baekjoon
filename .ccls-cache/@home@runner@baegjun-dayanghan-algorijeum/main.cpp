/*
아이디어 : 

시간 초과로 골치 아팠던 문제이다.

다 왔는데 마지막에 index(매개변수)를 생각못했다. 
index를 고려해야지 경우의 수의 중복이 안 일어난다.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int result = 0;
vector<pair<int, int>> v;
bool visited[9];

void DFS(int cnt, int sum, int rS, int rW) {
    if (cnt == N) {
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < N; i ++) {
        if (visited[i] == false) {
            rS -= v[i].second;
            rW -= v[i].first;
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i ++) {
        int s,w;
        cin >> s >> w;
        v.push_back({s,w});
    }    
    
    DFS(0, 0, v[0].first, v[0].second);
    
    
}    
