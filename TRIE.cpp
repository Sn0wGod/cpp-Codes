#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;

void dfile(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class Node
{
public:
    char ch;
    unordered_map<char,Node*> m;
    int c;
    Node(char ich)
    {
        ch = ich;
        c=0;
    }
};
class TRIE
{
    Node* root;
public:
    TRIE()
    {
        root = new Node('\0');
    }
    void insert(string s){
        Node* temp = root;
        for(int i=0;i<s.length();i++){
            if(temp->m[s[i]]){
                temp = temp->m[s[i]];
            }
            else{
                Node* n = new Node(s[i]);
                temp->m[s[i]] = n;
                temp = n;
            }
            temp->c = (temp->c)+1; 
        }
    }
    string get(string s){
        Node* temp = root;
        string x="";
        for(int i=0;i<s.length();i++){
            temp = temp->m[s[i]];
            if(temp->c == 1){
                x=x+s[i];
                return x;
            }
            else{
                x=x+s[i];
            }
        }
        return "";
    }
};





int32_t main()
{   
    dfile();
    // seive();
    TRIE t;
    string s[5]={"color","dog","duck","dove","apple"};
    for(int i=0;i<5;i++) t.insert(s[i]);

    for(int i=0;i<5;i++){
        string x = t.get(s[i]);
        if(x!="") cout<<x<<endl;
    }
    

    return 0;   
}



