#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define endl '\n'
#define fr first
#define sd second
#define gcd __gcd
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ppc   __builtin_popcount
#define ppcll __builtin_popcountll
#define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/***************************************Debug***********************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x << " ";_print(x);cerr<<endl;
#else
#define debug(x)
#endif
void _print(int x) {cerr << x;}
void _print(bool x) {cerr << x;}
void _print(char x) {cerr << x;}
void _print(string x) {cerr << x;}
void _print(unsigned long long x) {cerr << x;}
void _print(float x) {cerr << x;}
void _print(double x) {cerr << x;}
template<class T>void _print(set<T> v);
template<class T>void _print(vector<T> v);
template<class T>void _print(multiset<T> v);
template<class T>void _print(unordered_set<T> v);
template<class T, class V>void _print(map<T, V> v);
template<class T, class V>void _print(unordered_map<T, V> v);
template<class T>void _print(vector<vector<T>> v);
template<class T>void _print(stack<T> v);
template<class T>void _print(queue<T> v);
template<class T, class V>void _print(pair<T, V> p);
template<class T>void _print(queue<T> v) {cerr << "[ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << " ]";}
template<class T>void _print(stack<T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << " ]";}
template<class T, class V>void _print(pair<T, V> p) {_print(p.first); cerr << " "; _print(p.second); cerr << endl;}
template<class T>void _print(set<T> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(vector<T> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(multiset<T> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(unordered_set<T> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V>void _print(map<T, V> v) {cerr << "[ "; for (auto &i : v) {_print(i.first); cerr << " "; _print(i.second); cerr << "\n";} cerr << "]";}
template<class T, class V>void _print(unordered_map<T, V> v) {cerr << "[ "; for (auto &i : v) {_print(i.first); cerr << " "; _print(i.second); cerr << "\n";} cerr << "]";}
template<class T>void _print(vector<vector<T>> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << endl;} cerr << "]";}
 
/************************************************************************************************************/
template<class T> ostream& operator<<(std::ostream& o,vector<T> &v){ for(auto &x : v){ o<<x<<" ";}return o;}
template<class T> ostream& operator<<(std::ostream& o,set<T> &v){ for(auto &x : v){ o<<x<<" ";}return o;}
template<class T> istream& operator>>(std::istream &o , vector<T> &v){for(int i=0;i<v.size();i++){o>>v[i];}return o;}
int mod = 1e9+7;
/*--------------------------------------------------------------*/
void kal_425() 
{
    int n;
    cin>>n;
    vector<double> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<double>> dp(n+1,vector<double>(n+1,0.0));
    dp[0][0] = 1.0;    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0)
                dp[i][j] = (1-v[i-1])*dp[i-1][j];
            else
                dp[i][j] = v[i-1]*dp[i-1][j-1] + (1-v[i-1])*dp[i-1][j];
        }
    }
    double s = 0;
    for(int i=n;i>(n/2);i--){
        s += dp[n][i];
    }
    cout<<fixed<<setprecision(10)<<s<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin>>t;
    for(int i = 1; i <= t; i++){
           //cout<<"Case #"<<i<<": ";
           kal_425();
    }
    return 0;
}