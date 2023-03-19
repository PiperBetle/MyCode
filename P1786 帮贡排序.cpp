#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define int long long
using namespace std;
struct member
{
	string name;
	string job;
	int _job,ID;
	int level,contribution;
};
member a[1000007];
int change1(string s)
{
	if(s=="BangZhu")return 1;
	if(s=="FuBangZhu")return 2;
	if(s=="HuFa")return 3;
	if(s=="ZhangLao")return 4;
	if(s=="TangZhu")return 5;
	if(s=="JingYing")return 6;
	if(s=="BangZhong")return 7;
}
string change2(int n)
{
	if(n<=1)return "BangZhu";
	if(n<=3)return "FuBangZhu";
	if(n<=5)return "HuFa";
	if(n<=9)return "ZhangLao";
	if(n<=16)return "TangZhu";
	if(n<=41)return "JingYing";
	return "BangZhong";
}
bool cmp1(member x,member y)
{
	if(x.contribution!=y.contribution)return x.contribution>y.contribution;
	return x.ID<y.ID;
}
bool cmp2(member x,member y)
{
	if(change1(x.job)!=change1(y.job))return change1(x.job)<change1(y.job);
	if(x.level!=y.level)return x.level>y.level;
	return x.ID<y.ID;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].name>>a[i].job>>a[i].contribution>>a[i].level;
		a[i].ID=i;
	}
	sort(a+4,a+1+n,cmp1);	
	for(i=1;i<=n;i++)
		a[i].job=change2(i);
	sort(a+1,a+1+n,cmp2);
	for(i=1;i<=n;i++)
		cout<<a[i].name<<' '<<a[i].job<<' '<<a[i].level<<'\n';
	
    return 0;
}
