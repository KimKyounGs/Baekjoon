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

int R, C;
int graph[1001][1001];
int jX, jY;
queue<pair<int, int>> fQ;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void FireBFS()
{
    while(!fQ.empty())
    {
        int x = fQ.front().first;
        int y = fQ.front().second;
        fQ.pop();

        for (int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny << 0 || nx > R-1|| ny > C-1) continue;

            if (graph[nx][ny] == 0)
            {
                graph[nx][ny] = graph[x][y] - 1;
                fQ.push({nx, ny});
            }
        }   
    }
}

void BFS()
{
    queue<pair<int, int>> q;
    q.push({jX, jY});
    graph[jX][jY] = 1;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > R-1|| ny > C-1) continue;

            // 지훈이가 가려는 곳이 불이 타고 있는 곳이 아니거나 불의 탄 시점보다 더 빠른 경우에 이동 가능
            if (graph[nx][ny] == 0 || (graph[nx][ny] < 0 && -graph[nx][ny] > graph[x][y]+1))
            {
                graph[nx][ny] = graph[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i ++) 
    {
        for (int j = 0; j < C; j ++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                graph[i][j] = 1;
            }
            else if (c == '.')
            {
                graph[i][j] = 0;
            }
            else if (c == 'J')
            {
                // 지훈이가 가장자리에 있으면 바로 탈출 가능
                if (i == 0 || i == R-1 || j == 0 || j == C-1) 
                {
                    cout << 2 << '\n';
                    return 0;
                }
                graph[i][j] = 0;
                jX = i;
                jY = j;
            }
            else if (c == 'F')
            {
                graph[i][j] = -1;
                fQ.push({i,j});
            }
        }
    }

    FireBFS();
    for (int i = 0; i < R; i ++)
    {
        for (int j = 0; j < C; j ++)
        {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }

    cout << endl;
    BFS();

    for (int i = 0; i < R; i ++)
    {
        for (int j = 0; j < C; j ++)
        {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }

    cout << endl;

    int result = 0;
    for (int i = 0; i < R; i ++)
    {
        for (int j = 0; j < C; j ++)
        {
            if (i != 0 || i != R-1 || j != 0 || j != C-1) continue;

            if (graph[i][j] > 1) result = max(result, graph[i][j]);
        }
    }

    if (result == 0) cout << "IMPOSSIBLE" << endl;
    else cout << result + 1 << endl;
}