#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int cnt2(int x){return floor(log2(x))+1;}
bool s[100007];
inline void upd(int l,int r){for(;l<=r;l++)s[l]=1;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=0;
	int a,b,c;

	memset(s,0,sizeof s);
	cin>>a>>b>>c;
	int A=__builtin_popcount(a),B=__builtin_popcount(b),C=__builtin_popcount(c),T=A+B-C;
	if(A>B)std::swap(A,B),std::swap(a,b);                  
	int l=max(cnt2(a),max(cnt2(b),cnt2(c)));
	if(A+B<C||l-1+C<A+B)return cout<<-1,0;
	if(A+B==C)return cout<<(1<<C)-1,0;
	if(A>=T&&B>=T)upd(1,A+B-T*2),upd(A+B-T*2+2,C+1);
	else if(A<T&&B>=T)upd(1,B-T),upd(B-T+2,B-T+A),s[B+1]=1;
	else upd(2,C),s[T+1]=1;
	for(i=l;i>=1;i--)m=m*2+s[i];
	// for(i=l;i>=1;i--)cout<<s[i];
	// cout<<(m>=(1<<l)?-1:m);
	cout<<m;
 
	return 0;
}