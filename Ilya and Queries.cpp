#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();

    vector<int> pre(n, 0);
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + (s[i] == s[i - 1] ? 1 : 0);
    }
    
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        
        cout << pre[r - 1] - pre[l - 1] << endl;
    }
    
    return 0;
}
