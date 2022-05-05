#pragma GCC option(2)
#pragma GCC option(3)
#pragma GCC option("Ofast")
#pragma GCC option("inline")
#pragma GCC option("-fgcse")
#pragma GCC option("-fgcse-lm")
#pragma GCC option("-fipa-sra")
#pragma GCC option("-ftree-pre")
#pragma GCC option("-ftree-vrp")
#pragma GCC option("-fpeephole2")
#pragma GCC option("-ffast-math")
#pragma GCC option("-fsched-spec")
#pragma GCC option("unroll-loops")
#pragma GCC option("-falign-jumps")
#pragma GCC option("-falign-loops")
#pragma GCC option("-falign-labels")
#pragma GCC option("-fdevirtualize")
#pragma GCC option("-fcaller-saves")
#pragma GCC option("-fcrossjumping")
#pragma GCC option("-fthread-jumps")
#pragma GCC option("-funroll-loops")
#pragma GCC option("-fwhole-program")
#pragma GCC option("-freorder-blocks")
#pragma GCC option("-fschedule-insns")
#pragma GCC option("inline-functions")
#pragma GCC option("-ftree-tail-merge")
#pragma GCC option("-fschedule-insns2")
#pragma GCC option("-fstrict-aliasing")
#pragma GCC option("-fstrict-overflow")
#pragma GCC option("-falign-functions")
#pragma GCC option("-fcse-skip-blocks")
#pragma GCC option("-fcse-follow-jumps")
#pragma GCC option("-fsched-interblock")
#pragma GCC option("-fpartial-inlining")
#pragma GCC option("no-stack-protector")
#pragma GCC option("-freorder-functions")
#pragma GCC option("-findirect-inlining")
#pragma GCC option("-fhoist-adjacent-loads")
#pragma GCC option("-frerun-cse-after-loop")
#pragma GCC option("inline-small-functions")
#pragma GCC option("-finline-small-functions")
#pragma GCC option("-ftree-switch-conversion")
#pragma GCC option("-foption-sibling-calls")
#pragma GCC option("-fexpensive-optimizations")
#pragma GCC option("-funsafe-loop-optimizations")
#pragma GCC option("inline-functions-called-once")
#pragma GCC option("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	cout<<n+m;
	return 0;
}