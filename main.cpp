/*

참고 : https://jaimemin.tistory.com/674

이 부분은 이때까지 탐색해온 노드들을 더해주는 코드이다.
        for (int i = next; i != start; i = v[i-1])
        {
            cnt++;
        }
        cnt++;

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

int N, M, P;
int graph[1001][1001];
bool visited[1001][1001];
priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void BFS()
{
    while(!pq.empty())
    {
        int num = pq.top().first.first;
        int cnt = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 제한 및 벽 체크
            if (nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || graph[nx][ny] == -1) continue;

            if (graph[nx][ny] == 0) 
            {
                graph[nx][ny] = num;
                pq.push({{num,cnt+1}, {nx,ny}});
            }
        }
    }
}

int main()
{
    cin >> N >> M >> P;
    for (int i = 0; i < N; i ++)
    {
        for (int j = 0; j < M; j ++)
        {
            char c;
            cin >> c;

            if (c >= 48 && c <= 57)
            {
                int num = c - '48';
                graph[i][j] = num;
                pq.push({{0, 1},{i,j}});
            }
            else if (c == '.') 
            {
                graph[i][j] = 0;
            }
            else if (c == '#')
            {
                graph[i][j] = '-1';
            }
        }
    }

    BFS();
}