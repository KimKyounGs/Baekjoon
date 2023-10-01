/*
아이디어 :

참고 : https://gamedoridori.tistory.com/51
queue는 생각해봤지만 적용할 생각은 못했다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<long long> v;

void DFS(int target) {
    queue<long long> q;
    for (int i = 0; i <= 9; i ++) {
        q.push(i);
        v.push_back(i);
    }
    while(!q.empty()) {
        long long num = q.front();
        int last = num % 10;
        q.pop();
        for (int i = 0; i < last; i ++) {
            long long nNum = num * 10 + i;
            q.push(nNum);
            v.push_back(nNum);
        }
    }
    if (target >= v.size()) {
        cout << -1;
    }
    else {
        cout << v[target];
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
        
    cin >> N;

    DFS(N);
    return 0;
    
}
