#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> st;
    string str, reversed;

    cout << "Enter string: ";
    getline(cin, str);  // Read full line including spaces

    // Push characters into stack using while loop
    int i = 0;
    while (str[i] != '\0') {
        st.push(str[i]);
        i++;
    }

    // Pop characters to form the reversed string
    cout << "\nReversed string is: ";
    while (!st.empty()) {
        char ch = st.top();
        cout << ch;
        reversed += ch;
        st.pop();
    }

    // Check if the original string is the same as reversed
    if (str == reversed) {
        cout << "\n\nThe string is a palindrome." << endl;
    } else {
        cout << "\n\nThe string is NOT a palindrome." << endl;
    }

    return 0;
}

