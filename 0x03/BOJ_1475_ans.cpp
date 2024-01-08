// Authored by : OceanShape
// Co-authored by : BaaaaaaaaaaarkingDog, kiiimiiin
// http://boj.kr/a7a4aa95c4ee446990f868f926993161
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, a[10] = {}, ans = 0;
  cin >> N;
  
  // 자리수 추출
  while(N){
    a[N%10]++;
    N /= 10;
  }

    /*
     문제 그대로 해석하여 cnt 의 수를 줄이지 말고, 
     자리수마다 필요한 카드의 수를 카운트 => 계수 파악
     그 중 가장 큰 수의 카드 수만큼 세트가 필요함
    */
  for(int i = 0; i < 10; i++){
    if(i == 6 || i == 9) continue; // 일단 6과 9는 넘어가.
    ans = max(ans, a[i]);
  }
  // 6과 9는 같은 경우라고 볼 수 있기 때문에, 6의 계수와 9의 계수를 합하여 2로 나눈다.
  // 단, 나눈 값을 올림해야 함(하나라도 카드가 더 있다면 세트 증가 필요)
  
  // (a[6]+a[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 (a[6]+a[9]+1)/2을 계산
  ans = max(ans, (a[6]+a[9]+1)/2);
  cout << ans;
}