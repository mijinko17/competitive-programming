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
    int n;
    vector<vector<int>> t={{7,2},{3,4},{5,9}};
    vector<vector<int>>::iterator itr;
    itr=t.begin();
    for(vector<vector<int>>::iterator i=t.begin();i!=t.end();++i)
    {
        cout<<(*i)[1]<<endl;
    }
}