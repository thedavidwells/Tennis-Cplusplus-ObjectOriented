//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include "Set.hpp"
#include "Score.hpp"
#include "SetScore.hpp"

#include "Game.hpp"
#include "GameScore.hpp"
#include "PointScore.hpp"
#include "TieBreaker.hpp"
#include "TieBreakerScore.hpp"


Set::Set( Player *p1, Player *p2 ): Competition( p1, p2 ) {}


//  Implemented by David Wells
Score *Set::play( Player *p ) {
 
    // Create a score object for this SET
    SetScore *setScore = new SetScore(player1(), player2());
    
    // While we don't have a winner of the Set, continue playing games.
    while( !setScore -> haveAWinner()  ) {
        
        // Create a new game and score object
        Game *game = new Game( player1(), player2() );
        
        // Start playing the game
        Score *gameScore = game->play(p);
        
        // Get the winner from the game and add the points from the game
        setScore -> addScore( gameScore -> getWinner() );
        
        // Delete the game, and free up memory because the game is over
        delete game;
        
        // After the game switch servers
        p = p->otherPlayer(p);
        
        // If we have a TIE, play a tiebreaker!
        if( setScore->shouldPlayATieBreaker() ) {
            
           // create a new tiebreaker object with player 1 and player 2
            TieBreaker *tiebreaker = new TieBreaker (player1(), player2() );
            
            // We'll add the tiebreaker score to score, but we'll need to cast the result of playing a tiebreaker to the same type.
            setScore -> addTieScore( reinterpret_cast<TieBreakerScore *>(tiebreaker -> play(p)));
            
            
            // Now that we've settled the tie, we can return out of the set
            return setScore;
        }
        
       
        
    }
    
    return setScore;
}
