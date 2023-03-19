#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using std::cin;using std::cout;
constexpr int kN=1e4+7,MOD=1e9+7;
int b[kN<<1],lb,c[4][kN<<1],s[4];
struct matrix{
	int data[4][4],size;
	matrix(){memset(data,0,sizeof data);}
	matrix(const int &x):size(x){memset(data,0,sizeof data);}
	void build(){for(int i=1;i<=size;i++)data[i][i]=1;}
	int *operator[](const int &t){return data[t];}
	const int *operator[](const int &t)const{return data[t];}
	matrix operator*(const matrix &t){
		matrix res(size);
		for(int k=1;k<=size;k++)for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)
			res[i][j]=(res[i][j]+data[i][k]*t[k][j])%MOD;
		return res;
	}
	matrix &operator*=(const matrix &t){
		matrix res(size);
		for(int k=1;k<=size;k++)for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)
			res[i][j]=(res[i][j]+data[i][k]*t[k][j])%MOD;
		return *this=res;
	}
	matrix &operator^=(int &&t){
		matrix res(size);res.build();
		for(;t;t>>=1,*this=*this**this)if(t&1)res=res**this;
		return *this=res;
	}
};
matrix ans(3);
void base(matrix &t){
	t[1][1]=1;t[1][2]=1;t[1][3]=0;
	t[2][1]=1;t[2][2]=1;t[2][3]=1;
	t[3][1]=0;t[3][2]=1;t[3][3]=1;
}
struct block{int h,l,r;}a[kN+1];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].h>>a[i].l>>a[i].r,b[++lb]=a[i].l-1,b[++lb]=a[i].r;
	b[++lb]=1,b[++lb]=m;std::sort(b+1,b+1+lb);lb=std::unique(b+1,b+1+lb)-b-1;
	for(int i=1;i<=n;i++)c[a[i].h][std::lower_bound(b+1,b+1+lb,a[i].l)-b]++,c[a[i].h][std::lower_bound(b+1,b+1+lb,a[i].r)-b+1]--;
	ans[2][1]=1;for(int i=2;i<=lb;i++){
		matrix t(3);base(t);
		for(int j=1;j<=3;j++)if(s[j]+=c[j][i])t[j][1]=t[j][2]=t[j][3]=0;
		ans=(t^=(b[i]-b[i-1]))*ans;
	}
	cout<<ans[2][1];
	return 0;
}