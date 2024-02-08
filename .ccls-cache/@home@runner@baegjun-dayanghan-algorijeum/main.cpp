/*
아이디어 :


쉽게 쉽게 구현이 안된다..ㅠㅠ

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

int N;
int graph[22][22];
int total = 0;
int result = INF;

int Simulation(int x, int y, int d1, int d2) {
    if ((d1 >= 1) && (d2 >= 1) && (x >= 1) && (x < x + d1 + d2) && (x + d1 + d2 <= N) && (y - d1 >= 1) && (y - d1 < y) && (y < y + d2) && (y + d2 <= N)) {}
    else {
        return 0;
    }
  
    int result = 0;
    int arr[5] = {0,};
    int mins = INF;
    int maxs = -1;
    
    // 1
    for (int i = 1, sub = 0; i < x + d1; i++) {
        if (i >= x) {
            sub++;
        }
        for (int j = 1; j <= y - sub; j++) {
            arr[0] += graph[i][j];
        }
    }
    // 2 
    for (int j = N, sub = 0; j > y; j--) {
        if (j <= y + d2) {
            sub++;
        }
        for (int i = 1; i <= x + d2 - sub; i++) {
            arr[1] += graph[i][j];
        }
    }
    // 3
    for (int j = 1, sub = 0; j < y - d1 + d2; j++) {
        if (j >= y - d1) {
            sub++;
        }
        for (int i = N; i >= x + d1 + sub; i--) {
            arr[2] += graph[i][j];
        }
    }
    // 4
    for (int i = N, sub = 0; i > x + d2; i--) {
        if (i <= x + d1 + d2) {
            sub++;
        }
        for (int j = N; j >= y - d1 + d2 + sub; j--) {
            arr[3] += graph[i][j];
        }
    }

    arr[4] = total - (arr[0] + arr[1] + arr[2] + arr[3]);

    for (int i = 0; i < 5; i ++) {
        maxs = max(maxs, arr[i]);
        mins = min(mins, arr[i]);
    }

    result = maxs - mins;
    
    return result;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            cin >> graph[i][j];
            total += graph[i][j];
        }
    }

    for (int i = 1; i <= N; i ++) {
        for (int j = 2; j <= N; j++) {
            for (int d1 = 1; d1 <= j; d1++) {
                for (int d2 = 1; d2 < N - j; d2++) {
                    int value = Simulation(i, j, d1, d2);
                    if (value) {
                        result = min(result, value);
                    }
                }
            }
        
    }

}

