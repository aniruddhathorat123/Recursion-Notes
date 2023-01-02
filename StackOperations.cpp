#include<iostream>
#include<stack>
using namespace std;

stack<int> createStack(stack<int> s, int size) {
    if (size == 0) {
        return s;
    }
    s.push(size);
    size--;
    return createStack(s, size);
}

// print the stack from bottom to top.
void printStackBotToTop(stack<int> s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    printStackBotToTop(s);
    cout << temp << endl;
}

// print stack from top to bottom.
void printStackTopToBot(stack<int> s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    cout << temp << endl;
    printStackTopToBot(s);
}

stack<int> delKthEle(stack<int> s, int k) {
    if (k == 1) {
        s.pop();
        return s;
    }
    int temp = s.top();
    s.pop();
    s = delKthEle(s, k - 1);
    s.push(temp);
    return s;
}

stack<int> delMidElement(stack<int> s, int size) {
    if (s.size() == 0) {
        return s;
    }
    int k = (size / 2) + 1;
    return delKthEle(s, k);
}

// Insert at end in stack.
void insertAtEnd(stack<int> &s, int ele) {
    if (s.size() == 0) {
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtEnd(s, ele);
    s.push(temp);
    return;
}

// revers the stack.
void reverseStack(stack<int> &s) {
    if (s.size() <= 1) {
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtEnd(s, temp);
    return;
}



int main() {
    stack<int> s;
    s = createStack(s, 5);
    printStackTopToBot(s);
    cout << "Top: " << s.top() << endl;
    //cout << "After deleting middle element: " << endl;
    //printStackTopToBot(delMidElement(s, 5));
    cout << "Reversed stack: " << endl;
    reverseStack(s);
    printStackTopToBot(s);
    return 0;
}
