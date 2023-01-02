#include<iostream>
using namespace std;

void printSubset(string ip, string op) {
    if (ip.size() == 0) {
        cout << "`"<<op <<"`"<< endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    printSubset(ip, op1);
    printSubset(ip, op2);
}

int main() {
    string ip = "";
    cout << "Enter input: " << endl;
    cin >> ip;
    cout << "Subsets are :" << endl;
    printSubset(ip, "");
    return 0;
}