#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int mxW = 0; // 작은 변의 집합
    int mxH = 0; // 긴 변의 집합
    for(int i = 0; i<sizes.size(); i++){
        mxW = max(mxW, min(sizes[i][0], sizes[i][1]));
        mxH = max(mxH, max(sizes[i][0], sizes[i][1]));
    }
    return mxW*mxH;
}