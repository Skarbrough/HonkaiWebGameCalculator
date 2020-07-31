#include "role.h"
#include <cmath>
#include<random>
#include<chrono>
using namespace std;

HurtPakge Seele::passiveSkill(HurtPakge hurtPakge) {
	passiveFlag = !passiveFlag;
	return hurtPakge;
}

HurtPakge Seele::superSkill(HurtPakge hurtPakge) {
	if (passiveFlag == 1) {
		setAttack(getAttack() + 10);
		setDefence(getDefence() - 5);
	}
	else {
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
		unsigned int randNum = rng() % 15 + 1;
		setAttack(getAttack() - 10);
		setDefence(getDefence() + 5);
	}
	return hurtPakge;
}

HurtPakge Seele::myRound() {
	HurtPakge nan;
	passiveSkill(nan);
	superSkill(nan);
	HurtPakge hurtPakge = HurtPakge(this->getAttack(), 0);
	this->setSpeed(0);
	return hurtPakge;
}

void Seele::enemyRound(HurtPakge hurtPakge) {
	hurtPakge = passiveSkill(hurtPakge);
	int hurt = (hurtPakge.getEleDamage() + (hurtPakge.getPhyDamage() - this->getDefence()))*hurtPakge.getAttackNum();
	this->getHurt(hurt);
	this->setSpeed(100);
}