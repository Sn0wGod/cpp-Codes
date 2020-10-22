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
int f;
void dfs(int src,int par,int col,vector<int> &vis,vector<vector<int> > &g){
    vis[src] = col;
    for(auto x:g[src]){
        if(vis[x]==-1){
            dfs(x,src,3-col,vis,g);
        }
        else if(x!=par and col == vis[x]){
            f=1;
            break;
        }
    }
}


int32_t main()
{   
    dfile();
    // seive();
    f=0;
    int v,e;
    cin>>v>>e;
    vector<vector<int> > g(v);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<int> vis(v,-1);
    dfs(0,0,1,vis,g);
    if(f==1) cout<<"Not Bipartite";
    else cout<<"Bipartite";
    
    return 0;   
}
