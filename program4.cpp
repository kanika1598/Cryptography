#include <iostream>
#include <cmath>
using namespace std;

int gcd(int, int);
int main()
{
    int p, q, e, n, phi_n, g, t, k, d, m, orig = 1, c = 1, i;
    char plain, text;
    cout << "\nENTER TWO PRIME NUMBERS p AND q=";
    cin >> p >> q;
    n = p * q;
    phi_n = (p - 1) * (q - 1);
    for (e = 2; e < n; e++)
    {
        g = gcd(phi_n, e);
        if (g == 1)
            break;
    }
    cout << "\nENCRYPTION KEY e=" << e;
    t = 1 % phi_n;
    for (d = 1; d < phi_n; d++)
    {
        k = (d * e) % phi_n;
        if (k == t)
            break;
    }
    cout << "\nDECRYPTION KEY d=" << d;
    cout << "\nENTER PLAIN TEXT CHARACTER POSITION(alphabets start with one) m=";
    cin >> m;
    for (i = 1; i <= e; i++)
    {
        c = (c * m) % n;
    }
    cout << "\nCIPHER TEXT IS=" << c;
    for (i = 1; i <= d; i++)
    {
        orig = (orig * c) % n;
    }
    cout << "\nORIGINAL PLAIN TEXT IS=" << orig;
    return 0;
}

int gcd(int a, int b)
{
    int gd;
    if (a == 0)
    {
        gd = 0;
        return (gd);
    }
    else if (b == 0)
    {
        gd = a;
        return (gd);
    }
    else
    {
        gd = gcd(b, a % b);
        return (gd);
    }
}
