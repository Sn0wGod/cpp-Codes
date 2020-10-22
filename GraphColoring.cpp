//Input
//5 5
//0 1
//1 2
//2 3
//3 4
//4 0

//Output
//3
//0 1 0 1 2 





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


int32_t main()
{   
    dfile();
    // seive();
    int v,e;
    cin>>v>>e;
    vector<vector<int> > g(v);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int result[v];
    int available[v];
    result[0] = 0;
    available[0] = false;
    for(int i=1;i<v;i++){
        result[i] = -1;
        available[i] = false;
    }
    int cn = 0;
    for(int i=1;i<v;i++){
        for(auto x:g[i]){
            if(result[x]!=-1){
                available[result[x]] = true;
            }
        }
        int c = -1;
        for(int j=0;j<v;j++){
            if(available[j]==false){
                c = j;
                cn = max(cn,j+1);
                break;
            }
        }
        result[i] = c;
        for(auto x:g[i]){
            if(result[x]!=-1){
                available[result[x]] = false;
            }
        }
    }
    cout<<cn<<endl;
    for(int i=0;i<v;i++) cout<<result[i]<<" ";

    
    return 0;   
}
