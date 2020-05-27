//
// Created by yonatan on 21/05/2020.
//
#include "DemoGame.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <iostream>


void WarGame::FootSoldier::action(WarGame::Board& board) {
    std::cout<<"footSoldier action"<<std::endl;
    
}
void WarGame::FootCommander::action(WarGame::Board& board) {
    std::cout<<"footCommander action"<<std::endl;
}
WarGame::FootSoldier::~FootSoldier() {}
WarGame::FootCommander::~FootCommander(){}
