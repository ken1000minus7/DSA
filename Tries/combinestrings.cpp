#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
public:
    char character;
    bool isTerminal;
    unordered_map<char,TrieNode*> children;

    TrieNode(char character)
    {
        this->character = character;
        isTerminal = false;
    }
};

class Trie{

public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string s)
    {
        TrieNode* temp = root;
        for(int i=0;i<s.length();i++)
        {
            if(!temp->children.count(s[i]))
            {
                temp->children[s[i]] = new TrieNode(s[i]);
            }
            temp = temp->children[s[i]];
        }
        temp->isTerminal = true;
    }

    bool search(string s)
    {
        TrieNode* temp = root;
        for(int i=0;i<s.length();i++)
        {
            if(!temp->children.count(s[i])) return false;
            temp = temp->children[s[i]];
        }
        return temp->isTerminal;
    }

    void printStringsWithPrefix(string s)
    {
        TrieNode* temp = root;
        for(int i=0;i<s.length();i++)
        {
            if(!temp->children.count(s[i])) return;
            temp = temp->children[s[i]];
        }
        printStringsfromNode(temp,s);
    }

private:

    void printStringsfromNode(TrieNode* t,string s = "")
    {
        if(t->isTerminal) cout<<s<<"\n";
        for(auto child : t->children)
        {
            printStringsfromNode(child.second,s+child.first);
        }
    }

};

string reverseString(string s)
{
    string ans = "";
    for(int i=s.length()-1;i>=0;i--)
    {
        ans+=s[i];
    }
    return ans;
}

// In an array of strings find any two strings which on combining form the query string

int main()
{
    int n;
    Trie t1, t2;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        t1.insert(arr[i]);
        t2.insert(reverseString(arr[i]));
    }
    string s;
    cin>>s;
    int prefpres[s.length()] = {0};
    int suffpres[s.length()] = {0};
    TrieNode* temp = t1.root;
    for(int i=0;i<s.length();i++)
    {
        if(!temp->children.count(s[i])) break;
        TrieNode* nexi = temp->children[s[i]];
        if(nexi->isTerminal) prefpres[i]++;
        temp = nexi;
    }
    temp = t2.root;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(!temp->children.count(s[i])) break;
        TrieNode* nexi = temp->children[s[i]];
        if(nexi->isTerminal) suffpres[i]++;
        temp = nexi;
    }
    string s1 = "",s2 = "";
    bool found = false;
    for(int i=0;i<s.length()-1;i++)
    {
        s1+=s[i];
        if(prefpres[i] && suffpres[i+1])
        {
            for(int j = i+1;j<s.length();j++) s2+=s[j];
            found = true;
            break;
        }
    }
    if(found) cout<<s1<<" "<<s2<<"\n";
    else "Not found\n";
    return 0;
}