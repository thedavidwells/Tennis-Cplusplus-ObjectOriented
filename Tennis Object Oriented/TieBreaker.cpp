//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include "TieBreaker.hpp"
#include "TieBreakerScore.cpp"
#include "Score.hpp"
#include "GameScore.hpp"
#include "PointScore.hpp"

TieBreaker::TieBreaker( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *TieBreaker::play( Player *p ) {
    
    
    Score *score = new GameScore( player1(), player2() );
    
    while( !score->haveAWinner() ) {
        PointScore *pointScore = reinterpret_cast<PointScore *>( p->serveAPoint() );
        score->addScore( pointScore->getWinner() );
        delete pointScore;
    }
    return score;
    
    
    
    // Original C++ code:
    /*
     p1_score = p2_score = 0;
     point( player ) == PLAYER1 ? p1_score++ : p2_score++;
     int switchServe = 0;
     do {
     if( switchServe++ % 2 == 0 ) player = other(player);
     point( player ) == PLAYER1 ? p1_score++ : p2_score++;
     } while ( ! tie_over( p1_score, p2_score ) );
     return p1_score > p2_score ? PLAYER1 : PLAYER2;
     */
}

