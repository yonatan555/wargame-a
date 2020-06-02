//
// Created by yonatan on 02/06/2020.
//
#ifndef WARGAME_A_SNIPER_HPP
#define WARGAME_A_SNIPER_HPP
#include "Soldier.hpp"
#include "Board.hpp"
namespace WarGame {
    class Board;
    class Sniper : public Soldier {
    public:
        int damage_per_activity = 50;
        Sniper(int player) : Soldier(player,100,100) {};
        ~Sniper();

        virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) override;
    };
}
#endif //WARGAME_A_SNIPER_HPP