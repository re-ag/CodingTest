#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 999'999'999;
    for(unsigned int i = 0; i<(1<<sizes.size()); i++){
        int mxW = 0;
        int mxH = 0;
        for(unsigned int j = 0; j<sizes.size(); j++){
            int w, h;
            if((i & (1 << j)) != 0){
                w = sizes[j][0];
                h = sizes[j][1];
            }
            else{
                w = sizes[j][1];
                h = sizes[j][0];
            }
            mxW = max(mxW, w);
            mxH = max(mxH, h);
        }
        answer = min(answer, mxW * mxH);
    }
    return answer;
}