#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
std::basic_string<int>a;
std::basic_string<loli>b{0,1,2,3,4,5,6,7,8,9};
loli n;
signed main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int k=2;k<=17;k++){
		for(int d1=1;d1<=9;d1++)for(int d2=0;d2<=9;d2++){
			a={d1,d2};
			int w=d2-d1;
			loli t=d1*10+d2;
			for(int i=3;i<=k;i++){
				a+=a.back()+w;
				if(0>a.back()||a.back()>9)goto number;
			}
			for(int i=2;i<siz(a);i++)(t*=10)+=a[i];
			b+=t;
			number:;
		}
	}
	b+=11'1111'1111'1111'1111ll;
	// for(loli i:b)cout<<i<<'\n';
	cin>>n;
	cout<<*std::lower_bound(all(b),n);
	return 0;
}