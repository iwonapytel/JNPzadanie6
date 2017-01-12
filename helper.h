#ifndef HELPER_H
#define HELPER_H

typedef int Age;
typedef int AttackPower;
typedef int HealthPoints;
typedef int Time;

class Attacker {
public:
    Attacker(HealthPoints health, AttackPower attack_power);

    AttackPower getAttackPower() const;
    HealthPoints getHealth() const;
    void takeDamage(AttackPower attackPower);

protected:
    HealthPoints _health;
    AttackPower _attack_power;
};

#endif //HELPER_H
