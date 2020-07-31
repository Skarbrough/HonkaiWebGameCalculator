#pragma once
#include "role.h"

class HurtPakge {
	int phyDamage;//物理伤害
	int eleDamage;//元素伤害
	int attackNum;//造成次数
	bool movable;//冰冻标记
	bool skillable;//沉默标记
	int burnTimes;//点燃
	int burnHurt;//点燃伤害
	Role *resource;
public:
	HurtPakge() {}
	HurtPakge(int phy, int ele) :phyDamage(phy), eleDamage(ele) {
		this->attackNum = 1;
		this->movable = 0;
		this->skillable = 0;
		this->burnTimes = 0;
		this->burnHurt = 0;
	}
	void init() {
		this->phyDamage = 0;
		this->eleDamage = 0;
		this->attackNum = 1;
		this->movable = 0;
		this->skillable = 0;
		this->burnTimes = 0;
		this->burnHurt = 0;
	}
	//getting
	int getPhyDamage() {
		return this->phyDamage;
	}
	int getEleDamage() {
		return this->eleDamage;
	}
	int getAttackNum() {
		return this->attackNum;
	}
	int getMovable() {
		return this->movable;
	}
	int getSkillable() {
		return this->skillable;
	}
	int getBurnTimes() {
		return this->burnTimes;
	}
	int getBurnHurt() {
		return this->burnHurt;
	}
	Role* getResource() {
		return this->resource;
	}

	//setting
	void setPhyDamage(int phyDamage) {
		this->phyDamage = phyDamage;
	}
	void setEleDamage(int eleDamage) {
		this->eleDamage = eleDamage;
	}
	void setAttackNum(int attackNum) {
		this->attackNum = attackNum;
		return;
	}
	void setMovable(bool movable) {
		this->movable = movable;
		return;
	}
	void setSkillable(bool skillable) {
		this->skillable = skillable;
		return;
	}
	void setBurnTimes(int burnTimes) {
		this->burnTimes = burnTimes;
		return;
	}
	void setBurnHurt(int burnHurt) {
		this->burnHurt = burnHurt;
		return;
	}
	void steResource(Role* role) {
		this->resource = role;
	}
};