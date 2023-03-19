#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
int n;
double p;
//* c1 means unlook  c2 means look
double calc1(double c1,double c2,int res=3,int num=0){
	if(res==0)return num==1;
	double sum=c1+c2,ans=0;
	if(c1>0)ans+=c1/sum*calc1(c1-1,c2,res-1,num);
	if(c2>0)ans+=c2/sum*calc1(c1,c2-1,res-1,num+1);
	return ans;
}
double calc(double c1,double c2){
	double _3_0=c1/(c1+c2)*(c1-1)/(c1+c2-1)*(c1-2)/(c1+c2-2);
	double _3_1=calc1(c1,c2)/2;
	return 1-_3_0-_3_1;
}
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>p;
	for(int i=0;i<=n;i++)if(calc(n-i,i)>=p)return cout<<i,0;
	return 0;
}