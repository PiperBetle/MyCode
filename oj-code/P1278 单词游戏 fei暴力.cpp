#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define int long long
using namespace std;
struct word
{
	char begin,end;
	int length; 
}a[107];
int f[100007][107];
int change(char _c)
{
	if(_c=='A')return 0;
	if(_c=='E')return 1;
	if(_c=='I')return 2;
	if(_c=='O')return 3;
	if(_c=='U')return 4;
}
signed main()
{
//	freopen("words.in","r",stdin);
//	freopen("words.out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	string s;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		a[i].begin=change(s[0]);
		a[i].end=change(s[s.length()-1]);
		a[i].length=s.length();
	}
	for(i=0;i<(1<<n);i++)//枚举所有状态 
		for(j=0;j<n;j++)//枚举末尾字母 
			if(i&(1<<j))//保证这个字母在状态里出现 
				if(i==(1<<j)||f[i-(1<<j)][a[j].begin])//这是第一个字母 或者 可以从其他情况接上来 
				{
					f[i][a[j].end]=f[i-(1<<j)][a[j].begin]+a[j].length;//直接加上长度 
					ans=max(ans,f[i][a[j].end]);//比较最大值 
				}
	cout<<ans;
	
    return 0;
}
