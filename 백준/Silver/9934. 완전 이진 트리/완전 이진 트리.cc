#include <bits/stdc++.h>
using namespace std;
int k;
int arr[1028];
vector<int> v[10];
void BSearch(int low, int high, int level) {
    int mid = (low + high) / 2;
    v[level].push_back(arr[mid]);
    if (low == high) return;
    BSearch(low, mid - 1, level + 1);
    BSearch(mid + 1, high, level + 1);
}
int main() {
    scanf("%d", &k);
    for (int i = 0; i < pow(2, k) - 1; i++) {
        scanf("%d", &arr[i]);
    }
    BSearch(0, pow(2, k) - 2, 0);
    for (int i = 0; i < k; i++) {
        for (auto& ele : v[i]) printf("%d ", ele);
        printf("\n");
    }

    return 0;
}