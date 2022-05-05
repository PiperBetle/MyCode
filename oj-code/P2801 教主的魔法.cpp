#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int a[1000007],b[1000007],tag[1000007];
std::vector<int>s[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,q;
	int l,r;
	char c;
	
	cin>>n>>q;
	int size=sqrt(n),num=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i%size==1)num++;
		b[i]=num;
		s[num].emplace_back(a[i]);
	}
	for(i=1;i<=num;i++)std::sort(s[i].begin(),s[i].end());
	while(q--)
	{
		cin>>c>>l>>r>>k;
		if(c=='M')
		{
			for(i=l;i<=min(r,b[l]*size);i++)a[i]+=k;
			s[b[l]].clear();
			for(i=(b[l]-1)*size+1;i<=min(n,b[l]*size);i++)s[b[l]].emplace_back(a[i]);
			std::sort(s[b[l]].begin(),s[b[l]].end());
			if(b[l]==b[r])continue;
			for(i=b[l]+1;i<b[r];i++)tag[i]+=k;
			for(i=(b[r]-1)*size+1;i<=r;i++)a[i]+=k;
			s[b[r]].clear();
			for(i=(b[r]-1)*size+1;i<=min(n,b[r]*size);i++)s[b[r]].emplace_back(a[i]);
			std::sort(s[b[r]].begin(),s[b[r]].end());
		}
		else
		{
			int sum=0;
			for(i=l;i<=min(r,b[l]*size);i++)sum+=a[i]+tag[b[l]]<k;
			if(b[l]==b[r]){cout<<r-l+1-sum<<'\n';continue;}
			for(i=b[l]+1;i<b[r];i++)
				sum+=std::lower_bound(s[i].begin(),s[i].end(),k-tag[i])-s[i].begin();
			for(i=(b[r]-1)*size+1;i<=r;i++)sum+=a[i]+tag[b[r]]<k;
			cout<<r-l+1-sum<<'\n';
		}
	}

	return 0;
}