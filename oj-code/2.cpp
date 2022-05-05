#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<random>
#include<windows.h>
int main(int argc,char const *argv[]){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::mt19937 rand(std::random_device{}());
	std::vector<std::string>str;
	str.emplace_back("暴搜挂着机，打表出省一。骗分过样例，暴力出奇迹。");
	str.emplace_back("十年 OI 一场空，不开 long long 见祖宗。");
	str.emplace_back("我想到了一个绝妙的证法，但是这里空白太小，我写不下。");
	str.emplace_back("0x2b|~0x2b==0xff");
	str.emplace_back("复制+粘贴=Accepted");
	str.emplace_back("n 方过百万，暴力碾标算。");
	str.emplace_back("如果一个人比我小还比我强，那么我就可以退役了。");
	str.emplace_back("I AK IOI!");
	str.emplace_back("关于 SPFA，它死了");
	str.emplace_back("Farmer John 和他的奶牛 Bessie……");
	str.emplace_back("人生就像贪心，每一步的最好的，不一定就是最优解。");
	str.emplace_back("我是沙茶蒟蒻呜呜呜");
	str.emplace_back("你是神犇巨佬膜膜膜");
	str.emplace_back("unsigned long long rp=-1;");
	str.emplace_back("我来NOIP只做三件事！爆零！睡觉！扫雷！（跪）");
	str.emplace_back("加边！加边！加边！");
	str.emplace_back("push 的反义词难道不是 pop？");
	str.emplace_back("做多项式题就像嗑药，出多项式题就像贩毒。");
	str.emplace_back("说句闲话：研究珂学的最好方法是A了这道题，祝你们成功（滑稽");
	str.emplace_back("太皱的纸飞机飞不远。");
	str.emplace_back("所累哇多卡纳~");
	str.emplace_back("堕落！萌死他卡多！");
	str.emplace_back("那个男人又54320了。");
	str.emplace_back("上个厕所回来收尸。");
	str.emplace_back("安装TC130精神扰乱控制装置");
	str.emplace_back("畜生，是谁给了你基本卡组？是谁教会你打牌？是谁让你找个妹子随便坐？");
	str.emplace_back("新手第一步，发现心火牧。");
	str.emplace_back("玛里（）斯");
	str.emplace_back("你以为你打的是我的脸？？");
	str.emplace_back("那女孩对我说，代价为十辆铲车");
	str.emplace_back("愿青龙指引你，在 10 颗法力值的时候，钓上一整天的鱼！");
	str.emplace_back("伟安生，不解机，猎死解，运不远。");
	str.emplace_back("山上的朋友、树上的朋友、井里的朋友、铁窗后的朋友、天台上的朋友，举起你们的双手，把你的元气借给我，让对手接受王的制裁！");
	str.emplace_back("千奇百怪术士紫，百无一用猎人橙。");
	str.emplace_back("LGD•SG•DAI•老干爹•帅哥戴•时代弄潮儿•巴黎时尚周专用男模•异灵法异灵骑超凡德奇迹德偶数宇宙猎顶峰天花板•排位悍将•天梯杀戮之神•无敌上分机器•宇宙术创始人•叶问术快乐术宗师•炉石里程碑传承人•文学鉴赏家•留名千古流芳百世的著名术士学家•世界文学哲学科学数学奖获得者•超费理论创始者提出者•千万少女梦中情人•世界颜值的顶峰人奠基人•旧时代与新时代跨时代标杆人物•衔接世界与世界沟通交流的主导者•时尚流行音乐歌手•游戏全能王蜀山多面手•竞技场之王•不可置疑的大师•帅帅帅之无敌帅•天梯26神之戴神•异灵术老师​");
	str.emplace_back("正在看直播的水友请调低音量，在公共场所看直播的水友请戴上耳机，心脏不太好的水友请退出直播间。");
	str.emplace_back("这是1，这个撞这个是2，这个用技能咬一口是3……");
	str.emplace_back("我和老师去铲雪，老师叫我带铲子，我叫老师戴铲子。");
	str.emplace_back("对的对的，对的，哦！不对！");
	str.emplace_back("对的对的，对的，哦！不对！");
	str.emplace_back("对的对的，对的，哦！不对！");
	str.emplace_back("对的对的，对的，哦！不对！");
	str.emplace_back("对的对的，对的，哦！不对！");
	str.emplace_back("对的对的，对的，哦！不对！");
	str.emplace_back("对的对的，对的，哦！不对！");
	system(("echo \033[36;40m"+str[rand()%str.size()]).data());
	system("echo|set /p=\033[37;40m");
	return 0;
}