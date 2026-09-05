#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	vector<char>dp(sum+1,0);
	dp[0]=1;
	for(int i=0;i<n;i++){
		int w=a[i];
		vector<char>ndp=dp;
		for(int m=0;m<sum;m++){
			if(!dp[m])
			continue;
			if(m+w<=sum)
			ndp[m+w]=1;
			ndp[abs(m-w)]=1;
		}
		dp.swap(ndp);
	}
	int ans=0;
	for(int i=1;i<=sum;i++){
		if(dp[i])
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}


















