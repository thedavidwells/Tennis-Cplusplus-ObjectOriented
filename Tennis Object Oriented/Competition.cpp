//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include "Competition.hpp"
#include "Player.hpp"

Competition::Competition( Player *player1, Player *player2 ): p1( player1 ), p2 ( player2 ) {}

Player *Competition::player1() { return p1; }
Player *Competition::player2() { return p2; }
