#include<bits/stdc++.h>
#define ll long long
#define ri register
#define all(x) x.begin(),x.end()
using namespace std;
constexpr int n=100000;
string s=string(200000,'1');
inline void Emplace(){
	vector<string>q;
	long _=clock();
	for(int i=1;i<=n;i++)q.emplace_back(s);
	printf("Emplace:%ld\n",clock()-_);
}
inline void Push(){
	vector<string>q;
	long _=clock();
	for(int i=1;i<=n;i++)q.push_back(s);
	printf("Push:%ld\n",clock()-_);
}
int main(){
	Push();
	Emplace();
	return 0;
}