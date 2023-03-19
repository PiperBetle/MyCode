#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[407],b[407],n,m;
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
int sta[50];
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) (p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x)))
#endif
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
bool check(int cnt,int s,int used){
	if(cnt==m+1)return true;
	if(s==n+1)return false;
	if(used==0&&a[s]>=2){a[s]-=2;if(check(cnt+2,s,1))return true;a[s]+=2;}
	int i=a[s]/3;
	a[s]-=i*3;a[s+1]-=a[s];a[s+2]-=a[s];
	if(((s+2<=n&&a[s+1]>=0&&a[s+2]>=0)||(a[s]==0))&&check(cnt+a[s]*3+i*3,s+1,used))return true;
	a[s+2]+=a[s];a[s+1]+=a[s];a[s]+=i*3;
	return false;
}
signed main(){
//	freopen("majsoul.in","r",stdin);
//	freopen("majsoul.out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,t;n=read();m=read()*3+1;
	for(i=1;i<=m;i++)a[read()]++;
	for(t=i=1;i<=n;i++){
		if(!a[i-2]&&!a[i-1]&&!a[i]&&!a[i+1]&&!a[i+2])continue;
		for(j=1;j<=n;j++)b[j]=a[j];
		a[i]++;
		if(check(0,1,0))write(i),putchar(' '),t=0;
		a[i]--;
		for(j=1;j<=n;j++)a[j]=b[j];
	}
	if(t)printf("NO");
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}