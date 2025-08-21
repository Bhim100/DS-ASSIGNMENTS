#include <iostream>

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    int expected_sum = (n + 1) * (n + 2) / 2;
    int actual_sum = 0;
    for (int i = 0; i < n; i++)
    {
        actual_sum += arr[i];
    }
    int missing = expected_sum - actual_sum;
    std::cout << "Missing number: " << missing << std::endl;
    return 0;
}
