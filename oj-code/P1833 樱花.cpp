#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
struct tree{int c,w;};
std::vector<tree>a,b;
int f[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n=1,m,T;
	int c,w,t;
	int s_h,s_m,e_h,e_m;
	
	scanf("%d:%d%d:%d%d",&s_h,&s_m,&e_h,&e_m,&n);
	m=(e_h-s_h)*60-s_m+e_m;
	while(n--)
	{
		scanf("%d%d%d",&c,&w,&t);
		if(!t)a.emplace_back((tree){c,w});
		else for(i=1;;t-=i,i<<=1)
		{
			if(i>=t){b.emplace_back((tree){c*t,w*t});break;}
			b.emplace_back((tree){c*i,w*i});
		}
	}
	for(auto&i:a)for(j=i.c;j<=m;j++)f[j]=max(f[j],f[j-i.c]+i.w);
	for(auto&i:b)for(j=m;j>=i.c;j--)f[j]=max(f[j],f[j-i.c]+i.w);
	printf("%d",f[m]);
	
	return 0;
}
