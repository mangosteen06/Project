// card.cpp
// Author: Serafina Wong
// Implementation of the classes defined in card.h
#include "card.h"

Card::Card(string s ,string v ){
    suit = s;
    value = v;
}

bool operator==(const Card& left,const Card& right){
    return (left.suit ==right.suit) && (left.value ==right.value);
}
ostream& operator<<(ostream& os,const Card& next){
        cout << next.suit << " "<<next.value <<endl;
        return os;
    }
Card& Card::operator=(const Card& other){
    if(this!=&other){
        this->suit = other.suit;
        this->value = other.value;
    }
    return *this;
}
bool Great(string value1,string value2){//value1>value2
    int val1;
    int val2;
    if(value1==value2){
        return false;
    }
    if(value2=="a"){
        return true;
    }
    if(value1 =="a"){
        return false;
    }
    if(value1=="k"){
        return true;
    }
    if(value2=="k"){
        return false;
    }
    if(value1!="j"&&value1!="q"&&value1!="k"){
        val1=stoi(value1);
        if(value2!="j"&&value2!="q"&&value2!="k"){
            val2=stoi(value2);
            if(val1>val2){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        if(value2!="j"&&value2!="q"&&value2!="k"){
            return true;
        }else{
            if(value1=="j"){
                return false;
            }
            if(value2 =="j"){
                return true;
            }
        }
    }

}
 
bool operator<(const Card& left,const Card& right){
    if(left.suit != right.suit){
        if(left.suit == "c" ||right.suit == "h"){
            return true;
            }
        if(left.suit == "h" ||right.suit == "c"){
            return false;
        }
        if(left.suit == "d" ||right.suit == "s"){
            return true;
        }
         if(left.suit == "s" ||right.suit == "d"){
            return false;
        }
    }else{
        return Great(right.value,left.value);
    }
}

bool match( Card test, const set<Card>& other){
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
    if(Alice.empty()||Bob.empty()){
        return;
    }
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
