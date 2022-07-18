#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
public:
    int num;
    bool isTerminal;
    TrieNode* zeroNode, *oneNode;

    TrieNode(int n = 0)
    {
        this->num = n;
        isTerminal = false;
        zeroNode = NULL;
        oneNode = NULL;
    }
};

class Trie{

public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(int n)
    {
        TrieNode* temp = root;
        for(int i=31;i>=0;i--)
        {
            int num = (n>>i) & 1;
            if(num==0){
                if(temp->zeroNode==NULL) temp->zeroNode = new TrieNode(0);
                temp = temp->zeroNode;
            }
            else{
                if(temp->oneNode==NULL) temp->oneNode = new TrieNode(1);
                temp = temp->oneNode;
            }
        }
        temp->isTerminal = true;
    }

    int getXor(int n)
    {
        int ans = 0;
        TrieNode* temp = root;
        for(int i=31;i>=0;i--)
        {
            int num = (n>>i) & 1;
            ans = ans<<1;
            if(num==0)
            {
                if(temp->oneNode==NULL)
                {
                    temp=temp->zeroNode;
                }
                else
                {
                    ans++;
                    temp=temp->oneNode;
                }
            }
            else
            {
                if(temp->zeroNode==NULL)
                {
                    temp=temp->oneNode;
                }
                else
                {
                    ans++;
                    temp=temp->zeroNode;
                }
            }
        }
        return ans;
    }

};

int main()
{
    int n;
    Trie t;
    cin>>n;
    int arr[n];
    int ans = 0;
    int prefxor[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i>0)
        {
            prefxor[i] = arr[i];
        }
        else prefxor[i] = arr[i]^prefxor[i-1];
    }
    for(int i=0;i<n;i++)
    {
        if(i>0) ans = max(ans,t.getXor(prefxor[i]));
        else ans = max(ans,prefxor[i]);
        t.insert(prefxor[i]);
    }
    cout<<ans<<"\n";
    return 0;
}