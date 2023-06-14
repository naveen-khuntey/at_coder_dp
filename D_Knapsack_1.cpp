// Problem: D - Knapsack 1
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _to_ accept_hoja()
/*--------------------------------------------------------------*/
void kal_425() 
{
	int n,w;
	cin>>n>>w;
    vector<int> val(n),wt(n);
    for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];
    vector<vector<long long>> dp(n+1,vector<long long>(w+1,0LL));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j] = dp[i-1][j];
            if(wt[i-1] <= j){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]] + val[i-1]);
            }
        }
    } 
    cout<<dp[n][w];
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    kal_425();
    return 0;
}