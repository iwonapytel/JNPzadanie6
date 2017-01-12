#include "helper.h"

AttackPower Attacker::getAttackPower() const {
    return _attack_power;
}

HealthPoints Attacker::getHealth() const {
    return _health;
}

void Attacker::takeDamage(AttackPower attackPower) {
    _health -= min(_health, attackPower);
}