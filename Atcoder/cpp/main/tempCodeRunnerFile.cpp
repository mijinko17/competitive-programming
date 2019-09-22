#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int main()
{
    int n;
    int flag=0;
    int s;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> c;
    c.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        flag=0;
        s=c.size();
        for(int j=0;j<s;j++)
        {
            if(a[i]>c[j])
            {
                c[j]=a[i];
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            c.push_back(a[i]);
        }
    }
    cout<<c.size()<<endl;
}
