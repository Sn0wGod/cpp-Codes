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
 
int n=4;
int ti;
vector<int> disc(n);
vector<int> low(n);
vector<pair<int,int> > bridge;
set<int> point;
void dfs(int src,int par,vector<vector<int> > g){
    disc[src] = low[src] = ti++;
    int no_child = 0;
    for(auto child:g[src]){
        if(!disc[child]){
            dfs(child,src,g);
            no_child++;
            low[src] = min(low[src],low[child]);
            if(par!=-1 and low[child] >= disc[src]){
                point.insert(src);
            }
            if(low[child] > disc[src]){
                bridge.pb({src,child});
            }
        }
        else if(child!=par){
            low[src] = min(low[src],disc[child]);
        }
    }
    if(par==-1 and no_child>=2) point.insert(src);
}

int32_t main()
{   
    dfile();
    // seive();
    int v,e;
    cin>>v>>e;
    vector<vector<int> > g(v);
    for(int i=0;i<e;i++) {
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    ti = 1;
    dfs(0,-1,g);
    for(auto x:point){
        cout<<x<<" ";
    }

    cout<<endl;
    for(int i=0;i<bridge.size();i++) {
        cout<<bridge[i].first<<" "<<bridge[i].second<<endl;
    }
    
    return 0;   
}
