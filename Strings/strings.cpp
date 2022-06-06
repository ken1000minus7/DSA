#include<iostream>
#include<set>
using namespace std;

int length(char* s)
{
    int i=0;
    while(true)
    {
        if(s[i]=='\0') return i;
        i++;
    }
}

int wordCount(string s)
{
    int c =0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=' ' && (i==s.length()-1 || s[i+1]==' ')) c++;
    }
    return c;
}

void reverseString(char c[])
{
    int i=0;
    int j=0;
    while(c[j+1]!='\0') j++;
    while(i<j)
    {
        swap(c[i++],c[j--]);
    }
}

// can use masking and merging to find duplicates, using merging to set the bit of the correspondong and character and use masking to check if it is already set, if yes then it is duplicate
set<char> getDuplicates(string s)
{
    set<char> ans;
    int t = 0;
    for(int i=0;i<s.length();i++)
    {
        int x = 1 << (s[i]-'a');
        if(x&t) ans.insert(s[i]);
        else t = t|x;
    }
    return ans;
}

void permutations(int i,char s[],int n,string ans)
{
    if(i>=n)
    {
        cout<<ans<<"\n";
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(s[i]==s[j] && i!=j) continue;
        swap(s[i],s[j]);
        permutations(i+1,s,n,ans + s[i]);
        swap(s[i],s[j]);
    }
}

int done[1000] = {0};
void permutations(int i,string s,string ans)
{
    
    int n = s.length();
    if(i>=n)
    {
        cout<<ans<<"\n";
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(done[j]) continue;
        done[j]++;
        permutations(i+1,s,ans + s[j]);
        done[j]--;
    }
}

int main()
{
    // character contains ASCII code, each char takes 1 byte
    char a = 'a';
    char b = 66;
    cout<<a<<' '<<b<<"\n";

    // string is an array of characters, the last character is a null character indicating that the string ahs terminated
    char s1[] = {'l','o','l','\0'};

    // no need to specify null cahracter in this
    char s2[] = "loli";

    // creating string in heap
    // this like std::string so immutable, only char arrays are mutable
    char * s3 = "hehe";

    cout<<s1<<" "<<s2<<" "<<s3<<"\n";
    cout<<length(s1)<<' '<<length(s2)<<"\n";

    // covert character from upper to lower by adding 32, similarly lower to upper by subtracting ez
    char bb = b+32;

    cout<<wordCount("hello how are you    ma     boi hehe")<<"\n";
    reverseString(s2);
    cout<<s2<<"\n";
    string st;
    cin>>st;
    set<char> ans = getDuplicates(st);
    for(char i : ans) cout<<i<<" ";
    cout<<"\n";
    permutations(0,s2,4,"");
    string s10 = "helo";
    permutations(0,s10,"");
    return 0;
}