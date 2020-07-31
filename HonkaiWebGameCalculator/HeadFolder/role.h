#pragma once
#include "HurtPakge.h"

class Role {
private:
	int attack;
	int defence;
	int speed;//根据速度大小判定下一回合出手方
	int hp;
	int maxHP;
	bool movable;//是否被跳过回合
	bool skillable;//是否被沉默
	int burnTimes;//点燃标记持续时间
	int burnHurt;//点燃标记持续伤害
	
public:
	Role() { 
		this->maxHP = 100;
		this->movable = 0;
		this->skillable = 0;
		this->burnHurt = 0;
		this->burnTimes = 0;
	}
	virtual HurtPakge FisterSkill(HurtPakge hurtPakge) = 0;	//被动技能
	virtual HurtPakge superSkill(HurtPakge hurtPakge) = 0;		//主动技能
	virtual void enemyRound(HurtPakge hurtPakge) = 0;			//敌方回合收到伤害计算方法
	virtual HurtPakge myRound() = 0;							//我方回合造成伤害计算方法
	virtual void init() = 0;									//初始化角色
	unsigned int getRandNum();
	HurtPakge thisRound();
	void getHurt(HurtPakge hurt);
	void getBurnHurt();

	//increase
	void addHP(int blood);
	void addAttack(int effect);
	void addDefence(int effect);
	
	//setting
	void setAttack(int attack) {
		this->attack = attack;
	}
	void setDefence(int defence) {
		this->defence = defence;
	}
	void setSpeed(int speed) {
		this->speed = speed;
	}
	void setHp(int hp) {
		this->hp = hp;
	}
	void setMovable(bool moveFlag) {
		this->movable = moveFlag;
	}
	void setSkillable(bool skillFlag) {
		this->skillable = skillFlag;
	}
	void setBurnHurt(int burnTimes, int burnHurt) {
		this->burnTimes = burnTimes;
		this->burnHurt = burnHurt;
	}
	//getting
	int getAttack() {
		return this->attack;
	}
	int getDefence() {
		return this->defence;
	}
	int getSpeed() {
		return this->speed;
	}
	int getHP() {
		return this->hp;
	}
	bool getMoveable() {
		return this->movable;
	}
	bool getSkillable() {
		return this->skillable;
	}
};

class Kiana :public Role {
	int superFlag;
public:
	Kiana() {
		init();
	}
	void init() {
		this->setAttack(24);
		this->setDefence(11);
		this->setHp(100);
		this->setSpeed(23);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Mei :public Role {
	int superFlag;
public:
	Mei() {
		init();
	}
	void init() {
		this->setAttack(22);
		this->setDefence(12);
		this->setHp(100);
		this->setSpeed(30);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Bronya :public Role {
	int superFlag;
public:
	Bronya() {
		init();
	}
	void init() {
		this->setAttack(21);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(20);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Himeko :public Role {
	int superFlag;
public:
	Himeko() {
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(9);
		this->setHp(100);
		this->setSpeed(12);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Rita :public Role {
	int superFlag;
public:
	Rita() {
		init();
	}
	void init() {
		this->setAttack(26);
		this->setDefence(11);
		this->setHp(100);
		this->setSpeed(17);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Sakura :public Role {
	int superFlag;
public:
	Sakura() {
		init();
	}
	void init() {
		this->setAttack(20);
		this->setDefence(9);
		this->setHp(100);
		this->setSpeed(18);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Raven :public Role {
	int superFlag;
public:
	Raven() {
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(14);
		this->setHp(100);
		this->setSpeed(14);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Theresa :public Role {
	int superFlag;
public:
	Theresa() {
		init();
	}
	void init() {
		this->setAttack(19);
		this->setDefence(12);
		this->setHp(100);
		this->setSpeed(22);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Rozaliya :public Role {
	int superFlag;
public:
	Rozaliya() {
		init();
	}
	void init() {
		this->setAttack(18);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(10);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Seele :public Role {
	int superFlag;
	int passiveFlag;
public:
	Seele() {
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(13);
		this->setHp(100);
		this->setSpeed(26);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Durandal :public Role {
	int superFlag;
	int passiveFlag;
public:
	Durandal() {
		init();
	}
	void init() {
		this->setAttack(19);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(15);
		this->superFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};

class Fuhua :public Role {
	int superFlag;
	int passiveFlag;
public:
	Fuhua() {
		init();
	}
	void init() {
		this->setAttack(17);
		this->setDefence(15);
		this->setHp(100);
		this->setSpeed(16);
		this->superFlag = 0;
		this->passiveFlag = 0;
	}

	HurtPakge FisterSkill(HurtPakge hurtPakge);

	HurtPakge superSkill(HurtPakge hurtPakge);

	HurtPakge myRound();

	void enemyRound(HurtPakge hurtPakge);
};