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
    cout<<endl;
    cout << "Bob's cards: "<<endl;
    for(set<Card>::iterator it = Bob.begin(); it != Bob.end(); ++it){
        cout << *it;
    }
}
void game ( set<Card>& Alice, set<Card>& Bob){
  set<Card> remove;
  auto alice = Alice.begin(); 
  auto bob =Bob.rbegin();
  bool breaking= false;
  while(alice != Alice.end() || bob !=Bob.rend()){
    while(!match(*alice,Bob)){
      ++alice;
      if(alice==Alice.end()){
        break;
      }
    }
    if(alice==Alice.end()){
        break;
      }
    if(!remove.empty()){
      for(auto it =remove.begin();it != remove.end(); it++){
        if(*it==*alice){
          breaking = true;
        }
    }
    }
    if(breaking){
      break;
    }
    cout << "Alice picked matching card "<< *alice;
    remove.insert(*alice);
    ++alice;
    while(!match(*bob,Alice)){
      ++bob;
      if(bob==Bob.rend()){
        break;
      }
    }
    if(bob==Bob.rend()){
        break;
      }
    if(!remove.empty()){
      for(auto it =remove.begin();it != remove.end(); it++){
        if(*it==*bob){
          breaking = true;
        }
    }
    }
      
    if(breaking){
      break;
    }
    cout << "Bob picked matching card "<< *bob;
    remove.insert(*bob);
    ++bob;
  
  }
  auto Remove =remove.begin();
  while(Remove !=remove.end()){
      Alice.erase(*Remove);
      Bob.erase(*Remove);
      ++Remove;
  }
    cout<<endl;
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
