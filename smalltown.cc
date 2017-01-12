#include "smalltown.h"

#include <iostream>
#include <algorithm>
#include <cassert>

bool DefaultStrategy::isAttackTime(Time t) {
    return (t % 3 == 0 || t % 13 == 0) && (t % 7 != 0);
}

Status::Status(std::string monsterName, HealthPoints monsterHP,
       size_t citizensAlive) : _monsterName(monsterName), _monsterHP(monsterHP)
       , _citizensAlive(citizensAlive) {}

const std::string & Status::getMonsterName() {return _monsterName; }
const HealthPoints Status::getMonsterHP() {return _monsterHP; }
const size_t Status::getCitizensAlive() {return _citizensAlive; }

/* Implementation of class Builder */
Builder::Builder() {}

Builder & Builder::monster(MonsterPtr monster) {
    _monster = monster;
    return *this;
}

Builder & Builder::citizen(CitizenPtr citizen) {
    if (std::find(_citizens.begin(), _citizens.end(), citizen) == _citizens.end()) {
        _citizens.push_back(citizen);
    }

    return *this;
}

Builder & Builder::startTime(Time t0) {
    _t0 = t0;
    return *this;
}

Builder & Builder::maxTime(Time t1) {
    _t1 = t1;
    return *this;
}

Smalltown Builder::build() {
    assert(_monster != nullptr && _t0 >= 0 && _t1 >= 1);
    return SmallTown(_monster, _citizens, _t0, _t1);
}
