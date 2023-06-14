// Problem: A - Frog 1
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define endl '\n'
#define fr first
#define _to_ accept_hoja()
#define sd second
#define gcd __gcd
#define MP make_pair
#define PB push_back
#define mpii map<int,int>
#define pii pair<int, int>
#define vpii vector<pair<int,int>>
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ppc   __builtin_popcount
#define ppcll __builtin_popcountll
#define pbds tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define input(x,n) for(int i=0;i<n;i++){int y; cin>>y; x.push_back(y);}
template<class T> ostream& operator<<(std::ostream& o,vector<T> &v){ for(auto &x : v){ o<<x<<" ";}return o;}
template<class T> ostream& operator<<(std::ostream& o,set<T> &v){ for(auto &x : v){ o<<x<<" ";}return o;}
template<class T> istream& operator>>(std::istream &o , vector<T> &v){for(int i=0;i<v.size();i++){o>>v[i];}return o;}
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,0,-1,1,-1,1,0,-1};
int mod = 1e9+7;//998244353;
/*--------------------------------------------------------------*/
void kal_425() 
{
    int mn = INT64_MAX;
    int mx = INT64_MIN;
    int sum =0;
    int n;
    cin>>n;
    vector<int> v(n);
    cin>>v;
    vector<int> val(n,0LL);
    val[1]=abs(v[0]-v[1]);
    for(int i=2;i<n;i++){
    	val[i] = min(val[i-1]+abs(v[i]-v[i-1]), val[i-2] + abs(v[i-2]-v[i]));
    }
    // cout<<val<<endl;
    cout<<val[n-1];
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //clock_t z = clock();
    int t = 1;
    // cin>>t;
    for(int i = 1; i <= t; i++){
           //cout<<"Case #"<<i<<": ";
           kal_425();
    }
    //cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}