#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
std::string d="123456780",str;
int dx[]={0,1,-1,0},dy[]={1,0,0,-1},dep;
char dc[]={'r','d','u','l'},c;
std::vector<char>ans;
inline int h(const std::string &s,int sum=0){
	for(int i=0;i<9;i++)if(d[i]!=s[i]&&s[i])sum++;
	return sum;
}
inline bool check(const std::string &s,int sum=0){
	for(int i=0;i<9;i++)for(int j=i+1;j<9;j++)
		if(s[i]!='0'&&s[j]!='0'&&s[i]>s[j])sum++;
	return sum&1;
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
		ans.emplace_back(dc[i]);
		if(dfs(now+1,s,i))return true;
		ans.pop_back();
		std::swap(s[(nx-1)*3+ny-1],s[(x-1)*3+y-1]);
	}
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=0;i<9;i++)cin>>c,str.push_back(c=='x'?'0':c);
	if(check(str))return cout<<"unsolvable",0;
	for(dep=0;;dep++)if(dfs(0,str,-1)){for(auto it:ans)cout<<it;return 0;}
}