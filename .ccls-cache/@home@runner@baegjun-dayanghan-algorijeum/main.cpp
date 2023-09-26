/*
아이디어 : 


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
