//  Tennis Object Oriented
//  PROJECT 1 - PHASE 1
//  CS470 - Spring 2014
//
//  CREATED BY DAVID WELLS
//  Copyright (c) 2014 David Wells. All rights reserved.
//

#include<unistd.h>
#include<stdlib.h>
#include<iostream>
#include "Player.hpp"
#include "Game.hpp"
#include "GameScore.hpp"

#include "Competition.hpp"
#include "Match.hpp"
#include "MatchScore.hpp"
#include "PointScore.hpp"
#include "Set.hpp"
#include "Score.hpp"
#include "SetScore.hpp"
#include "TieBreaker.hpp"
#include "TieBreakerScore.hpp"

/*
 The program simulates a tennis match.  It first draws a random
 number to decide which of the two players serves the first game of
 the match.  Given the probability of player A winning a point
 against player B if she is serving, the function `point' decides
 the outcome of the point.  To make the program more realistic, one
 needs to change the way the function `point' decides which player
 wins a point.
 
 The rules of the game are:
 
 A match is won by the first player to win 3 sets.  A set is won by
 the first player to win 6 games if ahead by two games. If the set
 reaches a score of 6-5, another game is played.  If the player who
 is ahead wins that game, the set is over, won by a score of 7-5.
 Otherwise the score is 6-6 and a tie breaker is played. The winner
 of the tie breaker is the winner of the set 7-6.
 
 Players alternate who serves a game. The server is the player who
 first hits the ball. Player also alternate who serves the first
 game of a set.  A game is won by the first player to get at
 least 4 points and be ahead by two points. Tennis uses a strange
 way of counting points.  We can simply count points by 0,1,2,...
 
 Points are the basic unit of play.  A point consists of a player
 putting the ball into play (serving) followed by the two players
 hitting it back and forth until something goes wrong such as the
 ball is hit out of bounds.
 
 A tie breaker is a game in which the first player to score at least
 seven and be ahead by two wins.  The service in a tie breaker
 alternates. The player whose turn it would be to serve in a normal
 game serves once. Thereafter the players alternate serving twice
 until the tie breaker is over.
 
 Written by: Ali A. Kooshesh
 */


//  Revisions to main() by David Wells
//  Written to work similarly to tennis.cpp
int main()
{
    // Hard coded probability - by Kooshesh, used for testing and initialization of vars
    int prob1 = 70;
    int prob2 = 70;
    
    srand( getpid() );
    int randSeed;
    
    // Prompt the user
    std::cout << "Enter a seed for the random-number generator: ";
    std::cin >> randSeed;
    srand( randSeed );
    
    //  Allow user to set Player A and Player B probablility for winning
    std::cout << "Please enter the probablility of player A winning when (s)he serves: ";
    std::cin >> prob1;
    std::cout << "Please enter the probablility of player B winning when (s)he serves: ";
    std::cin >> prob2;
    
    
    // Create the Players
    Player *p1 = new Player( prob1 );
    Player *p2 = new Player( prob2 );
    
    // Create a MATCH - A match is the overall entity that encompases sets and games
    Match *aTennisMatch = new Match(p1, p2);
    
    
    // Create a score - and start playing the match!
    // The result of the match goes into score
    Score *score = aTennisMatch->play(p1);
    
    // Print the final score for this tennis match
    score -> print();
    
    
    // Clear out the match and the players from memory
    delete aTennisMatch;
    delete  reinterpret_cast<MatchScore *>(score);
    delete p1;
    delete p2;
   
    
    // All went well, so return!
    return 0;
}
