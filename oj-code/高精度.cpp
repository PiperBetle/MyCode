#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<vector>
using std::cin;using std::cout;
struct bigint{
private:
	int op;
	std::vector<int>data;
	static constexpr int base=10000,width=4;
public:
	int &operator[](const int &t){return data[t];}
	bigint &add(bigint &n){

	}
	bigint &operator=(int num){
		this->data.clear();
		if(num<0)op=-1,num=-num;else op=(num!=0);
		do data.emplace_back(num%base),num/=base;while(num);
		return *this;
	}
	friend std::ostream &operator<<(std::ostream &out,bigint &num){
		if(num.op==-1)out<<'-';
		out<<num.data.back();
		for(int i=num.data.size()-2;i>=0;i--)out<<std::setw(bigint::width)<<std::setfill('0')<<num[i];
		return out;
	}
};
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	bigint a;a=11451419;
	cout<<a;
    return 0;
}