/*
아이디어 : 

10 3
2 9 5

1 2 3 4 5 6 7 8 9 10

3 4 5 6 7 8 9 10 1 -- > 0




*/
#include <iostream>
#include <deque>

using namespace std;

int N, M;
deque<int> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i ++) {
        dq.push_back(i);
    }

    int result =0;
	while(M--){
		int num;
		cin >> num;

        int left, right;
		for(int i=0; i<dq.size(); i++){
			
			if(dq[i] == num){
				left = i;
				right = dq.size()-i;
				break;
				
			}
		}
		
		if(left<=right){
			while(1){
				if(dq.front()==num) break;

				dq.push_back(dq.front());
				dq.pop_front();
				result++;
				
			}
			dq.pop_front();
		}
		
		else{
			result++;
			while(1){
				if(dq.back()==num) break;
	
				dq.push_front(dq.back());
				dq.pop_back();
				result++;
				
			}
			dq.pop_back();
		}

	}
	
	cout << result << '\n';
}