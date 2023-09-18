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

int N, S;
int result;
vector<int> v;
// -7 -3 -2 5 8
// 

void DFS(int start, int sum) {
    if (start == N) return ;

    if (sum + v[start] == S) {
        //cout << "result ++ : " << start << '\n';
        result ++;
    }

    //cout << start << " : " << sum << ' ' << sum+v[start] << '\n';

    DFS(start + 1, sum);
    DFS(start + 1, sum + v[start]);
    
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i ++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    DFS(0, 0);
    
    cout << result << '\n';
}    
