#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
#endif
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
int pt[2000007],phi[20000007],len,tree[500007],n;
bool pr[20000007];
inline void add(int x,int k){for(;x<=n;x+=(x&-x))tree[x]+=k;}
inline int sum(int x,int k=0){for(;x;x-=(x&-x))k+=tree[x];return k;}
inline int qp(int a,int b,int p,int t=1,bool f=1){
	for(f=a>p?(a%=p,0):f;b;b>>=1,f=(a*=a)>p?(a%=p,0):f)
		if(b&1)f=(t*=a)>p?(t%=p,0):f;
	return f?t:t+p;
}
inline int query(int l,int r,int p){
	if(p==1)return 1;
	if(int ans=sum(l);l==r)return ans>=p?ans%p+p:ans;
	else return qp(ans,query(l+1,r,phi[p]),p);
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	pr[1]=true,phi[1]=1;
	for(int i=2;i<=20000000;i++){
		if(!pr[i])pt[++len]=i,phi[i]=i-1;
		for(int j=1;j<=len&&i*pt[j]<=20000000;j++){
			pr[i*pt[j]]=true;
			if(i%pt[j]==0){phi[i*pt[j]]=phi[i]*pt[j];break;}
			else phi[i*pt[j]]=phi[i]*(pt[j]-1);
		}
	}
	n=read();int m=read();
	for(int i=1,t;i<=n;i++)t=read(),add(i,t),add(i+1,-t);
	for(int i=1,l,r,p;i<=m;i++)
		if(read()==1)l=read(),r=read(),p=read(),add(l,p),add(r+1,-p);
		else l=read(),r=read(),p=read(),printf("%lld\n",query(l,r,p)%p);
	return 0;
}