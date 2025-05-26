#include <iostream>
using namespace std;

#define MAX 100

// User-defined stack class for characters
class CharStack {
    char arr[MAX];
    int top;

public:
    CharStack() {
        top = -1;
    }

    void push(char ch) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    CharStack st;
    string str, reversed;

    cout << "Enter string: ";
    getline(cin, str);  // Read full line including spaces

    // Push each character into the user-defined stack
    int i = 0;
    while (str[i] != '\0') {
        st.push(str[i]);
        i++;
    }

    // Pop from stack and form reversed string
    cout << "\nReversed string is: ";
    while (!st.isEmpty()) {
        char ch = st.pop();
        cout << ch;
        reversed += ch;
    }

    // Check for palindrome
    if (str == reversed) {
        cout << "\n\nThe string is a palindrome." << endl;
    } else {
        cout << "\n\nThe string is NOT a palindrome." << endl;
    }

    return 0;
}
