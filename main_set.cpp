// Feb 14: This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

bool match(Card test, const set<Card>& other){
     for(set<Card>::iterator it = other.begin(); it != other.end(); ++it){
        if(test == *it){
            return true;
        }
    }
    return false;
}

void print(const set<Card>& Alice,const set<Card>& Bob){
    cout << "Alice's cards: "<<endl;
    for(set<Card>::iterator it = Alice.begin(); it != Alice.end(); ++it){
        cout << *it;
    }
    cout << "Bob's cards: "<<endl;
    for(set<Card>::iterator it = Bob.begin(); it != Bob.end(); ++it){
        cout << *it;
    }
}
set<Card>::reverse_iterator BobTurn (set<Card>& Alice, set<Card>& Bob,set<Card>::reverse_iterator bob){
    while(!match(*bob,Alice)){
      ++bob;
    }
    cout << "Bob picked matching card "<< *bob;
    ++bob;
    Alice.erase(*bob);
    Bob.erase(*bob);
    return bob;
}
set<Card>::iterator AliceTurn (set<Card>& Alice, set<Card>& Bob, set<Card>::iterator alice){
   while(!match(*alice,Bob)){
      ++alice;
    }
    cout<<"Alice picked matching card "<< *alice;
    ++alice;
    Alice.erase(*alice);
    Bob.erase(*alice);
    return alice;
}
void game (set<Card>& Alice, set<Card>& Bob){

  auto alice = Alice.begin(); 
  auto bob =Bob.rbegin();
  while( alice != Alice.end() || bob !=Bob.rend()){
    alice = AliceTurn(Alice,Bob,alice);
    bob =BobTurn(Alice,Bob,bob);
  }
    print(Alice,Bob);
    return;
}

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
