#include "helper.h"
#include "citizen.h"

Citizen::Citizen(HealthPoints health, Age age) : _health(health), _age(age) {
    assert(health > 0);
}

HealthPoints Citizen::getHealth() const {
    return _health;
}

Age Citizen::getAge() const {
    return _age;
}

void Citizen::takeDamage(AttackPower damage) {
    _health -= std::min(damage, _health);
}

Adult::Adult(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= static_cast<HealthPoints>(MIN_ADULT_AGE) && age <= static_cast<HealthPoints>(MAX_ADULT_AGE));
}

Teenager::Teenager(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= static_cast<HealthPoints>(MIN_TEENAGER_AGE) && age <= static_cast<HealthPoints>(MAX_TEENAGER_AGE));
}

Sheriff::Sheriff(HealthPoints health, Age age, AttackPower attack_power) : Citizen(health, age),
                                                                            Attacker(attack_power) {
    assert(age >= static_cast<HealthPoints>(MIN_ADULT_AGE) && age <= static_cast<HealthPoints>(MAX_ADULT_AGE));
}

void Sheriff::fightBack(Monster& who_attacked) {
    who_attacked.takeDamage(getAttackPower());
}

std::shared_ptr<Adult>
createAdult(HealthPoints health, Age age) {
    return std::make_shared<Adult>(health, age);
}

std::shared_ptr<Teenager>
createTeenager(HealthPoints health, Age age) {
    return std::make_shared<Teenager>(health, age);
}

std::shared_ptr<Sheriff>
createSheriff(HealthPoints health, Age age, AttackPower attack_power) {
    return std::make_shared<Sheriff>(health, age, attack_power);
}