//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include "MatchScore.hpp"

MatchScore::MatchScore( Player *p1, Player *p2 ): Score( p1, p2 ), setNumber(0) {}

//  Implemented by David Wells
bool MatchScore::haveAWinner()  {
    
    //  Using the function match_over() from the tennis.cpp
    return player1Score() == 3 || player2Score() == 3;
    
}  // just to make the compiler happy!


//  Implemented by David Wells
void MatchScore::addScore( Score *score ) {
    
    // Create an array to hold all of the scores
    
    
    
}

void MatchScore::print() {
    for( int i = 0; i < setNumber; i++ )
      scores[i]->print();
}
MatchScore::~MatchScore() {
    for( int i = 0; i < setNumber; i++ )
      delete scores[i];
}
