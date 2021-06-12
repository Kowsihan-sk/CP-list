/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
const int N = 1e8 + 1;

int main()
{
    vector<bool> prime(N, true);

    // sieve of eratosthenes
    fo(p, 2, N, 1)
    {
        if (prime[p])
            f(p * p, N, p) prime[i] = false;
    }

    ll count = 0;
    f(2, N, 1)
    {
        if (prime[i])
            count++;
        if (count % 100 == 1 && prime[i])
        {
            cout << i << endl;
            count = 1;
        }
    }

    return 0;
}