#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _to_ accept_hoja()
/*--------------------------------------------------------------*/
void kal_425() 
{
	int n;
	cin>>n;
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    long long dp[n+1][3];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for(int i=1;i<=n;i++){
        dp[i][0] = a[i-1] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = b[i-1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = c[i-1] + max(dp[i-1][0],dp[i-1][1]);
    }                     
    long long mx = max({dp[n][0],dp[n][1],dp[n][2]});
    cout<<mx;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    kal_425();
    return 0;
}