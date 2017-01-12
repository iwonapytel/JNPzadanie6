#ifndef HELPER_H
#define HELPER_H

using Age = int;
using AttackPower = int;
using HealthPoints = int;
using Time = int;

class Attacker {
public:
    Attacker(HealthPoints health, AttackPower attack_power);

    AttackPower getAttackPower();
    HealthPoints getHealth();

protected:
    HealthPoints _health;
    AttackPower _attack_power;
};

#endif //HELPER_H
