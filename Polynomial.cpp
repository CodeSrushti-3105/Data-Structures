#include <iostream>
using namespace std;

class Polynomial {
private:
    int coeff[100];
    int exp[100];
    int n;

public:
    Polynomial() {
        n = 0;
    }

    void readPolynomial() 
	{
        cout << "Enter the number of terms: ";
        cin >> n;
        for (int i = 0; i < n; i++) 
		{
            cout << "Enter coefficient for term " << i + 1 << ": ";
            cin >> coeff[i];
            cout << "Enter exponent for term " << i + 1 << ": ";
            cin >> exp[i];
        }
    }

    void displayPolynomial() 
	{
        cout << "Polynomial: ";
        for (int i = 0; i < n; i++) 
		{
            cout << coeff[i] << "x^" << exp[i];
            if (i != n - 1) cout << " + ";
        }
        cout << endl;
    }

    void addPolynomial() {
        Polynomial p2, result;
        cout << "\nEnter the second polynomial:\n";
        p2.readPolynomial();

        int i = 0, j = 0, k = 0;
        while (i < n && j < p2.n) 
		{
            if (exp[i] == p2.exp[j])
			 {
                result.coeff[k] = coeff[i] + p2.coeff[j];
                result.exp[k] = exp[i];
                i++; j++; k++;
            } else if (exp[i] > p2.exp[j])
			 {
                result.coeff[k] = coeff[i];
                result.exp[k] = exp[i];
                i++; k++;
            } else {
                result.coeff[k] = p2.coeff[j];
                result.exp[k] = p2.exp[j];
                j++; k++;
            }
        }

        while (i < n) {
            result.coeff[k] = coeff[i];
            result.exp[k] = exp[i];
            i++; k++;
        }

        while (j < p2.n) {
            result.coeff[k] = p2.coeff[j];
            result.exp[k] = p2.exp[j];
            j++; k++;
        }

        result.n = k;
        cout << "Resultant Polynomial after Addition:\n";
        result.displayPolynomial();
    }
};

int main() {
    Polynomial p;
    int choice;

    do {
        cout << "\n--- Polynomial Menu ---\n";
        cout << "1. Read Polynomial\n";
        cout << "2. Display Polynomial\n";
        cout << "3. Add Two Polynomials\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p.readPolynomial();
            break;
        case 2:
            p.displayPolynomial();
            break;
        case 3:
            p.addPolynomial();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

