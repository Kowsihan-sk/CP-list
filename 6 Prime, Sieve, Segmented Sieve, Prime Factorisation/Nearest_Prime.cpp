/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
const int N = (int)1e6 + 4;

vector<bool> prime(N, true);
void sieve_prime()
{
    // sieve of eratosthenes
    fo(p, 2, N, 1)
    {
        if (prime[p])
            f(p * p, N, p) prime[i] = false;
    }
}

int main()
{
    sieve_prime();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TT;
    cin >> TT;

    while (TT--)
    {
        ll n, count = 0;
        cin >> n;
        f(0, N + 1, 1)
        {
            if ((n - i >= 2) && (prime[n - i]))
            {
                cout << n - i << "\n";
                break;
            }
            if ((n + i <= N) && (prime[n + i]))
            {
                cout << n + i << "\n";
                break;
            }
        }
    }

    return 0;
}