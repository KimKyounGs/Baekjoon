/*
아이디어 :

N,M 크기도 작고 5가지의 블록밖에 없었기 때문에 브르투포스로 풀기에 충분한 시간이여서 
모든 테트로미노를 주어진 N과 M크기의 사각형에서 다양하게 배치하여 크기를 구했음.
3,4,5번째 테트로미노는 2*3크기의 사각형으로 생각해서 배치함.

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

int N, M;
int graph[501][501];
int result = 0;

void One() {
    for (int i = 0; i < N; i ++ ) {
        for (int j = 0; j < M; j ++) {
            if (j + 3 < M) {
                result = max(graph[i][j] + graph[i][j + 1] + graph[i][j + 2] + graph[i][j + 3], result);
            }
            if (i + 3 < N) {
                result = max(graph[i][j] + graph[i + 1][j] + graph[i + 2][j] + graph[i + 3][j], result);
            }
        }
    } 
}

void Two() {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (i + 1 < N && j + 1 < M) {
                result = max(graph[i][j] + graph[i+1][j] + graph[i+1][j+1] + graph[i][j+1], result);
            }
        }
    }
}

void Three() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j ++) {
            if (i + 2 < N && j + 1 < M) {
                result = max(graph[i][j] + graph[i+1][j] + graph[i+2][j] + graph[i+2][j+1], result);
                result = max(graph[i][j+1] + graph[i+1][j+1] + graph[i+2][j+1] + graph[i+2][j], result);
                result = max(graph[i][j] + graph[i+1][j] + graph[i+2][j] + graph[i][j+1], result);
                result = max(graph[i][j] + graph[i+1][j+1] + graph[i+2][j+1] + graph[i][j+1], result);
            }

            if (i + 1 < N && j + 2 < M) {
                result = max(graph[i][j] + graph[i][j+1] + graph[i][j+2] + graph[i+1][j+2], result);
                result = max(graph[i+1][j] + graph[i+1][j+1] + graph[i+1][j+2] + graph[i][j+2], result);
                result = max(graph[i][j] + graph[i][j+1] + graph[i][j+2] + graph[i+1][j], result);
                result = max(graph[i+1][j] + graph[i+1][j+1] + graph[i+1][j+2] + graph[i][j], result);
            }
        }
    }
}

void Four() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j ++) {
            if (i + 2 < N && j + 1 < M) {
                result = max(graph[i][j] + graph[i+1][j] + graph[i+1][j+1] + graph[i+2][j+1], result);
                result = max(graph[i][j+1] + graph[i+1][j+1] + graph[i+1][j] + graph[i+2][j], result);
            }

            if (i + 1 < N && j + 2 < M) {
                result = max(graph[i][j+1] + graph[i][j+2] + graph[i+1][j] + graph[i+1][j+1], result);
                result = max(graph[i][j] + graph[i][j+1] + graph[i+1][j+1] + graph[i+1][j+2], result);
            }
        }
    }
}

void Five() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j ++) {
            if (i + 2 < N && j + 1 < M) {
                result = max(graph[i][j] + graph[i+1][j] + graph[i+2][j] + graph[i+1][j+1], result);
                result = max(graph[i][j+1] + graph[i+1][j+1] + graph[i+2][j+1] + graph[i+1][j], result);
            }

            if (i + 1 < N && j + 2 < M) {
                result = max(graph[i][j] + graph[i][j+1] + graph[i][j+2] + graph[i+1][j+1], result);
                result = max(graph[i+1][j] + graph[i+1][j+1] + graph[i+1][j+2] + graph[i][j+1], result);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j ++) {
            cin >> graph[i][j];
        }
    }

    One();
    Two();
    Three();
    Four();
    Five();

    cout << result << endl;
}


