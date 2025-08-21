#include <bits/stdc++.h>

using namespace std;

int main()
{

	int arr[] = {1, 2, 3, 3, 2, 1, 4, 5, 6};
	int n = sizeof(arr) / sizeof(int);

	int newarr[n];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		int found = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			newarr[k] = arr[i];
			k++;
		}
	}

	for (int i = 0; i < k; i++)
	{
		cout << newarr[i] << endl;
	}

	return 0;
}