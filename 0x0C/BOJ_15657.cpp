#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 15657 N과 M(8)
  https://www.acmicpc.net/problem/15657
*/

int n, m;
int arr[9];
int ans[9];
void func(int k){
  if(k == m){
    for(int i = 0; i< m; i++)
      cout << arr[ans[i]] << ' ';
    cout << '\n';
    return;
  }
  int st = 0;
  if(k != 0) st = ans[k-1];
  for(int i = st; i<n; i++){
    ans[k] = i;
    func(k+1);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i< n; i++)
    cin >> arr[i];
  sort(arr, arr+n);
  func(0);
}
