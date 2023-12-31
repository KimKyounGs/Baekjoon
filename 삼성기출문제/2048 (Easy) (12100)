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
#define INF 1e9

using namespace std;

int N;
int result;
int graph[21][21];

void Slide(int arr[][21], int dir)
{
    switch(dir)
        {
            // 동
            case 0 : {
                for (int i = 0; i < N; i ++) {
                    arr[0][]
                }
                break;
            }

            // 서
            case 1 : {

                break;
            }

            // 남
            case 2 : {

                break;
            }

            // 북
            case 3 : {

                break;
            }


        }
}

void DFS(int arr[][21], int cnt) 
{
    if(cnt == N)
    {
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result = max(result, arr[i][j]);
            }
        }
        return;
    }

    for (int i = 0; i < 4; i ++) {
        int temp[21][21];
        copy(&temp[0][0], &temp[0][0] + 21*21, &arr[0][0]);
        Slide(temp, i);
        DFS(temp, cnt + 1);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> graph[i][j];
        }
    }

    DFS(graph, 0);

    return 0;
}