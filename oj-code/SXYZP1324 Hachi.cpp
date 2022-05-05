#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
int b[10];
std::string s,eight="8";
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>s;
	if(s.length()==1){
		int t1=s[0]-'0';
		if(t1==8)return cout<<"Yes",0;
		else return cout<<"No",0;
	}
	if(s.length()==2){
		int t1=s[0]-'0',t2=s[1]-'0';
		if((10*t1+t2)%8==0||(10*t2+t1)%8==0)return cout<<"Yes",0;
		else return cout<<"No",0;
	}
	for(auto it:s)b[it-'0']++;
	for(int i=0;i<=9;i++)for(int j=0;j<=9;j++)for(int k=0;k<=9;k++){
		int t=100*i+10*j+k;
		if(t%8)continue;
		b[i]--;b[j]--;b[k]--;
		if(b[i]>=0&&b[j]>=0&&b[k]>=0&&(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]!=0||s.length()==3))
			return cout<<"Yes",0;
		b[i]++;b[j]++;b[k]++;
	}
	cout<<"No";
	return 0;
}