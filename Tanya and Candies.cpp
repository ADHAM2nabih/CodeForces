#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long siz,cnt=0,even=0,odd=0,x,evn=0,od=0;
    cin>>siz;
    int a[siz];
    for(int i=0; i<siz; i++)
    {
        cin>>a[i];
        if(i%2==0)
        {
            even +=a[i];
        }
        else
        {
            odd +=a[i];
        }
    }

    x = odd ;
    odd = even ;
    even = x ;

    for(int i=0; i<siz; i++)
    {

        if(i%2==0)
        {
            odd -= a[i];
            if((odd+od)==(even+evn))
            {
                cnt++;
            }
            evn+=a[i];
        }
        else
        {
            even -= a[i];
            if((odd+od)==(even+evn))
            {
                cnt++;
            }
            od+=a[i];
        }
    }
    cout<<cnt;
}
