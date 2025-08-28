#include <bits/stdc++.h>
using namespace std;

void Diagonal(int arr[], int n) {

    int A[100][100] = {0};  

    for (int i = 0; i < n; i++) {
        A[i][i] = arr[i];  
    }

    // Print the diagonal matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}


void Tridiagonal(int arr[], int n) {
    int A[100][100] = {0}; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { 
                
                A[i][j] = arr[i];  
            } 
            else if (i == j + 1) { 
                
                A[i][j] = arr[n -1+i];  
            } 
            else if (i == j -1) { 
                
                A[i][j] = arr[2*n +i-1];  
            } 
            
        }
    }

    // Print full matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void LowerTriangular(int arr[], int n) {
    int A[100][100] = {0}; 
    int k = 0; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) { 
            A[i][j] = arr[k];
            k++;
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void UpperTriangular(int arr[], int n) {
    int A[100][100] = {0}; 
    int k = 0; 

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { 
            A[i][j] = arr[k++];
        }
    }

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void Symmetric(int arr[], int n) {
    int A[100][100] = {0};

    int k = 0; 

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            A[i][j] = arr[k++];
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            A[i][j] = A[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
   
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    Symmetric(arr, 3);
    return 0;
}


