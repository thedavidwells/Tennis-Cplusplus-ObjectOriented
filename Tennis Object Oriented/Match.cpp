//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include "Match.hpp"
#include "MatchScore.hpp"
#include "Score.hpp"
#include "Set.hpp"
#include "Score.hpp"
#include "SetScore.hpp"

Match::Match( Player *p1, Player *p2 ): Competition( p1, p2 ) {}


//  Implemented by David Wells
Score *Match::play( Player *p ) {
    
    // Create a score object for this MATCH
    MatchScore *matchScore = new MatchScore( player1(), player2() );
    
    // While we don't have a winner of the Match, continue playing sets.
    while ( !matchScore->haveAWinner() ) {
        
        //  Create a new set and score object
        Set *set = new Set( player1(), player2() );
       
        //  Start playing a set  (which consists of many games)
        //  Set the set score as the result
        Score *setScore = set->play( player1() );
        
        //  Add the score to our Matchscore object
        matchScore -> addScore(setScore);
        
        //  The set is over so remove it before starting another
        delete set;
        
        //  Switch servers by setting p as the other player
        p = p -> otherPlayer(p);
        
    }
    
    
    return matchScore;
}
