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

int N;
int graph[101][101];
bool visited[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int result = INF;

void BFS(int x, int y, int num)
{
    queue<pair<int, int>> q;
    q.push({x,y});
    graph[x][y] = num;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > N-1 || ny > N-1 || graph[nx][ny] < 0) continue;

            if (graph[nx][ny] == 1)
            {
                graph[nx][ny] = num;
                q.push({nx,ny});
            }
        }
    }
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int num = graph[x][y];

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > N-1 || ny > N-1 || visited[nx][ny] < 0 || graph[nx][ny] == num) continue;

            if (graph[nx][ny] == 0)
            {

            }
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i ++)
    {
        for (int j = 0; j < N; j ++)
        {
            cin >> graph[i][j];
        }
    }

    int num = -1;
    for(int i = 0; i < N; i ++)
    {
        for (int j = 0; j < N; j ++)
        {
            if (graph[i][j] == 1)
            {
                BFS(i, j, num);
                num --;
            }
        }
    }

    for (int i = 0; i < N; i ++)
    {
        for (int j = 0; j < N; j ++)
        {
            if (graph[i][j] < 0)
            {
                BFS(i, j);
            }
            memset(visited, 0, sizeof(visited));
        }

    }
}