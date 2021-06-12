#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
typedef vector<ll> vl;
#define pb push_back

vl riddle(vl arr)
{
    // complete this function
    vl s;
    map<ll, ll> hm;
    s.pb(-1);

    f(0, Size(arr), 1)
    {
        if (s.back() == -1 || arr[s.back()] <= arr[i])
        {
            s.pb(i);
        }
        else
        {
            while (!s.empty() && arr[s.back()] > arr[i])
            {
                ll top = s.back();
                s.pop_back();
                if (hm.find(arr[top]) == hm.end())
                {
                    hm[arr[top]] = i - s.back() - 1;
                }
                else
                {
                    if (hm[arr[top]] < i - s.back() - 1)
                        hm[arr[top]] = i - s.back() - 1;
                }
                if (s.back() == -1)
                    break;
            }
            s.pb(i);
        }
    }
    while (!s.empty())
    {
        if (s.back() == -1)
        {
            s.pop_back();
            break;
        }
        ll top = s.back();
        s.pop_back();
        if (hm.find(arr[top]) == hm.end())
        {
            hm[arr[top]] = Size(arr) - s.back() - 1;
        }
        else
        {
            if (hm[arr[top]] < Size(arr) - s.back() - 1)
                hm[arr[top]] = Size(arr) - s.back() - 1;
        }
    }

    map<ll, ll> rhm;
    for (auto itr = hm.begin(); itr != hm.end(); itr++)
    {
        // cout << itr->first << " " << itr->second << endl;
        if (rhm.find(itr->second) == rhm.end())
        {
            rhm[itr->second] = itr->first;
        }
        else
        {
            if (rhm[itr->second] < itr->first)
                rhm[itr->second] = itr->first;
        }
    }

    ll t = Size(arr);
    for (auto itr = rhm.rbegin(); itr != rhm.rend();)
    {
        // cout << itr->first << " " << itr->second << endl;
        ll x = itr->first, y = itr->second;
        itr++;
        while (t > 0 && ((itr == rhm.rend()) || (t != itr->first)))
        {
            s.pb(y);
            t--;
        }
    }

    reverse(all(s));
    // f(0, Size(a), 1) cout << s[i] << endl;

    return s;
}

void ans(vl a)
{
    ll n = Size(a), i;

    stack<int> s;
    // int left[n], right[n], ans[n + 1], len;
    ll len;
    vl left(n), right(n), ans(n + 1);

    for (i = 0; i < n; ++i)
    {
        left[i] = -1, right[i] = n;
    }

    for (i = 0; i < n; ++i)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            left[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            right[i] = s.top();
        }
        s.push(i);
    }

    // memset(ans, 0, sizeof ans);
    for (i = 0; i < n; ++i)
    {
        len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }
    // f(1, n + 1, 1) cout << ans[i] << " " << endl;
    // cout << endl;

    for (i = n - 1; i >= 1; --i)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (i = 1; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    ll n;
    cin >> n;
    vl a(n);
    f(0, n, 1) cin >> a[i];
    // a = riddle(a);
    // f(0, n, 1) cout << a[i] << " ";
    ans(a);

    return 0;
}