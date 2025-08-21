#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 10, 9, 8};
    int target;
    cout << "Enter number to search: ";
    cin >> target;
    int result = binarySearch(arr, target);
    if (result != -1)
        cout << "Found  at:" << result << endl;
    else
        cout << "Not found" << endl;
    return 0;
}