#include "monster.h"

const std::string Mummy::_name = "Mummy";
const std::string Vampire::_name = "Vampire";
const std::string Zombie::_name = "Zombie";
const std::string GroupOfMonsters::_name = "GroupOfMonsters";

Monster::Monster(HealthPoints health, HealthPoints attack_power) : _health(health), _attack_power(attack_power) { }

HealthPoints Monster::getHealth() const {
    return _health;
}

void Monster::takeDamage(HealthPoints damage) {
    _health -= std::min(_health, damage);
}

Mummy::Mummy(HealthPoints health, HealthPoints attack_power) : _health(health), _attack_power(attack_power) { }

const std::string& Mummy::getName() const {
    return _name;
}

Vampire::Vampire(HealthPoints health, HealthPoints attack_power) : _health(health), _attack_power(attack_power) { }

const std::string& Vampire::getName() const {
    return _name;
}

Zombie::Zombie(HealthPoints health, HealthPoints attack_power) : _health(health), _attack_power(attack_power) { }

const std::string& Zombie::getName() const {
    return _name;
}

GroupOfMonsters::GroupOfMonsters(std::initializer_list<Monster> monsters) : _monsters(monsters) { }

GroupOfMonsters::GroupOfMonsters(std::vector<Monster> monsters) : _monsters(monsters) { }

HealthPoints GroupOfMonsters::getHealth() {
    HealthPoints health_of_group = 0;

    for (Monster monster : _monsters) {
        health_of_group += monster.getHealth();
    }

    return health_of_group;
}

AttackPower GroupOfMonsters::getAttackPower() {
    AttackPower attack_power_of_group = 0;

    for (Monster monster : _monsters) {
        attack_power_of_group += monster.getAttackPower();
    }

    return attack_power_of_group;
}

void GroupOfMonsters::takeDamage(AttackPower damage) {
    for (Monster monster : _monsters) {
        monster.takeDamage(damage);
    }
}

std::shared_ptr<Mummy>
createMummy(HealthPoints health, AttackPower attack_power) {
    return std::make_shared<Mummy>(health, attack_power);
}

std::shared_ptr<Vampire>
createVampire(HealthPoints health, AttackPower attack_power) {
    return std::make_shared<Vampire>(health, attack_power);
}

std::shared_ptr<Zombie>
createZombie(HealthPoints health, AttackPower attack_power) {
    return std::make_shared<Zombie>(health, attack_power);
}

std::shared_ptr<GroupOfMonsters>
createGroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}

std::shared_ptr<GroupOfMonsters>
createGroupOfMonsters(std::vector<std::shared_ptr<Monster>> monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}

