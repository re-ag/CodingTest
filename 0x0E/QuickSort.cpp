#include <iostream>
#include <algorithm>
using namespace std;
/*
    Quick Sort
*/

int arr[8] = { 6, -8, 1, 12,8, 3,7,-7 };
void quickSort(int st, int en) {
    if (en <= st+1) return;
    int pivot = arr[st];
    int l = st+1;
    int r = en - 1;
    while(1) {
        while (arr[l] <= pivot) ++l;
        while (arr[r] >= pivot) --r;
        if (l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[r], arr[st]);
    quickSort(st, r);
    quickSort(r + 1, en);
}

int main() {
    quickSort(0, 8);
    for (auto x : arr) cout << x << ' ';
}