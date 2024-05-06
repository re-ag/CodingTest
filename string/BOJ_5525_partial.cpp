#include <string>
#include <iostream>
using namespace std;
string s;
string f= "I";
int n, m;
size_t idx;
/*
    BOJ 5525 "IOIOI"
    https://www.acmicpc.net/problem/5525
    부분 성공

    깨달은 점
    * while(idx < m) 으로 하면 무한 반복됨
        - 이유는 find 후 npos리턴된 후 idx++하게 되면 idx가 0이되어
          다시 처음부터 find 하기 때문!
*/
int main(){
  int ans = 0;
  cin >> n >> m;
  cin >> s;
  for(int i = 0; i<n; i++)
    f+="OI";
  while(true){
    idx = s.find(f, idx);
    if(idx >= m)
      break;
    ++idx;
    ++ans;
  }
  cout << ans;
}