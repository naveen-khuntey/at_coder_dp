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
int n ,w;
vector<int> wgt(105),val(105);
vector<vector<int>> dp(100010,vector<int>(105,-1));
int getmin(int i, int v){
	if(v < 0)
		return INT32_MAX;
	if(v == 0)
		return 0;
	if(i < 0) 
		return INT32_MAX;

	if(dp[v][i] != -1)
		return dp[v][i];

	int take = wgt[i] + getmin(i-1, v-val[i]);
	int dont_take = getmin(i-1, v);
	return dp[v][i] = min(take, dont_take);
}
/*--------------------------------------------------------------*/
void kal_425() 
{
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>wgt[i]>>val[i];
    }
    int ans = 0;
    for(int i=1e5;i>=0;i--){
        if(getmin(n-1,i) <= w){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
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