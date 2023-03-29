#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

int main()
{
    FIO
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> sqdecomp;
    int b = sqrt(n);
    if(b * b != n) b++;
    int sz = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        sz++;
        if(sz == b || i == n - 1) {
            sqdecomp.push_back(sum);
            sum = 0;
            sz = 0;
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        int i = l;
        while(i <= r) {
            if(i % b == 0 && i + b - 1 <= r) {
                ans += sqdecomp[i / b];
                i += b;
            }
            else {
                ans += arr[i];
                i++;
            }
        } 
        cout << ans << "\n";
    }
    return 0;
}