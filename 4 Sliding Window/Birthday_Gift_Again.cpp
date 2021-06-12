#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
#define pb push_back
#define F first
#define S second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
const int N = 1e2 + 3;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int a[n], s1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                s1 += 1;
            a[i] = s1;
        }
        long long c = 0;
        for (int j = 1; j * j + j <= n; j++)
        {
            int p = j * j + j;
            for (int i = 0; i < n - (p - 1); i++)
            {
                int cnt1 = a[i + p - 1] - a[i];
                if (i == 0)
                {
                    if (a[i] == 1)
                        cnt1++;
                }
                else
                {
                    if (a[i] != a[i - 1])
                        cnt1++;
                }
                if (cnt1 == j)
                {
                    c++;
                }
            }
        }
        cout << c << endl;
    }

    return 0;
}
