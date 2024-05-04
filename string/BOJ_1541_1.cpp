#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
    BOJ 1541 "잃어버린 괄호"
    https://www.acmicpc.net/problem/1541
    
    1. 쭉 순회하면서 기호가 아닌 문자열은 num 문자열에 저장
    2. 기호인 경우
    2-1. isMinus 가 false 면 num문자열을 ans 에 더함
    2-2. isMinus 가 true 면 num 문자열을 ans 에 뺌
    2-3. 그 후 '-' 라면 isMinus 를 true로 저장
    3. 마지막 숫자는 for문에서 처리할 수 없으므로 isMinus에 따라 ans 에 저장함
*/
string str;
int ans = 0;
int main() {
  cin >> str;
  bool isMinus = false;
  string num = "";
  int tmp = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '-' || str[i] == '+') {
      tmp = stoi(num);
      num = "";
      if(!isMinus)
        ans += tmp;
      else
        ans -= tmp;
      if(str[i] == '-')
        isMinus = true;
    } else {
      num += str[i];
    }
  }
  if(isMinus)
    ans -= stoi(num);
  else
    ans += stoi(num);
  cout << ans;
}