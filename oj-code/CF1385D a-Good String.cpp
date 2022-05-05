#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
string a;
int gl(int left,int right,char ch)
{
	int mid=(left+right)>>1;
	if(left==right)return a[mid]!=ch;
	int sum1=0,sum2=0;
	for(int i=left;i<=mid;i++)if(a[i]!=ch)sum1++;
	for(int i=mid+1;i<=right;i++)if(a[i]!=ch)sum2++;
	sum1+=gl(mid+1,right,ch+1);
	sum2+=gl(left,mid,ch+1);
	return min(sum1,sum2);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	
	cin>>T;
	while(T--)
	{
		cin>>n>>a;
		a=" "+a;
		cout<<gl(1,n,'a')<<'\n';
	}
	
    return 0;
}
