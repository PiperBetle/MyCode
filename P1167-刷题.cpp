#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
struct Time
{
	int year,month,day,hour,minute;
}x,y;
bool check(int x)
{
	if(x%400==0) return 1;
	if((x%4==0)&&(x%100)) return 1;
	return 0;
}
int a[10007],d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int sl(Time t)
{
	for(int i=0;i<=t.year-1;i++)
		t.day+=365+check(i);
	if(t.month>2)
		t.day+=check(t.year);
	t.day+=d[t.month-1];
	return t.day*24*60+t.hour*60+t.minute+1;
}
signed main()
{
	int i,j,k;
	int n,m,t;
	int ans=0;
	
	for(int i=2;i<=12;i++) d[i]+=d[i-1];
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	scanf("%lld-%lld-%lld-%lld:%lld",&x.year,&x.month,&x.day,&x.hour,&x.minute);
	scanf("%lld-%lld-%lld-%lld:%lld",&y.year,&y.month,&y.day,&y.hour,&y.minute);
	m=sl(y)-sl(x);
	sort(a+1,a+1+n);
	for(i=1;i<=n&&m>=a[i];i++)
	{
		ans++;
		m-=a[i];
	}
	cout<<ans;
    return 0;
}