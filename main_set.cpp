// Feb 14: This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]); //Alice
  ifstream cardFile2 (argc[2]); //Bob
  string line;
  set<Card> Alice;
  set<Card> Bob;
  string cardValue;
  string cardSuit;
  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    cardSuit = line[0];
    cardValue= line[2];
    if (cardValue == "1"){
      cardValue = "10";
    }
    Card card(cardSuit,cardValue);
    Alice.insert(card);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    cardSuit = line[0];
    cardValue= line[2];
    if (cardValue == "1"){
      cardValue = "10";
    }
    Card card(cardSuit,cardValue);
    Bob.insert(card);
  }

  game(Alice,Bob);
  cardFile2.close();
  return 0;
}
