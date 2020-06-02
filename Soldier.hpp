//
// Created by yonatan on 21/05/2020.
//
#pragma once
#include <iostream>
#include <vector>
//shabbat shalom ahi
#include "Soldier.hpp"
#include "Board.hpp"
namespace WarGame{
    class Board;

class Soldier{
public:
    int player ;
    int initial_health_points;
     int max_hp;

    std::pair<int,int> findNearest(uint player_number ,std::pair<int,int> source,std::vector<std::vector<Soldier*>> &board );
    std::pair<int,int> findHighest(uint player_number ,std::pair<int,int> source,std::vector <std::vector<Soldier *>> &board );
    bool isLegalMove(std::vector <std::vector<Soldier *>> &board , std::pair<int,int> direction);
    Soldier(int player,int hp,int max) : player(player) , initial_health_points(hp),max_hp(max){};
    virtual ~Soldier(){} ;
    virtual void action(std::vector<std::vector<Soldier*>>& board,std::pair<int,int> source) = 0;




};

}