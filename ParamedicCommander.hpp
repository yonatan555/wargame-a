//
// Created by yonatan on 02/06/2020.
//
#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP
#include "Soldier.hpp"
#include "Board.hpp"
namespace WarGame {
    class Board;
    class ParamedicCommander : public Soldier {
    public:
        ParamedicCommander(int player) : Soldier(player, 200,200) {};
        ~ParamedicCommander();
       // virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) override;
    };
}
#endif //WARGAME_A_PARAMEDICCOMMANDER_HPP