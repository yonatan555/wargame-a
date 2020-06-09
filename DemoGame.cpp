/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 *
 * @author Oz Levi
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>
using namespace std;
namespace WarGame {

    DemoGame::DemoGame(): board (numRows, numCols) {
        // Add soldiers for player 1:
        assert(!board.has_soldiers(1));
        board[{0, 0}] = new FootSoldier(1);//player 1 soldier1
        board.has_soldiers(1);
        board[{0, 1}] = new FootCommander(1);//player 1 soldier2
        board.has_soldiers(1);
        board[{0, 2}] = new Sniper(1);//player 1 soldier3
        board.has_soldiers(1);
        board[{0, 3}] = new SniperCommander(1);//player 1 soldier4
        board.has_soldiers(1);
        board[{0, 4}] = new Paramedic(1);//player 1 soldier5
        board[{0, 5}] = new ParamedicCommander(1);//player 1 soldier6
        board.has_soldiers(1);

        assert(!board.has_soldiers(2));
        board[{7, 0}] = new FootSoldier(2);//player 2 soldier1
        board[{7, 1}] = new FootCommander(2);//player 2 soldier2
        board[{7, 2}] = new Sniper(2);//player 2 soldier3
        board[{7, 3}] = new SniperCommander(2);//player 2 soldier4
        board[{7, 4}] = new Paramedic(2);//player 2 soldier5
        board[{7, 5}] = new ParamedicCommander(2);//p


        cout<<"fin de mise"<<endl;
    }
        uint DemoGame::play() {
            cout<<"start play"<<endl;

            //consider using for.....
            //    assert(board.has_soldiers(2));
                 board.move(1, {0, 0}, WarGame::Board::MoveDIR::Up); //player2 soldier1 - 90
                // assert(board.has_soldiers(2)            /*    board.move(1, {0, 1}, WarGame::Board::MoveDIR::Up);//player2 soldier2 - 130, player 2 soldier1 - 80
                // assert(board.has_soldiers(2));
                 board.move(1, {0, 2}, WarGame::Board::MoveDIR::Up);//player2 soldier6 - 150
              //   assert(board.has_soldiers(2));
                 board.move(1, {0, 3},
                            WarGame::Board::MoveDIR::Up);//player2 soldier6 - 50, player 2 soldier2 80 //need to define that commander shoots first
              //   assert(board.has_soldiers(2));
                 board.move(1, {0, 4},
                            WarGame::Board::MoveDIR::Up);//player1 soldier4 - 120 //need to define that curing id done after the step/move
              //   assert(board.has_soldiers(2));
                 board.move(1, {0, 5},
                            WarGame::Board::MoveDIR::Up); //player1 soldier5 - 100, player 1 soldier4 - 120, player 1 soldier6 - 200
               //  assert(board.has_soldiers(2));


                 //sniper 1 will kill them all
                 board.move(1, {1, 3}, WarGame::Board::MoveDIR::Down); //player2 soldier6 - 100, player 2 soldier2 80
                // assert(board.has_soldiers(2));
                 board.move(1, {0, 3},WarGame::Board::MoveDIR::Up); //player2 soldier4 - 20, player2 soldier3 - 50 //need to define to check the closes when there are equalh healh points
              //   assert(board.has_soldiers(2));
                 board.move(1, {1, 3}, WarGame::Board::MoveDIR::Down); //player2 soldier5 - 0, player2 soldier6 - 50
                 // assert(board.has_soldiers(2));
                   board.move(1, {0, 3}, WarGame::Board::MoveDIR::Up); //player2 soldier1 - 0, player2 soldier2 - 30
                 //just to be Sure all is dead
            for (int i = 0; i < board.board.size(); ++i) {
                std::cout << "\n";
                for (int j = 0; j < board.board.at(0).size(); ++j) {
                    if (FootCommander *n = dynamic_cast<FootCommander *>(board.board[i][j])) {
                        std::cout << "| FC"<<board.board[i][j]->player<<i<<"-"<<j<<"|";//<<board.board[i][j].player<<
                    }  if (FootSoldier *n = dynamic_cast<FootSoldier *>(board.board[i][j])) {
                        std::cout << "| F "<<board.board[i][j]->player<<i <<"-"<<j<<"|";
                    }    if (ParamedicCommander *n = dynamic_cast<ParamedicCommander *>(board.board[i][j])) {
                        std::cout << "| PC "<<board.board[i][j]->player<<i <<"-"<<j<<"|";
                    }  if (Sniper *n = dynamic_cast<Sniper *>(board.board[i][j])) {
                        std::cout << "| S "<<board.board[i][j]->player<<i <<"-"<<j<<"|";
                    }  if (SniperCommander *n = dynamic_cast<SniperCommander *>(board.board[i][j])) {
                        std::cout << "| SC "<<board.board[i][j]->player<<i <<"-"<<j<<"|" << std::endl;
                    }
                    if (Paramedic *n = dynamic_cast<Paramedic *>(board.board[i][j])) {
                        std::cout << "| P "<<board.board[i][j]->player<<i <<"-"<<j<<"|";
                    }
                    else {
                        cout << "| x | "<<i <<"-"<<j;
                    }
                }
            }
            cout << "\n";
            cout << "\n";
            cout << "\n";
                 board.move(1, {1, 2}, WarGame::Board::MoveDIR::Down); //player2 soldier3 - 0, player2 soldier 6 - 20/10
            for (int i = 0; i < board.board.size(); ++i) {
                std::cout << "\n";
                for (int j = 0; j < board.board.at(0).size(); ++j) {
                    if (FootCommander *n = dynamic_cast<FootCommander *>(board.board[i][j])) {
                        std::cout << "| FC"<<board.board[i][j]->player<<i<<"-"<<j<<"|";//<<board.board[i][j].player<<
                    }  if (FootSoldier *n = dynamic_cast<FootSoldier *>(board.board[i][j])) {
                        std::cout << "| F "<<board.board[i][j]->player<<i <<"-"<<j<<"|";
                    }    if (ParamedicCommander *n = dynamic_cast<ParamedicCommander *>(board.board[i][j])) {
                        std::cout << "| PC "<<board.board[i][j]->player<<i <<"-"<<j<<"|";
                    }  if (Sniper *n = dynamic_cast<Sniper *>(board.board[i][j])) {
                        std::cout << "| S "<<board.board[i][j]->player<<i <<"-"<<j<<"|";
                    }  if (SniperCommander *n = dynamic_cast<SniperCommander *>(board.board[i][j])) {
                        std::cout << "| SC "<<board.board[i][j]->player<<i <<"-"<<j<<"|" << std::endl;
                    }
                    if (Paramedic *n = dynamic_cast<Paramedic *>(board.board[i][j])) {
                        std::cout << "| P "<<board.board[i][j]->player<<i <<"-"<<j<<"|";
                    }
                    else {
                        cout << "| x | "<<i <<"-"<<j;
                    }
                }
            }
            std::cout<<" moshe1"<<endl;
                 board.move(1, {0, 2}, WarGame::Board::MoveDIR::Up); //player2 soldier3 - 0, player2 soldier 6 - 0
            /*            board.move(1, {1, 2}, WarGame::Board::MoveDIR::Down); //player2 soldier3 - 0, player2 soldier 6 - 0
         /*             board.move(1, {0, 2}, WarGame::Board::MoveDIR::Up); //player2 soldier3 - 0, player2 soldier 6 - 0
            */

            //just to be Sure all is dead
        //    assert(!board.has_soldiers(2));

            ///good test
            /// Write more moves here..

            return 0;
        }
    }



WarGame::DemoGame::~DemoGame() {
        for (int iRow=0; iRow<numRows; ++iRow) {
            //std::cout<<"row"<<iRow<<std::endl;
            for (int iCol=0; iCol<numCols; ++iCol) {
                //std::cout<<"col"<<iCol<<std::endl;
                Soldier* soldier = board[{iRow,iCol}];
                if (soldier){
                    //std::cout<<"dstr"<<iCol<<std::endl;
                    delete soldier;
                }
            }
        }
    }
