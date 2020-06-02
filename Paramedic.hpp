//
// Created by yonatan on 02/06/2020.
//
#ifndef WARGAME_A_PARAMEDIC_HPP
#define WARGAME_A_PARAMEDIC_HPP
#include "Soldier.hpp"
#include "Board.hpp"
namespace WarGame {
    class Board;
    class Paramedic : public Soldier {
    public:
        Paramedic(int player) : Soldier(player,100,100){};
        ~Paramedic();
        virtual void action(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source) override;
    };
}
#endif //WARGAME_A_PARAMEDIC_HPP