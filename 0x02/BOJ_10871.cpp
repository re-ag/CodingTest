#include <iostream>
using namespace std;
int a[100001];
int x,n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tmp;
  cin >> n >> x;
  for(int i = 0; i<n; i++){
    cin >> tmp;
    if(tmp < x)
      cout << tmp << ' ';
  }
}