//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include "TieBreakerScore.hpp"
#include <stdlib.h>  //  to get the abs function
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw

TieBreakerScore::TieBreakerScore( Player *p1, Player *p2 ): Score(p1, p2) {}


//  Implemented by David Wells

//  Implementation of the two things I added to handle the tie situation, which is different from the normal game situation.

bool TieBreakerScore::haveAWinner(){
    
    /*  Used the following function from the tennis.cpp file:
     
     inline int tie_over(int a, int b)
     {
     return (a >= 7 || b >= 7) && abs(a - b) >= 2;
     }
     
     */
    return (player1Score() >= 7 || player2Score() >= 7)  && abs(player1Score() - player2Score() >=2 );
    

}


void TieBreakerScore::print() {
    
    /*  Used the following code snippet from the tennis.cpp file:
     
     if( p1_tscore != 0 || p2_tscore != 0 )
     cout << setw(16) << "(tie breaker  " << p1_tscore << "-" <<
     p2_tscore << ")";
     
     */
    
    std::cout << std::setw(16) << "(Tie Breaker  " << player1Score() << "-" <<
    player2Score() << ")";
    std::cout << std::endl;
    
    
    
}