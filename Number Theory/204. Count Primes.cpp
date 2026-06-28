class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }
        vector<bool> sieve(n, true);
        sieve[0] = sieve[1] = false;
        for (int i = 4; i < n; i += 2)
        {
            sieve[i] = false;
        }
        for (int i = 3; i * i < n; i++)
        {
            if (sieve[i])
            {
                for (int j = i * i; j < n; j += 2 * i)
                {
                    sieve[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++)
        {
            count += sieve[i];
        }

        return count;
    }
};