#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

/*
    if
        n = 1
        [1] x not possible

        n = 2
        [1, 2] or [2, 1] x not possible

        n = 3
        [1, 2, 3] or [1, 3, 2] or [2, 1, 3] or [2, 3, 1] or [3, 1, 2] or [3, 2, 1]

        n = 4
        [1, 2, 3, 4] or [1, 2, 4, 3] or [1, 3, 2, 4] or [1, 3, 4, 2] or [1, 4, 2, 3], [1, 4, 3, 2]
        [2, 1, 3, 4] x not possible

        n = 6
        [1, 2, 3, 4, 5, 6] or [1, 3, 5, 2, 4, 6]

        int n = 5;
        [1, 3, 5, 2, 4]


        int n = 5;
        [1, 2, 3, 4, 5]
        seen
        [t, _, t, _, t]
        ans
        [1, 3, 5 ]
        num = 1 -> 3 -> 5 -> 7 x;
        5 -> 3 x -> 2

        int n = 6;
        [1, 3, 5, 2, 4, 6]

        int n = 7
        [1, 3, 5, 7, 2, 4, 6]

        int n = 4
        [1, 3, 2, 4]

        n = 5
        1, 2, 3, 4, 5
        odd = 3
        even = 2
        1 3 5 2 4
        int n = 6
        int n = 9
        1 2 3 4 5 6 7 8 9
        odd = 5
        even = 4
        1 3 5 7 9 2 4 6 8

        i = 2 -> n / 2 ( 5 / 2 -> 2)

        // got the pattern

        n = 1;
        1 ans = 1
        n = 2;
        1 2 or 2 1
*/

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }

    int num = 2;
    int k = n / 2;
    for (int i = 0; i < k; i++)
    {
        cout << num << " ";
        num += 2;
    }

    num = 1;
    k = n % 2 == 0 ? n / 2 : (n / 2) + 1;
    for (int i = 0; i < k; i++)
    {
        cout << num << " ";
        num += 2;
    }
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