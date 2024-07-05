#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool bnry_srch(vector<long>&v,long qr)
{
    int low=0,high=v.size()-1;
    while(low<=high)
    {
        int mid = (low+high) /2;
        if(v[mid]>qr)
        {
            high = mid-1;
        }
        else if(v[mid]<qr)
        {
            low = mid+1;
        }
        else
        {
            return true;
        }
    }
    return false;

}

long lwr_bnd(vector<long>&v,long qr)
{
    long tmp =-1;
    int high=v.size()-1,low=0;
    while(low<=high)
    {
        int mid = (low+high) /2;
        if(v[mid]>=qr)
        {
            tmp = v[mid];
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return tmp;
}
long upr_bnd(vector<long>&v,long qr)
{
    long tmp =-1;
    int high=v.size()-1,low=0;
    while(low<=high)
    {
        int mid = (low+high) /2;
        if(v[mid]>qr)
        {
            tmp = v[mid];
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return tmp;
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<long>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    sort(v.begin(),v.end());
    while(q--)
    {
        string s;
        long query;
        cin>>s>>query;
        if(s=="binary_search")
        {
            if(bnry_srch(v,query))cout<<"found"<<endl;
            else  cout<<"not found"<<endl;

        }
        else if(s=="lower_bound")
        {
            cout<<lwr_bnd(v,query)<<endl;
        }
        else
        {
            cout<<upr_bnd(v,query)<<endl;
        }

    }

}
