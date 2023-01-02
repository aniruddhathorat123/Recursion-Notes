#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void insertEle(vector<int> &vect, int ele) {
    if (vect.size() == 0 || vect[vect.size() - 1] <= ele) {
        vect.push_back(ele);
        return;
    }
    int val = vect[vect.size() - 1];
    vect.pop_back();
    insertEle(vect, ele);
    vect.push_back(val);
}

void sortVect(vector<int> &vect) {
    if (vect.size() == 1) {
        return;
    }
    int temp = vect[vect.size() - 1];
    vect.pop_back();
    sortVect(vect);
    insertEle(vect, temp);
}

int main() {
    vector<int> vect = {0, 1, 5, 2};
    sortVect(vect);
    printVector(vect);
    return 0;
}