#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[107][107]={0},n,m;
char c[107][107]={0};
int p=0;
int dx[4]={-1,0,0,1},
	dy[4]={0,-1,1,0};
int first(int _x,int _y,char _from,char _to)
{
	for(int i=0;i<4;i++)
	{
		int nx=_x+dx[i],ny=_y+dy[i];
		if((nx<1)||(ny<1)||(nx>n)||(nx>m))continue;
		if(c[nx][ny]==_from)
		{
			c[nx][ny]=_to;
			first(nx,ny,_from,_to);
		}
	}
}
int final(int _x,int _y)
{
	int flag=0;
	for(int i=0;i<4;i++)
	{
		int nx=_x+dx[i],ny=_y+dy[i];
		if((nx>=1)&&(nx<=n)&&(ny>=1)&&(ny<=m)&&(a[nx][ny]<=a[_x+dx[minn]][_y+dy[minn]]))
		{
			flag=1;
			break;
		}
	}
	if(flag==1)return 0;
	for(int i=0;i<4;i++)
	{
		int nx=_x+dx[i],ny=_y+dy[i];
		if((nx>=1)&&(nx<=n)&&(ny>=1)&&(ny<=m)&&(a[nx][ny]>a[_x+dx[minn]][_y+dy[minn]]))
		{
			minn=i;
		}
	}
	int nx=_x+dx[minn],ny=_y+dy[minn];
	if(c[nx][ny]!='0')
			{
				first(_x,_y,p-1+'a',c[nx][ny]);
				p--;
			}
			else
			{
				c[nx][ny]=p-1+'a';
				final(nx,ny);
			}
			return 0;
	
	return 0;
}
int main()
{
//	freopen("watersheds.in","r",stdin);
//	freopen("watersheds.out","w",stdout);
	int i,j,k;
	int t,T,_n;
	int _i,_j,_k;
	
	cin>>T;
	for(_i=1;_i<=T;_i++)
	{
		for(i=0;i<107;i++)for(j=0;j<107;j++)a[i][j]=0,c[i][j]='0';
		p=0;
		cin>>n>>m;
		cout<<"Case #"<<_i<<":\n";
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(c[i][j]=='0')
				{
					p++;
					c[i][j]=p-1+'a';
					final(i,j);
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cout<<c[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
