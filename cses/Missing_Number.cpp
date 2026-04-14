#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long t_sum = 0, ac_sum = 0;
    t_sum = n * (n + 1) / 2;

    for (int i = 0; i < n; i++)
    {
        int val = 0;
        cin >> val;
        ac_sum += val;
    }
    cout << t_sum - ac_sum << "\n";
    return 0;
}