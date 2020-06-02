//
// Created by yonatan on 02/06/2020.
//
#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP
#include "Soldier.hpp"
#include "Board.hpp"
namespace WarGame {
    class Board;
    class SniperCommander : public Soldier {
    public:
        int damage_per_activity = 100;
        SniperCommander(int player) : Soldier(player, 120,120) {};
        ~SniperCommander();
        virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) override;
    };
}
#endif //WARGAME_A_SNIPERCOMMANDER_HPP