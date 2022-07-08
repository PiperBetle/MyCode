#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<vector>
#include<cassert>
using std::cin;using std::cout;
constexpr double eps=1e-8;
template<typename any>inline any sqr(const any &x){return x*x;}
inline int get_op(const double &x){if(fabs(x)<eps)return 0;return fabs(x)/x;}
struct vector{
	double x,y;
	bool operator<(const vector &t)const{return fabs(x-t.x)<eps?y<t.y:x<t.x;}
	bool operator==(const vector &t)const{return fabs(x-t.x)<eps&&fabs(y-t.y)<eps;}
	vector(const double &a=0,const double &b=0):x(a),y(b){}
	double operator~(){return sqrt(x*x+y*y);}
	template<typename any>friend any &operator>>(any &a,vector &b){return a>>b.x>>b.y;}
	template<typename any>friend any &operator<<(any &a,const vector &b){return a<<b.x<<' '<<b.y;}
	friend vector operator+(const vector &a,const vector &b){return {a.x+b.x,a.y+b.y};}
	vector &operator+=(const vector &t){x+=t.x,y+=t.y;return *this;}
	friend vector operator-(const vector &a,const vector &b){return {a.x-b.x,a.y-b.y};}
	vector &operator-=(const vector &t){x-=t.x,y-=t.y;return *this;}
	friend vector operator*(const vector &a,const double &b){return {a.x*b,a.y*b};}
	vector &operator*=(const double &t){x*=t,y*=t;return *this;}
	friend vector operator/(const vector &a,const double &b){return {a.x/b,a.y/b};}
	vector &operator/=(const double &t){x/=t,y/=t;return *this;}
	friend double operator*(const vector &a,const vector &b){return a.x*b.x+a.y*b.y;}
	friend double operator/(const vector &a,const vector &b){return a.x*b.y-a.y*b.x;}
	bool frontis(const vector &t)const{auto r=*this*t;return +eps<r;}
	bool backis(const vector &t)const{auto r=*this*t;return -eps>r;}
	bool leftis(const vector &t)const{auto r=*this/t;return +eps<r;}
	bool rightis(const vector &t)const{auto r=*this/t;return -eps>r;}
	friend double dis(const vector &a,const vector &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
	vector rot90(){return {-y,x};}
};
struct segment{
	vector p1,p2;
	segment(const vector &a={0,0},const vector &b={0,0}):p1(a),p2(b){};
	template<typename any>friend any &operator>>(any &a,segment &b){return a>>b.p1>>b.p2;}
	template<typename any>friend any &operator<<(any &a,const segment &b){return a<<b.p1<<' '<<b.p2;}
	friend bool operator&(const segment &a,const segment &b){return fabs((a.p2-a.p1)*(b.p2-b.p1))<eps;}
	friend bool operator|(const segment &a,const segment &b){return fabs((a.p2-a.p1)/(b.p2-b.p1))<eps;}
	friend bool banana(const segment &a,const segment &b){
		if(std::min(a.p1.x,a.p2.x)>std::max(b.p1.x,b.p2.x)||std::min(b.p1.x,b.p2.x)>std::max(a.p1.x,a.p2.x)||std::min(a.p1.y,a.p2.y)>std::max(b.p1.y,b.p2.y)||std::min(b.p1.y,b.p2.y)>std::max(a.p1.y,a.p2.y))return false;
		return get_op(((a.p2-a.p1)/(b.p1-a.p1))*((a.p2-a.p1)/(b.p2-a.p1)))<=0&&get_op(((b.p2-b.p1)/(a.p1-b.p1))*((b.p2-b.p1)/(a.p2-b.p1)))<=0;
	}
	friend vector focus(const segment &a,const segment &b){
		vector v=a.p2-a.p1,w=b.p2-b.p1,u=a.p1-b.p1;
		return a.p1+v*((w/u)/(v/w));
	}
	friend double dis(const segment &a,const vector &b){
		if(a.p1==a.p2)return ~(b-a.p1);
		auto v1=a.p2-a.p1,v2=b-a.p1,v3=b-a.p2;
		if(v1.backis(v2))return ~v2;
		if(v1.frontis(v3))return ~v3;
		return fabs(v1/v2)/~v1;
	}
	friend double dis(const segment &a,const segment &b){
		if(banana(a,b))return 0;
		return std::min({dis(a,b.p1),dis(a,b.p2),dis(b,a.p1),dis(b,a.p2)});
	}
	vector project(const vector &a)const{
		auto u=p2-p1,v=a-p1;
		auto r=u*v/~u;
		return p1+vector{r*u.x/~u,r*u.y/~u};
	}
	vector reflect(const vector &a)const{
		auto u=p2-p1,v=a-p1;
		auto r=u*v/~u;
		return p1+vector{r*u.x/~u,r*u.y/~u}*2-v;
	}
};
struct circle{
	vector p;double r;
	circle(const vector &a={0,0},const double &b=0):p(a),r(b){}
	template<typename any>friend any &operator>>(any &a,circle &b){return a>>b.p>>b.r;}
	template<typename any>friend any &operator<<(any &a,const circle &b){return a<<b.p<<' '<<b.r;}
	friend segment focus(const circle &a,const segment &b){
		auto d=b.project(a.p),u=b.p2-b.p1,e=u/~u;
		auto t=sqrt(a.r*a.r-sqr(dis(d,a.p)));
		segment res{d+e*t,d-e*t};
		if(res.p2<res.p1)std::swap(res.p1,res.p2);
		return res;
	}
};
struct points:std::vector<vector>{
#define p (*this)
	template<typename any>points &read(any &t,int n=-1){
		if(n==-1)cin>>n;
		p.resize(n);
		for(int i=0;i<n;i++)t>>p[i];
		return *this;
	}
	double area(){
		if(p.empty())return 0;
		double ans=0;
		for(size_t i=1;i<p.size()-1;i++)ans+=(p[i]-p[0])/(p[i+1]-p[0]);
		return ans/2;
	}
	points tobag(){
		std::sort(p.begin(),p.end());
		p.erase(std::unique(p.begin(),p.end()),p.end());
		points up;up.insert(up.end(),{p[0],p[1]});
		points dw;dw.insert(dw.end(),{p.back(),p[p.size()-2]});
		for(size_t i=2;i<p.size();up.emplace_back(p[i++]))
			for(size_t j=up.size();j>=2&&!(up[j-1]-up[j-2]).rightis(p[i]-up[j-2]);j--)up.pop_back();
		for(size_t i=p.size()-3;~i;dw.emplace_back(p[i--]))
			for(size_t j=dw.size();j>=2&&!(dw[j-1]-dw[j-2]).rightis(p[i]-dw[j-2]);j--)dw.pop_back();
		reverse(dw.begin(),dw.end());
		for(size_t i=up.size()-2;i>=1;i--)dw.emplace_back(up[i]);
		return dw;
	}
	double xzqk(){
		double ans=0;
		for(size_t i=0,j=1;i<p.size();i++){
			while((p[(i+1)%p.size()]-p[i])/(p[j]-p[i])<(p[(i+1)%p.size()]-p[i])/(p[(j+1)%p.size()]-p[i]))(++j)%=p.size();
			ans=std::max({ans,dis(p[i],p[j]),dis(p[(i+1)%p.size()],p[j])});
		}
		return ans;
	}
	circle incircle(){
		assert(p.size()==3);
		auto u=p[1]-p[0],v=p[2]-p[0];u=u/~u*~v;
		segment l1{p[0],p[0]+u+v};
		u=p[2]-p[1],v=p[0]-p[1];u=u/~u*~v;
		segment l2{p[1],p[1]+u+v};
		auto pp=focus(l1,l2);
		return circle{pp,dis(segment{p[0],p[1]},pp)};
	}
	circle outcirce(){
		assert(p.size()==3);
		auto u=p[1]-p[0],mid=(p[0]+p[1])/2;
		segment l1{mid,mid+u.rot90()};
		u=p[2]-p[0],mid=(p[0]+p[2])/2;
		segment l2{mid,mid+u.rot90()};
		auto pp=focus(l1,l2);
		return circle{pp,dis(p[0],pp)};
	}
#undef p
};
circle a;
segment b;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(10);
	int T;
	cin>>a>>T;
	while(T--){
		cin>>b;
		cout<<focus(a,b)<<'\n';
	}
	return 0;
}