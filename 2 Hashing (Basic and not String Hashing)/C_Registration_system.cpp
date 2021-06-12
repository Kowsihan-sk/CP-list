#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)

int main()
{
    map<string, int> dict;
    int n;
    cin >> n;

    fo(i, 0, n)
    {
        string temp;
        cin >> temp;

        dict[temp]++;
        if (dict[temp] == 1)
        {
            cout << "OK" << endl;
            continue;
        }

        cout << temp << dict[temp] - 1 << endl;
    }
    return 0;
}