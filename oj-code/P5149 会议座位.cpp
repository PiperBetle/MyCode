#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#define int long long
using std::cin;using std::cout;
int ans=0,a[100007],t[100007];
std::string name;
std::unordered_map<std::string,int>s;
void ms(int l,int r)
{
	if(l==r)return;
	int m=(l+r)/2;
	ms(l,m);ms(m+1,r);
	int p=l,i=l,j=m+1;
	while(i<=m&&j<=r)
		if(a[i]>a[j])ans=ans+m-i+1,t[p++]=a[j++];
		else t[p++]=a[i++];
	while(i<=m)t[p++]=a[i++];
	while(j<=r)t[p++]=a[j++];
	for(i=l;i<=r;i++)a[i]=t[i];
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>name,s[name]=i;
	for(i=1;i<=n;i++)cin>>name,a[i]=s[name];
	ms(1,n);
	cout<<ans;
	
	return 0;
}