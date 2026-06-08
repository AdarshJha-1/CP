/*
 * ==========================================================
 * Name:         Adarsh Jha, Aka Mr. Fool
 * File:         Palindrome_Reorder.cpp
 * Date:         2026-06-08
 * Time:         16:05:09
 * ==========================================================
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// void solve()
// {
//     string str;
//     cin >> str;

//     unordered_map<char, int> m;
//     for (const auto &c : str)
//     {
//         m[c]++;
//     }

//     int num_f_feq_of_odd = 0;
//     priority_queue<pair<int, int>> pq;
//     for (auto const &[k, v] : m)
//     {
//         if (v & 1 != 0)
//         {
//             num_f_feq_of_odd++;
//             if (num_f_feq_of_odd > 1)
//             {
//                 cout << "NO SOLUTION\n";
//                 return;
//             }
//         }
//         pq.push({v, k});
//     }

//     if (num_f_feq_of_odd > 1)
//     {
//         cout << "NO SOLUTION\n";
//         return;
//     }

//     string new_str(str.size(), '.');
//     int i = 0;
//     int j = str.size() - 1;
//     // now that i done above check i really don;t see the requirement of pq :)

//     char odd_char = ' ';
//     ll odd_char_fq = 0;
//     while (!pq.empty())
//     {
//         auto [fq, ch] = pq.top();
//         pq.pop();
//         if (fq % 2 != 0)
//         {
//             odd_char = ch;
//             odd_char_fq = fq;
//             continue;
//         }
//         while (fq)
//         {
//             new_str[i++] = ch;
//             fq--;
//             new_str[j--] = ch;
//             fq--;
//         }
//     }

//     while (odd_char_fq && i <= j)
//     {
//         new_str[i++] = odd_char;
//         odd_char_fq--;
//     }
//     cout << new_str << "\n";
// }

// above one is so over-complicated fixing it :)
void solve()
{
    string str;
    cin >> str;

    int n = str.size();
    unordered_map<char, int> m;
    for (const auto &c : str)
    {
        m[c]++;
    }

    int i = 0;
    int j = n - 1;
    int num_f_feq_of_odd = 0;

    char odd_char = ' ';
    ll odd_char_fq = 0;

    string new_str(n, '.');
    for (auto [k, v] : m)
    {
        if (v & 1 != 0)
        {
            if (num_f_feq_of_odd + 1 > 1)
            {
                cout << "NO SOLUTION\n";
                return;
            }
            num_f_feq_of_odd++;
            odd_char = k;
            odd_char_fq = v;
            continue;
        }
        while (v)
        {
            new_str[i++] = k;
            v--;
            new_str[j--] = k;
            v--;
        }
    }

    while (odd_char_fq && i <= j)
    {
        new_str[i++] = odd_char;
        odd_char_fq--;
    }

    cout << new_str << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
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