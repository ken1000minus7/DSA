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
    // longest prefix suffix, storing if the suffix of the substring ending at jth index is also a prefix of it
    // this will allow us to check from the prefix instead of the starting of the string
    // and instead of bringing back i, we can continue i from its current position as we have already checked the previous elements whether they are present or not using lps
    int lps[s2.length()+1] = {0};
    int t = 0;
    int j = 1;
    while(j<s2.length())
    {
        if(s2[j]==s2[t])
        {
            lps[j+1] = ++t;
            j++;
        }
        else if(t!=0) t=lps[t-1];
        else j++;
    }
    int i=0;
    j=0;
    while(i<s1.length())
    {
        // if there is a match we move both i and j forward
        if(s1[i]==s2[j])
        {
            i++;
            j++;
            // if j reached the end, then answer is found
            if(j==s2.length())
            {
                cout<<"Found at "<<(i-s2.length())<<"\n";
                return 0;
            }
        }
        // if j is still at the beginning of the string, no prefix is present behind i so we will just move forward
        else if(j==0) i++;
        // if there is a prefix present which matches with the current suffix we return back to it instead of returning to the starting of the string
        else
        {
            j = lps[j];
        }
    }
    cout<<-1<<"\n";
    return 0;
}