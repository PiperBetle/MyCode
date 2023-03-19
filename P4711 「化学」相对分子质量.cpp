#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<string>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
std::unordered_map<std::string,double>map;
std::string s;
inline double calc(std::string s)
{
	int l=s.length();double res=0;
	for(int i=0;i<l;i++)
	{
		if(isupper(s[i]))
		{
			std::string t1="";t1+=s[i];
			if(i<l&&islower(s[i+1]))t1+=s[++i];
			if(s[i+1]=='_')
			{
				int p2=s.find('}',i);
				std::string t2=s.substr(i+3,p2-i-3);
				res+=map[t1]*atoi(t2.data());
				i=p2;
			}
			else res+=map[t1];
		}
		else if(s[i]=='(')
		{
			int p1=s.find(')',i);
			std::string t1=s.substr(i+1,p1-i-1);
			int p2=s.find('}',p1);
			std::string t2=s.substr(p1+3,p2-p1-3);
			res+=calc(t1)*atoi(t2.data());
			i=p2;
		}
		else if(s[i]=='~')
		{
			std::string t2="1";
			if(s[i+1]!='H')
			{
				int p2=s.find('H',i);
				t2=s.substr(i+1,p2-i-1);
			}
			res+=map["H2O"]*atoi(t2.data());
			i=s.find('O',i);
		}
	}
	return res;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m;
	
	map["H"]=1;
	map["C"]=12;
	map["N"]=14;
	map["O"]=16;
	map["F"]=19;
	map["Na"]=23;
	map["Mg"]=24;
	map["Al"]=27;
	map["Si"]=28;
	map["P"]=31;
	map["S"]=32;
	map["Cl"]=35.5;
	map["K"]=39;
	map["Ca"]=40;
	map["Mn"]=55;
	map["Fe"]=56;
	map["Cu"]=64;
	map["Zn"]=65;
	map["Ag"]=108;
	map["I"]=127;
	map["Ba"]=137;
	map["Hf"]=178.5;
	map["Pt"]=195;
	map["Au"]=197;
	map["Hg"]=201;
	map["H2O"]=18;
	cin>>s;
	double ans=calc(s);
	int t=ans*10.0;
	if(t%10==5)cout<<t/10<<".5";
	else cout<<t/10;
	
	return 0;
}