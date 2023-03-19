#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_set>
using std::cin;using std::cout;
std::string a;
std::unordered_set<std::string>rs={"and","break","do","else","elseif","end","false","for","function","if","in","local","nil","not","or","repeat","return","then","true","until","while"};
std::unordered_set<std::string>sb={"+","-","*","/","%","^","#","==",">=","<=",">","<","~=","(",")","{","}","[","]",";",":",",",".","..","...","="};
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	while(std::getline(cin,a)){
		for(size_t i=0;i<a.size();i++){
			if(a[i]=='-'&&a[i+1]=='-'){
				goto eol;
			}
			if(a[i]==' '){
				continue;
			}
			if(a[i]=='0'&&(a[i+1]=='x'||a[i]+1=='X')){
				std::string t({a[i],a[i+1]});
				i+=2;
				for(size_t j=i;j<a.size()&&isalnum(a[j]);j++){
					t+=a[i=j];
				}
				cout<<"[NUMBER] "<<t<<'\n';
				continue;
			}
			if(isdigit(a[i])||(a[i]=='.'&&isdigit(a[i+1]))){
				std::string t;
				bool op=false,pt=false,ee=false;
				for(size_t j=i;j<a.size()&&(isdigit(a[j])||(op&&(a[j]=='+'||a[j]=='-'))||a[j]=='.'||a[j]=='e');j++){
					if(a[j]=='.'){
						if(pt){
							break;
						}else{
							pt=true;
						}
						if(a[j+1]=='e'){
							ee=true;
						}
					}
					if(a[j]=='e'){
						if(op){
							break;
						}else{
							op=true;
						}
					}
					if(a[j]=='+'||a[j]=='-'){
						if(ee)break;
						op=false;
					}
					t+=a[i=j];
				}
				while(t.front()=='0'&&t.size()>1&&t[1]!='.'&&t[1]!='e'){
					t.erase(0,1);
				}
				cout<<"[NUMBER] "<<t<<'\n';
				continue;
			}
			if(a[i]=='\"'||a[i]=='\''){
				std::string t({a[i++]});
				for(size_t j=i;j<a.size()&&((a[j]==t.front()&&a[j-1]=='\\')||a[j]!=t.front());j++){
					t+=a[i=j];
				}
				i++;
				cout<<"[STRING] "<<(t+=t.front())<<'\n';
				continue;
			}
			if(isalpha(a[i])){
				std::string t;
				for(size_t j=i;j<a.size()&&(isalnum(a[j])||a[j]=='_');j++){
					t+=a[i=j];
				}
				if(rs.count(t)){
					cout<<"[RESERVED] "<<t<<'\n';
				}else{
					cout<<"[NAME] "<<t<<'\n';
				}
				continue;
			}
			if(sb.count(std::string({a[i]}))){
				std::string t;
				for(int j=i;sb.count(t+a[j]);j++){
					t+=a[i=j];
				}
				cout<<"[SYMBOL] "<<t<<'\n';
				continue;
			}
		}
		eol:
		cout<<"[EOL]\n";
	}
	return 0;
}