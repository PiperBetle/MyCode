#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int ssr,sr,r,s,b,c,gan,zhen,wei,sheng,food,water;//概率为千分之n 
int ssro=0,sro=0,ro=90,so=90,bo=999,co=0,gano=0,zheno=0,weio=0,shengo=0,foodo=0,watero=0;//数量 
int tianshu=365,i,j,k,card,now,flag=1,zzxh=1,ak47=0;
int chi=1000,he=1000,jing=1000,money,qwert,isfu[21],houtiantianfu[11];
clock_t begin,end;
char t,jw,qi[4][4];
int sx,sy;
string as[4],fu[21];
int gan_=30,zhen_=30,wei_=30,sheng_=30,food_=30,water_=30;
int random(int,int);
void pr(int);
void getssr();
int main()
{
	for(i=0;i<=20;i++)isfu[i]=0; 
	fu[1]="好运气   ssr+0.6%";
	fu[2]="坏运气   ssr-0.6%";
	fu[4]="喜欢食物 食物卡+1.6%";
	fu[5]="讨厌食物 食物卡-1.6%";
	fu[7]="精神强大 精神下降更慢";
	fu[8]="精神脆弱 精神下降更慢";
	fu[9]="生存者   生存卡片+0.6%";
	fu[10]="宅       生存卡片-0.6%";
	fu[11]="少汗     消耗更少水分";
	fu[12]="多汗     消耗更多水分";
	fu[13]="忍者     消耗更少体力";
	fu[14]="肥胖     消耗更多体力";
	fu[15]="喜欢饮料 水卡+1.6%";
	fu[16]="讨厌饮料 水卡-1.6%";
	fu[17]="喜欢药物 药+1.6%";//药包括镇定剂
	fu[18]="讨厌药物 药-1.6%";//加起来
	fu[19]="贪婪     获得100-140元";
	fu[20]="忠诚     获得60-100元";
	as[1]="坏血病";as[2]="破伤风";as[3]="禽流感"; 
	ssr=12;
	food=water=58;
	gan=wei=sheng=10;
	zhen=24;
	b=194;
	s=130;
	r=96;
	sr=64;
	;
	c=1000-ssr-sr-r-s-b-gan-zhen-wei-sheng-food-water;
	srand(time(NULL));
	if(rand()%4==0)tianshu++;
	begin=clock();
	for(i=1;i<=tianshu;i++)
	{
		int iop=0;
		gan_=gan_+random(-5,5);if(gan_>=50)gan_=50;if(gan_<=10)gan_=10;
		zhen_=zhen_+random(-5,5);if(zhen_>=50)zhen_=50;if(zhen_<=10)zhen_=10;
		food_=food_+random(-5,5);if(food_>=50)food_=50;if(food_<=10)food_=10;
		water_=water_+random(-5,5);if(water_>=50)water_=50;if(water_<=10)water_=10;
		wei_=wei_+random(-5,5);if(wei_>=50)wei_=50;if(wei_<=10)wei_=10;
		sheng_=sheng_+random(-5,5);if(sheng_>=50)sheng_=50;if(sheng_<=10)sheng_=10;
		cout<<"第"<<i<<"天"<<endl;
		if(i==1)money=100;
		else
		{
			qwert=random(60,140);
			money+=qwert+houtiantianfu[3];
			cout<<"你获得了"<<qwert<<"元,现在有"<<money<<"元"<<endl;
			if(houtiantianfu[3]>0)cout<<"其中通过后天天赋你额外获得了"<<houtiantianfu[3]<<"元"<<endl; 
		}
		if((chi<=0)&&(he<=0))
		{
			system("color 8F");
			cout<<"饥渴难耐!"<<endl;
			pr(1);
			exit(1);
		}
		if(chi<=0)
		{
			system("color 8F");
			cout<<"饿殍遍野!"<<endl;
			pr(1);
			exit(1);
		}
		if(he<=0)
		{
			system("color 8F");
			cout<<"饮鸩止渴!"<<endl;
			pr(1);
			exit(1);
		}
		if(flag==1)
		{
			if(rand()%10==0)
			{
				flag=-1;
				qwert=rand()%3;
				switch(qwert)
				{
					case 0:zzxh=1;cout<<"你得了"<<as[1]<<endl;break;
					case 1:zzxh=2;cout<<"你得了"<<as[2]<<endl;break;
					case 2:zzxh=3;cout<<"你得了"<<as[3]<<endl;break;
				}
			}
		}
		
		for(;;)
		{
			cin>>t;
			if(t=='1')
			{
				if(money<10)
				{
					cout<<"资金不足,你只有"<<money<<"元"<<endl;
					jing--;
				}
				else
				{
					money-=10;
					card=rand()%1000+1;
					now=c;
					if(card<=now)
					{
						co++;
						cout<<"你抽到了c级卡"<<endl;
						jing-=random(10,20);
					}
					else
					{
						now+=b;
						if(card<=now)
						{
							bo++;
							cout<<"你抽到了b级卡"<<endl;
							jing-=random(10,15);
						}
						else
						{
							now+=s;
							if(card<=now)
							{
								so++;
								cout<<"你抽到了s级卡"<<endl; 
								jing-=random(5,15);
							}
							else
							{
								now+=r;
								if(card<=now)
								{
									ro++;
									cout<<"你抽到了r级卡"<<endl;
									jing-=random(5,10);
								}
								else
								{
									now+=sr;
									if(card<=now)
									{
										sro++;
										cout<<"你抽到了sr级卡"<<endl;
										jing-=random(1,10);
									}
									else
									{
										now+=water;
										if(card<=now)
										{
											watero++;
											cout<<"你抽到了水卡"<<endl;
											jing-=random(1,5);
											system("color B5");
											system("pause");
											system("color 07");
										}
										else
										{
											now+=food;
											if(card<=now)
											{
												foodo++;
												cout<<"你抽到了食物卡"<<endl;
												jing-=random(1,5);
												system("color E5");
												system("pause");
												system("color 07");
											}
											else
											{
												now+=wei;
												if(card<=now)
												{
													weio++;
													cout<<"你抽到了维生素卡"<<endl;
													jing-=random(1,3);
													system("color C5");
													system("pause");
													system("color 07");
												}
												else
												{
													now+=sheng;
													if(card<=now)
													{
														shengo++;
														cout<<"你抽到了抗生素卡"<<endl;
														jing-=random(1,3);
														system("color C5");
														system("pause");
														system("color 07");
													}
													else
													{
														now+=gan;
														if(card<=now)
														{
															gano++;
															cout<<"你抽到了抗感染卡"<<endl;
															jing-=random(1,3);
															system("color C5");
															system("pause");
															system("color 07");
														}
														else
														{
															now+=zhen;
															if(card<=now)
															{
																zheno++;
																cout<<"你抽到了镇定剂卡"<<endl;
																jing-=random(1,2);
																system("color F5");
																system("pause");
																system("color 07");
															}
															else
															{
																getssr();
															}	
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			} 
			else
			{
				if(t=='2')
				{
					break;
				}
				else
				if(t=='3')
				{
					pr(0);
				}
				else
				{
					if(t=='4')
					{
						if(foodo>=1)
						{
							if(chi>=1000)
							{
								system("color 8F");
								cout<<"肠肥脑满!"<<endl;
								pr(1);
								exit(1);
							}
							else
							{
								foodo--;
								qwert=random(100,200);
								chi+=qwert;
								chi=min(chi,1000);
								cout<<"体力增加"<<qwert<<",现在有"<<chi<<"体力"<<endl;
							}
						}
						else
						{
							cout<<"食物卡不足"<<endl;
							jing--;
						}
					}
					else
					{
						if(t=='5')
						{
							if(watero>=1)
							{
								watero--;
								qwert=random(100,200);
								he+=qwert;
								he=min(he,1000);
								cout<<"水分增加"<<qwert<<",现在有"<<he<<"水分"<<endl;
								if(rand()%10==0)
								{
									watero++;
									system("color D9");
									cout<<"再来一瓶"<<endl;
									system("pause");
									system("color 07");
								}
							}
							else
							{
								cout<<"水卡不足"<<endl;
								jing--;
							}
						}
						else
						{
							if(t=='6')
							{
								if(zheno>=1)
								{
									zheno--;
									qwert=random(100,200);
									jing+=qwert;
									jing=min(jing,1000);
									cout<<"精神增加"<<qwert<<",现在有"<<jing<<"精神"<<endl;
									iop++;
									if((iop>=3)&&(houtiantianfu[1]==0))
									{
										system("color 8F");
										cout<<"精神上瘾!"<<endl;
										pr(1);
										exit(1);
									}
								}
								else
								{
									cout<<"镇定剂卡不足"<<endl;
									jing--;
								}
							}
							else
							{
								if(t=='7')
								{
									if(flag==1)
									{
										cout<<"你很健康"<<endl;
										jing--;
									}
									else
									{
										if(zzxh==1)
										{
											if(weio>=1)
											{
												weio--;
												cout<<"你的"<<as[1]<<"治好了" <<endl;
												flag=1;
											}
											else
											{
												cout<<"维生素卡不足"<<endl;
												jing--;
											}
										}
										else
										{
											if(zzxh==2)
											{
												if(gano>=1)
												{
													gano--;
													cout<<"你的"<<as[2]<<"治好了" <<endl;
													flag=1;
												}
												else
												{
													cout<<"抗感染卡不足"<<endl;
													jing--;
												}
											} 
											else
											{
												if(shengo>=1)
												{
													shengo--;
													cout<<"你的"<<as[3]<<"治好了" <<endl;
													flag=1;
												}
												else
												{
													cout<<"抗生素卡不足"<<endl;
													jing--;
												}
											}
										}
									}
								}
								else
								{
									if(t=='8')
									{
										cout<<"你要换什么卡" <<endl;
										cout<<"1食物卡:"<<food_<<" 2水卡:"<<water_<<" 3镇定剂卡:"<<zhen_<<" 4维生素卡:"<<wei_<<" 5抗感染卡:"<<gan_<<" 6抗生素卡:"<<sheng_<<" 7离开"<<endl; 
										cin>>jw;
										switch(jw)
										{
											case '1':
												if(foodo<=0)
												{
													cout<<"食物卡不足"<<endl;
													jing--;
												}
												else
												{
													cout<<"交易成功 "<<"获得"<<food_<<"元 现有"<<food_+money<<"元"<<endl;
													foodo--;
													money+=food_;
												}
												break;
											case '2':
												if(watero<=0)
												{
													cout<<"水卡不足"<<endl;
													jing--;
												}
												else
												{
													cout<<"交易成功 "<<"获得"<<water_<<"元 现有"<<water_+money<<"元"<<endl;
													water--;
													money+=water_;
												}
												break;
											case '3':
												if(zheno<=0)
												{
													cout<<"镇定剂卡不足"<<endl;
													jing--;
												}
												else
												{
													cout<<"交易成功 "<<"获得"<<zhen_<<"元 现有"<<zhen_+money<<"元"<<endl;
													zheno--;
													money+=zhen_;
												}
												break;
											case '4':
												if(weio<=0)
												{
													cout<<"维生素卡不足"<<endl;
													jing--;
												}
												else
												{
													cout<<"交易成功 "<<"获得"<<wei_<<"元 现有"<<wei_+money<<"元"<<endl;
													weio--;
													money+=wei_;
												}
												break;
											case '5':
												if(gano<=0)
												{
													cout<<"抗感染卡不足"<<endl;
													jing--;
												}
												else
												{
													cout<<"交易成功 "<<"获得"<<gan_<<"元 现有"<<gan_+money<<"元"<<endl;
													gano--;
													money+=gan_;
												}
												break;
											case '6':
												if(shengo<=0)
												{
													cout<<"抗生素卡不足"<<endl;
													jing--;
												}
												else
												{
													cout<<"交易成功 "<<"获得"<<sheng_<<"元 现有"<<sheng_+money<<"元"<<endl;
													shengo--;
													money+=sheng_;
												}
												break;
											case '7':cout<<"你已退出交易"<<endl;break;
											default: cout<<"输入错误"<<endl;jing--;
										}
									}
									else
									{
										if(t=='9')
										{
											
										}
										else
										{
											if(t=='0')
											{
												system("cls");
												end=clock(); 
												pr(0);
											}
											else
											{
												if(t=='�')
												{
													cout<<"彩蛋!"<<endl; 
													if(ssro<=0)
													{
														getssr();
													}
													else
													{
														system("color 8F");
														cout<<"贪心成性!"<<endl;
														pr(1);
														exit(1);
													}
												}
												else
												{
													if(t=='a')
													{
														if(money<200)
														{
															cout<<"资金不足"<<endl;
															jing--; 
														}
														else
														{
															money-=200;
															chi+=random(125,175);
															if(chi>1000)chi=1000;
															he+=random(125,175);
															if(he>1000)he=1000;
															jing+=random(125,175);
															if(jing>1000)jing=1000;
															if(flag==-1)
															{
																flag=1;
																cout<<"你的"<<as[zzxh]<<"治好了"<<endl; 
															}
														}
													}
													else
													{
														if(t=='b')
														{
															if(bo<8)
															{
																cout<<"b级卡不足"<<endl;
																jing--;
															}
															else
															{
																bo-=8;
																qwert=random(1,10);
																switch(qwert)
																{
																	case 1:
																		if(houtiantianfu[1]==0)
																		{
																			houtiantianfu[1]=1;
																			cout<<"每天可以服用任意剂量的镇定剂"<<endl;
																		}
																		else
																		{
																			cout<<""<<endl;
																			sro++;
																			if(houtiantianfu[5]==1)sro++;
																		}
																		break;
																	case 2:
																		ssr++;
																		c--;
																		cout<<"ssr级卡概率+0.1%"<<endl;
																		break;
																	case 3:
																		houtiantianfu[3]+=5;
																		cout<<"每天额外获得5元"<<endl;
																		break;
																	case 4:
																		if(houtiantianfu[4]==0)
																		{
																			houtiantianfu[4]=1;
																			cout<<"可以按f购买镇定剂(50元一剂)"<<endl;
																		}
																		else
																		{
																			cout<<""<<endl;
																			sro++;
																			if(houtiantianfu[5]==1)sro++;
																		}
																		break;
																	case 5:
																		if(houtiantianfu[5]==0)
																		{
																			houtiantianfu[5]=1;
																			cout<<"获得后天天赋失败时额外获得1张sr级卡"<<endl;
																		}
																		else
																		{
																			cout<<""<<endl;
																			sro++;
																			if(houtiantianfu[5]==1)sro++;
																		}
																		break;
																	case 6:
																		if(houtiantianfu[6]==0)
																		{
																			houtiantianfu[6]=1;
																			cout<<"吃饱时继续进食获得ssr级卡而非脑满肠肥"<<endl;
																		}
																		else
																		{
																			cout<<""<<endl;
																			sro++;
																			if(houtiantianfu[5]==1)sro++;
																		}
																		break;
																	case 7:
																		if(houtiantianfu[7]==0)
																		{
																			houtiantianfu[7]=1;
																			cout<<""<<endl;
																		}
																		else
																		{
																			cout<<""<<endl;
																			sro++;
																			if(houtiantianfu[5]==1)sro++;
																		}
																		break;
																	case 8:
																		if(houtiantianfu[8]<50)
																		{
																			cout<<"用c级卡祈求ssr级卡的次数减少5次(不会少于50次)"<<endl;
																			houtiantianfu[8]+=5;
																		}
																		else
																		{
																			cout<<""<<endl;
																			sro++;
																			if(houtiantianfu[5]==1)sro++;
																		}
																		if(ak47>=100-houtiantianfu[8])
																		{
																			ak47=0;
																			getssr();
																		}
																		if(ak47>=100-houtiantianfu[8])
																		{
																			ak47=0;
																			getssr();
																		}
																		break;
																	case 9:
																		if(houtiantianfu[9]<50)
																		{
																			cout<<""<<endl;
																			houtiantianfu[9]+=5;
																		}
																		else
																		{
																			cout<<""<<endl;
																			sro++;
																			if(houtiantianfu[5]==1)sro++;
																		}
																		break;
																	default:
																		cout<<"获得天赋失败"<<endl;
																		sro++;
																		if(houtiantianfu[5]==1)sro++;
																}
															}
														}
														else
														{
															if(t=='c')
															{
																if(co<1)
																{
																	cout<<"c级卡不足"<<endl;
																	jing--;
																}
																else
																{
																	co--;
																	ak47++;
																	qwert=random(0,(ak47<9?ak47:9));
																	cout<<"神给你了"<<qwert<<"块钱"<<endl;
																	money+=qwert;
																	qwert=random(6,14);
																	jing+=qwert;
																	if(qwert<=9)
																	{
																		cout<<"你得到了神的安慰"<<endl;
																	}
																	else
																	{
																		if(qwert>=11)
																		{
																			cout<<"你得到了神的祝福"<<endl;
																		}
																		else
																		{
																			cout<<"你得到了神的宽恕"<<endl;
																		}
																	}
																	if(ak47>=100-houtiantianfu[8])
																	{
																		ak47=0;
																		getssr();
																	}
																}
															}
															else
															{
																if(t=='d')
																{
																	if(so<1)
																	{
																		cout<<"s级卡不足"<<endl;
																		jing--;
																	}
																	else
																	{
																		if(ro<1)
																		{
																			cout<<"r级卡不足"<<endl;
																			jing--;
																		}
																		else
																		{
																			if(money<5)
																			{
																				cout<<"金币不足"<<endl;
																				jing--;
																			}
																			else
																			{
																				so--;
																				ro--;
																				money-=5;
																				sro++;
																				cout<<"你合成了一张sr级卡"<<endl;
																			}
																		}
																	}
																}
																else
																{
																	if(t=='e')
																	{
																		if(sr<3)
																		{
																			cout<<"sr级卡不足"<<endl;
																			jing--;
																		}
																		else
																		{
																			sro-=3;
																			cout<<"你想换什么卡 1.食物卡 2.水卡 3.镇定剂卡"<<endl;
																			cin>>qwert;
																			if(qwert==1)
																			{
																				foodo++;
																				cout<<"你换到了一张食物卡"<<endl;
																			}
																			else
																			{
																				if(qwert==2)
																				{
																					watero++;
																					cout<<"你换到了一张水卡"<<endl;
																				}
																				else
																				{
																					zheno++;
																					cout<<"你换到了一张镇定剂卡"<<endl;
																				}
																			}
																		}
																	}
																	else
																	{
																		if(t=='f')
																		{
																			if(houtiantianfu[4]==0)
																			{
																				cout<<"你现在不能购买镇定剂卡"<<endl;
																				jing--;
																			}
																			else
																			{
																				if(money<50)
																				{
																					cout<<"资金不足,你只有"<<money<<"元"<<endl;
																				}
																				else
																				{
																					zheno++;
																				}
																			}
																		}
																		else
																		{
																			if(t=='g')
																			{
																				
																			}
																		}
																	}
																}
															}
														}
													}
												} 
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		chi-=random(50,100);
		he-=random(50,100);
		jing=jing+flag*random(50,100);
		if(jing>1000)jing=1000;
		if(jing<=333)
		{
			if(rand()%8==0)
			{
				system("color 8F");
				cout<<"精神失常!"<<endl;
				pr(1);
				exit(1);
			}
		}
	}
	system("color 8F");
	cout<<"行刑时间!"<<endl;
	pr(1);
	
	return 0;
}
int random(int a,int b)
{
	if(a<b)swap(a,b);
	return rand()%(a-b+1)+b;
}
void pr(int _flag)
{
	end=clock(); 
	cout<<"你有"<<money<<"元"<<endl; 
	cout<<"食物卡x"<<foodo<<" 水卡x"<<watero<<" 镇定剂卡x"<<zheno<<endl;
	cout<<"抗生素卡x"<<shengo<<" 抗感染卡x"<<gano<<" 维生素卡x"<<weio<<endl;
	cout<<"c级卡x"<<co<<" b级卡x"<<bo<<" s级卡x"<<so<<" r级卡x"<<ro<<" sr级卡x"<<sro<<" ssr级卡x"<<ssro<<endl;
	cout<<"体力:"<<chi<<" 水分:"<<he<<" 精神:"<<jing<<" 属于";
	if(jing>=667)cout<<"正常"<<endl;else if(jing<=333)cout<<"疯狂"<<endl;else cout<<"抑郁"<<endl;
	cout<<"你已经祈求"<<ak47<<"次,"<<"还需要祈求"<<100-houtiantianfu[8]<<"次"<<endl;
	cout<<"天数:"<<i<<" 时间:"<<(end-begin)/60000<<"分"<<((end-begin)/1000)%60<<"秒"<<endl<<"你";
	if(flag==1)cout<<"十分健康"<<endl;else cout<<"得了"<<as[zzxh]<<endl;
	if(_flag==1)system("pause");
}
void getssr()
{
	ssro++;
	cout<<"你抽到了ssr级卡"<<endl;
	system("color 64");
	system("pause");
	system("color 07");
	if(ssro>=100)
	{
		system("color dF");
		cout<<"胜利!"<<endl;
		system("pause");
		exit(1);
	}
	if(jing>=667)
	{
		jing+=(100,200);
		if(jing>1000)jing=1000;
	}
	else
	{
		if(jing>=333)
		{
			jing+=random(50,150);
		}
		else
		{
			system("color 8F");
			cout<<"乐极生悲!"<<endl;
			pr(1);
			exit(1);
		}
	}
}
