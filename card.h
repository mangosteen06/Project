// card.h
// Author: Serafina Wong
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
#include <set>
using namespace std;
class Card{
    public:
    Card(string s = "N",string v = "N");
    friend bool operator==(const Card& left,const Card& right);
    friend bool operator!=(const Card& left,const Card& right);
    friend bool operator<(const Card& left,const Card& right);
    friend ostream& operator<<(ostream& os,const Card& next);
    Card& operator=(const Card& other);
    private:
        string suit;
        string value;
};

void game ( set<Card>& Alice, set<Card>& Bob);
bool match( Card test, const set<Card>& other);
void print(const set<Card>& Alice,const set<Card>& Bob);
bool Great(string value1,string value2);
#endif
