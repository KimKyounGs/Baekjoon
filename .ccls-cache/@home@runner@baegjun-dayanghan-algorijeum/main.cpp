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
#include <deque>
#include <map>
#define INF 1e9
#define endl '\n'

using namespace std;

int T, N;
int dp[2][100001];
int arr[2][100001];

int main()
{    
    cin >> T;
    while(T--) {
        cin >> N;
        for (int i = 0; i < 2; i ++) {
            for (int j = 1; j <= N; j ++) {
                cin >> arr[i][j];
            }
        }
        // 초기화
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = arr[1][0];
        dp[1][1] = arr[1][1];
        
        for (int i = 1; i <= N; i ++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
        }

        cout << max(dp[0][N], dp[1][N]) << endl;
    }
}


