#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	BOJ 11055 실버2 "가장 큰 증가하는 부분 수열"
	https://www.acmicpc.net/problem/11055

	1. 테이블 정의
		dp[k] = k번째 까지 합의 최대값
	2. 점화식 정의
		dp[k] = (0~k-1값 중 나보다 작은 애들 중 최대값) + arr[k]
	3. 초기값
		dp[0] = arr[0]
*/
int n;
int arr[1001];
vector<int> dp;
int main(){
	cin >> n;
	for(int i = 0; i<n; i++)
		cin >> arr[i];
	dp.push_back(arr[0]);
	for(int i = 1; i < n; i++){
		int res = 0;
		for(int j = i - 1; j >= 0; j--){
			if(arr[j] < arr[i])
				res = max(res, dp[j]);
		}
		res += arr[i];
		dp.push_back(res);
	}
	cout << *max_element(dp.begin(), dp.end());
}