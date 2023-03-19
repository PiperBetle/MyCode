#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[100005],bl[100005],f[351][351],s[351][100005],mp[100005],cnt[100005];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int i,j,k,n,l,r,x=0;cin>>n;int sz=__builtin_sqrt(n),num=0;
	for(i=1;i<=n;i++){cin>>a[i];mp[i]=a[i];if(i%sz==1)num++;bl[i]=num;}
	std::sort(mp+1,mp+1+n);l=std::unique(mp+1,mp+n+1)-mp-1;
	for(i=1;i<=n;i++)a[i]=std::lower_bound(mp+1,mp+1+l,a[i])-mp;
	for(i=1;i<=num;i++)for(j=sz*(i-1)+1;j<=std::min(n,sz*i);j++)s[i][a[j]]++;
	for(i=1;i<=num;i++)for(j=1;j<=l;j++)s[i][j]+=s[i-1][j];
	#define compare(d1,n1,d2,n2) if((d1>d2)||(n1<n2&&d1==d2))n2=n1
	for(i=1;i<=num;i++)for(j=i;j<=num;j++)for(f[i][j]=f[i][j-1],k=sz*(j-1)+1;k<=std::min(n,sz*j);k++)
		compare(s[j][a[k]]-s[i-1][a[k]],a[k],s[j][f[i][j]]-s[i-1][f[i][j]],f[i][j]);
	for(int T=1;T<=n;T++){
		cin>>l>>r;if(l>r)std::swap(l,r);
		if(bl[r]-bl[l]<=1){
			for(x=0,i=l;i<=r;i++)cnt[a[i]]++;
			for(i=l;i<=r;i++)compare(cnt[a[i]],a[i],cnt[x],x);
			for(i=l;i<=r;i++)cnt[a[i]]=0;
			cout<<(x=mp[x])<<'\n';continue;
		}
		#define count(x) cnt[x]+s[bl[r]-1][x]-s[bl[l]][x]
		for(x=f[bl[l]+1][bl[r]-1],i=l;i<=sz*bl[l];i++)cnt[a[i]]++;
		for(i=sz*(bl[r]-1)+1;i<=r;i++)cnt[a[i]]++;
		for(i=l;i<=sz*bl[l];i++)compare(count(a[i]),a[i],count(x),x);
		for(i=sz*(bl[r]-1)+1;i<=r;i++)compare(count(a[i]),a[i],count(x),x);
		for(i=l;i<=sz*bl[l];i++)cnt[a[i]]=0;
		for(i=sz*(bl[r]-1)+1;i<=r;i++)cnt[a[i]]=0;
		cout<<(x=mp[x])<<'\n';
	}
	return 0;
}