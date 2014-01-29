#include<iostream>
#include "SetScore.hpp"
#include <stdlib.h>


SetScore::SetScore( Player *p1, Player *p2 ): Score(p1, p2), tieScore(0) {}


//  Implemented by David Wells
bool SetScore::haveAWinner()           {
    
    return ( player1Score() >= 6 || player2Score() >= 6 ) &&
                abs(player1Score()-player2Score()) >= 2;
}

//  Implemented by David Wells
bool SetScore::shouldPlayATieBreaker() {
    
    return player1Score() == 6 && player2Score() ==6 ;
}


void SetScore::addTieScore( TieBreakerScore *score ) {
    addScore( score->getWinner() );
    this->tieScore = score;
}

void SetScore::print() {
    std::cout << "SetScore...   printing begins" << std::endl;
    std::cout << "p1 score = " << player1Score() << "\np2 Score = " << player2Score() << std::endl;
    if( tieScore != NULL )
      tieScore->print();
    std::cout << "SetScore...   printing ends" << std::endl;
}
