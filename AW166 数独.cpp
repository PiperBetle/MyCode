#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using std::cin;using std::cout;
int a[17][17];
char b[17][17];
bool f1[17][17],f2[17][17],f3[17][17],flag;
inline void dfs(int now){
	if(flag)return;
	int x=(now-1)/9+1,y=now%9;if(y==0)y=9;
	if(a[x][y]!=0){dfs(now+1);return;}
	if(now==82){
		for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)cout<<a[i][j];
		cout<<'\n';
		flag=true;
	}
	for(int i=1;i<=9;i++){
		int t=(x-1)/3*3+(y-1)/3+1;
		if(f1[x][i]||f2[y][i]||f3[t][i])continue;
		a[x][y]=i;
		f1[x][i]=true;f2[y][i]=true;f3[t][i]=true;
		dfs(now+1);
		if(flag)return;
		f1[x][i]=false;f2[y][i]=false;f3[t][i]=false;
		a[x][y]=0;
	}
}
signed main(){
	// freopen("sudoku.in","r",stdin);
	// freopen("sudoku.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j;
	for(;;){
		flag=false;
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		memset(f3,0,sizeof f3);
		for(i=1;i<=9;i++)for(j=1;j<=9;j++){
			cin>>b[i][j];
			if(!isdigit(b[i][j])&&b[i][j]!='.')return 0;
			if(isdigit(b[i][j])){
				a[i][j]=b[i][j]-'0';
				f1[i][a[i][j]]=true;
				f2[j][a[i][j]]=true;
				int t=(i-1)/3*3+(j-1)/3+1;
				f3[t][a[i][j]]=true;
			}
			else a[i][j]=0;
		}
		dfs(1);
	}
}