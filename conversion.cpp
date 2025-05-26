#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return -1;
}

// Infix to Postfix
void infixToPostfix(char infix[])
{
    stack<char> s;
    int i = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i++];

        if (isalnum(ch))
        {
            cout << ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(ch))
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                cout << s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

// Infix to Prefix
void infixToprefix(string infix)
{
    stack<char> s;
    string prefix;

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            prefix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(c))
        {
            while (!s.empty() && precedence(s.top()) > precedence(c))
            {
                prefix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    cout << prefix << endl;
}

// Prefix to Postfix    
void prefixToPostfix(string prefix)
{
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string result = op1 + op2 + c;
            s.push(result);
        }
    }
    cout << s.top() << endl;
}

// Prefix to Infix
void prefixToInfix(string prefix)
{
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string result = "(" + op1 + c + op2 + ")";
            s.push(result);
        }
    }
    cout << s.top() << endl;
}

// Postfix to Infix
void postfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string result = "(" + op1 + c + op2 + ")";
            s.push(result);
        }
    }
    cout << s.top() << endl;
}

// Postfix to Prefix
void postfixToPrefix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string result = c + op1 + op2;
            s.push(result);
        }
    }
    cout << s.top() << endl;
}

// Main Menu
int main()
{
    int choice;
    char infixExpr[30];
    string expr;

    do
    {
        cout << "\nExpression Conversion Menu";
        cout << "\n1. Infix to Postfix";
        cout << "\n2. Infix to Prefix";
        cout << "\n3. Prefix to Postfix";
        cout << "\n4. Prefix to Infix";
        cout << "\n5. Postfix to Infix";
        cout << "\n6. Postfix to Prefix";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter infix expression: ";
            cin.getline(infixExpr, 30);
            cout << "Postfix: ";
            infixToPostfix(infixExpr);
            break;
        case 2:
            cout << "Enter infix expression: ";
            cin.getline(infixExpr, 30);
            cout << "Prefix: ";
            infixToprefix(infixExpr);
            break;
        case 3:
            cout << "Enter prefix expression: ";
            getline(cin, expr);
            cout << "Postfix: ";
            prefixToPostfix(expr);
            break;
        case 4:
            cout << "Enter prefix expression: ";
            getline(cin, expr);
            cout << "Infix: ";
            prefixToInfix(expr);
            break;
        case 5:
            cout << "Enter postfix expression: ";
            getline(cin, expr);
            cout << "Infix: ";
            postfixToInfix(expr);
            break;
        case 6:
            cout << "Enter postfix expression: ";
            getline(cin, expr);
            cout << "Prefix: ";
            postfixToPrefix(expr);
            break;
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
