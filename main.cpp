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
bool visit[101][101];
int result;

void Solution() 
{
    for (int i = 0; i < N; i ++) {
        bool check = true;
        for (int j = 0; j < N-1; j ++) {
            if (abs(graph[i][j]-graph[i][j+1]) == 1 && check) {
                int cnt = 1;
                // 낮은 칸에 경사로를 놓기. (왼쪽)
                if (graph[i][j] < graph[i][j+1] && !visit[i][j]) {
                    visit[i][j] = true;
                    while(cnt != L) {
                        if (j - cnt >= 0 && graph[i][j] == graph[i][j-cnt] && !visit[i][j-cnt]) {
                            visit[i][j-cnt] = true;
                            cnt ++;
                        }
                        else {
                            check = false;
                            break;
                        }
                    }
                }
                // 낮은 칸에 경사로를 놓기. (오른쪽)
                else if (graph[i][j] > graph[i][j+1] && !visit[i][j+1]){
                    visit[i][j + 1] = true;
                    while(cnt != L) {
                        if (j + 1 + cnt <= N-1 && graph[i][j+1] == graph[i][j+1+cnt] && !visit[i][j+1+cnt]) {
                            visit[i][j+1+cnt] = true;
                            cnt ++;
                        }
                        else {
                            check = false;
                            break;
                        }
                    }
                }
                else {
                    check = false;
                    break;
                }
            }   
            else if (abs(graph[i][j]-graph[i][j+1]) > 1) {
                check = false;
                break;
            }
        }
        if (check == true) {
            //cout << "가로 = " << i+1 << "번째" << endl;  
            result ++;
        }
    }

    /*
    cout << endl;
    for (int i = 0; i < N; i++ ) {
        for (int j = 0; j < N; j ++) {
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
    */
    

    memset(visit, 0, sizeof(visit));
    

    for (int i = 0; i < N; i ++) {
        bool check = true;
        for (int j = 0; j < N-1; j ++) {
            if (abs(graph[j][i]-graph[j+1][i]) == 1 && check) {
                int cnt = 1;
                // 낮은 칸에 경사로를 놓기. (왼쪽)
                if (graph[j][i] < graph[j+1][i] && !visit[j][i]) {
                    visit[j][i] = true;
                    while(cnt != L) {
                        if (j - cnt >= 0 && graph[j][i] == graph[j-cnt][i] && !visit[j-cnt][i]) {
                            visit[j-cnt][i] = true;
                            cnt ++;
                        }
                        else {
                            check = false;
                            break;
                        }
                    }
                }
                // 낮은 칸에 경사로를 놓기. (오른쪽)
                else if (graph[j][i] > graph[j+1][i] && !visit[j+1][i]) {
                    visit[j+1][i] = true;
                    while(cnt != L) {
                        if (j +1 + cnt <= N-1 && graph[j+1][i] == graph[j+1+cnt][i] && !visit[j+1+cnt][i]) {
                            visit[j+1+cnt][i] = true;
                            cnt ++;
                        }
                        else {
                            check = false;
                            break;
                        }
                    }
                }
                else {
                    check = false;
                    break;
                }
            }   
            else if (abs(graph[j][i]-graph[j+1][i]) > 1) {
                check = false;
                break;
            }
        }
        if (check == true) {
            //cout << "세로 = " << i+1 << "번째" << endl;  
            result ++;
        }
    }

    /*
    cout << endl;
    for (int i = 0; i < N; i++ ) {
        for (int j = 0; j < N; j ++) {
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
    */
    
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

    cout << result << endl;
}


