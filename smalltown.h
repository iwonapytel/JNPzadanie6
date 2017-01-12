#ifndef _SMALLTOWN_H_
#define _SMALLTOWN_H_

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include "monster.h"
#include "citizen.h"

/* Przerzucić gdzieś indziej */

using MonsterPtr = std::shared_ptr<Monster>;
using CitizenPtr = std::shared_ptr<Citizen>;

class AttackTimeStrategy {
public:
    virtual bool isAttackTime(Time t) const = 0;
}

class DefaultStrategy : public AttackTimeStrategy {
    bool isAttackTime(Time t) const override;
}

class Status {
private:
    std::string _monsterName;
    HealthPoints _monsterHP;
    size_t _citizensAlive;
public:
    Status(std::string monsterName, HealthPoints monsterHP,
           size_t citizensAlive);

    const std::string & getMonsterName() const;
    HealthPoints & getMonsterHP() const;
    size_t getCitizensAlive() const;
}

class Builder {
private:
    MonsterPtr _monster;
    std::vector<CitizenPtr> _citizens;
    Time _t0 = -1;
    Time _t1 = -1;
public:
    Builder();

    Builder & monster(MonsterPtr monster);
    Builder & citizen(CitizenPtr citizen);
    Builder & startTime(Time t0);
    Builder & maxTime(Time t1);

    Smalltown build();
    }
}

class SmallTown {
private:
    MonsterPtr monster;
    std::vector<CitizenPtr> citizens;
    Time t0, t1;
    AttackTimeStrategy strategy;
    size_t citizensAlive;
public:
    SmallTown(const MonsterPtr & monster, const std::vector<CitizenPtr> citizens,
              Time t0, Time t1);

    SmallTown(const MonsterPtr & monster, const std::vector<CitizenPtr> citizens,
              Time t0, Time t1, AttackTimeStrategy strategy);

    Status getStatus() const;

    void tick(Time timeStep);
}
