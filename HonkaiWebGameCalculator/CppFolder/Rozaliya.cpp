#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
using namespace std;

HurtPakge Rozaliya::FisterSkill(HurtPakge hurtPakge) {
	unsigned int randNum = getRandNum();
	if (randNum < 30)hurtPakge.setPhyDamage((double)hurtPakge.getPhyDamage()*0.5);//½µµÍ¹¥»÷
	else if (randNum < 60)hurtPakge.setPhyDamage((double)hurtPakge.getPhyDamage()*1.5);//Ìá¸ß¹¥»÷
	return hurtPakge;
}

HurtPakge Rozaliya::superSkill(HurtPakge hurtPakge) {
	if (superFlag == 2) {
		hurtPakge.setEleDamage(0);
		hurtPakge.setPhyDamage(15);
		hurtPakge.setAttackNum(10);
		superFlag = 0;
		this->setMovable(1);
	}
	else superFlag++;
	return hurtPakge;
}

HurtPakge Rozaliya::myRound() {
	HurtPakge hurtPakge = HurtPakge(this->getAttack(), 0);
	hurtPakge = superSkill(hurtPakge);
	this->setSpeed(0);
	return hurtPakge;
}

void Rozaliya::enemyRound(HurtPakge hurtPakge) {
	hurtPakge = FisterSkill(hurtPakge);
	this->getHurt(hurt);
	this->setSpeed(100);
}