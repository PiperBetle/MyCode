#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
std::string d="111110111100*110000100000",s,str;
int T,dep,dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1};
inline int h(const std::string &s,int sum=0){
	for(int i=0;i<25;i++)if(d[i]!=s[i]&&s[i]!=' ')sum++;
	return sum;
}
bool dfs(int now,std::string s,int pre){
	int i=h(s),x=0,y=0;
	if(!i)return true;
	if(now+i>dep+1)return false;
	for(i=0;i<25;i++)if(s[i]=='*'){x=i/5+1;y=i%5+1;break;}
	for(i=0;i<8;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>5||ny<1||ny>5||pre+i==7)continue;
		std::swap(s[(nx-1)*5+ny-1],s[(x-1)*5+y-1]);
		if(dfs(now+1,s,i))return true;
		std::swap(s[(nx-1)*5+ny-1],s[(x-1)*5+y-1]);
	}
	return false;
}
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>T;
	while(T--){
		s.clear();
		cin>>str;s+=str;
		cin>>str;s+=str;
		cin>>str;s+=str;
		cin>>str;s+=str;
		cin>>str;s+=str;
		for(dep=0;dep<=15;dep++)if(dfs(0,s,-1))break;
		if(dep==16)cout<<"-1\n";else cout<<dep<<'\n';
	}
	return 0;
}