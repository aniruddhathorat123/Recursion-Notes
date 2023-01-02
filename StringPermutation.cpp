#include<iostream>
using namespace std;

void getSpacePermutations(string input, string output) {
    if (input.size() == 0) {
        cout << output << endl;
        return;
    }
    string op1 = output + " ";
    string op2 = output;
    op1.push_back(input[0]);
    op2.push_back(input[0]);
    input.erase(input.begin() + 0);
    getSpacePermutations(input, op1);
    getSpacePermutations(input, op2);
    return;
}

void getCasePermutations(string input, string output) {
    if (input.size() == 0) {
        cout << output << endl;
        return;
    }
    string op1 = "";
    string op2 = "";
    if (islower(input[0])) {
        op1 = output + input[0];
        op2 = output;
        op2.push_back(toupper(input[0]));
    } else {
        op1 = output;
        op1.push_back(tolower(input[0]));
        op2 = output + input[0];
    }
    input.erase(input.begin() + 0);
    getCasePermutations(input, op1);
    getCasePermutations(input, op2);
    return;
}

void getLetterWithDigitPermutations(string input, string output) {
    if (input.size() == 0) {
        cout << output << endl;
        return;
    }
    string op1 = output;
    string op2 = output;
    if (isalpha(input[0])) {
        if (isupper(input[0])) {
            op2.push_back(tolower(input[0]));
            op1.push_back(input[0]);
        } else {
            op1.push_back(input[0]);
            op2.push_back(toupper(input[0]));
        }
        input.erase(input.begin() + 0);
        getLetterWithDigitPermutations(input, op1);
        getLetterWithDigitPermutations(input, op2);
    } else {
        op1.push_back(input[0]);
        input.erase(input.begin() + 0);
        getLetterWithDigitPermutations(input, op1);
        return;
    }
}

int main() {
    string input = "";
    string input1 = "";
    string output = "";
    string output1 = "";
    string output2 = "";
    cout << "Enter the input: ";
    cin >> input;
    input1 = input;
    // output.push_back(input[0]);
    // input.erase(input.begin() + 0);
    // cout << "Space Permutations are: " << endl;
    // getSpacePermutations(input, output);
    // cout << "Case Permutations are: " << endl;
    // getCasePermutations(input1, output1);
    cout << "Letter case permuations: " << endl;
    getLetterWithDigitPermutations(input, output);
    return 0;
}