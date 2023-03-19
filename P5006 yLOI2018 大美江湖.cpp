#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
char c[107][107];
int dx[]={0,0,0,-1,1},
	dy[]={0,-1,1,0,0};
struct people{double HP,ST,DE;}A,B;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,op;
	int x,y,q;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>c[i][j];
	cin>>B.HP>>B.ST>>B.DE>>x>>y>>A.ST>>A.DE>>q;A.HP=0;
	while(q--)
	{
		cin>>op;
		if(op==1)cout<<A.HP<<' '<<A.ST<<' '<<A.DE<<'\n';
		else
		{
			cin>>op;
			x+=dx[op];y+=dy[op];
			if(c[x][y]=='R')A.HP=max(A.HP-10,0.0);
			else if(c[x][y]=='Q')A.ST+=5;
			else if(c[x][y]=='Y')A.DE+=5;
			else if(c[x][y]=='M')A.HP+=max(1.0,ceil(B.HP/max(1.0,A.ST-B.DE))*max(1.0,B.ST-A.DE));
		}
	}
	
	return 0;
}