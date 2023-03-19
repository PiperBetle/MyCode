#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
char s[37][37][37];
bool b[37][37][37];
int dx[]={-1,1,0,0,0,0},
	dy[]={0,0,-1,1,0,0},
	dz[]={0,0,0,0,-1,1};
struct point{int x,y,z,step;}now,go,start;
std::queue<point>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int l,r,c;
	int x1,y1,z1,x2,y2,z2;
	
	memset(b,0,sizeof b);
	cin>>l>>r>>c;
	for(i=1;i<=l;i++)for(j=1;j<=r;j++)for(k=1;k<=c;k++)
	{
		cin>>s[i][j][k];
		if(s[i][j][k]=='S')x1=i,y1=j,z1=k;
		if(s[i][j][k]=='E')x2=i,y2=j,z2=k;
	}
	while(!q.empty())q.pop();
	q.push({x1,y1,z1,0});
	do
	{
		now=q.front();q.pop();
		for(i=0;i<6;i++)
		{
			go.x=now.x+dx[i];
			go.y=now.y+dy[i];
			go.z=now.z+dz[i];
			if(go.x>=1&&go.x<=l&&
			   go.y>=1&&go.y<=r&&
			   go.z>=1&&go.z<=c&&
			   !b[go.x][go.y][go.z]&&
			   s[go.x][go.y][go.z]!='#')
			{
				if(go.x==x2&&go.y==y2&&go.z==z2)
					return cout<<"Escaped in "<<now.step+1<<" minute(s).",0;
				b[go.x][go.y][go.z]=1;
				go.step=now.step+1;
				q.push(go);
			}
		}
	}while(!q.empty());
	cout<<"Trapped!";
	
	return 0;
}