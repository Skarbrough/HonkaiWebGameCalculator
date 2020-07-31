#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;

void Role::getHurt(HurtPakge hurtPakge) {
	int hurt = (hurtPakge.getEleDamage() + (hurtPakge.getPhyDamage() - this->getDefence()))*hurtPakge.getAttackNum();
	this->hp = std::max(0, this->hp - hurt);
}

void Role::getBurnHurt() {
	if (this->burnTimes) {
		this->hp -= this->burnHurt;
		this->burnTimes--;
	}
}

unsigned int Role::getRandNum() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return rng();
}

HurtPakge Role::thisRound() {
	HurtPakge hurtPakge = this->myRound();
	if (this->movable) hurtPakge.init();
	this->movable = 0;
	return hurtPakge;
}

void Role::addHP(int blood) {
	this->hp = min(maxHP, hp + blood);
}
void Role::addAttack(int effect) {
	this->attack = max(0, attack + effect);
}
void Role::addDefence(int effect) {
	this->defence = max(0, defence + effect);
}