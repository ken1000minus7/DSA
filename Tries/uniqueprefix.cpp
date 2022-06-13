#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
public:
    char character;
    bool isTerminal;
    int freq;
    unordered_map<char,TrieNode*> children;

    TrieNode(char character)
    {
        this->character = character;
        isTerminal = false;
        freq = 0;
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
            temp->freq++;
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

// for each string in string of arrays, find its unique prefix

int main()
{
    int n;
    Trie t;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        t.insert(arr[i]);
    }
    string ans[n];
    for(int i=0;i<n;i++)
    {
        string s = arr[i];
        string pref = "";
        TrieNode* temp = t.root;
        for(int i=0;i<s.length();i++)
        {
            pref+=s[i];
            TrieNode* nexi = temp->children[s[i]];
            if(nexi->freq==1) break;
            temp = nexi;
        }
        ans[i] = pref;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}