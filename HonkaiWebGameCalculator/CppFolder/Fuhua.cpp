#include "role.h"
#include<random>
#include<chrono>
using namespace std;

HurtPakge Fuhua::passiveSkill(HurtPakge hurtPakge) {
	if (this->passiveFlag) hurtPakge.setEleDamage(0);
	if (this->passiveFlag == 0 && this->getHP() <= 0) {
		this->setHp(1);
		this->passiveFlag = 1;
	}
	return hurtPakge;
}

HurtPakge Fuhua::superSkill(HurtPakge hurtPakge) {
	if (this->superFlag == 2) {
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//随机数生成器
		hurtPakge.init();
		hurtPakge.setEleDamage((rng() % 21) + 10);
		this->superFlag = 0;
	}
	else this->superFlag++;
	return hurtPakge;
}

void Fuhua::enemyRound(HurtPakge hurtPakge) {
	hurtPakge = this->passiveSkill(hurtPakge);
	int hurt = hurtPakge.getEleDamage() + (hurtPakge.getPhyDamage() - this->getDefence())*hurtPakge.getAttackNum();
	this->getHurt(hurt);
	this->passiveSkill(hurtPakge);
	this->setSpeed(100);
}

HurtPakge Fuhua::myRound() {
	HurtPakge hurtPakge = HurtPakge(this->getAttack(), 0);
	hurtPakge = superSkill(hurtPakge);
	this->setSpeed(0);
	return hurtPakge;
}