//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include<iostream>
#include "SetScore.hpp"
#include <stdlib.h>
#include "iostream"  // for cout
#include "iomanip"   // for setw
using namespace std; // so i don't have to type std:: before everything


SetScore::SetScore( Player *p1, Player *p2 ): Score(p1, p2), tieScore(0) {}


//  Implemented by David Wells
bool SetScore::haveAWinner()           {
    
    //  Using the function from the tennis.cpp
    //  And according to the rules of tennis provided:
    //  "A set is won by the first player to win 6 games if ahead by 2 games"
    return ( player1Score() >= 6 || player2Score() >= 6 ) &&
                abs(player1Score()-player2Score()) >= 2;
}

//  Implemented by David Wells
bool SetScore::shouldPlayATieBreaker() {
    
    //  Using the function from the tennis.cpp
    //  Also per the rules... if a score of 6-6 is reached we play a tie-breaker
    return player1Score() == 6 && player2Score() ==6 ;
}


void SetScore::addTieScore( TieBreakerScore *score ) {
    addScore( score->getWinner() );
    this->tieScore = score;
}

//  Implemented by David Wells
void SetScore::print() {
    
    cout << setw(10) << player1Score() << setw(18) << player2Score();
    
    if (tieScore != NULL ) {
        
        tieScore -> print();
        
    }
    
}
