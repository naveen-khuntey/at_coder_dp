// Problem: F - LCS
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s,g;
    cin>>s>>g;
    int n = s.size();
    int m = g.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=0;i<=m;i++) dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == g[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string lcs = "";
    int i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1] == g[j-1]){
            lcs += s[i-1];
            i--;j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout<<lcs;
    return 0;
}