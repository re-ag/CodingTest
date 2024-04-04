#include <algorithm>
#include <iostream>
using namespace std;
/*
    BOJ 14501 실버3 "퇴사"
    https://www.acmicpc.net/problem/14501

    1. 테이블 정의
        dp[k] = k일부터 일을 시작했을 때, 최대 이익
    2. 점화식 정의
        if(i+t[i] <= n+1)
            dp[i] = max(dp[i+t[i]] + p[i], dp[i+1]); 
        else
            dp[i] = dp[i+1];
    3. 초기값 정의
        dp[0] = p[0]
*/
int n;
int t[1002];
int p[1002];
int dp[1002];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];
    
    for(int i = n; i>0; i--){
        if(i+t[i] <= n+1){ // i일의 상담 마지막 날이 n보다 작다면, 마지막 날의 다음 날부터 시작하는 상담을 할 때를 고려해야 함!
            /*
                1. dp[마지막날 다음 날] + i일의 상담 금액
                2. i일에 상담하지 않고, i+1일에 상담하는 경우의 금액
            */
            dp[i] = max(dp[i+t[i]] + p[i], dp[i+1]); 
        }
        else
        dp[i] = dp[i+1];
    }
    cout << *max_element(dp, dp + n +1);
}