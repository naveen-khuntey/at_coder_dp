// Problem: B - Frog 2
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _to_ accept_hoja()
/*--------------------------------------------------------------*/
void kal_425() 
{
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	vector<int> dp(n,INT_MAX);
	dp[0] = 0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=k;j++){
			if(i-j >= 0){
				dp[i] = min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));
			}
		}
	}
	cout<<dp[n-1];
    
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    kal_425();
    return 0;
}