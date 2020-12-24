#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int n, a, p[100], c[100][100], k[100], i, j, m[100][100], x, d, e, f;
    cout << "\nENTER PLAIN TEXT SIZE=";
    cin >> n;
    cout << "\nENTER PLAIN TEXT=";
    for (i = 1; i <= n; i++)
        cin >> p[i];
    cout << "\nENTER BLOCK SIZE=";
    cin >> a;
    d = n % a;
    x = 1;
    e = (n / a);
    if (d != 0)
        e = e + 1;
    if (d != 0)
    {
        for (i = 1; i <= d; i++)
            p[n + i] = 0;
    }
    for (i = 1; i <= e; i++)
    {
        for (j = 1; j <= a; j++)
        {
            m[i][j] = p[x];
            x++;
        }
    }
    cout << "\nENTER KEY(of block size)=";
    for (i = 1; i <= a; i++)
        cin >> k[i];
    for (i = 1; i <= e; i++)
    {
        for (j = 1; j <= a; j++)
        {
            f = k[j];
            c[i][j] = m[i][f];
        }
    }
    cout << "\nCIPHER TEXT IS=";
    for (i = 1; i <= e; i++)
    {
        for (j = 1; j <= a; j++)
        {
            cout << " " << c[i][j];
        }
    }
    return 0;
}
