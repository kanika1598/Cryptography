#include <iostream>
#include <cstring>
using namespace std;

void ceaser(char str1[80])
{
    int i = 0;
    while (i < strlen(str1))
    {
        str1[i] = int(str1[i]) + 3;
        i++;
    }
    cout << "Ceaser CIPHER\n";
    cout << str1 << endl;
}
void revceaser(char str1[80])
{
    int i = 0;
    while (i < strlen(str1))
    {
        str1[i] = int(str1[i]) - 3;
        i++;
    }
    cout << "Revers Ceaser CIER\n";
    cout << str1 << endl;
}
void reverse(char str[80])
{
    cout << "Reverse CIPHER\n";
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--)
        cout << str[i];
    cout << endl;
}
void rereverse(char str1[80])
{
    cout << "Decrypt Revers CIPHER\n";
    int length = strlen(str1);
    for (int i = 0; i <= length; i++)
        cout << str1[i];
    cout << endl;
}
int main()
{
    char str1[80];
    int i = 0;
    cout << "Enter The Message to Encrypt?\n";
    cin >> str1;
    ceaser(str1);
    reverse(str1);
    revceaser(str1);
    rereverse(str1);
    return 0;
}
