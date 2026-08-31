#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> m;
    int maxFreq = 0;
    ll totalSum = 0;
    int mfVal = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        totalSum += a;
        m[a]++;
        if (m[a] > maxFreq)
        {
            maxFreq = m[a];
            mfVal = a;
        }
    }

    if (maxFreq > n - maxFreq)
    {
        totalSum -= 1LL * (n - (n - maxFreq + 2)) * mfVal;
    }

    cout << totalSum << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}