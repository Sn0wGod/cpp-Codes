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
void topo(int src,vector<int> &vis,vector<vector<pair<int,int> > >g,vector<int> &order){
    vis[src] = 1;
    for(auto x:g[src]){
        if(!vis[x.first]){
            topo(x.first,vis,g,order);
        }
    }
    order.push_back(src);
}

int32_t main()
{   
    dfile();
    // seive();
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int> > > g(v);
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].pb({y,w});
    }
    vector<int> vis(v,0);
    vector<int> order;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,vis,g,order);
        }
    }
    reverse(order.begin(),order.end());
    vector<int> dis(v,INT_MIN);
    dis[1] = 0;
    for(int i=0;i<order.size();i++){
        if(dis[order[i]]!=INT_MIN){
            for(auto x:g[order[i]]){
                int y = x.first;
                int w = x.second;
                dis[y] = max(dis[y] , dis[order[i]]+w);
            }
        }
    }
    for(int i=0;i<dis.size();i++){
        cout<<dis[i]<<" ";
    }
    
    return 0;   
}
