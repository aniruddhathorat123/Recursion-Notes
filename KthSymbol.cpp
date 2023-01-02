#include<iostream>
#include<math.h>
using namespace std;

int getKthInGrammer(int n, int k) {
    if (n == 1) {
        return 0;
    }
    int mid = (pow(2, n - 1) / 2);
    if (k <= mid) {
        return getKthInGrammer(n - 1, k);
    } else {
        return !(getKthInGrammer(n - 1, k - mid));
    }
}

int main() {
    cout << "Kth element in n = 3, k = 2: " << getKthInGrammer(3, 2) << endl;
    return 0;
}