#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<int> vi;

int main()
{
    string s;
    getline(cin, s);

    vi characters(95);
    fo(i, 0, s.length())
    {
        characters[(int)s[i] - 32]++;
    }

    int max_occ_char = 0, count = 0;
    fo(i, 0, 95)
    {
        if (characters[i] > count)
        {
            count = characters[i];
            max_occ_char = i + 32;
        }
    }
    cout << (char)max_occ_char << " " << count << endl;

    return 0;
}