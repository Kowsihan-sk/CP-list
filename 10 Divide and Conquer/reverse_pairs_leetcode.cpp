/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define endl "\n"
#define f(a, b, c) for (ll i = a; i < b; i += c)

int merge(vector<int> &nums, int low, int mid, int high)
{
    int cnt = 0, j = mid + 1;
    for (int i = low; i < mid + 1; i++)
    {
        while (j <= high && (nums[i] > (2LL * nums[j])))
            j++;
        cnt += (j - (mid + 1));
    }

    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] > nums[right])
            temp.push_back(nums[right++]);
        else
            temp.push_back(nums[left++]);
    }
    while (left <= mid)
        temp.push_back(nums[left++]);
    while (right <= high)
        temp.push_back(nums[right++]);

    for (int i = low; i <= high; i++)
        nums[i] = temp[i - low];
    return cnt;
}

int mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return 0;
    int mid = (low + high) / 2;
    int inv = mergeSort(nums, low, mid);
    inv += mergeSort(nums, mid + 1, high);
    inv += merge(nums, low, mid, high);
    return inv;
}
int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    fast;

    ll n;
    cin >> n;

    vector<int> a(n);
    f(0, n, 1) cin >> a[i];
    cout << reversePairs(a) << endl;

    return 0;
}