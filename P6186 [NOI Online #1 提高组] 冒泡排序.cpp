#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
int sta[50];
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
inline void write(int x){
	if(x==0){putchar('0');return;}
	int len=0;
	if(x<0)x=-x,putchar('-');
	while(x)sta[len++]=x%10+'0',x/=10;
	while(len--)putchar(sta[len]);
}
int n,tree[200007],a[200007],b[200007],r[200007];
inline int lowbit(int x){return x&-x;}
inline void add(int x,int k=1){for(;x<=n;x+=lowbit(x))tree[x]+=k;}
inline int query(int x,int sum=0){for(;x;x-=lowbit(x))sum+=tree[x];return sum;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	n=read();int t,x,m=read();long long tot=0ll;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=i-1-query(a[i]),tot+=b[i],r[b[i]]++,add(a[i]);
	memset(tree,0,sizeof tree);
	add(1,tot);tot=0ll;
	for(int i=1;i<=n;i++)tot+=r[i-1],add(i+1,tot-n);
	for(int i=1;i<=m;i++){
		cin>>t>>x;
		x=std::min(x,n-1);
		if(t==2){write(query(x+1));putchar('\n');continue;}
		std::swap(a[x],a[x+1]);std::swap(b[x],b[x+1]);
		if(a[x]>=a[x+1])add(1,1),b[x+1]++,add(b[x+1]+1,-1);
		else add(1,-1),add(b[x]+1),b[x]--;
	}
	return 0;
}