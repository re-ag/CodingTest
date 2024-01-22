#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 15654 N과 M(5)
  https://www.acmicpc.net/problem/15654
*/
int n, m;
int arr[9];
int ans[9];
bool isused[10001];
// N과 M(1) 문제와 로직 같음
void func(int k){
  if(k == m){
    for(int i=0; i< m; i++)
      cout << ans[i] <<' ';
    cout << '\n';
    return;
  }
  for(int i =0; i<n; i++){
    if(!isused[arr[i]]){
      isused[arr[i]] = true; // arr[i] 사용 처리
      ans[k] = arr[i]; // ans 에 추가
      func(k+1); // 다음 원소를 정하러 한단계 더 들어감
      isused[arr[i]] = false; // k번째 인덱스를 arr[i] 로 정한 모든 경우에 대해 다 확인했으니, isused = false
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n); // 어짜피 오름차순이기 때문에 sort 미리 해놓기
  func(0);
}