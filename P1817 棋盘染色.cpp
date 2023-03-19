#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1},n,m;
bool vis[10][10];
long long ans=0,a[10][10];
inline void dfs(int x,int y){
	if(x<1||x>=n||y<1||y>=m){ans++;return;}
	vis[x][y]=true;
	for(int i=0;i<4;i++)if(!vis[x+dx[i]][y+dy[i]])dfs(x+dx[i],y+dy[i]);
	vis[x][y]=false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int i;
	// for(n=1;n<=7;n++)for(m=1;m<=8;m++){
	// 	ans=0;
	// 	for(i=1;i<n;i++)memset(vis,0,sizeof vis),vis[i][0]=true,dfs(i,1);
	// 	for(i=1;i<m;i++)memset(vis,0,sizeof vis),vis[0][i]=true,dfs(1,i);
	// 	cout<<"a["<<n<<"]["<<m<<"]="<<ans<<";\n";
	// }
	a[1][1]=0;  
	a[1][2]=1;  
	a[1][3]=2;  
	a[1][4]=3;  
	a[1][5]=4;  
	a[1][6]=5;  
	a[1][7]=6;
	a[1][8]=7;
	a[2][1]=1;
	a[2][2]=6;
	a[2][3]=15;
	a[2][4]=28;
	a[2][5]=45;
	a[2][6]=66;
	a[2][7]=91;
	a[2][8]=120;
	a[3][1]=2;
	a[3][2]=15;
	a[3][3]=52;
	a[3][4]=143;
	a[3][5]=350;
	a[3][6]=799;
	a[3][7]=1744;
	a[3][8]=3695;
	a[4][1]=3;
	a[4][2]=28;
	a[4][3]=143;
	a[4][4]=614;
	a[4][5]=2431;
	a[4][6]=9184;
	a[4][7]=33603;
	a[4][8]=120090;
	a[5][1]=4;
	a[5][2]=45;
	a[5][3]=350;
	a[5][4]=2431;
	a[5][5]=16000;
	a[5][6]=102147;
	a[5][7]=637330;
	a[5][8]=3903895;
	a[6][1]=5;
	a[6][2]=66;
	a[6][3]=799;
	a[6][4]=9184;
	a[6][5]=102147;
	a[6][6]=1114394;
	a[6][7]=11948355;
	a[6][8]=126244104;
	a[7][1]=6;
	a[7][2]=91;
	a[7][3]=1744;
	a[7][4]=33603;
	a[7][5]=637330;
	a[7][6]=11948355;
	a[7][7]=220762028;
	a[7][8]=4028145967;
	cin>>n>>m;
	cout<<(a[n][m]<<1);
	return 0;
}