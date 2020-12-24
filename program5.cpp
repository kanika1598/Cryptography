#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int n, g, x, y, k1, k2, A = 1, B = 1, a, b, K1 = 1, K2 = 1, i;
    cout << "ENTER TWO PRIME NUMBERS n AND g=";
    cin >> n >> g;
    cout << "\nCHOOSE A LARGE RANDOM NUMBER x=";
    cin >> x;
    for (i = 0; i < x; i++)
    {
        A = (A * g) % n;
    }
    cout << "\nCHOOSE ANOTHER RANDOM NUMBER y=";
    cin >> y;
    for (i = 0; i < y; i++)
    {
        B = (B * g) % n;
    }
    for (i = 0; i < x; i++)
    {
        K1 = (K1 * B) % n;
    }
    for (i = 0; i < y; i++)
    {
        K2 = (K2 * A) % n;
    }
    cout << "\nNUMBER SEND BY SENDER TO RECEIVER A=" << A;
    cout << "\nNUMBER SEND BY RECEIVER TO SENDER B=" << B;
    cout << "\nSECRET KEY COMPUTED BY SENDER K1=" << K1;
    cout << "\nSECRET KEY COMPUTED BY RECEIVER K2=" << K2;
    return 0;
}
