#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[100007];
constexpr int inf=0x3f3f3f3f;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,max=-inf,min=inf,cnt=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],max=std::max(max,a[i]),min=std::min(min,a[i]);
	if(max>min+1)return cout<<"No",0;
	if(max==min)return cout<<(min==n-1||2*min<=n?"Yes":"No"),0;
	for(int i=1;i<=n;i++)if(a[i]==min)cnt++;
	return cout<<(min<cnt||n-cnt<2*(max-cnt)?"No":"Yes"),0;
}