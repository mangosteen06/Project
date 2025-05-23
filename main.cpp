// Feb 14: This file should implement the game using a custom implementation of a BST (that is based on your implementation from lab02)
#include <iostream>
#include <fstream>
#include <string>
#include "card_list.h"
//Do not include set in this file

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;
  string cardSuit, cardValue;
  bst AliceCards;
  bst BobCards;
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
      bst::Card card(cardSuit,cardValue);
     AliceCards.insert(card);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
      cardSuit = line[0];
      cardValue= line[2];
      if (cardValue == "1"){
        cardValue = "10";
      }
      bst::Card card(cardSuit,cardValue);
      BobCards.insert(card);
  }
  cardFile2.close();
  playGame(AliceCards,BobCards);
  printDeck(AliceCards,BobCards);
  return 0;
}
