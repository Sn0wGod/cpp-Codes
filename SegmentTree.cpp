#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
/*#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int;*/
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int              long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pq             priority_queue<int>
#define pqr             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000000
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MOD 1000000007
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}


int modInv(int a,int b,int m)
{
    int res=1;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}





int p[1000006];
vi prime;
//int mrp[1000000];
void seive(){
    for(int i=2;i<1000006;i++) {
        if(p[i]){
            prime.pb(i);
            for(int j=i*i;j<=1000006;j=j+i){
                p[j]=0;
            }
        }
    }

}

int a[1000000]={0};


void build(int *tree,int ss,int se,int idx){
    if(ss==se){
        tree[idx]=a[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(tree,ss,mid,2*idx+1);
    build(tree,mid+1,se,2*idx+2);
    tree[idx]=__gcd(tree[2*idx+1],tree[2*idx+2])%MOD;
    return;
}

int query(int *tree,int ss,int se,int l,int r,int idx){
    if(ss>=l && r>=se){
        return tree[idx];
    }
    if(l>se || ss>r){
        return 0;
    }
    int mid=(ss+se)/2;
    int left=query(tree,ss,mid,l,r,2*idx+1);
    int right=query(tree,mid+1,se,l,r,2*idx+2);
    return (left+right);
}

void update(int *tree,int ss,int se,int i,int idx,int inc){
    if(ss>i || i>se){
        return;
    }
    if(ss==se){
        tree[idx]+=inc;
        return;
    }
    int mid=(ss+se)/2;
    update(tree,ss,mid,i,2*idx+1,inc);
    update(tree,mid+1,se,i,2*idx+2,inc);
    tree[idx]=(tree[2*idx+1])+(tree[2*idx+2]);
    
}

int32_t main()
{
    // memset(prime,0,sizeof(prime));
    //memset(p,1,sizeof(p));   
    //seive();
    file();
    c_p_c();
    //int mo=1000000007;
   int n,q;
   cin>>n>>q;
  // for(int i=1;i<=n;i++) cin>>a[i];
    int tree[4*n+1]={0};
    //build(tree,1,n,0);
    while(q--){
        int typ;
        cin>>typ;
        if(typ==1){
            int x;
            cin>>x;
            a[x]+=1;
            update(tree,1,n,x,0,1);
        }
        else if(typ==2){
            int y;
            cin>>y;
            a[y]-=1;
            if(a[y])
                update(tree,1,n,y,0,-1);
            else
                a[y]=1;
                 update(tree,1,n,y,0,0);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query(tree,1,n,l,r,0)<<endl;
        }
       
    }

    return 0;
}
