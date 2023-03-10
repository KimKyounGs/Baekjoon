/*
아이디어 : 

23.3.11

어려워서 못 풀었는데 구글에서 검색하고 나니 구간 합 구하기 5(11660) 문제와 동일하게 이차원배열에서의 누적합을 구하는 방식을 써야했었다.
누적합의 활용 끝판왕까지 본 것 같다.

참고 : https://velog.io/@landlala/c-%EB%B0%B1%EC%A4%80-25682-%EC%B2%B4%EC%8A%A4%ED%8C%90-%EB%8B%A4%EC%8B%9C-%EC%B9%A0%ED%95%98%EA%B8%B0-2

문제 접근 : https://jih3508.tistory.com/59
이차원에서의 누적합 : https://jih3508.tistory.com/50

*/
#include <iostream>
#include <algorithm>

using namespace std;
int N, M, K;
char board[2000][2000];

int chess(char color) {
	int value, pSum[2001][2001] = {};
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!((i + j) % 2)) value = board[i][j] != color; // (i + j) % 2 = 0인 경우, 인자로 불러온 color 그대로
			else value = board[i][j] == color; // (i + j) % 2 = 1인 경우, 인자로 불러온 color 반대로
			
			pSum[i + 1][j + 1] = pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j] + value;
		}
	}
	int tmp, result = 100000000;
	
	for (int i = 0; i <= N - K; i++) {
		for (int j = 0; j <= M - K; j++) {
			tmp = pSum[i + K][j + K] - pSum[i][j + K] - pSum[i + K][j] + pSum[i][j];
			result = (tmp < result) ? tmp : result;
		}
	}
	
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	cout << min(chess('B'), chess('W')) << '\n';
}