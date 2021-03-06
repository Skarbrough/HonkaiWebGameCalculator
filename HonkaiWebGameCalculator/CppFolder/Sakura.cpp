#include "role.h"
#include <cmath>
#include<random>
#include<chrono>
using namespace std;

HurtPakge Sakura::passiveSkill(HurtPakge hurtPakge) {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	unsigned int randNum = rng() % 100;
	if (randNum < 30)
		setHp(getHP() + 25);
	return hurtPakge;
}

HurtPakge Sakura::superSkill(HurtPakge hurtPakge) {
	if (superFlag == 1) {
		hurtPakge.setEleDamage(25);
		hurtPakge.setPhyDamage(0);
		hurtPakge.setAttackNum(1);
		superFlag = 0;
		this->setMovable(1);
	}
	else superFlag++;
	return hurtPakge;
}

HurtPakge Sakura::myRound() {
	passiveSkill(HurtPakge());
	HurtPakge hurtPakge = HurtPakge(this->getAttack(), 0);
	hurtPakge = superSkill(hurtPakge);
	this->setSpeed(0);
	return hurtPakge;
}

void Sakura::enemyRound(HurtPakge hurtPakge) {
	hurtPakge = passiveSkill(hurtPakge);
	int hurt = (hurtPakge.getEleDamage() + (hurtPakge.getPhyDamage() - this->getDefence()))*hurtPakge.getAttackNum();
	this->getHurt(hurt);
	this->setSpeed(100);
}