#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
std::string d="123804765",str;
int dx[]={0,1,-1,0},dy[]={1,0,0,-1},dep;
inline int h(const std::string &s,int sum=0){
	for(int i=0;i<9;i++)if(d[i]!=s[i]&&s[i])sum++;
	return sum;
}
bool dfs(int now,std::string s,int pre){
	int i=h(s);
	if(!i)return true;
	if(now+i>dep+1)return false;
	int x=0,y=0,nx,ny;
	for(i=0;i<9;i++)if(s[i]=='0')x=i/3+1,y=i%3+1;
	for(i=0;i<4;i++){
		nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>3||ny<1||ny>3||pre+i==3)continue;
		std::swap(s[(nx-1)*3+ny-1],s[(x-1)*3+y-1]);
		if(dfs(now+1,s,i))return true;
		std::swap(s[(nx-1)*3+ny-1],s[(x-1)*3+y-1]);
	}
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>str;
	for(dep=0;;dep++)if(dfs(0,str,-1))return cout<<dep,0;
}