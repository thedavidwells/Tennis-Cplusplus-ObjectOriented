#include "MatchScore.hpp"

MatchScore::MatchScore( Player *p1, Player *p2 ): Score( p1, p2 ), setNumber(0) {}
bool MatchScore::haveAWinner()  { return false;  }  // just to make the compiler happy!
void MatchScore::addScore( Score *score ) {
}

void MatchScore::print() {
    for( int i = 0; i < setNumber; i++ )
      scores[i]->print();
}
MatchScore::~MatchScore() {
    for( int i = 0; i < setNumber; i++ )
      delete scores[i];
}
