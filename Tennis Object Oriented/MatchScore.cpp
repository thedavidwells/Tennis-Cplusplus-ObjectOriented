//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include "MatchScore.hpp"
#include "iostream"  // for cout
#include "iomanip"   // for setw
using namespace std; // so i don't have to type std:: before everything

MatchScore::MatchScore( Player *p1, Player *p2 ): Score( p1, p2 ), setNumber(0) {}

//  Implemented by David Wells
bool MatchScore::haveAWinner()  {
    
    //  Using the function match_over() from the tennis.cpp
    return player1Score() == 3 || player2Score() == 3;
    
}  // just to make the compiler happy!


//  Implemented by David Wells
void MatchScore::addScore( Score *score ) {
    
    // Create an array to hold all of the scores
    scores[setNumber] = reinterpret_cast<SetScore *>(score);
    
    // Increment the set number
    setNumber++;
    
    // Check the winner.  Whoever wins gets their point score incremented
    score -> getWinner() == player1() ? p1Score++ : p2Score++;
    
}

//  Implemented by David Wells
void MatchScore::print() {
    
    // Using same format as tennis.cpp for printing:
    cout << "   Set No.    Player A          Player B\n";
    for( int i = 0; i < setNumber; i++ ) {
        
        // Just setting widths and specifying format for printing
        cout << setw(7) << i+1;
        scores[i]->print();
        cout << endl;
        
    }
    
    // Print out final winner of the match:
    
    //  If player 1 is the winner
    if ( player1Score() > player2Score() ) {
        cout << "\nPlayer A wins the match " << player1Score() << " sets to "
        << player2Score() << endl;
        cout << endl;
    }
    
    // Or if player 2 is the winner
    else{
        cout << "\nPlayer B wins the match " << player2Score() << " sets to "
        << player1Score() << endl;
        cout << endl;
    }
}


MatchScore::~MatchScore() {
    for( int i = 0; i < setNumber; i++ )
      delete scores[i];
}
