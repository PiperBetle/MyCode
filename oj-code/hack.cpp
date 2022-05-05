#include<cstdio>
#include<cctype>
#include<map>
#include<cmath>
using namespace std;
inline int R(){
	int r=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return r;
}
int a,b,m,n,y,x,p;
map<int,int> mp;
inline int gcd(int a,int b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}
inline int fastm(int a,int k){
	long long ans=1,node=a;
	while(k){
		if(k&1) ans=ans*node%p;
		k>>=1;
		node=node*node%p;
	}
	return ans;
}
inline void BSGS(){
	mp.clear();
	y=sqrt(p)+1;
	map<int,int>:: iterator it;//迭代器 
	for(register long long flag=b%p,i=0;i<y;i++,flag=flag*a%p){
		it=mp.find(flag);//flag=a^n*b
		if(it!=mp.end()) it->second=i;
		//如果之前有过同样的flag,那么显然后来的会更优，因为ny减完会更小 
		else mp.insert(pair<int,int>(flag,i));//否则插入 
	}
	long long cnt=fastm(a,y);//a^y，后面可以直接乘 
	long long flag=cnt;
	for(register long long i=1;i<=y;i++,flag=flag*cnt%p){
		it=mp.find(flag);
		if(it==mp.end()) continue;//如果找不到继续 
		printf("%d\n",y*i-(it->second));//x=my-n
		return ;
	}
	printf("no solution\n");
	return ;
}
int main(){
	scanf("%d%d%d",&p,&a,&b);
	if(b%gcd(p,a)) printf("no solution\n");//判是否合法 
	else BSGS();
	return 0;
}