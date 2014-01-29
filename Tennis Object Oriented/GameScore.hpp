//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#ifndef _GameScore_hpp
#define _GameScore_hpp


#include "Score.hpp"
#include "Player.hpp"

/**  The player who scores at least 4 points and is ahead by at least
 *  2 points wins a game.
 */

class GameScore: public Score {

public:
  GameScore( Player *p1, Player *p2 );
  bool haveAWinner();
  void print();
};

#endif
