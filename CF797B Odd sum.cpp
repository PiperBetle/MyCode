#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
int a[100007];
std::string str;
signed main(){
//	freopen("seq.in","r",stdin);
//	freopen("seq.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n;
	cin>>n;
	int ans=-0x3f3f3f3f3f3f3f3f,sum=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0&&a[i]%2==0)sum+=a[i],n--,i--;
		else if(a[i]<=0&&a[i]%2==0)n--,i--;
	}
	if(n==0)return cout<<"QAQ",0;
	std::sort(a+1,a+1+n,std::greater<int>());
	for(i=1;i<=n;i++){
		sum+=a[i];
		if(i%2==0)continue;
		ans=std::max(ans,sum);
	}
	return cout<<ans,0;
}