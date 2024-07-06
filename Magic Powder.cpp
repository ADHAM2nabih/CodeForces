#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k,tmp;
    cin>>n>>k;
    tmp=k;
    vector<ll>need(n),ingr(n);
    for(int i=0; i<n; i++)cin>>need[i];
    for(int i=0; i<n; i++)cin>>ingr[i];

    ll low=0,high=2e9+2,answer=0;
    while(low<=high)
    {
        ll mid = low+(high-low)/2,flag=1;
        for(int i=0; i<n; i++)
        {
            ll df = need[i]*mid-ingr[i];

            if( df>0 )tmp-=df;
            if(tmp<0) flag=0;
        }

        if(flag)
        {
            answer = mid;
            low = mid+1;
        }
        else high = mid-1;
        flag = 1;
        tmp=k;
    }
    cout<<answer;
}
