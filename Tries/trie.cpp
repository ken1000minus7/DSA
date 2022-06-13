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

    void deleteString(string s);

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

int main()
{
    int n =5;
    Trie t;
    while(n--)
    {
        string s;
        cin>>s;
        t.insert(s);
    }
    string s;
    cin>>s;
    cout<<t.search(s)<<"\n";

    n=3;
    while(n--)
    {
        string s;
        cin>>s;
        t.printStringsWithPrefix(s);
    }
    // cin>>s;
    // t.deleteString(s);
    // cin>>s;
    // cout<<t.search(s)<<"\n";
    return 0;
}