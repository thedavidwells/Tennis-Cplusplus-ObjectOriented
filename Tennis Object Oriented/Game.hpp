//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#ifndef _Game_hpp
#define _Game_hpp

#include "Competition.hpp"

/**  A Game is a Competition in which a player (specified by the
 *  argument to "play") serves points until there is a winner.  The
 *  rule of winning a game is given by class, GameScore.
 */

class Game: public Competition {
public:
  Game( Player *p1, Player *p2 );
  Score *play( Player *p );
};

#endif
