#include<bits/stdc++.h>
using namespace std;
#define siz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
class Solution {
public:
    string longestPalindrome(string s) {
		int n=siz(s);
		string res;
		for(int i=0;i<n;i++){
			int l=i,r=i;
			while(0<l&&r<n-1&&s[l-1]==s[r+1])l--,r++;
			auto t=s.substr(l,r-l+1);
			if(siz(t)>siz(res))res=t;
		}
		for(int i=1;i<n;i++)if(s[i-1]==s[i]){
			int l=i-1,r=i;
			while(0<l&&r<n-1&&s[l-1]==s[r+1])l--,r++;
			auto t=s.substr(l,r-l+1);
			if(siz(t)>siz(res))res=t;
		}
		return res;
    }
};