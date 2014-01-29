#include "Set.hpp"
#include "Score.hpp"
#include "SetScore.hpp"

#include "Game.hpp"
#include "GameScore.hpp"
#include "PointScore.hpp"


Set::Set( Player *p1, Player *p2 ): Competition( p1, p2 ) {}


//  Implemented by David Wells
Score *Set::play( Player *p ) {
 
    // Create a score object for this set
    Score *score = new SetScore(player1(), player2());
    
    // While we don't have a winner of the Set, continue playing games.
    while( !score -> haveAWinner()  ) {
        
        // Create a new game and score object
        Game *game = new Game( player1(), player2() );
        Score *gameScore = new GameScore( player1(), player2() );
        
        // Start playing the game
        score = game->play(p);
        
        // If we have a winner, add the
        if ( gameScore->haveAWinner() ) {
            score->addScore( gameScore -> getWinner() );
            
            // the game is over, so remove it before starting a new game in the next iteration
            delete game;
        }
        
        
        
    }
    
    return score;
}

/*

     Score *score = new SetScore (player1(), player2());
 
     while( !score->haveAWinner() ) {
 
         Game *game = new Game (player1(), player2());
         Score *gameScore = new GameScore( player1(), player2() );
         score->addScore(gameScore->getWinner());
         delete game;
     }
 
     return score;
     
 }

*/