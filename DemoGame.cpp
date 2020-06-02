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
#include <cassert>

namespace WarGame {

    DemoGame::DemoGame(): board (numRows, numCols) {
        // Add soldiers for player 1:
        //assert(!board.has_soldiers(1));
        board[{0,1}] = new Sniper(1);
     //   board[{6,5}] = new FootSoldier(1);
        //assert(board.has_soldiers(1));
        // Add soldiers for player 2:
        //assert(!board.has_soldiers(2));
        board[{7,1}] = new FootCommander(2);
        board[{7,2}] = new Paramedic(2);
       // board[{7,3}] = new FootCommander(2);
        //board[{7,5}] = new FootSoldier(2);
       //assert(board.has_soldiers(2));
        // In your game, you can put more soldier types, such as the sniper and the paramedic types.
    }
    uint DemoGame::play() {
        board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
       // board.move(1, {1,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
        //board.move(1, {0,3}, Board::MoveDIR::Up);
        if (!board.has_soldiers(2)) return 1;
                board.move(2, {7,2}, Board::MoveDIR::Up);//[8,2]    // FootSoldier of player 2 moves forward and attacks from {7,1} to {6,1}.
                 if (!board.has_soldiers(1)) return 2;
                 std::cout<<board[{7,1}]->initial_health_points<<std::endl;
/*
                 board.move(1, {0,3}, Board::MoveDIR::Up);      // FootCommander of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack.
                 if (!board.has_soldiers(2)) rern 1;

                 board.move(2, {7,3}, Board::MoveDIR::Left);    // FootCommander of player 2 moves left from {7,3} to {7,2}, and all soldiers of player 2 attack.
                 if (!board.has_soldiers(1)) return 2;
         */
        /// Write more moves here..

      // If no player won, return "tie":
        return 0;
    }

    DemoGame::~DemoGame() {
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
}