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
        FootCommander(int player) : Soldier(player, 150) {};
        ~FootCommander();
        int damage_per_activity = 20;

        virtual void action(Board &board) override;



    };
}

#endif //WARGAME_A_FOOTCOMMANDER_HPP