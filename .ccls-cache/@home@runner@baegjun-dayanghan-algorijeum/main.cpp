/*
아이디어 :
굳
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K;
int road[101][2];
int bike[101][2];
int dp[101][100001];

int DP(int n, int time) {
    if (n == 0) return 0;
    
    if (dp[n][time] != -1) return dp[n][time];

    dp[n][time] = -1000001;

    if (time - road[n][0] >= 0) {
        dp[n][time] = max(dp[n][time], DP(n-1, time - road[n][0]) + road[n][1]);
    }

    if (time - bike[n][0] >= 0) {
        dp[n][time] = max(dp[n][time], DP(n-1, time - bike[n][0]) + bike[n][1]);
    }

    return dp[n][time];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i ++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        road[i][0] = a;
        road[i][1] = b;
        bike[i][0] = c;
        bike[i][1] = d;
    }

    memset(dp, -1, sizeof(dp));

    cout << DP(N, K) << '\n';

	return 0;
}