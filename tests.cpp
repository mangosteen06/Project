// testbst.cpp
// Tests intbst.cpp for CS 24 lab

#include "card_list.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    bst empty, single, multiple,duplicate, other;
    bst::Card card1("h","10");
    bst::Card card2("h","10");
    bst::Card card3("d","a");
    bst::Card card4("s","j");
    bst::Card card5("c","k");
    bst::Card card6("d","4");
    bst::Card card7("h","1");
    cout<< "Check insert and print"<<endl<<endl;
    single.insert(card7);
    multiple.insert(card1);
    multiple.insert(card3);
    multiple.insert(card4);
    multiple.insert(card5);
    multiple.insert(card6);
    multiple.insert(card7);
    duplicate.insert(card1);
    duplicate.insert(card1);
    duplicate.insert(card3);
    other.insert(card1);
    other.insert(card3);
    other.insert(card4);
    other.insert(card5);

    cout<< "Empty deck: ";
    cout<<endl;
    empty.printCard();
    cout<<endl;
    cout<< "Single deck: h 1";
    cout<<endl;
    single.printCard();
    cout<<endl;
    cout<< "multiple deck: c k, d a, d 4, s j, h 1, h 10";
    cout<<endl;
    multiple.printCard();
    cout<<endl;
    cout<<"duplicate deck: d a, h 10";
    cout<<endl;
    duplicate.printCard();
    cout<<endl;
    cout<<"other deck:c k, d a, s j, h 10";
    cout<<endl;
    other.printCard();
    cout<<endl;

    cout<< "Check contains"<<endl;
    cout<< "Should be False:";
    cout<<empty.contains(card1);
    cout<<endl;
    cout<< "Should be False:";
    cout<<single.contains(card1);
    cout<<endl;
    cout<< "Should be true:";
    cout<<multiple.contains(card1);
    cout<<endl;
    cout<< "Should be true:";
    cout<<duplicate.contains(card1);
    cout<<endl;
    cout<< "Should be true:";
    cout<<other.contains(card1);
    cout<<endl;

    cout<< "Check remove--Decks should now no longer have h 10";
    empty.remove(card1);
    single.remove(card1);
    multiple.remove(card1);
    duplicate.remove(card1);
    other.remove(card1);
    cout<<endl;

    cout<< "Empty deck: ";
    cout<<endl;
    empty.printCard();
    cout<<endl;
    cout<< "Single deck: h 1";
    cout<<endl;
    cout<< "Verify: "<<endl;
    single.printCard();
    cout<<endl;
    cout<< "multiple deck: c k, d a, d 4, s j, h 1";
    cout<<endl;
    cout<< "Verify: "<<endl;
    multiple.printCard();
    cout<<endl;
    cout<< "Verify: "<<endl;
    cout<<"duplicate deck: d a";
    cout<<endl;
    cout<< "Verify: "<<endl;
    duplicate.printCard();
    cout<<endl;
    cout<<"other deck:c k, d a, s j";
    cout<<endl;
    cout<< "Verify: "<<endl;
    other.printCard();
    cout<<endl;

    cout<< "Check empty"<<endl;
    cout<< "Should be true"<<endl;
    cout<<empty.empty();
    cout<<endl;
    cout<< "Should be false"<<endl;
    cout<< single.empty();
    cout<<endl;
    cout<< "Should be false"<<endl;
    cout<<multiple.empty();
    cout<<endl;
    cout<< "Should be false"<<endl;
    cout<<duplicate.empty();
    cout<<endl;
    cout<< "Should be false"<<endl;
    cout<<other.empty();
    cout<<endl;
    cout<<endl;
    cout<< "Check getPredecessorNode"<<endl;
    cout<< "Empty deck: Should be none"<<endl;
    if(empty.getPredecessorNode(card3)== nullptr){
        cout<< "none";
    }else{
        cout<< empty.getPredecessorNode(card3)->data;
    }
    cout<<endl;
    cout<< "Single deck: Should be none"<<endl;
    if(single.getPredecessorNode(card3)== nullptr){
        cout<< "none";
    }else{
        cout<< single.getPredecessorNode(card3)->data;
    }
    cout<<endl;
    cout<< "Multiple Cards deck: Should be c k"<<endl;
    if(multiple.getPredecessorNode(card3)== nullptr){
        cout<< "none";
    }else{
        cout<< multiple.getPredecessorNode(card3)->data;
    }
    cout<<endl;
    cout<< "Duplicate Cards deck: Should be none"<<endl;
    if(duplicate.getPredecessorNode(card3)== nullptr){
        cout<< "none";
    }else{
        cout<< duplicate.getPredecessorNode(card3)->data;
    }
    cout<<endl;
    cout<< "Other Cards deck: Should be c k"<<endl;
    if(other.getPredecessorNode(card3)== nullptr){
        cout<< "none";
    }else{
        cout<< other.getPredecessorNode(card3)->data;
    }
    cout<<endl;
    cout<< "Check getSuccessorNode";
    cout<<endl;
    cout<< "Empty deck: Should be none"<<endl;
    if(empty.getSuccessorNode(card5)== nullptr){
        cout<< "none";
    }else{
        cout<< empty.getSuccessorNode(card5)->data;
    }
    cout<<endl;
    cout<< "Single deck: Should be h 1"<<endl;
    if(single.getSuccessorNode(card5)== nullptr){
        cout<< "none";
    }else{
        cout<< single.getSuccessorNode(card5)->data;
    }
    cout<<endl;
    cout<< "Multiple Cards deck: Should be d a"<<endl;
    if(multiple.getSuccessorNode(card5)== nullptr){
        cout<< "none";
    }else{
        cout<< multiple.getSuccessorNode(card5)->data;
    }
    cout<<endl;
    cout<< "Duplicate Cards deck: Should be d a"<<endl;
    if(duplicate.getSuccessorNode(card5)== nullptr){
        cout<< "none";
    }else{
        cout<< duplicate.getSuccessorNode(card5)->data;
    }
    cout<<endl;
    cout<< "Other Cards deck: Should be d a"<<endl;
    if(other.getSuccessorNode(card5)== nullptr){
        cout<< "none";
    }else{
        cout<< other.getSuccessorNode(card5)->data;
    }
    cout<<endl;

    cout<< "Check getmin";
    cout<<endl;
    cout<< "Empty deck: Should be none"<<endl;
    if(empty.getmin()== nullptr){
        cout<< "none";
    }else{
        cout<< empty.getmin()->data;
    }
    cout<<endl;
    cout<< "Single deck: Should be h 1"<<endl;
    if(single.getmin()== nullptr){
        cout<< "none";
    }else{
        cout<< single.getmin()->data;
    }
    cout<<endl;
    cout<< "Multiple Cards deck: Should be c k"<<endl;
    if(multiple.getmin()== nullptr){
        cout<< "none";
    }else{
        cout<< multiple.getmin()->data;
    }
    cout<<endl;
    cout<< "Duplicate Cards deck: Should be d a"<<endl;
    if(duplicate.getmin()== nullptr){
        cout<< "none";
    }else{
        cout<< duplicate.getmin()->data;
    }
    cout<<endl;
    cout<< "Other Cards deck: Should be c k"<<endl;
    if(other.getmin()== nullptr){
        cout<< "none";
    }else{
        cout<< other.getmin()->data;
    }
    cout<<endl;

    cout<< "Check getmax";
    cout<<endl;
    cout<< "Empty deck: Should be none"<<endl;
    if(empty.getmax()== nullptr){
        cout<< "none";
    }else{
        cout<< empty.getmax()->data;
    }
    cout<<endl;
    cout<< "Single deck: Should be h 1"<<endl;
    if(single.getmax()== nullptr){
        cout<< "none";
    }else{
        cout<< single.getmax()->data;
    }
    cout<<endl;
    cout<< "Multiple Cards deck: Should be h 1"<<endl;
    if(multiple.getmax()== nullptr){
        cout<< "none";
    }else{
        cout<< multiple.getmax()->data;
    }
    cout<<endl;
    cout<< "Duplicate Cards deck: Should be d a"<<endl;
    if(duplicate.getmax()== nullptr){
        cout<< "none";
    }else{
        cout<< duplicate.getmax()->data;
    }
    cout<<endl;
    cout<< "Other Cards deck: Should be s j"<<endl;
    if(other.getmax()== nullptr){
        cout<< "none";
    }else{
        cout<< other.getmax()->data;
    }
    cout<<endl;
    cout<< "Check empty tree iterator";
    cout<<endl;
    bst::iterator begin = empty.begin();
    bst::iterator end = empty.end();
    bst::iterator rbegin = empty.rbegin();
    bst::iterator rend = empty.rend();
    cout<<"should be true:" <<  (begin ==end && rbegin== rend); 
    cout<<endl;
    cout<< "Check single node tree iterator: should give: h 1";
    cout<<endl;
    for(bst::iterator it = single.begin(); it != single.end(); ++it){
        cout<< *it;
    }
    cout<<endl;
    for(bst::iterator it = single.rbegin(); it != single.rend(); --it){
        cout<< *it;
    }

    cout<< "Check multiple node tree iterator: should give: c k, d a, d 4, s j, h 1 and h 1, s j, d 4, d a, c k";
    cout<<endl;
    for(bst::iterator it = multiple.begin(); it != multiple.end(); ++it){
        cout<< *it;
    }
    cout<<endl;
    for(bst::iterator it = multiple.rbegin(); it != multiple.rend(); --it){
        cout<< *it;
    }
    
    cout<< "Check == and != ";
    cout<<endl;
    bst::iterator begina = multiple.begin();
    bst::iterator enda = multiple.end();
    bst::iterator rbegina = multiple.rbegin();
    bst::iterator renda = multiple.rend();
    cout<<"should be true:";
    cout<< (begina == begina);
    cout<<endl;
    cout<<"should be true:";
    cout<< (begina != enda);
    cout<<endl;
    cout<<"should be true:";
    cout<< (rbegina == rbegina);
    cout<<endl;
    cout<<"should be true:";
    cout<< (rbegina != renda);
    cout<<endl;

    playGame(empty,multiple);
    printDeck(empty,multiple);
    playGame(other,single);
    printDeck(other,single);
    playGame(other,multiple);
    printDeck(other,multiple);
     playGame(empty,empty);
    printDeck(empty,empty);
 
}
