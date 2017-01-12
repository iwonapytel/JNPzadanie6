#include "monster.h"

Monster::Monster(HealthPoints health, HealthPoints attack_power, std::string name) :
        _health(health), _name(name), Attacker(attack_power) { }

HealthPoints Monster::getHealth() const {
    return _health;
}

void Monster::takeDamage(HealthPoints damage) {
    _health -= std::min(_health, damage);
}

Mummy::Mummy(HealthPoints health, HealthPoints attack_power)
        : Monster(health, attack_power, "Mummy") { }

const std::string& Mummy::getName() const {
    return _name;
}

Vampire::Vampire(HealthPoints health, HealthPoints attack_power)
        : Monster(health, attack_power, "Vampire") { }

const std::string& Vampire::getName() const {
    return _name;
}

Zombie::Zombie(HealthPoints health, HealthPoints attack_power)
        : Monster(health, attack_power, "Zombie") { }

const std::string& Zombie::getName() const {
    return _name;
}

GroupOfMonsters::GroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters)
        : _monsters(monsters), _name("GroupOfMonsters") { }

GroupOfMonsters::GroupOfMonsters(const std::vector<std::shared_ptr<Monster>>& monsters)
        : _monsters(monsters), _name("GroupOfMonsters") { }

GroupOfMonsters::GroupOfMonsters(std::vector<std::shared_ptr<Monster>>&& monsters)
        : _monsters(monsters), _name("GroupOfMonsters") { }

HealthPoints GroupOfMonsters::getHealth() const {
    HealthPoints health_of_group = 0;

    for (std::shared_ptr<Monster> monster : _monsters) {
        health_of_group += monster->getHealth();
    }

    return health_of_group;
}

AttackPower GroupOfMonsters::getAttackPower() const {
    AttackPower attack_power_of_group = 0;

    for (std::shared_ptr<Monster> monster : _monsters) {
        attack_power_of_group += monster.getAttackPower();
    }

    return attack_power_of_group;
}

void GroupOfMonsters::takeDamage(AttackPower damage) {
    for (std::shared_ptr<Monster> monster : _monsters) {
        monster.takeDamage(damage);
    }
}

const std::string& GroupOfMonsters::getName() const {
    return _name;
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
createGroupOfMonsters(const std::vector<std::shared_ptr<Monster>>& monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}

std::shared_ptr<GroupOfMonsters>
createGroupOfMonsters(std::vector<std::shared_ptr<Monster>>&& monsters) {
    return std::make_shared<GroupOfMonsters>(std::move(monsters));
}


