//
// Created by yonatan on 21/05/2020.
//
#ifndef WARGAME_A_FOOTCOMMANDER_HPP
#define WARGAME_A_FOOTCOMMANDER_HPP
#include "Soldier.hpp"
#include "Board.hpp"
namespace WarGame {
    class Board;
    class FootCommander : public Soldier {
    public:
        int damage_per_activity = 20;
        FootCommander(int player) : Soldier(player,150,150) {};
        ~FootCommander();
        virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) override;
    };
}
#endif //WARGAME_A_FOOTCOMMANDER_HPP