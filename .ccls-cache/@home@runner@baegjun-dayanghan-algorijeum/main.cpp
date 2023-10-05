/*
아이디어 :

"모든 단어는 "anta"로 시작되고, "tica"로 끝난다." 
그러면 a c i n t 는 무조건 가지고 있어야 한다.


여기서 비트마스킹 개념이 들어간다.

idx 매개변수를 넣어줘야지 중복이 안되어서 시간초과가 뜨지 않는다.
유의하도록 하자. 
가르침 받았다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N, K;
int result = 0;
vector<string> words;
bool alphabet[26] = {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};

void DFS(int cnt, int idx) {
    if (cnt == K) {
        int wordCnt = N;
        // 활성화 되어있는 알파벳으로 읽을 수 있는지 확인.
        for (int i = 0; i < N; i++) {
            int len = words[i].length();
            for (int j = 4; j < len-4; j ++) {
                if (alphabet[words[i][j] - 'a'] == false) {
                    wordCnt --;
                    break;
                }
            }
        }

        result = max(result, wordCnt);
        return;
    }
    
    for (int i = idx; i < 26; i ++) {
        if (alphabet[i] == false) {
            alphabet[i] = true;
            DFS(cnt + 1, i);
            alphabet[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i ++) {
        string str;
        cin >> str;
        words.push_back(str);
    }

    if (K < 5) {
        cout << 0 << '\n';
        return 0;
    }

    DFS(5, 0);

    cout << result << '\n';
    return 0;
}
