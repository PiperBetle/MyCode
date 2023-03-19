#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using std::cin;using std::cout;
int s[1000007],len=0;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int lcm(int a,int b){return a/gcd(a,b)*b;}
signed main(){
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int l,r,ans=0;
	cin>>l>>r;
	for(int i=1;i<=r;i++)s[i]=0x3f3f3f3f;
	for(ans=0;l<=r;l++){
		int num=0x3f3f3f3f;
		for(int i=1;i*i<=l;i++){
			if(l%i!=0)continue;
			int c1=i,c2=l/i;
			num=std::min(num,lcm(s[c1],l));
			s[c1]=std::min(s[c1],l);
			if(c1==c2)continue;
			num=std::min(num,lcm(s[c2],l));
			s[c2]=std::min(s[c2],l);
		}
		if(num==0x3f3f3f3f)num=0;
		cout<<l<<' '<<num<<'\n';
		ans+=num;
	}
	cout<<ans;
	return 0;
}