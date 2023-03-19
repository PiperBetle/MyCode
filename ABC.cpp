#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<random>
#define siz(x) int((x).size())
std::mt19937 rng(std::random_device{}());
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	std::string ABC="start https://atcoder.jp/contests/abc",TSK="/tasks";
	// int n;cin>>n;
	int n=254;
	system((ABC+std::to_string(rng()%(n+1)+1)+TSK).data());
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}