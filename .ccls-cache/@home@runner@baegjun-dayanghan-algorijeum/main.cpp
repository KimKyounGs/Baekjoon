/*
# 아이디어 

누적합 설명서 : https://book.acmicpc.net/algorithm/prefix-sum
*/
#include <iostream>

using namespace std;

int N, M;
int sum[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i ++) {
        int n;
        cin >> n;
        sum[i] = sum[i-1] + n;
    }

    while(M--) {
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i-1] << '\n'; 
    }
}