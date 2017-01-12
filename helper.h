#ifndef HELPER_H
#define HELPER_H

using HealthPoints = int;
using Age = int;
using AttackPower = int;

class Attacker {
    AttackPower getAttackPower();

public:
    AttackPower _attack_power;
};

#endif //HELPER_H
