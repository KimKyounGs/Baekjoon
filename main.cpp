/*
아이디어 :

밀고 땅기고 하는 구현이 빡셌다.
합치는 과정에서 합쳐지면 j-- or j++ 을 해야 합쳐진 것이 또 안 합쳐진다.


반례 처리.
https://www.acmicpc.net/board/view/128093

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
vector<vector<int>> graph;

void Slide(vector<vector<int>> &v, int dir)
{
    switch(dir)
        {
            // 동
            case 0 : {
                // 1. 땡기기
                for (int i = 0; i < N; i ++) {
                    for (int j = N-1; j >= 0; j--) {
                        if (v[i][j] != 0) {
                            bool check = false;
                            int temp = j;
                            while(temp < N-1) {
                                if (v[i][temp+1] == 0) {
                                    temp ++;
                                    check = true;
                                }
                                else {
                                    break;
                                }
                            }
                            if (check) {
                                v[i][temp] = v[i][j];
                                v[i][j] = 0;
                            }
                        }
                    }
                }
                // 2. 합치기.
                for (int i = 0; i < N; i ++) {
                    for (int j = N-1; j >= 0; j--) {
                        if (v[i][j] != 0) {
                            if (j - 1 >= 0 && v[i][j-1] == v[i][j]) {
                                v[i][j] *= 2;
                                v[i][j-1] = 0;
                                j--;
                            }
                        }
                    }
                }
                // 3. 다시 채워주기.
                for (int i = 0; i < N; i ++) {
                    for (int j = N-1; j >= 0; j--) {
                        if (v[i][j] != 0) {
                            bool check = false;
                            int temp = j;
                            while(temp < N-1) {
                                if (v[i][temp+1] == 0) {
                                    temp ++;
                                    check = true;
                                }
                                else {
                                    break;
                                }
                            }
                            if (check) {
                                v[i][temp] = v[i][j];
                                v[i][j] = 0;
                            }
                        }
                    }
                }

                // Debug
                 /*
                cout << "동쪽으로 슬라이드" << '\n';
                
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        cout << v[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << '\n';
                */
                break;
            }

            // 서
            case 1 : {
                // 1. 땡기기
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        if (v[i][j] != 0) {
                            bool check = false;
                            int temp = j;
                            while(temp > 0) {
                                if (v[i][temp-1] == 0) {
                                    temp --;
                                    check = true;
                                }
                                else {
                                    break;
                                }
                            }
                            if (check) {
                                v[i][temp] = v[i][j];
                                v[i][j] = 0;
                            }
                        }
                    }
                }
                // 2. 합치기.
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        if (v[i][j] != 0) {
                            if (j + 1 < N && v[i][j+1] == v[i][j]) {
                                v[i][j] *= 2;
                                v[i][j+1] = 0;
                                j++;
                            }
                        }
                    }
                }
                // 3. 다시 채워주기.
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        if (v[i][j] != 0) {
                            bool check = false;
                            int temp = j;
                            while(temp > 0) {
                                if (v[i][temp-1] == 0) {
                                    temp --;
                                    check = true;
                                }
                                else {
                                    break;
                                }
                            }
                            if (check) {
                                v[i][temp] = v[i][j];
                                v[i][j] = 0;
                            }
                        }
                    }
                }

                // Debug
                /*
                cout << "서쪽으로 슬라이드" << '\n';
                
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        cout << v[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << '\n';
                */
                break;
            }

            // 북
            case 2 : {
                // 1. 땡기기
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        if (v[j][i] != 0) {
                            bool check = false;
                            int temp = j;
                            while(temp > 0) {
                                if (v[temp-1][i] == 0) {
                                    temp --;
                                    check = true;
                                }
                                else {
                                    break;
                                }
                            }
                            if (check) {
                                v[temp][i] = v[j][i];
                                v[j][i] = 0;
                            }
                        }
                    }
                }
                // 2. 합치기.
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        if (v[j][i] != 0) {
                            if (j + 1 < N && v[j+1][i] == v[j][i]) {
                                v[j][i] *= 2;
                                v[j+1][i] = 0;
                                j++;
                            }
                        }
                    }
                }
                // 3. 다시 채워주기.
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        if (v[j][i] != 0) {
                            bool check = false;
                            int temp = j;
                            while(temp > 0) {
                                if (v[temp-1][i] == 0) {
                                    temp --;
                                    check = true;
                                }
                                else {
                                    break;
                                }
                            }
                            if (check) {
                                v[temp][i] = v[j][i];
                                v[j][i] = 0;
                            }
                        }
                    }
                }

                // Debug
                /*
                cout << "북쪽으로 슬라이드" << '\n';
                
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        cout << v[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << '\n';
                */
                break;
            }

            // 북
            case 3 : {
                // 1. 땡기기
                for (int i = 0; i < N; i ++) {
                    for (int j = N-1; j >= 0; j--) {
                        if (v[j][i] != 0) {
                            bool check = false;
                            int temp = j;
                            while(temp < N-1) {
                                if (v[temp+1][i] == 0) {
                                    temp ++;
                                    check = true;
                                }
                                else {
                                    break;
                                }
                            }
                            if (check) {
                                v[temp][i] = v[j][i];
                                v[j][i] = 0;
                            }
                        }
                    }
                }
                // 2. 합치기.
                for (int i = 0; i < N; i ++) {
                    for (int j = N-1; j >= 0; j--) {
                        if (v[j][i] != 0) {
                            if (j - 1 >= 0 && v[j-1][i] == v[j][i]) {
                                v[j][i] *= 2;
                                v[j-1][i] = 0;
                                j--;
                            }
                        }
                    }
                }
                // 3. 다시 채워주기.
                for (int i = 0; i < N; i ++) {
                    for (int j = N-1; j >= 0; j--) {
                        if (v[j][i] != 0) {
                            bool check = false;
                            int temp = j;
                            while(temp < N-1) {
                                if (v[temp+1][i] == 0) {
                                    temp ++;
                                    check = true;
                                }
                                else {
                                    break;
                                }
                            }
                            if (check) {
                                v[temp][i] = v[j][i];
                                v[j][i] = 0;
                            }
                        }
                    }
                }
                
                // Debug
                /*
                cout << "남쪽으로 슬라이드" << '\n';
                
                for (int i = 0; i < N; i ++) {
                    for (int j = 0; j < N; j++) {
                        cout << v[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << '\n';
                */
                break;
            }

            default: {
                cout << "default" << '\n';
            }
        }
}

/*
동 동 동 동 동

0 4 4 32
4 0 2 64
8 8 0 0
0 16 64 4

*/
vector<int> debugV;
void DFS(vector<vector<int>> v, int cnt) 
{
    if(cnt == 5)
    {
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //cout << v[i][j] << ' ';
                if (result < v[i][j]) {
                    result = v[i][j];
                    //cout << result << '\n';
                    /*
                    for (int z = 0; z < debugV.size(); z ++) {
                        cout << debugV[z] << ' ';
                    }
                    cout << '\n';
                    */
                }
            }
            //cout << '\n';
        }
        return;
    }
    vector<vector<int>> tempV;
    tempV.assign(v.size(), vector<int>(v.size())); // 벡터 크기 할당.
    copy(v.begin(), v.end(), tempV.begin()); // 벡터 복사
    
    for (int i = 0; i < 4; i ++) {
        //cout << "cnt : " << cnt << " i : " << i << '\n';
        debugV.push_back(i);
        Slide(v, i);
        DFS(v, cnt + 1);
        debugV.pop_back();
        v.assign(tempV.size(), vector<int>(tempV.size())); // 벡터 크기 할당.
        copy(tempV.begin(), tempV.end(), v.begin()); // 벡터 복사
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i ++) {
        vector<int> temp;
        for (int j = 0; j < N; j ++) {
            int n;
            cin >> n;
            temp.push_back({n});
        }
        graph.push_back(temp);
    }

    DFS(graph, 0);
    /*
    Slide(graph, 2);
    Slide(graph, 0);
    Slide(graph, 3);
    Slide(graph, 1);
    Slide(graph, 2);
    */
    cout << result << '\n';
    return 0;
}