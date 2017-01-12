#include "smalltown.h"

#include <iostream>
#include <algorithm>
#include <cassert>

/* Implementation of class DefaultStrategy */

bool DefaultStrategy::isAttackTime(Time t) const {
    return (t % 3 == 0 || t % 13 == 0) && (t % 7 != 0);
}

/* Implementation of class Status */

Status::Status(std::string monsterName, HealthPoints monsterHP,
       size_t citizensAlive) : _monsterName(monsterName), _monsterHP(monsterHP)
       , _citizensAlive(citizensAlive) {}

const std::string & Status::getMonsterName() const {return _monsterName; }
HealthPoints Status::getMonsterHP() const {return _monsterHP; }
size_t Status::getCitizensAlive() const {return _citizensAlive; }

/* Smalltown implementation */
SmallTown::SmallTown(const MonsterPtr & monster, const std::vector<CitizenPtr> citizens,
          Time t0, Time t1, AttackTimeStrategy* strategy) : _monster(monster), _citizens(citizens), _time(t0), _maxTime(t1), _strategy(strategy) {
              assert(_monster != nullptr);
              assert(_citizens.size() > 0);
              assert(_time <= _maxTime);
              assert(_strategy != nullptr);
              _citizensAlive = 0;
              for (const auto & c : _citizens) {
                  assert(c != nullptr);
                  if (c->getHealth() > 0) {
                      _citizensAlive++;
                  }
              }
          }

SmallTown::SmallTown(const MonsterPtr & monster, const std::vector<CitizenPtr> citizens,
          Time t0, Time t1) : SmallTown(monster, citizens, t0, t1, new DefaultStrategy) {};

Status SmallTown::getStatus() const {
    return Status(_monster->getName(), _monster->getHealth(), _citizensAlive);
}

void SmallTown::performAttack() {
    for (auto & c : _citizens) {
        if (c->getHealth() > 0) {
            c->takeDamage(*_monster);
            if (c->getHealth() <= 0) {
                _citizensAlive--;
            }
            if (_monster->getHealth() <= 0) {
                return;
            }
        }
    }
}

void SmallTown::tick(Time timeStep) {
    bool monsterAlive = (_monster->getHealth() > 0);
    if(_citizensAlive == 0 && monsterAlive) {
        std::cout << "MONSTER WON" << std::endl;
    } else if (_citizensAlive > 0 && !monsterAlive) {
        std::cout << "CITIZENS WON" << std::endl;
    } else if (_citizensAlive == 0 && !monsterAlive) {
        std::cout << "DRAW" << std::endl;
    } else if (_strategy.isAttackTime(_time)) {
        performAttack();
    }
    _time = (_time + timeStep) % (_maxTime + 1);
}

/* Implementation of class Builder */
SmallTown::Builder::Builder() {}

SmallTown::Builder & SmallTown::Builder::monster(MonsterPtr monster) {
    _monster = monster;
    return *this;
}

SmallTown::Builder & SmallTown::Builder::citizen(CitizenPtr citizen) {
    if (std::find(_citizens.begin(), _citizens.end(), citizen) == _citizens.end()) {
        _citizens.push_back(citizen);
    }

    return *this;
}

SmallTown::Builder & SmallTown::Builder::startTime(Time t0) {
    _t0 = t0;
    return *this;
}

SmallTown::Builder & SmallTown::Builder::maxTime(Time t1) {
    _t1 = t1;
    return *this;
}

SmallTown SmallTown::Builder::build() {
    assert(_monster != nullptr && _t0 >= 0 && _t1 >= 0);
    return SmallTown(_monster, _citizens, _t0, _t1);
}
