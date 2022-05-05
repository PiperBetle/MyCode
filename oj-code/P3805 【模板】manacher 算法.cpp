#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
std::string a,b;
int p[30000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=1;

	cin>>b;
	a.clear();a.append(1,'~');a.append(1,'|');
	int lb=b.length();
	for(i=0;i<lb;i++)a.append(1,b[i]),a.append(1,'|');
	int r=0,mid=0,la=a.length()-1;
	for(i=1;i<=la;i++)
	{
		if(i<=r)p[i]=min(p[(mid<<1)-i],mid+p[mid]-i);else p[i]=1;
		while(a[i-p[i]]==a[i+p[i]])p[i]++;
		if(i+p[i]>r)r=i+p[i],mid=i;
		ans=max(ans,p[i]);
	}
	cout<<ans-1;
	
	return 0;
}