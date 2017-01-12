#include "helper.h"

Attacker::Attacker(AttackPower attack_power) : _attack_power(attack_power) { }

AttackPower Attacker::getAttackPower() const {
    return _attack_power;
}

void Attacker::takeDamage(AttackPower attackPower) {
    _health -= min(_health, attackPower);
}