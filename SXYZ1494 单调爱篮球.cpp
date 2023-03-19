#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int t[1000007];
signed main(){
//	freopen("love.in","r",stdin);
//	freopen("love.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m1,m2,l,d,p,sum=0,ans1=0,ans2=0,cnt;
	cin>>n>>l>>m1>>d>>p;m2=m1;
	for(i=1;i<=l;i++)cin>>t[i],sum+=t[i];
	std::sort(t+1,t+1+l);
	for(i=1;i<=l;i++){
		if(t[i]!=0)cnt=m1/t[i];
		else cnt=n;
		if(cnt>n)cnt=n;
		ans1+=cnt*d;
		if(i==l)ans1+=cnt*p;
		m1-=cnt*t[i];
	}
	if(sum!=0)cnt=m2/sum;
	else cnt=n;
	if(cnt>n)cnt=n;
	ans2+=cnt*(d*l+p);
	m2-=cnt*sum;
	n-=cnt;
	for(i=1;i<=l;i++){
		if(t[i]!=0)cnt=m2/t[i];
		else cnt=n;
		if(cnt>n)cnt=n;
		ans2+=cnt*d;
		if(i==l)ans2+=cnt*p;
		m2-=cnt*t[i];
	}
	cout<<std::max(ans1,ans2);
	return 0;
}