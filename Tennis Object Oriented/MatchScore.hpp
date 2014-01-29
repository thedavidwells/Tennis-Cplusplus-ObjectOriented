//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#ifndef _MatchScore_hpp
#define _MatchScore_hpp

#include "Score.hpp"
#include "Player.hpp"
#include "SetScore.hpp"
#include "TieBreakerScore.hpp"

/**  A match is won by the player who wins the first 3 sets. 
 */

class MatchScore: public Score {

public: 
  MatchScore( Player *p1, Player *p2 );
  bool haveAWinner();
  void addScore( Score *score );
  void print();
  ~MatchScore();

private:
  SetScore *scores[5];
  int setNumber;
};

#endif
