#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,cnt=0;
        cin>>l>>r;
        for(int i = l-1;i<r-1;i++)
        {
            if(s[i]==s[i+1])cnt++;
        }
        cout<<cnt<<endl;

    }
}
