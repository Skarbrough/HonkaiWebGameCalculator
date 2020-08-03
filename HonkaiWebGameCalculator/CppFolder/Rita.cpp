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
	}
	return hurtPakge;
}

HurtPakge Rita::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % secondFlag) {
		hurtPakge.getResource()->addHP(4);
		hurtPakge.setSkillable(false);
		hurtPakge.setAttackDebuff(-60);
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