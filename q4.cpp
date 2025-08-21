#include <bits/stdc++.h>
using namespace std;

void concatenate(char str1[], char str2[])
{
    int i = 0, j = 0;

    while (str1[i] != '\0')
    {
        i++;
    }

    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';
}

void reverseString(char str[])
{
    int n = strlen(str);

    for (int i = 0; i < n / 2; i++)
    {

        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void removeVowels(char str[])
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

void sortStrings(char arr[][50], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                char temp[50];

                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

char toLowercase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + 32;
    }
    return ch;
}
int main()
{

    char c = 'H';

    char lower = toLowercase(c);
    cout << lower;
}
