#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b>> c;
  int cnt[10] = {0,};
  int ans = a*b*c;
  while(ans){
    cnt[ans%10]++;
    ans /= 10;
  }
  for(int i = 0; i<10; i++)
    cout << cnt[i] << '\n';
}