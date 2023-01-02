#include<iostream>
using namespace std;

void printBNWith1GE0(int one, int zero, int n, string output) {
    if (n == 0) {
        cout << output << endl;
        return;
    }
    string op1 = output;
    op1.push_back('1');
    printBNWith1GE0(one + 1, zero, n - 1, op1);

    if (one > zero) {
        string op2 = output;
        op2.push_back('0');
        printBNWith1GE0(one, zero + 1, n - 1, op2);
    }
}


int main() {
    int one, zero, n;
    cout << "Enter length of binary number: ";
    cin >> n;
    cout << "Binary number with 1 more than equal to 0:" << endl;
    one = 0;
    zero = 0;
    printBNWith1GE0(0, 0, n, "");
    return 0;
}