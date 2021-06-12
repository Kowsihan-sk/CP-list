#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<int> vi;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vi a(n), h_map(1001);
        fo(i, 0, n)
        {
            cin >> a[i];
            h_map[a[i]]++;
        }

        int count = 0;
        fo(i, 1, 1001)
        {
            fo(j, i, 1001)
            {
                int s, c;
                s = sqrt(i + j);
                c = cbrt(i + j);
                if ((i + j) == s * s || (i + j) == c * c * c)
                {
                    if (i == j)
                        count += h_map[i] * (h_map[i] - 1) / 2;
                    else
                        count += h_map[i] * h_map[j];
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}