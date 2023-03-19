#include<bits/stdc++.h>
using namespace std;
#define siz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
class Solution {
public:
    int reverse(int x) {
		constexpr int N=214748364;
		int res=0;
		while(x){
			int d=x%10;
			if(res>N||(res==N&&d>7))return 0;
			if(res<-N||(res==-N&&d<-8))return 0;
			res=res*10+d;x/=10;
		}
		return res;
    }
};