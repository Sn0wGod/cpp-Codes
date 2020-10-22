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
#define mp12            make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pq1             priority_queue<int>
#define pqr1            priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void fast()
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
    a=a%m;
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
// int c;
int dp[101][100001];


int32_t main()
{
    // memset(prime,0,sizeof(prime));
    //memset(p,1,sizeof(p));   
    //seive();
    file();
    fast();
    //int mo=1000000007;
   



    return 0;
    
    
}

