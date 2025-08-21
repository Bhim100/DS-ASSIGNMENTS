#include <bits/stdc++.h>

using namespace std;

void reverse(int arr[], int n)

{

    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - 1 - i]);
    }
}

void multiply(int arr1[][3], int arr2[][2], int r1, int r2, int c1, int c2, int C[][2])
{

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)

        {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                C[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void transpose(int arr[2][3], int trans[3][2])
{

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            trans[j][i] = arr[i][j];
        }
    }
}

int main()
{
    int arr1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    int trans[3][2];
    transpose(arr1, trans);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}