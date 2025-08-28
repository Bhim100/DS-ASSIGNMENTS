#include <iostream>
using namespace std;

class Triplet {
public:
    int row, col, val;
};

class SparseMatrix {
public:
    int rows, cols, terms;
    Triplet data[100];   

    SparseMatrix(int r=0, int c=0, int t=0) {
        rows = r; cols = c; terms = t;
    }

    void input() {
        cout << "Enter rows, cols, non-zero terms: ";
        cin >> rows >> cols >> terms;
        if (terms > (rows * cols) / 2) {
            cout << "Not a sparse matrix.\n";
            exit(0);
        }
        cout << "Enter row col value for each non-zero term:\n";
        for (int i = 0; i < terms; i++) {
            cin >> data[i].row >> data[i].col >> data[i].val;
        }
        
        
    }

    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i < terms; i++) {
            cout << data[i].row << " " << data[i].col << " " << data[i].val << "\n";
        }
    }

    void transpose() {
        
        swap(rows, cols);

        
        for (int i = 0; i < terms; i++) {
            swap(data[i].row, data[i].col);
        }

       
        for (int i = 0; i < terms - 1; i++) {
            for (int j = i + 1; j < terms; j++) {
                if (data[i].row > data[j].row ||
                   (data[i].row == data[j].row && data[i].col > data[j].col)) {
                    swap(data[i], data[j]);
                }
            }
        }
    }

    void add(const SparseMatrix &b, SparseMatrix &result) {
        if (rows != b.rows || cols != b.cols) {
            cout << " dimensions do not match for addition.\n";
            exit(0);
        }

        result.rows = rows;
        result.cols = cols;
        result.terms = 0;

        int i = 0, j = 0;
        while (i < terms && j < b.terms) {
            if (data[i].row < b.data[j].row || 
               (data[i].row == b.data[j].row && data[i].col < b.data[j].col)) {
                result.data[result.terms++] = data[i++];
            } else if (data[i].row > b.data[j].row || 
                      (data[i].row == b.data[j].row && data[i].col > b.data[j].col)) {
                result.data[result.terms++] = b.data[j++];
            } else {
                int summedVal = data[i].val + b.data[j].val;
                if (summedVal != 0) {
                    result.data[result.terms++] = {data[i].row, data[i].col, summedVal};
                }
                i++; j++;
            }
        }

        while (i < terms) {
            result.data[result.terms++] = data[i++];
        }
        while (j < b.terms) {
            result.data[result.terms++] = b.data[j++];
        }
    }

   void multiply(const SparseMatrix &b, SparseMatrix &result) {
    if (cols != b.rows) {
        cout << "dimensions do not match for multiplication.\n";
        exit(0);
    }

    // make a transposed copy of b
    SparseMatrix B_T = b;
    B_T.transpose();

    result.rows = rows;
    result.cols = b.cols;
    result.terms = 0;

    for (int i = 0; i < terms; i++) {
        int r = data[i].row;
        for (int j = 0; j < B_T.terms; j++) {
            int c = B_T.data[j].row;

            if (data[i].col == B_T.data[j].col) {
                int pos = -1;

                // check if entry (r,c) already exists
                for (int k = 0; k < result.terms; k++) {
                    if (result.data[k].row == r && result.data[k].col == c) {
                        pos = k;
                        break;
                    }
                }

                if (pos == -1) {
                    result.data[result.terms++] = {r, c, data[i].val * B_T.data[j].val};
                } else {
                    result.data[pos].val += data[i].val * B_T.data[j].val;
                }
            }
        }
    }
}

   


}; 

int main() {
    

    

    return 0;
}
