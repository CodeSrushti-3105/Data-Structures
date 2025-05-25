#include<iostream>
#include<cstring>
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
};

void STRING::read() {
    cout << "Enter String: ";
    cin.ignore(); // Clear input buffer (important if you used cin >> before getline)
    getline(cin, str);
}

void STRING::display() {
    cout << "\nString is: " << str;
}

void STRING::checkocc(char ch) {
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    cout << "Occurrence of '" << ch << "' is: " << count;
}

void STRING::remove(char ch) {
    string result;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ch) {
            result += str[i];
        }
    }
    cout << "String after removing '" << ch << "': " << result;
}

void STRING::replace(char o, char n) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == o) {
            str[i] = n;
        }
    }
    cout << "\nString after replacement: " << str;
}

void STRING::extract(int start, int length) {
    if (start < 0 || start + length > str.length()) {
        cout << "Invalid start or length!";
        return;
    }
    string st = str.substr(start, length); // Better to use substr instead of manual loop
    cout << "Extracted string is: " << st;
}

void STRING::ispalindrome() {
    string st = string(str.rbegin(), str.rend()); // Reverse using rbegin/rend
    if (str == st) {
        cout << "String is a palindrome";
    } else {
        cout << "String is not a palindrome";
    }
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
            int start, length;
            cout << "\nEnter starting position and length of the string to extract: ";
            cin >> start >> length;
            s.extract(start, length);
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
