#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
char s[100007];
bool pr[100007];
int pt[100007],len;
std::vector<int>a;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	pr[1]=1;
	for(i=2;i<=100000;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=100000;j++)
		{
			pr[i*pt[j]]=1;
			if(!(i%pt[j]))break;
		}
	}
	for(;;)
	{
		cin.get(s,100007).get();int l=strlen(s);
		n=0;a.clear();cout<<"Enter the number=";
		for(i=k=0;i<l;i++)if(isdigit(s[i]))n=(n<<1)+(n<<3)+(s[i]^48),k=1;
		if(k==0)return 0;else k=1;m=n;
		cout<<"\nPrime? ";
		if(n<=1){cout<<"No!\n\n";continue;}
		if(n>=40000000){cout<<"No!\nThe number is too large!\n\n";continue;}
		for(i=1;pt[i]*pt[i]<=n;i++)while(n%pt[i]==0)a.emplace_back(pt[i]),n/=pt[i];
		if(n>=2)a.emplace_back(n);
		if(a.size()==1){cout<<"Yes!\n\n";continue;}else cout<<"No!\n"<<m<<'=';
		for(auto it=a.begin()+1;it!=a.end();it++,k++)
			if(*it!=*(it-1))cout<<*(it-1)<<'^'<<k<<'*',k=0;
		cout<<*(a.end()-1)<<'^'<<k<<"\n\n";
	}
	
	return 0;
}