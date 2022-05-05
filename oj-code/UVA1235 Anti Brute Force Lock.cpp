#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
using std::string;using std::min;
int f[2007];
string s[2007],b="0000";
template<typename any>inline any abs(any x){return 0<x?-x:x;}
inline int dis(string&a,string&b,int sum=0){
	sum+=min(abs(a[0]-b[0]),10-abs(a[0]-b[0]));
	sum+=min(abs(a[1]-b[1]),10-abs(a[1]-b[1]));
	sum+=min(abs(a[2]-b[2]),10-abs(a[2]-b[2]));
	sum+=min(abs(a[3]-b[3]),10-abs(a[3]-b[3]));
	return sum;
}
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
struct edge{int u,v,t;bool operator<(const edge&n){return t<n.t;}}a[4000007];
signed main(){
//	freopen("jfca.in","r",stdin);
//	freopen("jfca.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,T,t,ans,n;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0x3f3f3f3f;
		int l=0,cnt=0;
		for(i=1;i<=n;i++){
			cin>>t;f[i]=i;s[i]="";
			if(t<10)s[i].append(3,'0');
			else if(t<100)s[i].append(2,'0');
			else if(t<1000)s[i].append(1,'0');
			ans=min(ans,dis(b,s[i]+=std::to_string(t)));
		}
		for(i=1;i<n;i++)for(j=i+1;j<=n;j++)a[++l]=edge{i,j,dis(s[i],s[j])};
		std::sort(a+1,a+1+l);
		for(i=1;i<=l;i++){
			int fx=find(a[i].u),fy=find(a[i].v);
			if(fx==fy)continue;
			f[fx]=fy;ans+=a[i].t;
			if(++cnt==n-1)break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
