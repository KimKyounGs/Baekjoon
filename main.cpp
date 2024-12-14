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

int N, K;
int arr[11][11];
int ky[21];
int mh[21];
bool visited[11];
bool result = false;
vector<int> v;


bool Simulation()
{   
    int victory[3] = {0, 0, 0}; // 지우, 경희, 민호
    int order[3] = {1, 2, 0}; // 지우, 경희, 민호

    int idx = 0;

    for (int i = 0; i < 20; i ++)
    {   
        if (victory[0] == K || victory[1] == K || victory[2] == K)
        {
            if (victory[0] == K) return true;
            else return false;
        }

        int player1 = -1;
        int player2 = -1;
        for (int j = 0; j < 3; j ++)
        {
            if (order[j] == 1)
            {
                player1 = j;
            }
            else if (order[j] == 2)
            {
                player2 = j;
            }
        }

        // 지우 차례
        if (player1 == 0 || player2 == 0)
        {
            // 지우가 첫 번째
            if (player1 == 0)
            {
                int value = (player2 == 1) ? ky[i] : mh[i];
                if (arr[v[idx]][value] == 0 || arr[v[idx]][value] == 1)
                {
                    // 경희
                    if (player2 == 1)
                    {
                        order[0] = 0;
                        order[1] = 1;
                        order[2] = 2;
                        victory[1] ++;
                    }
                    // 민호
                    else if (player2 == 2)
                    {
                        order[0] = 0;
                        order[1] = 2;
                        order[2] = 1;
                        victory[2] ++;
                    }
                }
                else if (arr[v[idx]][value] == 2)
                {
                    // 경희
                    if (player2 == 1)
                    {
                        order[0] = 1;
                        order[1] = 0;
                        order[2] = 2;
                    }
                    // 민호
                    else if (player2 == 2)
                    {
                        order[0] = 1;
                        order[1] = 2;
                        order[2] = 0;
                    }
                    victory[0] ++;
                }
            }
            // 지우가 두 번쨰
            else if (player2 == 0)
            {
                int value = (player1 == 1) ? ky[i] : mh[i];
                if (arr[value][v[idx]] == 2 || arr[value][v[idx]] == 1)
                {
                    // 경희
                    if (player1 == 1)
                    {
                        order[0] = 1;
                        order[1] = 0;
                        order[2] = 2;
                    }
                    // 민호
                    else if (player1 == 2)
                    {
                        order[0] = 1;
                        order[1] = 2;
                        order[2] = 0;
                    }
                    victory[0] ++;
                }
                else if (arr[value][v[idx]] == 0)
                {
                    // 경희
                    if (player1 == 1)
                    {
                        order[0] = 0;
                        order[1] = 1;
                        order[2] = 2;
                        victory[1] ++;
                    }
                    // 민호
                    else if (player1 == 2)
                    {
                        order[0] = 0;
                        order[1] = 2;
                        order[2] = 1;
                        victory[2] ++;
                    }
                }
            }
            idx ++;
        }
        // 경희 vs 민호
        else
        {
            // 경희 vs 민호
            if (player1 == 1 && player2 == 2)
            {
                if (arr[ky[i]][mh[i]] == 0 || arr[ky[i]][mh[i]] == 1)
                {
                    order[0] = 2;
                    order[1] = 0;
                    order[2] = 1;
                    victory[2] ++;
                }
                else if (arr[ky[i]][mh[i]] == 2)
                {
                    order[0] = 2;
                    order[1] = 1;
                    order[2] = 0;
                    victory[1] ++;
                }
            }
            // 민호 vs 경희
            else if (player1 == 2 && player2 == 1)
            {
                if (arr[mh[i]][ky[i]] == 0 || arr[mh[i]][ky[i]] == 1)
                {
                    order[0] = 2;
                    order[1] = 1;
                    order[2] = 0;
                    victory[1] ++;
                }
                else if (arr[mh[i]][ky[i]] == 2)
                {
                    order[0] = 2;
                    order[1] = 0;
                    order[2] = 1;
                    victory[2] ++;
                }
            }
        }
    }
    return false;
}

void DFS(int cnt)
{
    if (cnt == N)
    {
        if (Simulation())
        {
            result = true;
        }
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            v.push_back(i);
            visited[i] = true;
            DFS(cnt + 1);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    cin>> N >> K;
    for (int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 20; i ++)
    {
        cin >> ky[i];
    }
    for (int i = 0; i < 20; i ++)
    {
        cin >> mh[i];
    }

    DFS(0);

    if (result == true)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}