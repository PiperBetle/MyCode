#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<vector>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
std::unordered_map<int,int>f;
inline int find(int x){if(!f.count(x))f[x]=x;return f[x]==x?x:f[x]=find(f[x]);}
struct ask{int x,y;}t;
std::vector<ask>a;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int x,y,type;
	
	cin>>T;
	while(T--)
	{
		cin>>n;bool flag=0;
		f.clear();a.clear();
		for(i=1;i<=n;i++)
		{
			cin>>t.x>>t.y>>type;
			if(!type)a.emplace_back(t);
			else 
			{
				int fx=find(t.x),fy=find(t.y);
				if(fx!=fy)f[find(t.x)]=find(t.y);
			}
		}
		for(auto it=a.begin();it!=a.end();it++)
		{
			if(flag)break;
			int fx=find(it->x),fy=find(it->y);
			if(fx==fy)flag=1;
		}
		if(flag)cout<<"NO\n";else cout<<"YES\n";
	}
	
	return 0;
}
