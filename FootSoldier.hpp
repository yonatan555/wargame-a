//
// Created by yonatan on 21/05/2020.
//
#pragma once

#ifndef WARGAME_A_FOOTSOLDIER_HPP
#define WARGAME_A_FOOTSOLDIER_HPP

#include "Soldier.hpp"

namespace WarGame{
    class Board;
class FootSoldier : public Soldier{
public:
    int damage_per_activity = 10 ;
    FootSoldier(int player) : Soldier(player,100) {};
    ~FootSoldier();
    virtual void action  (Board& b) override ;
};
}
#endif //WARGAME_A_FOOTSOLDIER_HPP
