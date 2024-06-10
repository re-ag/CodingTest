#include <iostream>
using namespace std;
/*
    BOJ 10844 실버1 "쉬운 계단 수"
    https://www.acmicpc.net/problem/10844

    1. 테이블 정의하기
        dp[N][0~9]: N자리수의 경우 0~9로 끝나는 수의 개수
    2. 점화식 세우기
        dp[N][i] = dp[N-1][i-1] + dp[N-1][i+1]
        단, dp[N][0] = dp[N-1][1], dp[N][9] = dp[N-1][8]
    3. 초기값
        dp[1][0] = 0, dp[1][1~9] = 1

    틀린 이유:
    ans를 구할 때 dp[N][0]~dp[N][9] 원소들의 합으로 구하지 않고
    ans[N-1]*2 - (dp[N][0] + dp[N][9])로 구함
    논리적으로 틀린것은 아니나, mod 범위가 넘어가기 때문에 계속 틀리는 것 같음
*/
int N;
unsigned long long num[101][10];
long long k = 1'000'000'000;
int main() {
    cin >> N;
    for (int i = 1; i <= 9; i++)
        num[1][i] = 1;
    for (int i = 2; i <= 100; i++) {
        num[i][0] = num[i - 1][1] % k;
        for (int j = 1; j <= 8; j++) {
        num[i][j] = (num[i - 1][j - 1] % k + num[i - 1][j + 1] % k) % k;
        }
        num[i][9] = num[i - 1][8] % k;
    }
    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans % k + num[N][i] % k) % k;
    }
    cout << ans % k;
}
