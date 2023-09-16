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

int N, M;
int parent[101];

int find_root(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if (x != y) {
        parent[y] = x;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i ++) {
        int x, y;
        cin >> x >> y;
    }

    
}    
