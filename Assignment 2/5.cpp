#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> myStack;

    for (int i = 0; i < n; i++) {
        string key;
        cin >> key;

        if (key == "push") {
            int x;
            cin >> x;
            myStack.push(x);
        } else if (key == "pop") {
            if (!myStack.empty()) {
                myStack.pop();
            }
        }
    }


    stack<int> tempStack;
    while (!myStack.empty()) {
        tempStack.push(myStack.top());
        myStack.pop();
    }

    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }

    cout << endl;

    return 0;
}

