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

int n, k;
vector<int> v;
int dp[10001];

// 1 2 3
// 1 -> 1 
// 2 -> 1 1 / 2
// 3 -> 1 1 1 / 2 1 / 3
// 4 -> 1 1 1 1 / 2 2 / 3 1
// 5 -> 1 1 1 1 1 / 2 1 1 1, 2 2 1 / 3 2

// 1원으로 만들 수 있는 방법을 생각한 뒤에 1, 2로 만들 수 있는 방법 더헤주고 1,2,3 으로 만들 수 있는 방법 더해주기..
// 이런 식으로 겹치지 않게 해줌.

int main()
{    
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    dp[0] = 1;
    int len = v.size();
    for (int i = 0; i < len; i ++) {
        for (int j = v[i]; j <= k; j ++) {
            dp[j] += dp[j-v[i]];
        }
    }

    cout << dp[k] << '\n';
}


