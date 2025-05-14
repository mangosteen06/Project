// card.h
// Author: Serafina Wong
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;
class Card{
    public:
    Card(string s = "N",string v = "N");
    friend bool operator==(const Card& left,const Card& right);
    friend bool operator!=(const Card& left,const Card& right);
    friend bool operator<(const Card& left,const Card& right);
    friend ostream& operator<<(ostream& os,const Card& next);
    private:
        string suit;
        string value;
};
#endif
