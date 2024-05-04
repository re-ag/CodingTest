#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
    BOJ 1541 "잃어버린 괄호"
    https://www.acmicpc.net/problem/1541
    
    1. 첫번째 수는 일단 ans 에 더함
    2-1. "-"를 찾기 전까지는 일단 다음 숫자들을 다 ans에 더함
    2-2. "-"를 찾았다면 그 뒤 숫자들은 다 ans에 빼줌

    WRONG: 하나의 숫자만 있는 경우의 처리를 안해줌....
*/
string str;
int ans = 0;
int main() {
  cin >> str;
  size_t pos = 0;
  size_t minus = str.find("-");
  size_t plus = str.find("+");
  size_t min_ = 0;
  if (plus != string::npos && minus == string::npos) { // all plus
    while (plus != string::npos) {
      plus = str.find("+", pos);
      ans += stoi(str.substr(pos, plus - pos));
      pos = plus + 1;
    }
  } else if (plus == string::npos && minus == string::npos) {
    ans += stoi(str.substr(pos, str.length() - pos));
  } else {
    ans += stoi(str.substr(pos, min(plus, minus) - pos)); // first number
    pos = min(plus, minus) + 1;
    if (plus < minus) {
      while (true) {
        plus = str.find("+", pos);
        if (plus == string::npos || plus > minus)
          break;
        ans += stoi(str.substr(pos, plus - pos));
        pos = plus + 1;
      }
      ans += stoi(str.substr(pos, minus - pos));
      pos = minus + 1;
    }
    while (min_ != string::npos) {
      minus = str.find("-", pos);
      plus = str.find("+", pos);
      min_ = min(minus, plus);
      if (min_ == string::npos)
        break;
      ans -= stoi(str.substr(pos, min_ - pos));
      pos = min_ + 1;
    }
    ans -= stoi(str.substr(pos, str.length() - pos));
  }
  cout << ans;
}