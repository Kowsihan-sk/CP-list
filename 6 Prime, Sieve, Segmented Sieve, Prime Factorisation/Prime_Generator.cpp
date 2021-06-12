/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
const int N = 1e8 + 1;

bool isPrime(ll n)
{
    // 6n - 1 and 6n + 1
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void prime_soe(vector<bool> &prime)
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
    int TT;
    cin >> TT;

    while (TT--)
    {
        ll n, m;
        cin >> n >> m;
        f(n, m + 1, 1)
        {
            if (isPrime(i))
                cout << i << endl;
        }
        cout << endl;
    }

    return 0;
}