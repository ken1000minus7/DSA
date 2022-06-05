#include<iostream>
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
    return 0;
}