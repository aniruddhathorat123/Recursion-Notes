#include<iostream>
using namespace std;

void printOneToN(int n) {
    if (n == 1) {
        cout << n << " ";
        return;
    } 
    printOneToN(n - 1);
    cout << n << " ";
}

void printNToOne(int n) {
    if (n == 1) {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    printNToOne(n - 1);
}

int printFactorial(int n) {
    if (n == 2) {
        return 2;
    }
    return n * printFactorial(n - 1);
}

int main() {
    printOneToN(10);
    cout << endl;
    printNToOne(10);
    cout << endl << "Factorial of 6 : " << printFactorial(6) << endl;
    return 0;
}