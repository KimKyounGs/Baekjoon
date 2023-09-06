/*
아이디어 : 

0층부터 i호실에는 i명
Ex) 1층 -> 3호에는 0층 1호부터 3호까지 합

문제에서 "아래(a-1)층의 1호부터 b호까지 사람들의 수의 합"이라는 문장을 보고 다이나믹 프로그래밍으로 풀면 좋을 것 같았음.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T;
int dp[15][15];

int main() {
    cin >> T;

    for (int i = 0; i <= 14; i ++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= 14; i ++) {
        for (int j = 1; j <= 14; j ++) {
            for (int z = 1; z <= j; z ++) {
                dp[i][j] += dp[i-1][z];
            }
        }
    }

    /*
    for (int i = 0; i <= 14; i ++) {
        for (int j = 1; j <= 14; j ++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    
    while(T--) {
        int k, n;
        cin >> k >> n;
        cout << dp[k][n] << '\n';
    }
    
    return 0;
}