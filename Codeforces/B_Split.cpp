/*
 * ==========================================================
 * Name:         Adarsh Jha, Aka Mr. Fool
 * File:         B_Split.cpp
 * Date:         2026-06-13
 * Time:         23:15:37
 * ==========================================================
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    some a1 freq = 4 -> which is even can we break it down to odd yess like 3 + 1 both are odd
    for bigger even such as 12 we can do it like 11 + 1 so for any even we can divide it into both array in 1 and freq - 1 right ?

    and for odd if freq <= 3 put it in one of the array and if freq is some bigger odd no. like 17 can we divide it into 2 odd ?? if we can do it ans will be +1 more
    for  17 -> 1 + 16 x
            ->

            it simple like  even = odd + odd
                            odd = odd + even
                            even = even + even


    all i did above was wrong

    2nd approach
    i missed read that each array is of n size only means any subseq i add of odd should be under in array size of n only

    n = 2
    for 1 2 3 4 -> 2n elements
    [1 2 ] [3 4] both size 2 only

    for n = 6

    1 2 3 4 5 4 1 4 1 5 4 6 -> 2n elements
    sort -> 1 1 1 2 3 4 4 4 4 5 5 6
    [1 1 1 2 3 6]  [4 4 4 4 5 5]

    so i can maintain 2 array and in greedy way push the element which after + remain <= n size right?


    for
    n = 3
    5 5 5 5 5 5
    5 -> 6 times

    if freq > n
    then i have to divide it in part
    and i should divide it in odd part so it get counted in both array
    [5 5 5] [5 5 5]


    if freq if even which can;t be divide into 2 odd part then and also which is > n size then ans should ne 0


*/

void solve()
{
    ll n;
    cin >> n;
    unordered_map<ll, ll> m;
    ll v;
    for (ll i = 0; i < 2 * n; i++)
    {
        cin >> v;
        m[v]++;
    }

    vector<ll> a1;
    vector<ll> a2;

    for (auto &[k, v] : m)
    {
        if (v % 2 == 0)
        {
            if (v >= n)
            {
                cout << 0 << "\n";
                return;
            }
            else
            {
                // only take v - 1 part leave 1 for odd v for next arr
                if ((a1.size() + (v - 1)) < n)
                {
                    for (int i = 0; i < v - 1; i++)
                    {
                        a1.push_back(k);
                        m[k]--;
                    }
                }
                else
                {
                }
            }
        }
        else
        {
            if ((a1.size() + v) < n)
            {
                for (int i = 0; i < v; i++)
                {
                    a1.push_back(k);
                    m[k]--;
                }
            }
        }
    }

    for (auto &[k, v] : m)
    {
        if (v == 0)
        {
            continue;
        }
        if (a2.size() + v >= n)
        {
            cout << 0 << "\n";
            return;
        }
        if (v % 2 == 0)
        {
            if (v >= n)
            {
                cout << 0 << "\n";
                return;
            }
            else
            {
                for (int i = 0; i < v; i++)
                {
                    a2.push_back(k);
                }
            }
        }
        else
        {
            if ((a2.size() + v) < n)
            {
                for (int i = 0; i < v; i++)
                {
                    a2.push_back(k);
                }
            }
        }
    }

    cout << a1.size() + a2.size() << "\n";
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

/*
⣿⣿⣿⣿⣿⣷⣿⣿⣿⡅⡹⢿⠆⠙⠋⠉⠻⠿⣿⣿⣿⣿⣿⣿⣮⠻⣦⡙⢷⡑⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣌⠡⠌⠂⣙⠻⣛⠻⠷⠐⠈⠛⢱⣮⣷⣽⣿
⣿⣿⣿⣿⡇⢿⢹⣿⣶⠐⠁⠀⣀⣠⣤⠄⠀⠀⠈⠙⠻⣿⣿⣿⣦⣵⣌⠻⣷⢝⠦⠚⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢟⣻⣿⣊⡃⠀⣙⠿⣿⣿⣿⣎⢮⡀⢮⣽⣿⣿
⢿⣿⣿⣿⣧⡸⡎⡛⡩⠖⠀⣴⣿⣿⣿⠀⠀⠀⠀⠸⠇⠀⠙⢿⣿⣿⣿⣷⣌⢷⣑⢷⣄⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣫⠶⠛⠉⠀⠁⠀⠈⠈⠀⠠⠜⠻⣿⣆⢿⣼⣿⣿⣿
⢐⣿⣿⣿⣿⣧⢧⣧⢻⣦⢀⣹⣿⣿⣿⣇⠀⠄⠀⠀⠀⡀⠀⠈⢻⣿⣿⣿⣿⣷⣝⢦⡹⠷⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿⠈⠁⠀⠀⠀⠁⠀⠀⠀⠱⣶⣄⡀⠀⠈⠛⠜⣿⣿⣿⣿
⠀⠊⢫⣿⣏⣿⡌⣼⣄⢫⡌⣿⣿⣿⣿⣿⣦⡈⠲⣄⣤⣤⡡⢀⣠⣿⣿⣿⣿⣿⣿⣷⣼⣍⢬⣦⡙⣿⣿⣿⣿⣿⣯⢁⡄⠀⡀⡀⠀⠄⢈⣠⢪⠀⣿⣿⣿⣦⠀⢉⢂⠹⡿⣿⣿
⠀⠀⠄⢹⢃⢻⣟⠙⣿⣦⠱⢻⣿⣿⣿⣿⣿⣿⣷⣬⣍⣭⣥⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⡙⢿⣼⡿⣿⣿⣿⣿⣿⣷⣄⠘⣱⢦⣤⡴⡿⢈⣼⣿⣿⣿⣇⣴⣶⣮⣅⢻⣿⡏
⠀⠀⠈⠹⣇⢡⢿⡆⠻⣿⣷⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣍⡻⣿⣟⣻⣿⣿⣿⣿⣷⣦⣥⣬⣤⣴⣾⣿⣿⣿⣿⣷⣿⣿⣿⣿⣷⡜⠃
⠀⠀⠀⢀⣘⠈⢂⠃⣧⡹⣿⣷⡄⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⣅⡙⢿⣟⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⡕⠂
⠀⠀⠀⠀⠀⠀⠛⢷⣜⢷⡌⠻⣿⣿⣦⣝⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣹⣷⣦⣹⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠉⠃⠀
*/