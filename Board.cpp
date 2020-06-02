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
else if( source.first > board.size()-1 || source.first<0||source.second <0 ||source.second >board.at(0).size()-1 ){
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
    //int x = source.first,y=source.second;
    pair<int,int> dest  ;
    if(direction==MoveDIR::Left)
    {
        //y--;
        dest.first = source.first ;
        dest.second = source.second-1 ;
        board[source.first][source.second-1]=temp;
    }
    else if(direction==MoveDIR::Right)
    {
       // y++;
        dest.first = source.first ;
        dest.second = source.second+1 ;
        board[source.first][source.second+1]=temp;
    }
   else  if(direction==MoveDIR::Down)
   {
     //  x--;
       dest.first = source.first-1 ;
       dest.second = source.second ;
       board[source.first-1][source.second]=temp;
   }
   else if(direction==MoveDIR::Up)
   {
    //   x++;
       dest.first = source.first-1 ;
       dest.second = source.second ;
       board[source.first+1][source.second]=temp;
   }
    board[source.first][source.second]= nullptr;
    temp->action(this->board,dest);
}
}


bool WarGame::Board::isLegalMove(std::pair<int,int> source , MoveDIR direction){
    if(direction==MoveDIR::Up ) {
        if (source.first + 1 >= board.size() || board[source.first + 1][source.second] != nullptr) {
            return false;
        }
    }
   else if(direction==MoveDIR::Down&& (source.first-1 < 0 || board[source.first-1][source.second]!=nullptr))
   {
           return false;
    }
   else if(direction==MoveDIR::Left&& (source.second -1 < 0 ||board[source.first][source.second-1]!=nullptr))
   {
           return false;
    }
    else if(direction==MoveDIR::Right&& (source.second+1 >= board.at(0).size()|| board[source.first][source.second+1]!=nullptr)){
            return false;
    }
        std::cout<<"true"<<std::endl;
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
WarGame::Soldier*& WarGame::Board::operator[](std::pair<int,int> location){//kore et ze badistructor lama?
    return board[location.first][location.second] ;
}

WarGame::Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
    //if(board[location.first][location.second] != nullptr) {
        return board[location.first][location.second];
    //}
   // return nullptr;
}

