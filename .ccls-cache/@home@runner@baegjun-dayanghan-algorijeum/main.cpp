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

int N, L;
int graph[101][101];
bool visite[101][101];
int result;

void Solution() 
{
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (abs(graph[i][j]-graph[i][j]) == 1) {
                // 왼쪽에 경사로
                bool left = false;
                if (j - L >= 0) {
                    
                }

                // 오른쪽에 경사로
                bool right = false;
            }
            else {
                break;
            }
        }
    }
}

int main()
{
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    Solution();
}


