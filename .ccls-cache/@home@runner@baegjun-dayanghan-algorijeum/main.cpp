/*
아이디어 :
설명 : https://velog.io/@jua0610/%EB%B0%B1%EC%A4%80-11657-%ED%83%80%EC%9E%84%EB%A8%B8%EC%8B%A0-%EB%B2%A8%EB%A7%8C-%ED%8F%AC%EB%93%9C-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
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

int N, M, x, y, z;
long long dist[501];
bool cycle;

vector <pair <int, int>> edge[501];

void Bellmanford() {
    fill(dist, dist + N + 1, INF); // 변경하려는 원소의 범위 시작주소, 변경하려는 원소 개수, 변경 값
    dist[1] = 0;

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < edge[i].size(); j++) {
                int next = edge[i][j].first;
                int nextcost = edge[i][j].second;

                if (dist[i] != INF && dist[next] > dist[i] + nextcost) {
                    dist[next] = dist[i] + nextcost;
                    if (k == N) cycle = true;
                }
            }
        }
    }
    if (cycle) cout << -1;
    else {
        for (int i = 2; i <= N; i++)
      // dist[i] = INF 경우는 해당 도시로 가는 경로가 없는 것
            cout << (dist[i] != INF ? dist[i] : -1) << "\n";
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        edge[x].push_back({ y, z });
    }
    Bellmanford();
}


