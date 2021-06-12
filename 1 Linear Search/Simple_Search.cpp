#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<int> vi;

int main()
{
    int n;
    cin >> n;

    vi a(n);
    fo(i, 0, n)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    fo(i, 0, n)
    {
        if(a[i] == k)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}