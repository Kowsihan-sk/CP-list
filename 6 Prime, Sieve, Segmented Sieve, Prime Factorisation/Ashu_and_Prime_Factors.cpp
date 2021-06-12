/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<ll> vl;
const int N = (int)1e6 + 1;

vl prime(N, 1);
void sieve_min_pf()
{
    // sieve of eratosthenes
    fo(p, 2, N, 1)
    {
        ll count = 1;
        if (prime[p])
            f(p * p, N, p)
            {
                if (prime[i])
                    count++;
                prime[i] = 0;
            }
        prime[p] = count;
    }
}

int main()
{
    fast;
    sieve_min_pf();
    int TT;
    cin >> TT;

    while (TT--)
    {
        ll n;
        cin >> n;
        cout << prime[n] << "\n";
    }

    return 0;
}