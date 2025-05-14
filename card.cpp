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
bool great(string value1,string value2){//value1>value2
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
        return great(right.value,left.value);
    }
}