//
// Created by yonatan on 22/05/2020.
//
#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"

#include <cassert>
    namespace WarGame {
        WarGame::Board board(8, 8);
        TEST_CASE ("legal and illegal moves AND constructors (foot commander)") {
//24
            CHECK(!board.has_soldiers(1));
            board[{0, 0}] = new FootCommander(1);
            CHECK(board[{0,0}]);
            CHECK(board[{0,0}]);
            board[{0, 3}] = new FootCommander(1);
            CHECK(board[{0,3}]);
            board[{0, 7}] = new FootCommander(1);
            CHECK(board[{0,7}]);
            CHECK(board.has_soldiers(1));
            CHECK(!board.has_soldiers(2));
            board[{7, 0}] = new FootCommander(2);
            CHECK(board[{7,0}]);
            board[{7, 3}] = new FootCommander(2);
            CHECK(board[{7,3}]);
            board[{7, 7}] = new FootCommander(2);
            CHECK(board[{7,7}]);
            CHECK(board.has_soldiers(2));
         CHECK(board.has_soldiers(1));
         CHECK(board.has_soldiers(2));


        }

        TEST_CASE ("FootSoldier VS FootCommander") {//19
            WarGame::Board board(5, 5);
            CHECK(!board.has_soldiers(1));
            board[{0, 0}] = new FootSoldier(1);
            CHECK(board[{0,0}]);
            CHECK(board[{0,0}]);
            board[{1, 1}] = new FootCommander(1);
            board[{0, 1}] = new FootSoldier(1);
            board[{0, 2}] = new FootSoldier(1);
            CHECK(board.has_soldiers(1));
            CHECK(!board.has_soldiers(2));
            for (int i = 0; i < 5; i++) {
                board[{4,i}] = new FootSoldier(2);
                CHECK(board[{4,i}]);
            }

            for (int i = 1; i < 5; i++) {
                board[{4,i}] = new FootSoldier(2);
                CHECK(board[{4,i}]);
                board.move(2,{4,i},WarGame::Board::MoveDIR::Down);
                CHECK(board[{4-i,i}]);
            }
                    CHECK(board.has_soldiers(2));
        }

        TEST_CASE ("FootSoldier VS FootSoldier") {
            WarGame::Board board(8, 8);
            CHECK(!board.has_soldiers(1));
            board[{3, 6}] = new FootSoldier(1);
            CHECK_THROWS((board[{3, 6}] = new FootSoldier(1)));
            CHECK_THROWS((board[{3, 6}] = new FootSoldier(2)));
            board[{5, 3}] = new FootSoldier(1);
            board[{6, 1}] = new FootSoldier(1);
            CHECK(board.has_soldiers(1));
            for (int i = 0; i < 8; i++) {
            board[{i, i}] = new FootSoldier(1);
            CHECK(board.has_soldiers(1));
            CHECK(!board.has_soldiers(2));
            }
            CHECK(!board.has_soldiers(2));
        }

        TEST_CASE ("moves outside AND illegal moves") {
            WarGame::Board board(8,8);
            CHECK(!board.has_soldiers(1));
            board[{5,1}] = new FootSoldier(1);
            board[{5,2}] = new FootSoldier(2);
            CHECK_THROWS(board.move(1, {6, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
            CHECK_THROWS(board.move(1, {6, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
            CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
            CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Down)); //no soldier their
            CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Down)); //no soldier their
            CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Right)); //no soldier their
            CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Right)); //no soldier their
            CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Left)); //no soldier their
            CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Left)); //no soldier their
            CHECK(!board.has_soldiers(2));
            CHECK(!board.has_soldiers(2));
            board[{5, 4}] = new FootSoldier(2);
            CHECK_THROWS(board.move(2, {3, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
            board[{5, 1}] = new FootSoldier(1);
            board[{7, 1}] = new FootSoldier(1);
            //CHECK_THROWS(board.move(1, {7, 1}, WarGame::Board::MoveDIR::Up)); //outside
            board[{0, 1}] = new FootSoldier(1);
            //CHECK_THROWS(board.move(1, {7, 1}, WarGame::Board::MoveDIR::Down)); //outside
            board[{0, 7}] = new FootSoldier(2);
            //CHECK_THROWS(board.move(2, {0, 7}, WarGame::Board::MoveDIR::Right)); //outside
            board[{0, 0}] = new FootSoldier(2);

            //CHECK_THROWS(board.move(2, {0, 7}, WarGame::Board::MoveDIR::Left)); //outside
        }
        TEST_CASE ("init") {//34
            CHECK(!board.has_soldiers(1));
            CHECK(!board.has_soldiers(1));
            CHECK(!board.has_soldiers(2));
            CHECK(!board.has_soldiers(2));
            for (int i = 0; i < 7; i++) {
            board[{i, 0}] = new FootCommander(1);
            board[{i, 7}] = new FootCommander(2);
            board[{i+1, 0}] = new FootSoldier(1);
            board[{i+1, 6}] = new FootSoldier(2);
            CHECK(board[{i, 0}]);
            CHECK(board[{i, 0}]);
            CHECK(board[{i, 7}]);
            CHECK(board[{i+1, 6}]);
            CHECK(board[{i+1, 0}]);
            }
        }
    }

