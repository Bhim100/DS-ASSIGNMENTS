#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int arr[100];

    while (true)
    {
        cout << "     MENU     " << endl;
        cout << "1.CREATE\n";
        cout << "2.DISPLAY\n";
        cout << "3.INSERT\n";
        cout << "4.DELETE\n";
        cout << "5.LINEAR SEARCH\n";
        cout << "6.EXIT\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter number of elements:";
            cin >> n;
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            break;
        }
        case 2:
        {
            if (n == 0)
            {
                cout << "Array is empty.\n";
            }
            else
            {
                cout << "Array elements: ";
                for (int i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        }
        case 3:
        {
            int pos, val;
            cout << "Enter position (1 to " << n + 1 << "): ";
            cin >> pos;
            if (pos < 1 || pos > n + 1)
            {
                cout << "Invalid position.\n";
            }
            else
            {
                cout << "Enter value: ";
                cin >> val;
                for (int i = n; i >= pos; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[pos - 1] = val;
                n++;
            }
            break;
        }
        case 4:
        {
            int pos;
            cout << "Enter position (1 to " << n << "): ";
            cin >> pos;
            if (pos < 1 || pos > n)
            {
                cout << "Invalid position.\n";
            }
            else
            {
                for (int i = pos - 1; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n--;
                cout << "Element deleted.\n";
            }
            break;
        }
        case 5:
        {
            int val, found = -1;
            cout << "Enter value to search: ";
            cin >> val;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == val)
                {
                    found = i;
                    break;
                }
            }
            if (found != -1)
                cout << "Element found at position " << found + 1 << endl;
            else
                cout << "Element not found.\n";
            break;
        }
        case 6:
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
