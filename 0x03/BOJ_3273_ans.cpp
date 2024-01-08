// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
using namespace std;

bool occur[1000001];
int nums[100001];
int n,x;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums[i] = temp;
        // occur[temp] = 1  // <-- 미리 체크를 하면 ai+aj = k (i < j), i<j 조건을 만족하지 못함
	}

	cin >> x;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int num = nums[i];
		/*if(num != (x-num) && occur[num] && occur[x-num])
				ans++;*/
		if (x - num > 0 && x - num < 1000001 && occur[x - num])
			ans++;
		occur[num] = true; // occur[x-num] 이 존재하는 지 체크 후, occur[num] = 1 처리!가 핵심
	}
	cout << ans;
}
