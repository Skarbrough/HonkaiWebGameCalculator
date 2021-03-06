#define _CRT_SECURE_NO_WARNINGS
#define BATTLETIMES 10000
#include <iostream>
#include <conio.h>
#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include<random>
#include<chrono>
using namespace std;

template<class T1, class T2>
bool  BattleSimulate(T1* x, T2* y) {
	while (true) {
		if (x->getHP() <= 0) return false;
		if (y->getHP() <= 0) return true;
		if (x->getSpeed() >= y->getSpeed()) y->enemyRound(x->thisRound());
		else x->enemyRound(y->thisRound());
	}
}

void TitleDisp() {
	cout << "******************************************************************\n"
		"*                                                                *\n"
		"*                     蹦蹦蹦网页活动模拟器                       *\n"
		"*                                                                *\n"
		"******************************************************************\n";
	cout << endl;
}
void RoleMenu() {
	roles.push_back(Theresa());
	roles.push_back(Bronya());
	roles.push_back(Fuhua());
	roles.push_back(Rozaliya());
	roles.push_back(Sakura());
	roles.push_back(Seele());
	cout << "德丽莎：1	布洛妮娅：2	符华：3		罗萨莉娅：4	\n"
			"樱莲：5		希儿：6	\n";
	cout << endl;
}

vector<Role> roles;

int main() {
	int winTimes1, winTimes2;
	int select1, select2;
	char isContinue;
	while (true) {
		//初始化
		HurtPakge hurtpakge;
		TitleDisp();RoleMenu();
		winTimes1 = 0; winTimes2 = 0;
		cout << "			选择角色1:";
		cin >> select1;
		cout << "			选择角色2:";
		cin >> select2;
		Role *role1 = &roles[select1 - 1];
		Role *role2 = &roles[select2 - 1];
		//战斗模拟
		int n = 10000;
		for (int i = 1;i <= n;i++) {
			role1->init();
			role2->init();
			if(i%100 == 0)
				cout << ">";
			typeid(int);
			if (BattleSimulate(role1, role2)) winTimes1++;
			else winTimes2++;
		}
		
		//胜场数输出
		cout << "\n			  模拟战斗次数" << n << endl;
		cout << "\n		      角色1的胜场数为" << winTimes1 << endl;
		cout << "\n		      角色2的胜场数为" << winTimes2 << endl;
		//循环结束/继续
		cout << "\n继续请按y，否则退出\n";
		isContinue = _getch();
		if (isContinue == 'y' || isContinue == 'Y');
		else break;
		system("cls");
	}
	return 0;
}