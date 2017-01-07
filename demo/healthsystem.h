#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H

class HealthSystem
{
public:
	HealthSystem();
	virtual ~HealthSystem();

	void setHealth(int _health);
	void setDamage(int _damage);

	int getHealth(){return curHealth;}
	int getDamage(){return damage;}

	void applyDamage(int _damage);
	bool deathCheck();

private:
	int totalHealth;
	int curHealth;
	int damage;
};

#endif
