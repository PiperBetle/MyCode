#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct carrot
{
	int sum,cnt;
	carrot(){cnt=1;}
	carrot cutup(){carrot ca;ca.cnt++;return ca;}
	int calc(){return (sum%cnt)*(sum/cnt+1)*(sum/cnt+1)+(cnt-sum%cnt)*(sum/cnt)*(sum/cnt);}
	int ccalc(){return this->cutup().calc();}
	int delta(){return (this->calc())-(this->cutup().calc());}
	bool friend operator<(carrot x,carrot y){return x.delta()<y.delta();};
}a[100007];
std::priority_queue<carrot>q;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;

	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].sum;
		q.push(a[i]);
		ans+=a[i].calc();
	}
	for(i=1;i<=k-n;i++)
	{
		carrot t=q.top();
		q.pop();
		ans-=t.delta();
		t.cnt++;
		q.push(t);
	}
	cout<<ans<<'\n';
	
	return 0;
}