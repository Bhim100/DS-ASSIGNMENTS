#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {1, 1, 1, 2, 2, 2, 3, 6, 5, 9, 70};
    int n = sizeof(arr) / sizeof(int);
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    cout << " distinct elements: " << s.size() << endl;
    return 0;
}
