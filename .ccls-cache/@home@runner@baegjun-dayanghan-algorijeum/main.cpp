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

int N, M, K;
bool arr[51][51];
int result;

void Switch(int idx, bool (*temp)[51])
{
    for (int i = 0; i < N; i ++) {
        temp[i][idx] = !temp[i][idx];
    }
}

int CheckResult(bool (*temp)[51])
{
    int value = 0;
    for (int i = 0; i < N; i ++) {
        int cnt = 0;
        for (int j = 0; j < M; j ++) {
            if (temp[i][j]) cnt ++;
        }
        if (cnt == M) value++;
    }

    return value;
}

void DFS(int cnt, bool temp[51][51])  
{
    if (cnt == K) {
        result = max(result, CheckResult(temp));
        return;
    }

    for (int i = 0; i < M; i ++) {
        Switch(i, temp);
        DFS(cnt + 1, temp);
        Switch(i, temp);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            scanf("%1d",&arr[i][j]);
        }
    }
    cin >> K;

    DFS(0, arr);
    cout << result << endl;
}


