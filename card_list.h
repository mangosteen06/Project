// card_list.h
// Author: Serafina Wong
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include <string>
#include <iostream>
using namespace std;
class bst{
    public:
        struct Card{
            string value;
            string suit;
             Card(string s= "0", string v= "0") {
                suit = s;
                value = v;
            }
            Card& operator=(const Card& other);
            bool operator==(const Card& other);
            bool operator!=(const Card& other);
            bool operator<(const Card& other);
            };
    private: 
        struct Node{
            Card data;
            Node* right;
            Node* left;
            Node(Card value) {
                data = value;
                right = nullptr;
                left = nullptr;
            }
        };
        Node* root;
        void insert(Card value, Node *n);
        void printCard(Node *n) const ;
        Node* getNodeFor(Card value, Node* n) const;
        void clear(Node *n) ;
   public:
        bst();
        ~bst();
        void insert(Card value);
        void printCard() const ;
        bool contains(Card value) const;
        bool empty() const;
        Node* getPredecessorNode(Card value) const;
        Node* getSuccessorNode(Card value) const;
        bool remove(Card value);
        friend ostream& operator<<(ostream& os,const Card& next);
        Node* getmin() const;
        Node* getmax() const;
        class iterator;
        iterator begin() const;
        iterator end()const;
        iterator rbegin()const;
        iterator rend()const;
    };
class bst::iterator{
    private:
        bst::Node* n;
        const bst* tree;

    public:
        iterator(bst::Node* p = nullptr,const bst* Tree= nullptr): n(p), tree(Tree){
    }
    bst::Card operator*() {
        return n->data;
    }
    iterator& operator++(){
        n = tree->getSuccessorNode(n->data);
        return *this;
    }
    iterator& operator--(){
        n = tree->getPredecessorNode(n->data);
        return *this;
    }

    friend bool operator==(const iterator& left,const iterator& right){
        if (left.n == nullptr && right.n == nullptr) {
        return true;
        }
        if (left.n == nullptr || right.n == nullptr) {
            return false;
        }
        return left.n->data == right.n->data;
        
    }
    friend bool operator!=(const iterator& left,const iterator& right){
        if (left.n == nullptr && right.n == nullptr) {
    return false;
    }
    if (left.n == nullptr || right.n == nullptr) {
        return true;
    }
    return left.n->data != right.n->data;
    }
    };
bool match(bst::Card test, const bst& other);
void playGame ( bst& Alice, bst& Bob);
void printDeck ( const bst& Alice, const bst& Bob);
bool great(string value1,string value2);
#endif
