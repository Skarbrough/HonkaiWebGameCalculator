#include "../HeadFolder/Role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Rita::FisterSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 != hurtPakge.getRound() % secondFlag) {
		int atk = max(hurtPakge.getPhyDamage() - 3, 0);
		hurtPakge.setPhyDamage(atk);
		hurtPakge.setAttackDebuff(-4);
		cout << getName() << "使用了技能女仆的温柔清理！对方失去了战意，攻击力下降了！\n";
	}
	return hurtPakge;
}

HurtPakge Rita::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % secondFlag) {
		hurtPakge.getResource()->addHP(4);
		hurtPakge.setSkillable(false);
		hurtPakge.setAttackDebuff(-60);
		cout << getName() << "使用了技能完美心意！对方完全不想打了，技能都不放了，伤害也降低了！\n";
	}
	if (2 == hurtPakge.getRound() % secondFlag) {
		hurtPakge.setSkillable(true);
	}
}

HurtPakge Rita::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FisterSkill(hurtPakge);
}

void Rita::enemyRound(HurtPakge& hurtPakge) {
	getHurt(hurtPakge);
}