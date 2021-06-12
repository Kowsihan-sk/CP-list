#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    int n, m;
    cin >> n >> m;

    vii a(n), b(n);
    fo(i, 0, n)
    {
        a[i] = vi(m);
        b[i] = vi(m);
        fo(j, 0, m)
        {
            cin >> a[i][j];
            b[i][j] = 1;
        }
    }

    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            if (!a[i][j])
            {
                fo(k, 0, n) b[k][j] = 0;
                fo(k, 0, m) b[i][k] = 0;
            }
        }
    }

    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            int temp = 0;
            fo(k, 0, n) temp |= b[k][j];
            fo(k, 0, m) temp |= b[i][k];
            if (temp != a[i][j])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}