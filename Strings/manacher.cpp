#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

int main()
{
    FIO
    string s;
    cin>>s;
    int a = 0;
    // add # in between characters to handle even length substrings
    string man = "#";
    for(int i=0;i<s.length();i++)
    {
        man += s[i];
        man += "#";
    }
    // range of current center
    int r = 0;
    // current center
    int c = 0;
    // range of langest pali centered at ith index
    vector<int> pali(man.length());

    for(int i=0;i<man.length();i++)
    {
        // mirror of element around the current center
        int mirror = 2*c - i;
        // if i is within range of current center begin with the mirror's pali 
        if(i<r)
        {
            pali[i] = min(pali[mirror],r-i);
        }
        int j = 0;
        // start expanding till it remains a pali
        while(i-pali[i]>0 && i+pali[i]<man.length()-1 & man[i-pali[i]-1]==man[i+pali[i]+1])
        {
            pali[i]++;
        }
        // if exceeded the range of current center, update the center
        if(i+pali[i]>r)
        {
            c = i;
            r = i + pali[i];
        }
        // a stores index which has largest pali centered at it
        if(pali[i]>pali[a]) a = i;
    }
    
    string ans = "";
    // get the pali string centered at a
    for(int i=a-pali[a];i<=a+pali[a];i++)
    {
        if(man[i]!='#') ans+=man[i];
    }
    cout<<ans<<"\n";
    return 0;
}