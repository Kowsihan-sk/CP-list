#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    int n, p;
    cin >> n >> p;

    vi light(p + 1);
    fo(i, 0, n)
    {
        int l, r;
        cin >> l >> r;

        if (l - r >= 0)
            light[l - r]++;
        else
            light[0]++;

        if (l + r + 1 <= p)
            light[l + r + 1]--;
    }

    fo(i, 1, p + 1)
    {
        light[i] += light[i - 1];
    }

    int meh = 0, msf = 0;
    fo(i, 0, p + 1)
    {
        if (light[i] != 1 && i <= p)
            meh++;
        else
            meh = 0;

        if (msf < meh)
            msf = meh;
    }

    cout << msf << endl;

    return 0;
}