#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
#define MOD 19940417
using std::cin;using std::cout;
int a[50007],bicon[50007][21],n,m,l,r,k;
struct stn{
	int ls,rs,data[21],add,mul;
	stn():add(0),mul(0){memset(data,0,sizeof data);}
	int size(){return rs-ls+1;}
	int &operator[](const int &t){return data[t];}
	friend stn operator+(stn a,stn b){
		stn t;t.ls=a.ls,t.rs=b.rs;
		for(int i=0;i<=std::min(20ll,a.size());i++)for(int j=0;i+j<=20ll&&j<=b.size();j++)
			t[i+j]=(t[i+j]+a[i]*b[j])%MOD;
		return t;
	}
	void sadd(int k){
		int t[21]={1};
		for(int i=1;i<=std::min(20ll,this->size());i++)t[i]=t[i-1]*k%MOD;
		for(int i=std::min(20ll,this->size());i>=1;i--)for(int j=0;j<i;j++)
			data[i]=(data[i]+data[j]*t[i-j]%MOD*bicon[this->size()-j][i-j])%MOD;
		add=(add+k)%MOD;
	}
	void smul(){
		for(int i=1;i<=std::min(20ll,this->size());i++)if(i&1)data[i]=MOD-data[i];
		mul=!mul;add=MOD-add;
	}
}s[200007];
#define mid ((s[now].ls+s[now].rs)>>1)
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){s[now][0]=1;s[now][1]=(a[l]%MOD+MOD)%MOD;return;}
	build(now<<1,l,mid);build(now<<1|1,mid+1,r);
	s[now]=s[now<<1]+s[now<<1|1];
}
inline void spread(int now){
	if(s[now].mul){s[now<<1].smul();s[now<<1|1].smul();s[now].mul=0;}
	if(s[now].add){s[now<<1].sadd(s[now].add);s[now<<1|1].sadd(s[now].add);s[now].add=0;}
}
inline void add(int now,int l,int r,int k){
	if(l<=s[now].ls&&s[now].rs<=r){s[now].sadd(k);return;}
	spread(now);if(l<=mid)add(now<<1,l,r,k);if(r>mid)add(now<<1|1,l,r,k);
	s[now]=s[now<<1]+s[now<<1|1];
}
inline void mul(int now,int l,int r){
	if(l<=s[now].ls&&s[now].rs<=r){s[now].smul();return;}
	spread(now);if(l<=mid)mul(now<<1,l,r);if(r>mid)mul(now<<1|1,l,r);
	s[now]=s[now<<1]+s[now<<1|1];
}
stn query(int now,int l,int r){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now];
	spread(now);if(r<=mid)return query(now<<1,l,r);if(l>mid)return query(now<<1|1,l,r);
	return query(now<<1,l,r)+query(now<<1|1,l,r);
}
signed main(){
	freopen("le.in","r",stdin);
	freopen("le.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=n;i++)for(int j=bicon[i][0]=1;j<=std::min(20ll,i);j++)
		bicon[i][j]=(bicon[i-1][j]+bicon[i-1][j-1])%MOD;
	build(1,1,n);
	while(m--){
		char c;cin>>c;switch(c){
			case 'I':cin>>l>>r>>k;k=(k%MOD+MOD)%MOD;add(1,l,r,k);break;
			case 'R':cin>>l>>r;mul(1,l,r);break;
			case 'Q':cin>>l>>r>>k;int ans=query(1,l,r)[k];cout<<(ans+MOD)%MOD<<'\n';break;
		}
	}
	return 0;
}