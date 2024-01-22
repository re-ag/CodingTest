#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 15654 N과 M(5)
  https://www.acmicpc.net/problem/15654
*/
int n, m;
int arr[9];
int ans[9];
bool isused[9];
// N과 M(1) 문제와 로직 같음
void func(int k){
  if(k == m){
    for(int i=0; i< m; i++)
      cout << arr[ans[i]] <<' ';
    cout << '\n';
    return;
  }
  for(int i =0; i<n; i++){
    if(!isused[i]){
      isused[i] = true; // i인덱스 사용 처리(굳이 arr[i] 로 할 필요 없음)
      ans[k] = i; // ans 에 index i를! 추가
      func(k+1); // 다음 원소를 정하러 한단계 더 들어감
      isused[i] = false; // k번째 인덱스를 arr[i] 로 정한 모든 경우에 대해 다 확인했으니, isused = false
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