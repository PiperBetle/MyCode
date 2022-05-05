#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a_big[100007],l_big=0;
int a_small[100007],l_small=0;
int mid,n;
inline void up_big(int x)
{
	int j=x,k;
	l_big++;
	a_big[l_big]=j;
	while(j>1)
	{
		k=(j>>1);
		if(a_big[j]<=a_big[k])break;
		swap(a_big[j],a_big[k]);
		j=k;
	}
}
inline int down_big()
{
	int j=a_big[1],k,re=a_big[1];
	a_big[1]=a_big[l_big];
	l_big--;
	while((j<<1)<=l_big)
	{
		k=(j<<1);
		if((k<l_big)&&(a_big[k]<a_big[k+1]))++k;
		if(a_big[k]<=a_big[j])break;
		swap(a_big[j],a_big[k]);
		j=k;
	}
	return re;
}
inline void up_small(int x)
{
	int j=x,k;
	l_small++;
	a_small[l_small]=j;
	while(j>1)
	{
		k=(j>>1);
		if(a_small[j]<=a_small[k])break;
		swap(a_small[j],a_small[k]);
		j=k;
	}
}
inline int down_small()
{
	int j=a_small[1],k,re=a_small[1];
	a_small[1]=a_small[l_small];
	l_small--;
	while((j<<1)<=l_small)
	{
		k=(j<<1);
		if((k<l_small)&&(a_small[k]<a_small[k+1]))++k;
		if(a_small[k]<=a_small[j])break;
		swap(a_small[j],a_small[k]);
		j=k;
	}
	return re;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int x,y;
	
	cin>>n>>mid;
	cout<<mid<<"\n";
	for(i=2;i<=n;i++)
	{
		cin>>x;
		if(x>mid)up_small(x);
		else up_big(x);
		if(i%2)
		{
			while(l_big!=l_small)
			{
				if(l_big>l_small)
				{
					up_small(mid);
					mid=a_big[1];
					down_big();
				}
				else
				{
					up_big(mid);
					mid=a_small[1];
					down_small();
				}
			}
			cout<<mid<<"\n";
		}
	}
	
	return 0;
}
