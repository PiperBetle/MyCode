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
int ssr,sr,r,s,b,c,gan,zhen,wei,sheng,food,water;//����Ϊǧ��֮n 
int ssro=0,sro=0,ro=90,so=90,bo=999,co=0,gano=0,zheno=0,weio=0,shengo=0,foodo=0,watero=0;//���� 
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
	fu[1]="������   ssr+0.6%";
	fu[2]="������   ssr-0.6%";
	fu[4]="ϲ��ʳ�� ʳ�￨+1.6%";
	fu[5]="����ʳ�� ʳ�￨-1.6%";
	fu[7]="����ǿ�� �����½�����";
	fu[8]="������� �����½�����";
	fu[9]="������   ���濨Ƭ+0.6%";
	fu[10]="լ       ���濨Ƭ-0.6%";
	fu[11]="�ٺ�     ���ĸ���ˮ��";
	fu[12]="�ູ     ���ĸ���ˮ��";
	fu[13]="����     ���ĸ�������";
	fu[14]="����     ���ĸ�������";
	fu[15]="ϲ������ ˮ��+1.6%";
	fu[16]="�������� ˮ��-1.6%";
	fu[17]="ϲ��ҩ�� ҩ+1.6%";//ҩ�����򶨼�
	fu[18]="����ҩ�� ҩ-1.6%";//������
	fu[19]="̰��     ���100-140Ԫ";
	fu[20]="�ҳ�     ���60-100Ԫ";
	as[1]="��Ѫ��";as[2]="���˷�";as[3]="������"; 
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
		cout<<"��"<<i<<"��"<<endl;
		if(i==1)money=100;
		else
		{
			qwert=random(60,140);
			money+=qwert+houtiantianfu[3];
			cout<<"������"<<qwert<<"Ԫ,������"<<money<<"Ԫ"<<endl;
			if(houtiantianfu[3]>0)cout<<"����ͨ�������츳���������"<<houtiantianfu[3]<<"Ԫ"<<endl; 
		}
		if((chi<=0)&&(he<=0))
		{
			system("color 8F");
			cout<<"��������!"<<endl;
			pr(1);
			exit(1);
		}
		if(chi<=0)
		{
			system("color 8F");
			cout<<"�����Ұ!"<<endl;
			pr(1);
			exit(1);
		}
		if(he<=0)
		{
			system("color 8F");
			cout<<"���ֹ��!"<<endl;
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
					case 0:zzxh=1;cout<<"�����"<<as[1]<<endl;break;
					case 1:zzxh=2;cout<<"�����"<<as[2]<<endl;break;
					case 2:zzxh=3;cout<<"�����"<<as[3]<<endl;break;
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
					cout<<"�ʽ���,��ֻ��"<<money<<"Ԫ"<<endl;
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
						cout<<"��鵽��c����"<<endl;
						jing-=random(10,20);
					}
					else
					{
						now+=b;
						if(card<=now)
						{
							bo++;
							cout<<"��鵽��b����"<<endl;
							jing-=random(10,15);
						}
						else
						{
							now+=s;
							if(card<=now)
							{
								so++;
								cout<<"��鵽��s����"<<endl; 
								jing-=random(5,15);
							}
							else
							{
								now+=r;
								if(card<=now)
								{
									ro++;
									cout<<"��鵽��r����"<<endl;
									jing-=random(5,10);
								}
								else
								{
									now+=sr;
									if(card<=now)
									{
										sro++;
										cout<<"��鵽��sr����"<<endl;
										jing-=random(1,10);
									}
									else
									{
										now+=water;
										if(card<=now)
										{
											watero++;
											cout<<"��鵽��ˮ��"<<endl;
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
												cout<<"��鵽��ʳ�￨"<<endl;
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
													cout<<"��鵽��ά���ؿ�"<<endl;
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
														cout<<"��鵽�˿����ؿ�"<<endl;
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
															cout<<"��鵽�˿���Ⱦ��"<<endl;
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
																cout<<"��鵽���򶨼���"<<endl;
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
								cout<<"��������!"<<endl;
								pr(1);
								exit(1);
							}
							else
							{
								foodo--;
								qwert=random(100,200);
								chi+=qwert;
								chi=min(chi,1000);
								cout<<"��������"<<qwert<<",������"<<chi<<"����"<<endl;
							}
						}
						else
						{
							cout<<"ʳ�￨����"<<endl;
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
								cout<<"ˮ������"<<qwert<<",������"<<he<<"ˮ��"<<endl;
								if(rand()%10==0)
								{
									watero++;
									system("color D9");
									cout<<"����һƿ"<<endl;
									system("pause");
									system("color 07");
								}
							}
							else
							{
								cout<<"ˮ������"<<endl;
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
									cout<<"��������"<<qwert<<",������"<<jing<<"����"<<endl;
									iop++;
									if((iop>=3)&&(houtiantianfu[1]==0))
									{
										system("color 8F");
										cout<<"�������!"<<endl;
										pr(1);
										exit(1);
									}
								}
								else
								{
									cout<<"�򶨼�������"<<endl;
									jing--;
								}
							}
							else
							{
								if(t=='7')
								{
									if(flag==1)
									{
										cout<<"��ܽ���"<<endl;
										jing--;
									}
									else
									{
										if(zzxh==1)
										{
											if(weio>=1)
											{
												weio--;
												cout<<"���"<<as[1]<<"�κ���" <<endl;
												flag=1;
											}
											else
											{
												cout<<"ά���ؿ�����"<<endl;
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
													cout<<"���"<<as[2]<<"�κ���" <<endl;
													flag=1;
												}
												else
												{
													cout<<"����Ⱦ������"<<endl;
													jing--;
												}
											} 
											else
											{
												if(shengo>=1)
												{
													shengo--;
													cout<<"���"<<as[3]<<"�κ���" <<endl;
													flag=1;
												}
												else
												{
													cout<<"�����ؿ�����"<<endl;
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
										cout<<"��Ҫ��ʲô��" <<endl;
										cout<<"1ʳ�￨:"<<food_<<" 2ˮ��:"<<water_<<" 3�򶨼���:"<<zhen_<<" 4ά���ؿ�:"<<wei_<<" 5����Ⱦ��:"<<gan_<<" 6�����ؿ�:"<<sheng_<<" 7�뿪"<<endl; 
										cin>>jw;
										switch(jw)
										{
											case '1':
												if(foodo<=0)
												{
													cout<<"ʳ�￨����"<<endl;
													jing--;
												}
												else
												{
													cout<<"���׳ɹ� "<<"���"<<food_<<"Ԫ ����"<<food_+money<<"Ԫ"<<endl;
													foodo--;
													money+=food_;
												}
												break;
											case '2':
												if(watero<=0)
												{
													cout<<"ˮ������"<<endl;
													jing--;
												}
												else
												{
													cout<<"���׳ɹ� "<<"���"<<water_<<"Ԫ ����"<<water_+money<<"Ԫ"<<endl;
													water--;
													money+=water_;
												}
												break;
											case '3':
												if(zheno<=0)
												{
													cout<<"�򶨼�������"<<endl;
													jing--;
												}
												else
												{
													cout<<"���׳ɹ� "<<"���"<<zhen_<<"Ԫ ����"<<zhen_+money<<"Ԫ"<<endl;
													zheno--;
													money+=zhen_;
												}
												break;
											case '4':
												if(weio<=0)
												{
													cout<<"ά���ؿ�����"<<endl;
													jing--;
												}
												else
												{
													cout<<"���׳ɹ� "<<"���"<<wei_<<"Ԫ ����"<<wei_+money<<"Ԫ"<<endl;
													weio--;
													money+=wei_;
												}
												break;
											case '5':
												if(gano<=0)
												{
													cout<<"����Ⱦ������"<<endl;
													jing--;
												}
												else
												{
													cout<<"���׳ɹ� "<<"���"<<gan_<<"Ԫ ����"<<gan_+money<<"Ԫ"<<endl;
													gano--;
													money+=gan_;
												}
												break;
											case '6':
												if(shengo<=0)
												{
													cout<<"�����ؿ�����"<<endl;
													jing--;
												}
												else
												{
													cout<<"���׳ɹ� "<<"���"<<sheng_<<"Ԫ ����"<<sheng_+money<<"Ԫ"<<endl;
													shengo--;
													money+=sheng_;
												}
												break;
											case '7':cout<<"�����˳�����"<<endl;break;
											default: cout<<"�������"<<endl;jing--;
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
													cout<<"�ʵ�!"<<endl; 
													if(ssro<=0)
													{
														getssr();
													}
													else
													{
														system("color 8F");
														cout<<"̰�ĳ���!"<<endl;
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
															cout<<"�ʽ���"<<endl;
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
																cout<<"���"<<as[zzxh]<<"�κ���"<<endl; 
															}
														}
													}
													else
													{
														if(t=='b')
														{
															if(bo<8)
															{
																cout<<"b��������"<<endl;
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
																			cout<<"ÿ����Է�������������򶨼�"<<endl;
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
																		cout<<"ssr��������+0.1%"<<endl;
																		break;
																	case 3:
																		houtiantianfu[3]+=5;
																		cout<<"ÿ�������5Ԫ"<<endl;
																		break;
																	case 4:
																		if(houtiantianfu[4]==0)
																		{
																			houtiantianfu[4]=1;
																			cout<<"���԰�f�����򶨼�(50Ԫһ��)"<<endl;
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
																			cout<<"��ú����츳ʧ��ʱ������1��sr����"<<endl;
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
																			cout<<"�Ա�ʱ������ʳ���ssr����������������"<<endl;
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
																			cout<<"��c��������ssr�����Ĵ�������5��(��������50��)"<<endl;
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
																		cout<<"����츳ʧ��"<<endl;
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
																	cout<<"c��������"<<endl;
																	jing--;
																}
																else
																{
																	co--;
																	ak47++;
																	qwert=random(0,(ak47<9?ak47:9));
																	cout<<"�������"<<qwert<<"��Ǯ"<<endl;
																	money+=qwert;
																	qwert=random(6,14);
																	jing+=qwert;
																	if(qwert<=9)
																	{
																		cout<<"��õ�����İ�ο"<<endl;
																	}
																	else
																	{
																		if(qwert>=11)
																		{
																			cout<<"��õ������ף��"<<endl;
																		}
																		else
																		{
																			cout<<"��õ�����Ŀ�ˡ"<<endl;
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
																		cout<<"s��������"<<endl;
																		jing--;
																	}
																	else
																	{
																		if(ro<1)
																		{
																			cout<<"r��������"<<endl;
																			jing--;
																		}
																		else
																		{
																			if(money<5)
																			{
																				cout<<"��Ҳ���"<<endl;
																				jing--;
																			}
																			else
																			{
																				so--;
																				ro--;
																				money-=5;
																				sro++;
																				cout<<"��ϳ���һ��sr����"<<endl;
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
																			cout<<"sr��������"<<endl;
																			jing--;
																		}
																		else
																		{
																			sro-=3;
																			cout<<"���뻻ʲô�� 1.ʳ�￨ 2.ˮ�� 3.�򶨼���"<<endl;
																			cin>>qwert;
																			if(qwert==1)
																			{
																				foodo++;
																				cout<<"�㻻����һ��ʳ�￨"<<endl;
																			}
																			else
																			{
																				if(qwert==2)
																				{
																					watero++;
																					cout<<"�㻻����һ��ˮ��"<<endl;
																				}
																				else
																				{
																					zheno++;
																					cout<<"�㻻����һ���򶨼���"<<endl;
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
																				cout<<"�����ڲ��ܹ����򶨼���"<<endl;
																				jing--;
																			}
																			else
																			{
																				if(money<50)
																				{
																					cout<<"�ʽ���,��ֻ��"<<money<<"Ԫ"<<endl;
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
				cout<<"����ʧ��!"<<endl;
				pr(1);
				exit(1);
			}
		}
	}
	system("color 8F");
	cout<<"����ʱ��!"<<endl;
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
	cout<<"����"<<money<<"Ԫ"<<endl; 
	cout<<"ʳ�￨x"<<foodo<<" ˮ��x"<<watero<<" �򶨼���x"<<zheno<<endl;
	cout<<"�����ؿ�x"<<shengo<<" ����Ⱦ��x"<<gano<<" ά���ؿ�x"<<weio<<endl;
	cout<<"c����x"<<co<<" b����x"<<bo<<" s����x"<<so<<" r����x"<<ro<<" sr����x"<<sro<<" ssr����x"<<ssro<<endl;
	cout<<"����:"<<chi<<" ˮ��:"<<he<<" ����:"<<jing<<" ����";
	if(jing>=667)cout<<"����"<<endl;else if(jing<=333)cout<<"���"<<endl;else cout<<"����"<<endl;
	cout<<"���Ѿ�����"<<ak47<<"��,"<<"����Ҫ����"<<100-houtiantianfu[8]<<"��"<<endl;
	cout<<"����:"<<i<<" ʱ��:"<<(end-begin)/60000<<"��"<<((end-begin)/1000)%60<<"��"<<endl<<"��";
	if(flag==1)cout<<"ʮ�ֽ���"<<endl;else cout<<"����"<<as[zzxh]<<endl;
	if(_flag==1)system("pause");
}
void getssr()
{
	ssro++;
	cout<<"��鵽��ssr����"<<endl;
	system("color 64");
	system("pause");
	system("color 07");
	if(ssro>=100)
	{
		system("color dF");
		cout<<"ʤ��!"<<endl;
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
			cout<<"�ּ�����!"<<endl;
			pr(1);
			exit(1);
		}
	}
}
