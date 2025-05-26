#include<iostream>
using namespace std;

class STRING {
    string str;

public:
    void read();
    void display();
    void checkocc(char ch);
    void extract(int s, int l);
    void remove(char ch);
    void replace(char o, char n);
    void ispalindrome();
    int length(); // User-defined length function
};

void STRING::read() {
    cout << "Enter String: ";
    cin.ignore();
    getline(cin, str);
}

void STRING::display() {
    cout << "\nString is: " << str;
}

int STRING::length() {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void STRING::checkocc(char ch) {
    int count = 0;
    for (int i = 0; i < length(); i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    cout << "Occurrence of '" << ch << "' is: " << count;
}

void STRING::remove(char ch) {
    string result = "";
    for (int i = 0; i < length(); i++) {
        if (str[i] != ch) {
            result += str[i];
        }
    }
    cout << "String after removing '" << ch << "': " << result;
}

void STRING::replace(char o, char n) {
    for (int i = 0; i < length(); i++) {
        if (str[i] == o) {
            str[i] = n;
        }
    }
    cout << "\nString after replacement: " << str;
}

void STRING::extract(int start, int len) {
    if (start < 0 || start + len > length()) {
        cout << "Invalid start or length!";
        return;
    }

    string st = "";
    for (int i = start; i < start + len; i++) {
        st += str[i];
    }
    cout << "Extracted string is: " << st;
}

void STRING::ispalindrome() {
    int len = this->length();

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            cout << "The string is NOT a palindrome." << endl;
            return;
        }
    }

    cout << "The string is a palindrome." << endl;
}

int main() {
    char ch;
    STRING s;
    int choice;

    s.read();
    s.display();

    do {
        cout << "\n\n** MENU **";
        cout << "\n1. Check occurrence of particular character in string";
        cout << "\n2. Extract a new string from original string";
        cout << "\n3. Remove all occurrences of a particular character";
        cout << "\n4. Replace a character";
        cout << "\n5. Check whether string is palindrome or not";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter character to check occurrence: ";
                cin >> ch;
                s.checkocc(ch);
                break;

            case 2: {
                int start, len;
                cout << "\nEnter starting position and length of the string to extract: ";
                cin >> start >> len;
                s.extract(start, len);
                break;
            }

            case 3:
                cout << "\nEnter character to remove from string: ";
                cin >> ch;
                s.remove(ch);
                break;

            case 4: {
                char o, n;
                cout << "\nEnter old character and new character to replace: ";
                cin >> o >> n;
                s.replace(o, n);
                break;
            }

            case 5:
                s.ispalindrome();
                break;

            case 6:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice.";
        }

    } while (choice != 6);

    return 0;
}
