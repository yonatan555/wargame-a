//
// Created by yonatan on 21/05/2020.
//
#include <typeinfo>
#include "DemoGame.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <iostream>


WarGame::FootSoldier::FootSoldier(int player) : Soldier(player, 100, 100) {}

void WarGame::FootSoldier::action(std::vector <std::vector<Soldier *>> &board, std::pair<int, int> source) {
    std::pair<int, int> sourceSoldier = findNearest(this->player, source, board);
    if(sourceSoldier.first!=-1) {
        Soldier *curr = board[sourceSoldier.first][sourceSoldier.second];
        // std::cout<<curr->initial_health_points<<endl;
        curr->initial_health_points = curr->initial_health_points - this->damage_per_activity;
        // std::cout << curr->initial_health_points << endl;
        if (curr->initial_health_points <= 0) {
            delete curr;
            board[sourceSoldier.first][sourceSoldier.second] = nullptr;
        }
    }

}
void WarGame::FootCommander::action(std::vector <std::vector<Soldier *>> &board, std::pair<int, int> source) {
    std::pair<int, int> sourceSoldier = findNearest(this->player, source, board);

    Soldier *curr = board[sourceSoldier.first][sourceSoldier.second];
   // std::cout << curr->initial_health_points << endl;
    curr->initial_health_points = curr->initial_health_points - this->damage_per_activity;
    if (curr->initial_health_points <= 0) {
        delete curr;
        board[sourceSoldier.first][sourceSoldier.second] = nullptr;
    }
    // std::cout<<curr->initial_health_points<<endl;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(0).size(); ++j) {
            if (board[i][j] != nullptr && board[i][j]->player == this->player) {
                if (FootSoldier *n = dynamic_cast<FootSoldier *>(board[i][j])) {
                    std::pair<int, int> dest;
                    dest.first = i;
                    dest.second = j;
                    n->action(board, dest);
                }

            }
        }
    }
}

void WarGame::Sniper::action(std::vector <std::vector<Soldier *>> &board, std::pair<int, int> source) {
    std::cout<<" moshe6-1"<<std::endl;
    std::pair<int, int> sourceSoldier = findHighest(this->player, source, board);
    std::cout<<" moshe 6-2"<<std::endl;
    if(sourceSoldier.first !=-1) {
        Soldier *curr = board[sourceSoldier.first][sourceSoldier.second];
        std::cout << " moshe 6-3" << std::endl;
        std::cout << sourceSoldier.first << std::endl;
        std::cout << sourceSoldier.second << std::endl;
        std::cout << curr->initial_health_points << endl;
        curr->initial_health_points = curr->initial_health_points - this->damage_per_activity;
        std::cout << " moshe 6-4" << std::endl;
        //std::cout << curr->initial_health_points << endl;
        if (curr->initial_health_points <= 0) {
            delete curr;
            board[sourceSoldier.first][sourceSoldier.second] = nullptr;
        }
    }

}
void WarGame::SniperCommander::action(std::vector <std::vector<Soldier *>> &board, std::pair<int, int> source) {
    std::pair<int, int> sourceSoldier = findHighest(this->player, source, board);
    Soldier *curr = board[sourceSoldier.first][sourceSoldier.second];
    // std::cout << curr->initial_health_points << endl;
    curr->initial_health_points = curr->initial_health_points - this->damage_per_activity;
    if (curr->initial_health_points <= 0) {
        delete curr;
        board[sourceSoldier.first][sourceSoldier.second] = nullptr;
    }
    // std::cout<<curr->initial_health_points<<endl;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(0).size(); ++j) {
            if (board[i][j] != nullptr && board[i][j]->player == this->player) {
                if (Sniper* n = dynamic_cast<Sniper*>(board[i][j])) {
                    std::pair<int, int> dest;
                    dest.first = i;
                    dest.second = j;
                    n->action(board, dest);
                }
            }
        }
    }
}

void WarGame::Paramedic::action(std::vector <std::vector<Soldier *>> &board, std::pair<int, int> source) {
    if( isLegalMove(board ,{source.first+1,source.second+1})&&board[source.first+1][source.second+1]!= nullptr && board[source.first+1][source.second+1]->player==this->player){
        board[source.first+1][source.second+1]->initial_health_points = board[source.first+1][source.second+1]->max_hp;
    }
    if( isLegalMove(board ,{source.first,source.second+1})&&board[source.first][source.second+1]!= nullptr && board[source.first][source.second+1]->player==this->player){
        board[source.first][source.second+1]->initial_health_points = board[source.first][source.second+1]->max_hp;
    }
    if( isLegalMove(board,{source.first-1,source.second+1})&&board[source.first-1][source.second+1]!= nullptr && board[source.first-1][source.second+1]->player==this->player){
        board[source.first-1][source.second+1]->initial_health_points = board[source.first-1][source.second+1]->max_hp;
    }
    if( isLegalMove(board,{source.first+1,source.second})&&board[source.first+1][source.second]!= nullptr && board[source.first+1][source.second]->player==this->player){
        board[source.first+1][source.second]->initial_health_points = board[source.first+1][source.second]->max_hp;
    }
    if( isLegalMove(board ,{source.first-1,source.second})&&board[source.first-1][source.second]!= nullptr && board[source.first-1][source.second]->player==this->player){
        board[source.first-1][source.second]->initial_health_points = board[source.first-1][source.second]->max_hp;
    }
    if( isLegalMove(board ,{source.first+1,source.second-1})&&board[source.first+1][source.second-1]!= nullptr && board[source.first+1][source.second-1]->player==this->player){
        board[source.first+1][source.second-1]->initial_health_points = board[source.first+1][source.second-1]->max_hp;
    }
    if( isLegalMove(board ,{source.first,source.second-1})&&board[source.first][source.second-1]!= nullptr && board[source.first][source.second-1]->player==this->player){
        board[source.first][source.second-1]->initial_health_points = board[source.first][source.second-1]->max_hp;
    }
    if( isLegalMove(board ,{source.first-1,source.second-1})&&board[source.first-1][source.second-1]!= nullptr && board[source.first-1][source.second-1]->player==this->player){
        board[source.first-1][source.second-1]->initial_health_points = board[source.first-1][source.second-1]->max_hp;
    }
}
void WarGame::ParamedicCommander::action(std::vector <std::vector<Soldier *>> &board, std::pair < int,int > source) {
    if( isLegalMove(board ,{source.first+1,source.second+1})&&board[source.first+1][source.second+1]!= nullptr && board[source.first+1][source.second+1]->player==this->player){
        board[source.first+1][source.second+1]->initial_health_points = board[source.first+1][source.second+1]->max_hp;
    }
    if( isLegalMove(board ,{source.first,source.second+1})&&board[source.first][source.second+1]!= nullptr && board[source.first][source.second+1]->player==this->player){
        board[source.first][source.second+1]->initial_health_points = board[source.first][source.second+1]->max_hp;
    }
    if( isLegalMove(board,{source.first-1,source.second+1})&&board[source.first-1][source.second+1]!= nullptr && board[source.first-1][source.second+1]->player==this->player){
        board[source.first-1][source.second+1]->initial_health_points = board[source.first-1][source.second+1]->max_hp;
    }
    if( isLegalMove(board,{source.first+1,source.second})&&board[source.first+1][source.second]!= nullptr && board[source.first+1][source.second]->player==this->player){
        board[source.first+1][source.second]->initial_health_points = board[source.first+1][source.second]->max_hp;
    }
    if( isLegalMove(board ,{source.first-1,source.second})&&board[source.first-1][source.second]!= nullptr && board[source.first-1][source.second]->player==this->player){
        board[source.first-1][source.second]->initial_health_points = board[source.first-1][source.second]->max_hp;
    }
    if( isLegalMove(board ,{source.first+1,source.second-1})&&board[source.first+1][source.second-1]!= nullptr && board[source.first+1][source.second-1]->player==this->player){
        board[source.first+1][source.second-1]->initial_health_points = board[source.first+1][source.second-1]->max_hp;
    }
    if( isLegalMove(board ,{source.first,source.second-1})&&board[source.first][source.second-1]!= nullptr && board[source.first][source.second-1]->player==this->player){
        board[source.first][source.second-1]->initial_health_points = board[source.first][source.second-1]->max_hp;
    }
    if( isLegalMove(board ,{source.first-1,source.second-1})&&board[source.first-1][source.second-1]!= nullptr && board[source.first-1][source.second-1]->player==this->player){
        board[source.first-1][source.second-1]->initial_health_points = board[source.first-1][source.second-1]->max_hp;
    }
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(0).size(); ++j) {
            if (board[i][j] != nullptr && board[i][j]->player == this->player) {
                if (Paramedic* n = dynamic_cast<Paramedic*>(board[i][j])) {
                    std::pair<int, int> dest;
                    dest.first = i;
                    dest.second = j;
                    n->action(board, dest);
                }
            }
        }
    }
}

std::pair<int,int> WarGame::Soldier::findHighest(uint player_number, std::pair<int, int> source,std::vector <std::vector<Soldier *>> &board) {

    int highest=-1;
    std::pair<int,int> ret;
    ret.first = -1 ;
    ret.second = -1 ;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(0).size(); ++j) {

            std::cout<<i<<j<<std::endl;
            if(board[i][j]!= nullptr && board[i][j]->player != player_number){
                if(board[i][j]->initial_health_points>=highest){
                    std::cout<<"hi22"<<std::endl;
                    highest=board[i][j]->initial_health_points;
                    ret = {i,j};
                }
            }
        }
    }

   // if(ret.first == -1 || ret.second == -1 ){
     //   throw std::invalid_argument("iliegal move");
    //}

    return ret;
}
std::pair<int, int> WarGame::Soldier::findNearest(uint player_number, std::pair<int, int> source,std::vector <std::vector<Soldier *>> &board) {
    int x = source.first, y = source.second;
    int minDist = pow(board.size(), 2);
    std::pair<int, int> ret;
    ret.first=-1;
    ret.first=-1;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(0).size(); ++j) {
            if (board[i][j] != nullptr && board[i][j]->player != player_number) {
                int calc = std::sqrt(pow(i - x, 2) + pow(j - y, 2));
                if (minDist > calc) {
                    minDist = calc;
                    ret = {i, j};
                }
            }
        }
    }
    return ret;
}
bool WarGame::Soldier::isLegalMove(std::vector <std::vector<Soldier *>> &board  , std::pair<int,int> dest){

        if(dest.first<0 || dest.first>board.size() || dest.second<0 || dest.second>board.at(0).size()){
            return false;

    }
        else {
            return true;
        }
}



WarGame::FootSoldier::~FootSoldier() {}
WarGame::FootCommander::~FootCommander() {}
WarGame::ParamedicCommander::~ParamedicCommander() {}
WarGame::Paramedic::~Paramedic() {}
WarGame::Sniper::~Sniper() {}
WarGame::SniperCommander::~SniperCommander() {}
