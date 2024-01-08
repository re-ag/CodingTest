#include <iostream>

using namespace std;

int orig[9] = {1, 1, 1, 1, 1, 1, 2, 1, 1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 자리수마다 가지고 있는 카드의 수, 6의 경우 9를 표현할 수 있어서 2개
  int cnt[9] = {1, 1, 1, 1, 1, 1, 2, 1, 1}; 
  int n;
  int ans = 1;
  cin >> n;
  while (n) {
    int tmp = n % 10; // 자리수 추출
    if (tmp == 9) // 9의 경우 6으로 간주
      tmp = 6;
    if (cnt[tmp] == 0) { // 카드가 없다면
      ans++; // 세트 수 추가
      for (int i = 0; i < 9; i++)
        cnt[i] += orig[i]; // 세트 추가한 만큼 각 카드의 수 증가
    }
    cnt[tmp]--; // 카드 소모했으니 카드 수 감소
    n /= 10;
  }
  cout << ans;
  return 0;
}