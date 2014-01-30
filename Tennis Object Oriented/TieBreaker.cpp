//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include "TieBreaker.hpp"
#include "TieBreakerScore.hpp"
#include "Score.hpp"
#include "GameScore.hpp"
#include "PointScore.hpp"

TieBreaker::TieBreaker( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

//  Implemented by David Wells
Score *TieBreaker::play( Player *p ) {
    
    
    //  Create a score object for this TieBreaker round
    //  A tiebreaker has different rules, so we made a different class to handle that
    TieBreakerScore *tieScore = new TieBreakerScore(player1(), player2() );
    
    //  We are adding a point score to the tiescore and it needs to be type-casted to the same type
    tieScore -> addScore(reinterpret_cast<PointScore *>(p->serveAPoint())->getWinner() );
    
    // Switch servers
    p = p -> otherPlayer(p);
    
    // Create a variable to keep track of when we switch servers (initialized to not switch)
    bool switchTheServer = false;
    
    //  While we don't have a winner of the tie-breaker round...
    while( !tieScore -> haveAWinner() ) {
        
        tieScore -> addScore(reinterpret_cast<PointScore *>(p->serveAPoint())->getWinner() );
        
        //  Here we determine if we need to switch servers
        //  Because we switch the server in a tie-breaker round every 2 turns
        if (switchTheServer) {
            
            //  Switch the servers, the same way we've done it before
            p = p -> otherPlayer(p);
            
        }
        
        // Set the server variable to the opposite of whatever it is currently set to
        switchTheServer = !switchTheServer;

        
    }
    
    return tieScore;
    
    
    
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

