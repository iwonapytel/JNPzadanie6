#ifndef HELPER_H
#define HELPER_H

typedef int Age;
typedef int AttackPower;
typedef int HealthPoints;
typedef int Time;

class Attacker {
public:
    Attacker(AttackPower attack_power);

    AttackPower getAttackPower() const;

private:
    AttackPower _attack_power;
};

#endif //HELPER_H
