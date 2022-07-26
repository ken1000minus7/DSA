#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

int main()
{
    FIO
    int n;
    cin>>n;
    int ans = 0;
    while(n>0)
    {
        n &= (n-1);
        ans++;
    }
    cout << ans << "\n";
    return 0;
}