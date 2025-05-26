#include<iostream>
using namespace std;

class sparse{
private:
    int row, col, term;
    int matrix[100][3];
public:
    sparse(){
        row = col = term = 0;
    }

    void read_mat(){
        cout << "Enter the number of rows and columns: ";
        cin >> row >> col;
        cout << "Enter the number of non-zero terms: ";
        cin >> term;

        matrix[0][0] = row;
        matrix[0][1] = col;
        matrix[0][2] = term;

        cout << "Enter the elements as row, column, value:\n";
        for (int i = 1; i <= term; i++) {
            cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
        }
    }

    void display_mat(){
        cout << "\nRow\tCol\tValue" << endl;
        for(int i = 0; i <= term; i++){
            cout << matrix[i][0] << '\t' << matrix[i][1] << '\t' << matrix[i][2] << endl;
        }
    }

    sparse add_sparse(const sparse &b) {
    sparse c;

    if (row != b.row || col != b.col) {
        cout << "Addition cannot be done due to size mismatch." << endl;
        return c; // Return empty matrix
    }

    c.row = row;
    c.col = col;

    int i = 1, j = 1, k = 1;

    while (i <= term && j <= b.term) {
        if (matrix[i][0] == b.matrix[j][0] && matrix[i][1] == b.matrix[j][1]) {
            int sum = matrix[i][2] + b.matrix[j][2];
            if (sum != 0) {
                c.matrix[k][0] = matrix[i][0];
                c.matrix[k][1] = matrix[i][1];
                c.matrix[k][2] = sum;
                k++;
            }
            i++; j++;
        }
        else if (matrix[i][0] < b.matrix[j][0] ||
                 (matrix[i][0] == b.matrix[j][0] && matrix[i][1] < b.matrix[j][1])) {
            c.matrix[k][0] = matrix[i][0];
            c.matrix[k][1] = matrix[i][1];
            c.matrix[k][2] = matrix[i][2];
            i++; k++;
        }
        else {
            c.matrix[k][0] = b.matrix[j][0];
            c.matrix[k][1] = b.matrix[j][1];
            c.matrix[k][2] = b.matrix[j][2];
            j++; k++;
        }
    }

    while (i <= term) {
        c.matrix[k][0] = matrix[i][0];
        c.matrix[k][1] = matrix[i][1];
        c.matrix[k][2] = matrix[i][2];
        i++; k++;
    }

    while (j <= b.term) {
        c.matrix[k][0] = b.matrix[j][0];
        c.matrix[k][1] = b.matrix[j][1];
        c.matrix[k][2] = b.matrix[j][2];
        j++; k++;
    }

    c.term = k - 1;
    c.matrix[0][0] = c.row;
    c.matrix[0][1] = c.col;
    c.matrix[0][2] = c.term;

    return c;
}


    sparse simple_transpose(){
        sparse b;
        b.row = col;
        b.col = row;
        b.term = term;

        int index = 1;
        for(int c = 0; c < col; c++){
            for(int i = 1; i <= term; i++){
                if(matrix[i][1] == c){
                    b.matrix[index][0] = matrix[i][1];
                    b.matrix[index][1] = matrix[i][0];
                    b.matrix[index][2] = matrix[i][2];
                    index++;
                }
            }
        }

        b.matrix[0][0] = b.row;
        b.matrix[0][1] = b.col;
        b.matrix[0][2] = b.term;
        return b;
    }

    sparse fast_transpose(){
        sparse b;
        b.row = col;
        b.col = row;
        b.term = term;

        int count[100] = {0}, start[100] = {0};

        for(int i = 1; i <= term; i++){
            count[matrix[i][1]]++;
        }

        start[0] = 1;
        for(int i = 1; i < col; i++){
            start[i] = start[i - 1] + count[i - 1];
        }

        for(int i = 1; i <= term; i++){
            int pos = start[matrix[i][1]]++;
            b.matrix[pos][0] = matrix[i][1];
            b.matrix[pos][1] = matrix[i][0];
            b.matrix[pos][2] = matrix[i][2];
        }

        b.matrix[0][0] = b.row;
        b.matrix[0][1] = b.col;
        b.matrix[0][2] = b.term;
        return b;
    }
};

int main() {
    sparse a, b, c;
    int ch;

    do {
        cout << "\nMENU";
        cout << "\n1. Read Matrix";
        cout << "\n2. Display Matrix";
        cout << "\n3. Add Two Sparse Matrices";
        cout << "\n4. Simple Transpose";
        cout << "\n5. Fast Transpose";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                a.read_mat();
                break;
            case 2:
                a.display_mat();
                break;
            case 3:
                cout << "Enter second matrix:\n";
                b.read_mat();
                c = a.add_sparse(b);
                cout << "\nResultant Matrix after Addition:\n";
                c.display_mat();
                break;

                break;
            case 4:
                b = a.simple_transpose();
                cout << "\nSimple Transpose:\n";
                b.display_mat();
                break;
            case 5:
                b = a.fast_transpose();
                cout << "\nFast Transpose:\n";
                b.display_mat();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 6);

    return 0;
}
