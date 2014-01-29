//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#ifndef _TieBreakerScore_hpp
#define _TieBreakerScore_hpp

#include "Score.hpp"
#include "Player.hpp"

/**  The player who scores at least 7 points and is ahead by at least
 *  2 points wins a tie-breaker.
 */

class TieBreakerScore: public Score {
public:
  TieBreakerScore( Player *p1, Player *p2 );
};

#endif
