#include <iostream>
#include <fstream>
#define f first
#define s second
#include <utility>
using namespace std;
int main()
{
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");
    char arr[10][10];
    pair<int,int>b,r,l;
    double area = 0;

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            fin>>arr[i][j];
            if(arr[i][j]=='B')
            {
                b.f = i;
                b.f++;
                b.s = j ;
                b.s++;            }
            else if(arr[i][j]=='R')
            {
                r.f = i;
                r.f++;
                r.s = i;
                r.s++;
            }
            else if(arr[i][j]=='L')
            {
                l.f = i;
                l.f++;
                l.s = j;
                l.s++;
            }
        }
    }

    area = abs((b.f *abs(r.s - l.s))+(r.f*abs(b.s -l.s))+(l.f*abs(b.s-r.s)));
    int res = abs(b.f-l.f)+abs(b.s-l.s)-1;
    if(!area)
    {
        fout<<res+2;
    }
    else
    {
        fout<<res;
    }

}
