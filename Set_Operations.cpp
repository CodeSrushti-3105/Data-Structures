
#include<iostream>
#include<string>
using namespace std;

class Set {
    string s[20];
    int n;

public:
    void read_set();
    void display_set();
    Set intersection(Set);
    Set union_set(Set);
    Set difference(Set);
};

void Set::read_set() {
    cout << "\nEnter number of Students: ";
    cin >> n;
    cout << "Enter Student Names: ";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
}

void Set::display_set() {
    cout << "{";
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "}";
}

Set Set::intersection(Set B) {
    Set T;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < B.n; j++) {
            if (s[i] == B.s[j]) {
                T.s[k++] = s[i];
                break;
            }
        }
    }
    T.n = k;
    return T;
}

Set Set::union_set(Set B) {
    Set T;
    int k = 0;
    for (int i = 0; i < n; i++) {
        T.s[k++] = s[i];
    }
    for (int i = 0; i < B.n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (B.s[i] == s[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            T.s[k++] = B.s[i];
        }
    }
    T.n = k;
    return T;
}

Set Set::difference(Set B) {
    Set T;
    int k = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < B.n; j++) {
            if (s[i] == B.s[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            T.s[k++] = s[i];
        }
    }
    T.n = k;
    return T;
}

int main() {
    Set CC, PC, PP, MM;
    Set result;
    int choice;

    cout << "\n--- Enter Details for Coding Contest ---";
    CC.read_set();
    CC.display_set();

    cout << "\n\n--- Enter Details for Project Competition ---";
    PC.read_set();
    PC.display_set();

    cout << "\n\n--- Enter Details for Paper Presentation ---";
    PP.read_set();
    PP.display_set();

    cout << "\n\n--- Enter Details for MasterMind ---";
    MM.read_set();
    MM.display_set();

    do {
        cout << "\n\n=== MENU ===";
        cout << "\n1. Participants in both Coding and Project";
        cout << "\n2. Participants in Coding OR Project OR Mastermind";
        cout << "\n3. Participants in Coding but not in Mastermind";
        cout << "\n4. Participants in ALL events";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                result = CC.intersection(PC);
                cout << "\nParticipants in both Coding and Project: ";
                result.display_set();
                break;

            case 2:
                result = CC.union_set(PC);
                result = result.union_set(MM);
                cout << "\nParticipants in Coding OR Project OR Mastermind: ";
                result.display_set();
                break;

            case 3:
                result = CC.difference(MM);
                cout << "\nParticipants in Coding but NOT in Mastermind: ";
                result.display_set();
                break;

            case 4:
                result = CC.intersection(PC);
                result = result.intersection(PP);
                result = result.intersection(MM);
                cout << "\nParticipants in ALL events: ";
                result.display_set();
                break;

            case 5:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice! Try again.";
        }
    } while (choice != 5);

    return 0;
}
