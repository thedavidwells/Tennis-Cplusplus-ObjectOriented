//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include "MatchScore.hpp"

MatchScore::MatchScore( Player *p1, Player *p2 ): Score( p1, p2 ), setNumber(0) {}
bool MatchScore::haveAWinner()  { return false;  }  // just to make the compiler happy!
void MatchScore::addScore( Score *score ) {
}

void MatchScore::print() {
    for( int i = 0; i < setNumber; i++ )
      scores[i]->print();
}
MatchScore::~MatchScore() {
    for( int i = 0; i < setNumber; i++ )
      delete scores[i];
}
