#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<list>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
struct point{int x,y,step,flag;bool operator<(const point &n)const{return step>n.step;}}begin,go;
std::priority_queue<point>q;
std::list<point>s;
char c[1007][1007];
int dis[1007][1007][3];
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
	{
		cin>>c[i][j];
		if(c[i][j]=='S')begin.x=i,begin.y=j,c[i][j]='0';
		else if(c[i][j]=='M')c[i][j]='0';
		else if(c[i][j]=='X')s.emplace_back((point){i,j,0,0});
	}
	begin.step=begin.flag=0;while(!q.empty())q.pop();
	memset(dis,0x3f,sizeof dis);dis[begin.x][begin.y][begin.flag]=0;
	q.push(begin);
	do
	{
		point now=q.top();q.pop();
		cout<<now.x<<' '<<now.y<<' '<<now.step<<' '<<now.flag<<' '<<c[now.x][now.y]<<'\n';
		for(i=0;i<4;i++)
		{
			go.x=now.x+dx[i];go.y=now.y+dy[i];
			if(go.x>n||go.x<1||go.y>m||go.y<1)continue;
			switch(c[go.x][go.y])
			{
				case '0':
					go.step=now.step+1;
					go.flag=now.flag;
					if(dis[go.x][go.y][go.flag]>go.step)
						q.push(go),dis[go.x][go.y][go.flag]=go.step;
					break;
				case '1':
					if(now.flag==2)
					{
						go.step=now.step+1;
						go.flag=now.flag;
						if(dis[go.x][go.y][go.flag]>go.step)
							q.push(go),dis[go.x][go.y][go.flag]=go.step;
					}
					break;
				case '2':
					if(!now.flag)go.step=now.flag+4;
					else go.step=now.step+1;
					go.flag=now.flag;
					if(dis[go.x][go.y][go.flag]>go.step)
						q.push(go),dis[go.x][go.y][go.flag]=go.step;
					break;
				case '3':
					if(!now.flag)go.step=now.flag+9;
					else go.step=now.step+1;
					go.flag=now.flag;
					if(dis[go.x][go.y][go.flag]>go.step)
						q.push(go),dis[go.x][go.y][go.flag]=go.step;
					break;
				case '4':
					go.step=now.step+1;
					go.flag=max(1,now.flag);
					if(dis[go.x][go.y][go.flag]>go.step)
						q.push(go),dis[go.x][go.y][go.flag]=go.step;
					break;
				case '5':
					go.step=now.step+1;
					go.flag=now.flag;
					if(dis[go.x][go.y][go.flag]>go.step)
						q.push(go),dis[go.x][go.y][go.flag]=go.step;
					go.step=now.step+5;
					go.flag=2;
					q.push(go),dis[go.x][go.y][go.flag]=go.step;
					break;
				case 'X':
					go.step=now.step+1;
					go.flag=now.step;
					for(auto it=s.begin();it!=s.end();it++)
						if(it->x==now.x+dx[i]&&it->y==now.y+dy[i])s.erase(it++);
						else if(dis[it->x][it->y][go.flag]>go.step)
							dis[it->x][it->y][go.flag]=go.step,q.push({it->x,it->y,go.step,go.flag}); 
					break;
				case 'E':
					return cout<<go.step,0;
			}
		}
	}while(!q.empty());
	cout<<"We want to live in the TouHou World forever";
	
	return 0;
}
