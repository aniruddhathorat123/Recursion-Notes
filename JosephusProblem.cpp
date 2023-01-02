#include<iostream>
#include<vector>
using namespace std;

void findLast(vector<int> vect, int index, int k, int &ans) {
    if (vect.size() == 1) {
        ans = vect[0];
        return;
    }
    index = (index + k) % vect.size();
    vect.erase(vect.begin() + index);
    findLast(vect, index, k, ans);
}

int main() {
    int n, k, ans;
    vector<int> vect;
    cout << "Enter the size: ";
    cin >> n;
    cout << "Enter the delete position: ";
    cin >> k;

    for (int i = 1; i <= n; i++) {
        vect.push_back(i);
    }
    ans = -1;
    findLast(vect, 0, k - 1, ans);
    cout << "Last remaining element: " << ans << endl;
    return 0;
}