#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	// std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m=0;cin>>n;
	if(n>=100000){n-=100000,m=3234566667;goto ss;}
	if(n>=99319){n-=99319,m=3234321000;goto ss;}
	if(n>=98625){n-=98625,m=3233210000;goto ss;}
	if(n>=98002){n-=98002,m=3232100000;goto ss;}
	if(n>=97308){n-=97308,m=3223210000;goto ss;}
	if(n>=96685){n-=96685,m=3222100000;goto ss;}
	if(n>=96202){n-=96202,m=3221000000;goto ss;}
	if(n>=95579){n-=95579,m=3212100000;goto ss;}
	if(n>=95097){n-=95097,m=3211000001;goto ss;}
	if(n>=94829){n-=94829,m=3210000000;goto ss;}
	if(n>=94109){n-=94109,m=2345432100;goto ss;}
	if(n>=93389){n-=93389,m=2344321000;goto ss;}
	if(n>=92695){n-=92695,m=2343210000;goto ss;}
	if(n>=91975){n-=91975,m=2334321000;goto ss;}
	if(n>=91281){n-=91281,m=2333210000;goto ss;}
	if(n>=90658){n-=90658,m=2332100000;goto ss;}
	if(n>=89964){n-=89964,m=2323210000;goto ss;}
	if(n>=89341){n-=89341,m=2322100000;goto ss;}
	if(n>=88858){n-=88858,m=2321000000;goto ss;}
	if(n>=88138){n-=88138,m=2234321000;goto ss;}
	if(n>=87444){n-=87444,m=2233210000;goto ss;}
	if(n>=86821){n-=86821,m=2232100000;goto ss;}
	if(n>=86127){n-=86127,m=2223210000;goto ss;}
	if(n>=85504){n-=85504,m=2222100000;goto ss;}
	if(n>=85021){n-=85021,m=2221000000;goto ss;}
	if(n>=84398){n-=84398,m=2212100000;goto ss;}
	if(n>=83916){n-=83916,m=2211000001;goto ss;}
	if(n>=83648){n-=83648,m=2210000000;goto ss;}
	if(n>=82954){n-=82954,m=2123210000;goto ss;}
	if(n>=82331){n-=82331,m=2122100000;goto ss;}
	if(n>=81848){n-=81848,m=2121000000;goto ss;}
	if(n>=81225){n-=81225,m=2112100000;goto ss;}
	if(n>=80743){n-=80743,m=2111000001;goto ss;}
	if(n>=80475){n-=80475,m=2110000000;goto ss;}
	if(n>=79993){n-=79993,m=2101000001;goto ss;}
	if(n>=79725){n-=79725,m=2100000000;goto ss;}
	if(n>=79005){n-=79005,m=1234321000;goto ss;}
	if(n>=78311){n-=78311,m=1233210000;goto ss;}
	if(n>=77688){n-=77688,m=1232100000;goto ss;}
	if(n>=76994){n-=76994,m=1223210000;goto ss;}
	if(n>=76371){n-=76371,m=1222100000;goto ss;}
	if(n>=75888){n-=75888,m=1221000000;goto ss;}
	if(n>=75265){n-=75265,m=1212100000;goto ss;}
	if(n>=74783){n-=74783,m=1211000001;goto ss;}
	if(n>=74515){n-=74515,m=1210000000;goto ss;}
	if(n>=73821){n-=73821,m=1123210000;goto ss;}
	if(n>=73198){n-=73198,m=1122100000;goto ss;}
	if(n>=72715){n-=72715,m=1121000000;goto ss;}
	if(n>=72092){n-=72092,m=1112100000;goto ss;}
	if(n>=71610){n-=71610,m=1111000001;goto ss;}
	if(n>=71342){n-=71342,m=1110000000;goto ss;}
	if(n>=70860){n-=70860,m=1101000001;goto ss;}
	if(n>=70592){n-=70592,m=1100000000;goto ss;}
	if(n>=69969){n-=69969,m=1012100000;goto ss;}
	if(n>=69487){n-=69487,m=1011000001;goto ss;}
	if(n>=69219){n-=69219,m=1010000000;goto ss;}
	if(n>=68736){n-=68736,m=1001000000;goto ss;}
	if(n>=68202){n-=68202,m=999876543;goto ss;}
	if(n>=67719){n-=67719,m=998765432;goto ss;}
	if(n>=67452){n-=67452,m=989876543;goto ss;}
	if(n>=66969){n-=66969,m=988765432;goto ss;}
	if(n>=66346){n-=66346,m=987654321;goto ss;}
	if(n>=66079){n-=66079,m=899876543;goto ss;}
	if(n>=65596){n-=65596,m=898765432;goto ss;}
	if(n>=65329){n-=65329,m=889876543;goto ss;}
	if(n>=64846){n-=64846,m=888765432;goto ss;}
	if(n>=64223){n-=64223,m=887654321;goto ss;}
	if(n>=63740){n-=63740,m=878765432;goto ss;}
	if(n>=63117){n-=63117,m=877654321;goto ss;}
	if(n>=62423){n-=62423,m=876543210;goto ss;}
	if(n>=62156){n-=62156,m=789876543;goto ss;}
	if(n>=61673){n-=61673,m=788765432;goto ss;}
	if(n>=61050){n-=61050,m=787654321;goto ss;}
	if(n>=60567){n-=60567,m=778765432;goto ss;}
	if(n>=59944){n-=59944,m=777654321;goto ss;}
	if(n>=59250){n-=59250,m=776543210;goto ss;}
	if(n>=58627){n-=58627,m=767654321;goto ss;}
	if(n>=57933){n-=57933,m=766543210;goto ss;}
	if(n>=57213){n-=57213,m=765432100;goto ss;}
	if(n>=56730){n-=56730,m=678765432;goto ss;}
	if(n>=56107){n-=56107,m=677654321;goto ss;}
	if(n>=55413){n-=55413,m=676543210;goto ss;}
	if(n>=54790){n-=54790,m=667654321;goto ss;}
	if(n>=54096){n-=54096,m=666543210;goto ss;}
	if(n>=53376){n-=53376,m=665432100;goto ss;}
	if(n>=52682){n-=52682,m=656543210;goto ss;}
	if(n>=51962){n-=51962,m=655432100;goto ss;}
	if(n>=51242){n-=51242,m=654321000;goto ss;}
	if(n>=50619){n-=50619,m=567654321;goto ss;}
	if(n>=49925){n-=49925,m=566543210;goto ss;}
	if(n>=49205){n-=49205,m=565432100;goto ss;}
	if(n>=48511){n-=48511,m=556543210;goto ss;}
	if(n>=47791){n-=47791,m=555432100;goto ss;}
	if(n>=47071){n-=47071,m=554321000;goto ss;}
	if(n>=46351){n-=46351,m=545432100;goto ss;}
	if(n>=45631){n-=45631,m=544321000;goto ss;}
	if(n>=44937){n-=44937,m=543210000;goto ss;}
	if(n>=44243){n-=44243,m=456543210;goto ss;}
	if(n>=43523){n-=43523,m=455432100;goto ss;}
	if(n>=42803){n-=42803,m=454321000;goto ss;}
	if(n>=42083){n-=42083,m=445432100;goto ss;}
	if(n>=41363){n-=41363,m=444321000;goto ss;}
	if(n>=40669){n-=40669,m=443210000;goto ss;}
	if(n>=39949){n-=39949,m=434321000;goto ss;}
	if(n>=39255){n-=39255,m=433210000;goto ss;}
	if(n>=38632){n-=38632,m=432100000;goto ss;}
	if(n>=37912){n-=37912,m=345432100;goto ss;}
	if(n>=37192){n-=37192,m=344321000;goto ss;}
	if(n>=36498){n-=36498,m=343210000;goto ss;}
	if(n>=35778){n-=35778,m=334321000;goto ss;}
	if(n>=35084){n-=35084,m=333210000;goto ss;}
	if(n>=34461){n-=34461,m=332100000;goto ss;}
	if(n>=33767){n-=33767,m=323210000;goto ss;}
	if(n>=33144){n-=33144,m=322100000;goto ss;}
	if(n>=32661){n-=32661,m=321000000;goto ss;}
	if(n>=31941){n-=31941,m=234321000;goto ss;}
	if(n>=31247){n-=31247,m=233210000;goto ss;}
	if(n>=30624){n-=30624,m=232100000;goto ss;}
	if(n>=29930){n-=29930,m=223210000;goto ss;}
	if(n>=29307){n-=29307,m=222100000;goto ss;}
	if(n>=28824){n-=28824,m=221000000;goto ss;}
	if(n>=28201){n-=28201,m=212100000;goto ss;}
	if(n>=27719){n-=27719,m=211000001;goto ss;}
	if(n>=27451){n-=27451,m=210000000;goto ss;}
	if(n>=26757){n-=26757,m=123210000;goto ss;}
	if(n>=26134){n-=26134,m=122100000;goto ss;}
	if(n>=25651){n-=25651,m=121000000;goto ss;}
	if(n>=25028){n-=25028,m=112100000;goto ss;}
	if(n>=24546){n-=24546,m=111000001;goto ss;}
	if(n>=24278){n-=24278,m=110000000;goto ss;}
	if(n>=23795){n-=23795,m=101000000;goto ss;}
	if(n>=23261){n-=23261,m=99876543;goto ss;}
	if(n>=22778){n-=22778,m=98765432;goto ss;}
	if(n>=22511){n-=22511,m=89876543;goto ss;}
	if(n>=22028){n-=22028,m=88765432;goto ss;}
	if(n>=21405){n-=21405,m=87654321;goto ss;}
	if(n>=20922){n-=20922,m=78765432;goto ss;}
	if(n>=20299){n-=20299,m=77654321;goto ss;}
	if(n>=19605){n-=19605,m=76543210;goto ss;}
	if(n>=18982){n-=18982,m=67654321;goto ss;}
	if(n>=18288){n-=18288,m=66543210;goto ss;}
	if(n>=17568){n-=17568,m=65432100;goto ss;}
	if(n>=16874){n-=16874,m=56543210;goto ss;}
	if(n>=16154){n-=16154,m=55432100;goto ss;}
	if(n>=15434){n-=15434,m=54321000;goto ss;}
	if(n>=14714){n-=14714,m=45432100;goto ss;}
	if(n>=13994){n-=13994,m=44321000;goto ss;}
	if(n>=13300){n-=13300,m=43210000;goto ss;}
	if(n>=12580){n-=12580,m=34321000;goto ss;}
	if(n>=11886){n-=11886,m=33210000;goto ss;}
	if(n>=11263){n-=11263,m=32100000;goto ss;}
	if(n>=10569){n-=10569,m=23210000;goto ss;}
	if(n>=9946){n-=9946,m=22100000;goto ss;}
	if(n>=9463){n-=9463,m=21000000;goto ss;}
	if(n>=8840){n-=8840,m=12100000;goto ss;}
	if(n>=8357){n-=8357,m=11000000;goto ss;}
	if(n>=7823){n-=7823,m=9876543;goto ss;}
	if(n>=7340){n-=7340,m=8765432;goto ss;}
	if(n>=6717){n-=6717,m=7654321;goto ss;}
	if(n>=6023){n-=6023,m=6543210;goto ss;}
	if(n>=5303){n-=5303,m=5432100;goto ss;}
	if(n>=4583){n-=4583,m=4321000;goto ss;}
	if(n>=3889){n-=3889,m=3210000;goto ss;}
	if(n>=3266){n-=3266,m=2100000;goto ss;}
	if(n>=2784){n-=2784,m=1000001;goto ss;}
	ss:
	for(;n;){
		auto s=std::to_string(++m);
		for(int j=1;j<siz(s);j++)if(abs(s[j]-s[j-1])>1)goto next;
		n--;
		next:;
	}
	cout<<m;
	// std::basic_string<int>ans;
	// int m=0;
	// for(int i=1;;i++){
	// 	auto s=std::to_string(i);
	// 	for(int j=1;j<siz(s);j++)if(abs(s[j]-s[j-1])>1)goto next;
	// 	ans+=i;
	// 	if(siz(ans)>=100000)break;
	// 	next:;
	// }
	// for(int i=0;i<siz(ans);i++){
	// 	for(int j=i+1;;j++){
	// 		if(j==siz(ans)-1||ans[j]-ans[i]>=int(1e6)){
	// 			// printf("if(n>=%u){n-=%u,m=%u\n",j+1,j+1,j);
	// 			cout<<"if(n>="<<j+1<<"){n-="<<j+1<<",m="<<ans[j]<<";\n";
	// 			i=j;
	// 			break;
	// 		}
	// 	}
	// }
	return 0;
}