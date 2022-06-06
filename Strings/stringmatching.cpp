#include<iostream>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s2.length()>s1.length())
    {
        cout<<-1<<"\n";
        return 0;
    }
    // problem with algo, if some large prefix of s2 is same as a substring of s1 then lot of time is wasted in checking if s2 is actually is a substring and if not found we have to recompute everything fot the next index
    // very bad case example s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaa" s2="aaaaaaab"
    for(int i = 0;i + s2.length() - 1 < s1.length() ;i++)
    {
        int k = i;
        int j = 0;
        while(j<s2.length() && s1[k]==s2[j]) j++,k++;
        if(j==s2.length())
        {
            cout<<"Found at "<<i<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";
    return 0;
}