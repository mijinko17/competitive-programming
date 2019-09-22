#include <iostream>
#include <vector>
using namespace std;

int powmod(int a, int n, int p)
{
    long long int temp;

    if (n == 1)
    {
        return a;
    }
    else
    {
        temp = powmod(a, n / 2, p);
        if (n % 2 == 0)
        {
            return (temp * temp) % p;
        }
        else
        {
            return (((temp * temp) % p) * a) % p;
        }
    }
}

int inv(int a, int p)
{
    return powmod(a, p - 2, p);
}

int main()
{
    int n, k;
    long long int ans;
    long long int p = 1000000007;
    cin >> n >> k;
    ans = n - k + 1;
    cout << ans << endl;
    for (int i = 2; i <= k; i++)
    {
        if (k >= i && k <= n - i + 1)
        {
            ans = (ans * (n - k + 2 - i)) % p;
            ans = (ans * (k - i + 1)) % p;
            ans = (ans * inv(i, p)) % p;
            ans = (ans * inv(i - 1, p)) % p;
            cout << ans << endl;
        }
        else
        {
            cout << '0' << endl;
        }
    }
}