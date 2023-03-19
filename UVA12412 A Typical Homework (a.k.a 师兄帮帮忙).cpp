#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using std::cin;
using std::cout;
struct student
{
	std::string SID, CID, name;
	int Chinese, Mathematics, English, Programming;
	double totle, average;
	int rank, shunxu;
	bool operator<(const student &n)
	{
		return this->average > n.average;
	}
} st;
std::string str;
std::vector<student> a;
signed main()
{
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.setf(std::ios::fixed);
	for (int t, person = 0;;)
	{
		cout << "Welcome to Student Performance Management System (SPMS).\n\n";
		cout << "1 - Add\n";
		cout << "2 - Remove\n";
		cout << "3 - Query\n";
		cout << "4 - Show ranking\n";
		cout << "5 - Show Statistics\n";
		cout << "0 - Exit\n\n";
		cin >> t;
		switch (t)
		{
		case 0:
			return 0;
		case 1:
			for (;;)
			{
				cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish.\n";
				cin >> st.SID;
				if (st.SID == "0")
				{
					break;
				}
				cin >> st.CID >> st.name >> st.Chinese >> st.Mathematics >> st.English >> st.Programming;
				bool flag = true;
				for (auto it : a)
				{
					if (st.SID == it.SID)
					{
						flag = false;
						cout << "Duplicated SID.\n";
						break;
					}
				}
				if (flag)
				{
					st.totle = st.Chinese + st.Mathematics + st.English + st.Programming;
					st.average = st.totle / 4.0;
					st.shunxu = ++person;
					a.emplace_back(st);
				}
			}
			break;
		case 2:
			for (;;)
			{
				cout << "Please enter SID or name. Enter 0 to finish.\n";
				cin >> str;
				if (str == "0")
				{
					break;
				}
				int cnt = 0;
				if (str.size() == 10 && isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3]) && isdigit(str[4]) && isdigit(str[5]) && isdigit(str[6]) && isdigit(str[7]) && isdigit(str[8]) && isdigit(str[9]))
				{
					for (auto it = a.begin(); it < a.end();)
					{
						if (it->SID == str)
						{
							it = a.erase(it);
							cnt++;
						}
						else
						{
							it++;
						}
					}
				}
				else
				{
					for (auto it = a.begin(); it < a.end();)
					{
						if (it->name == str)
						{
							it = a.erase(it);
							cnt++;
						}
						else
						{
							it++;
						}
					}
				}
				cout << cnt << " student(s) removed.\n";
			}
			break;
		case 3:
			std::sort(a.begin(), a.end());
			a[0].rank = 1;
			for (int i = 1; i < int(a.size()); i++)
			{
				if (a[i].totle == a[i - 1].totle)
				{
					a[i].rank = a[i - 1].rank;
				}
				else
				{
					a[i].rank = i + 1;
				}
			}
			std::sort(a.begin(), a.end(), [&](const student &x, const student &y)
					  { return x.shunxu < y.shunxu; });
			for (;;)
			{
				cout << "Please enter SID or name. Enter 0 to finish.\n";
				cin >> str;
				if (str == "0")
				{
					break;
				}
				if (str.size() == 10 && isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3]) && isdigit(str[4]) && isdigit(str[5]) && isdigit(str[6]) && isdigit(str[7]) && isdigit(str[8]) && isdigit(str[9]))
				{
					for (auto it : a)
					{
						if (it.SID == str)
						{
							cout << it.rank << ' ' << it.SID << ' ' << it.CID << ' ' << it.name << ' ';
							cout << it.Chinese << ' ' << it.Mathematics << ' ' << it.English << ' ' << it.Programming;
							cout << ' ' << std::setprecision(0) << it.totle << ' ' << std::setprecision(2) << it.average + 1e-5 << '\n';
						}
					}
				}
				else
				{
					for (auto it : a)
					{
						if (it.name == str)
						{
							cout << it.rank << ' ' << it.SID << ' ' << it.CID << ' ' << it.name << ' ';
							cout << it.Chinese << ' ' << it.Mathematics << ' ' << it.English << ' ' << it.Programming;
							cout << ' ' << std::setprecision(0) << it.totle << ' ' << std::setprecision(2) << it.average + 1e-5 << '\n';
						}
					}
				}
			}
			break;
		case 4:
			cout << "Showing the ranklist hurts students' self-esteem. Don't do that.\n";
			break;
		case 5:
			cout << "Please enter class ID, 0 for the whole statistics.\n";
			cin >> str;
			int num = 0;
			int Chinese_sum = 0, Mathematics_sum = 0, English_sum = 0, Programming_sum = 0;
			int Chinese_cnt_1 = 0, Mathematics_cnt_1 = 0, English_cnt_1 = 0, Programming_cnt_1 = 0;
			int Chinese_cnt_2 = 0, Mathematics_cnt_2 = 0, English_cnt_2 = 0, Programming_cnt_2 = 0;
			int plus_4 = 0, plus_3 = 0, plus_2 = 0, plus_1 = 0, plus_0 = 0;
			if (str != "0")
			{
				for (auto it : a)
				{
					if (it.CID == str)
					{
						Chinese_sum += it.Chinese;
						Mathematics_sum += it.Mathematics;
						English_sum += it.English;
						Programming_sum += it.Programming;
						num++;
						int CcC = 0;
						if (it.Chinese >= 60)
						{
							Chinese_cnt_1++;
							CcC++;
						}
						else
						{
							Chinese_cnt_2++;
						}
						if (it.Mathematics >= 60)
						{
							Mathematics_cnt_1++;
							CcC++;
						}
						else
						{
							Mathematics_cnt_2++;
						}
						if (it.English >= 60)
						{
							English_cnt_1++;
							CcC++;
						}
						else
						{
							English_cnt_2++;
						}
						if (it.Programming >= 60)
						{
							Programming_cnt_1++;
							CcC++;
						}
						else
						{
							Programming_cnt_2++;
						}
						switch (CcC)
						{
						case 4:
							plus_4++;
							plus_3++;
							plus_2++;
							plus_1++;
							break;
						case 3:
							plus_3++;
							plus_2++;
							plus_1++;
							break;
						case 2:
							plus_2++;
							plus_1++;
							break;
						case 1:
							plus_1++;
							break;
						}
						if (CcC == 0)
						{
							plus_0++;
						}
					}
				}
			}
			else
			{
				for (auto it : a)
				{
					Chinese_sum += it.Chinese;
					Mathematics_sum += it.Mathematics;
					English_sum += it.English;
					Programming_sum += it.Programming;
					num++;
					int CcC = 0;
					if (it.Chinese >= 60)
					{
						Chinese_cnt_1++;
						CcC++;
					}
					else
					{
						Chinese_cnt_2++;
					}
					if (it.Mathematics >= 60)
					{
						Mathematics_cnt_1++;
						CcC++;
					}
					else
					{
						Mathematics_cnt_2++;
					}
					if (it.English >= 60)
					{
						English_cnt_1++;
						CcC++;
					}
					else
					{
						English_cnt_2++;
					}
					if (it.Programming >= 60)
					{
						Programming_cnt_1++;
						CcC++;
					}
					else
					{
						Programming_cnt_2++;
					}
					switch (CcC)
					{
					case 4:
						plus_4++;
						plus_3++;
						plus_2++;
						plus_1++;
						break;
					case 3:
						plus_3++;
						plus_2++;
						plus_1++;
						break;
					case 2:
						plus_2++;
						plus_1++;
						break;
					case 1:
						plus_1++;
						break;
					}
					if (CcC == 0)
					{
						plus_0++;
					}
				}
			}
			cout << "Chinese\n";
			cout << "Average Score: " << std::setprecision(2) << 1. * Chinese_sum / num + 1e-5 << '\n';
			cout << "Number of passed students: " << Chinese_cnt_1 << '\n';
			cout << "Number of failed students: " << Chinese_cnt_2 << "\n\n";
			cout << "Mathematics\n";
			cout << "Average Score: " << std::setprecision(2) << 1. * Mathematics_sum / num + 1e-5 << '\n';
			cout << "Number of passed students: " << Mathematics_cnt_1 << '\n';
			cout << "Number of failed students: " << Mathematics_cnt_2 << "\n\n";
			cout << "English\n";
			cout << "Average Score: " << std::setprecision(2) << 1. * English_sum / num + 1e-5 << '\n';
			cout << "Number of passed students: " << English_cnt_1 << '\n';
			cout << "Number of failed students: " << English_cnt_2 << "\n\n";
			cout << "Programming\n";
			cout << "Average Score: " << std::setprecision(2) << 1. * Programming_sum / num + 1e-5 << '\n';
			cout << "Number of passed students: " << Programming_cnt_1 << '\n';
			cout << "Number of failed students: " << Programming_cnt_2 << "\n\n";
			cout << "Overall:\n";
			cout << "Number of students who passed all subjects: " << plus_4 << '\n';
			cout << "Number of students who passed 3 or more subjects: " << plus_3 << '\n';
			cout << "Number of students who passed 2 or more subjects: " << plus_2 << '\n';
			cout << "Number of students who passed 1 or more subjects: " << plus_1 << '\n';
			cout << "Number of students who failed all subjects: " << plus_0 << "\n\n";
			break;
		}
	}
}