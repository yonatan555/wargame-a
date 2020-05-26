//
// Created by yonatan on 21/05/2020.
//

#pragma once
#include <iostream>
//shabbat shalom ahi


namespace WarGame{
    class Board;
class Soldier{
public:
    int initial_health_points;
    int player;
    virtual ~Soldier(){ std::cout<<"Destructing base \n"; } ;
    virtual void action(Board& board) = 0;
    Soldier(int player,int hp) : player(player) , initial_health_points(hp){};
};

}



