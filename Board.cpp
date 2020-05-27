//
// Created by yonatan on 21/05/2020.
//

#include <iostream>
#include "Board.hpp"

void WarGame::Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
if(player_number>2 ||player_number<1 ){
   cout<<"need to write exeption no player like this"<<endl;
    throw std::invalid_argument("there is no player like this");
}
else if( source.first> board.size()-1 || source.first<0||source.second <0 ||source.second >board.at(0).size()-1 ){
    cout<<"need to write exeption source is not on the board"<<endl;
     throw std::invalid_argument("there is no source on the board");
}
else if(board[source.first][source.second] == nullptr ||board[source.first][source.second]->player != player_number){
    cout<<"need to write exeption none player of your team"<<endl;
     throw std::invalid_argument("none plyaer of your team");
}
else if(!isLegalMove(source , direction)){
    cout<<"need to write exeption not legal move"<<endl;
     throw std::invalid_argument("iliegal move");
}
else{
    cout<<"played"<<endl;
    Soldier* temp = board[source.first][source.second];

    board[source.first][source.second]= nullptr;

  int x = source.first,y=source.second;

    if(direction==MoveDIR::Left)
    {
        y--;
        board[source.first][source.second-1]=temp;
    }
    else if(direction==MoveDIR::Right)
    {
        y++;
        board[source.first][source.second+1]=temp;
    }
   else  if(direction==MoveDIR::Down)
   {
       x--;
       board[source.first-1][source.second]=temp;
   }
   else if(direction==MoveDIR::Up)
   {
       x++;
       board[source.first+1][source.second]=temp;
   }
    board[x][y]->action(*this);
}

}
std::pair<int,int> WarGame::Board::findNearest(uint player_number,std::pair<int,int> source){
    int x= source.first , y=source.second;
    int minDist=pow(board.size(),2);
    std::pair<int,int> ret;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(0).size(); ++j) {
            if(board[i][j]!= nullptr && board[i][j]->player != player_number){
                int calc = std::sqrt(pow(i-x,2)+pow(j-y,2));
                if(minDist>calc){
                    minDist=calc;
                    ret = {i,j};
                }
            }
        }
    }
    return ret;
}
std::pair<int,int> WarGame::Board::findHighest(uint player_number, pair<int, int> source) {

    int highest=0;
    std::pair<int,int> ret;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(0).size(); ++j) {
            if(board[i][j]!= nullptr && board[i][j]->player != player_number){
                if(board[i][j]->initial_health_points>highest){
                  highest=board[i][j]->initial_health_points;
                    ret = {i,j};
                }
            }
        }
    }
    return ret;
}
bool WarGame::Board::isLegalMove(std::pair<int,int> source , MoveDIR direction){
    if(direction==MoveDIR::Up){
        if(source.first==7 || board[source.first+1][source.second]!=nullptr){
            return false;
        }
    }
   else if(direction==MoveDIR::Down|| board[source.first-1][source.second]!=nullptr){
       if(source.first==0) {
           return false;
       }
    }
   else if(direction==MoveDIR::Left|| board[source.first][source.second-1]!=nullptr){
       if(source.second==0){
           return false;
       }
    }
    else if(direction==MoveDIR::Right|| board[source.first][source.second+1]!=nullptr){
        if(source.second==7){
            return false;
        }
    }
    return true;

}

bool WarGame::Board::has_soldiers(uint player_number) const{

    for (int i = 0; i < this->board.size() ; ++i) {
        for (int j = 0; j < this->board.at(0).size() ; ++j) {
          if(board[i][j]!= nullptr && board[i][j]->player == player_number){
              return true;
          }
        }
    }
    return false;
}
/*WarGame::Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
    if(board[location.first][location.second] == nullptr){
        return board[location.first][location.second] ;
    } else{
        throw std::invalid_argument("there is a solider there");
    }//exception
}*/
WarGame::Soldier*& WarGame::Board::operator[](std::pair<int,int> location){//kore et ze badistructor lama?
    return board[location.first][location.second] ;
}
WarGame::Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
    if(board[location.first][location.second]!= nullptr) {
        return board[location.first][location.second];
    }
    return nullptr;
}

