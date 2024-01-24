#include <bits/stdc++.h>
using namespace std;
/*
    BOJ 16987 계란으로 계란치기
    n 개 중 계란 선택 2개
    1. i와 i+1 ~ n까지의 계란을 친다.
        1-1. 이때 치는 조건은 둘 다 깨지지 않은 상태여야 함(Y 가 0 초과)
    2. i++증가

    3
    8 5
    1 100
    3 5
    (0,2) -> (0,1) 순서로 깰 경우 3개를 깰 수 있음
    하지만 (0,1) -> (0,2) -> (1,2) 순으로 생각했을 때는 (0,1)때 2개가 깨져서 나머지 1개를 깰 방법이 없음
    (0,1), (0,2) (1,0) (1,2) (2,0) (2,1)
    
    
    (i, 나머지 중 하나) -> (i+1, 나머지 중 하나) ...->(n-1, 나머지 중 하나)

    (x)위치의 계란을 기준으로 깨는 함수라고 할 때,
        여기서 나머지 중 하나는 x를 제외한 나머지 중에 깨지지않은 계란  선택
        

*/
#define X first 
#define Y second
int n;
int ans;
pair<int,int> eggs[9];
bool vis[9];

bool checkVis(){ // 모든 계란에 대해 다 탐색했는가? -> true
    for(int i = 0; i< n; i++)
        if(!vis[i]) return false;
    return true;
}
void func(int x, int sx, int b){ 

    for(int i = sx; i<n; i++){ // i를 기준으로 i+1부터 n까지 깨보기

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i =0 ; i< n; i++){
        cin >> eggs[i].X >> eggs[i].Y; 
    }
    for(int i =0 ; i<n; i++){
        func(i, i+1, 0);
    }
}