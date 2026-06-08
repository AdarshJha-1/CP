#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

// void solve()
// {
//     string s;
//     cin >> s;

//     int ans = 0;

//     int i = 0;
//     int j = 0;
//     int currCount = 0;
//     while (j <= s.size())
//     {
//         if (s[i] == s[j])
//         {
//             currCount++;
//             j++;
//         }
//         else
//         {
//             ans = max(ans, currCount);
//             currCount = 0;
//             i = j;
//         }
//     }

//     cout << ans << endl;
// }

void solve()
{
    string s;
    cin >> s;

    int ans = 1;
    int curr = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            curr++;
        }
        else
        {
            ans = max(ans, curr);
            curr = 1;
        }
    }
    ans = max(ans, curr);

    cout << ans << endl;
}
int32_t main()
{
    fast_io;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}