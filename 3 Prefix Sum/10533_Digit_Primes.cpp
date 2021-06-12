#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<ll> vll;
const int N = 1e6 + 2;

bool isPrime(ll n)
{
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

int digitSum(ll x)
{
    int temp = 0;
    while (x)
    {
        temp += x % 10;
        x /= 10;
    }
    return temp;
}

int main()
{
    int T;
    scanf("%d", &T);

    vll a(N);
    ll count = 0;
    fo(i, 0, N)
    {
        int tmp = digitSum(i);
        if (isPrime(tmp) && isPrime(i))
            count++;
        a[i] = count;
    }

    while (T--)
    {
        int l, r;
        cin >> l >> r;

        int count = a[r] - a[l - 1];
        printf("%d\n", count);
    }

    return 0;
}
