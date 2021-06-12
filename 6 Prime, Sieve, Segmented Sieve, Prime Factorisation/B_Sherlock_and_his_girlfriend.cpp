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
const int N = (int)1e5 + 4;

vector<bool> prime(N, true);
void sieve_prime(ll n)
{
    // sieve of eratosthenes
    fo(p, 2, n, 1)
    {
        if (prime[p])
            f(p * p, n, p) prime[i] = false;
    }
}

int main()
{
    fast;
    int n;
    cin >> n;
    sieve_prime(n + 3);

    if (n <= 2)
        cout << "1\n";
    else
        cout << "2\n";

    f(2, n + 2, 1)
    {
        if (prime[i])
            cout << "1 ";
        else
            cout << "2 ";
    }

    return 0;
}