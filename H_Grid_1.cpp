// Problem: H - Grid 1
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_h
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    int mod = 1e9 + 7;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<long long>> dp(n,vector<long long>(m,0LL));
    bool k = false;
    int i=0;
    while(i<n && v[i][0] == '.') dp[i++][0] = 1;
    while(i<n) dp[i++][0] = 0;
    i=0;
    while(i<m && v[0][i] == '.') dp[0][i++] = 1;
    while(i<m) dp[0][i++] = 0;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(v[i][j] == '.'){
                dp[i][j] += (dp[i-1][j] + dp[i][j-1]);
            }
            else{
                dp[i][j] = 0;
            }
            dp[i][j] %= mod;
        }
    }
    cout<<dp[n-1][m-1];
    return 0;
}