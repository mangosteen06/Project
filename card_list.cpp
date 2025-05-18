// card_list.cpp
// Author:  Serafina Wong
// Implementation of the classes defined in card_list.h
#include "card_list.h"
#include <string>
#include <iostream>
using namespace std;

bst::bst(){
    root = nullptr;
}

// destructor deletes all nodes
bst::~bst() {
    clear(root);
}

// recursive helper for destructor
void bst::clear(Node *n) {
    if(n == nullptr){
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
    n = nullptr;
    
}

// insert value in tree; return false if duplicate
void bst::insert(bst::Card value) {
    if(root == nullptr){
        root= new Node(value);
    }else{
        insert(value,root);
    }
   
}

// recursive helper for insert (assumes n is never 0)
void bst::insert(bst::Card value, Node *n) {
   if(value == n->data){
        return ;
    }else if (value< n->data){
        if(n->left == nullptr){
            n->left = new Node(value);
            return ;
        }
        return insert(value, n->left);
    }else if(n->data<value ){
         if(n->right == nullptr){
            n->right = new Node(value);
            return ;
        }
       return insert(value, n->right); 
    }
}

void bst::printCard() const {
     printCard(root);
}
void bst::printCard(Node *n) const {
     if(n== nullptr) {
        return;
     }
    printCard(n->left);
    cout << n->data << " ";
    printCard(n->right);
}

bst::Node* bst::getNodeFor(bst::Card value, Node* n) const{
     if(n == nullptr){
        return NULL;
     }else if(value == n->data){
        return n;
    }else if (value< n->data){
        return getNodeFor(value, n->left);
    }else if(n->data<value ){
       return getNodeFor(value, n->right); 
    }else{
        return NULL;
    }
}

// returns true if value is in the tree; false if not
bool bst::contains(bst::Card value) const {
    if(getNodeFor(value,root)==NULL){
        return false;
    }else{
        return true;
    }
}

// returns the Node containing the predecessor of the given value
bst::Node* bst::getPredecessorNode(bst::Card value) const{
     Node*n = root;
     Node*result= nullptr;
     while(n != nullptr){
       if(value == n->data){
            if(n->left !=nullptr){
                n = n->left;
                while(n->right != nullptr){
                    n= n->right;
                }
                result = n;
            }
            return result;
        }else if(value <n->data){
            n = n->left;
        }else if(n->data<value ){
            result = n;
            n = n->right;
        }
     }
     return result;
}

// returns the predecessor value of the given value or 0 if there is none


// returns the Node containing the successor of the given value
bst::Node* bst::getSuccessorNode(bst::Card value) const{
    Node*n = root;
     Node*result= nullptr;
     while(n != nullptr){
       if(value == n->data){
            if(n->right !=nullptr){
                n = n->right;
                while(n->left != nullptr){
                    n= n->left;
                }
                result = n;
            }
            return result;
        }else if(value <n->data){
            result = n;
            n = n->left;
        }else if(n->data<value){
            n = n->right;
        }
     }
     return result;
    
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool bst::remove(bst::Card value){
    if (!contains(value)) {
        return false; 
    }
    Node* b;
    Node* p = nullptr;
    Node* n = getNodeFor(value,root);
    Node * iter = root;
    while (iter != nullptr && iter->data != value) {
        p=iter;
        if(value <iter->data){
            iter = iter->left;
        }else if(iter->data<value ){
            iter = iter->right;
        }
    }
     if (n->left != nullptr && n->right != nullptr) {
        Node* New = getSuccessorNode(value);
        while (iter != nullptr && iter->data != New->data) {
            p=iter ;
            if (New->data < iter->data) {
                iter = iter->left;
            } else {
                iter = iter->right;
            }
    }
        n->data = New->data;
        n = New;
    }

    if(n->left != nullptr){
         b= n->left;
    }else{
        b= n->right; 
    }
    if (p == nullptr) {
        root = b;
    } else if (p->left == n) {
        p->left = b;
    } else {
        p->right = b;
    }

    delete n;
    return true;

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
bool bst::Card::operator==(const bst::Card& other){
    return (this->suit ==other.suit) && (this->value ==other.value);
}
bool bst::Card::operator!=(const bst::Card& other){
    return !(*this == other);
}
ostream& operator<<(ostream& os,const bst::Card& next){
        cout << next.suit << " "<<next.value <<endl;
        return os;
    }
bst::Card& bst::Card::operator=(const bst::Card& other){
    if(this!=&other){
        this->suit = other.suit;
        this->value = other.value;
    }
    return *this;
}
bool bst::Card::operator<(const bst::Card& other){
    if(this->suit != other.suit){
        if(this->suit == "c" ||other.suit == "h"){
            return true;
            }
        if(this->suit == "h" ||other.suit == "c"){
            return false;
        }
        if(this->suit == "d" ||other.suit == "s"){
            return true;
        }
         if(this->suit == "s" ||other.suit == "d"){
            return false;
        }
    }else{
        return great(other.value,this->value);
    }
}
bst::iterator bst::rbegin ()const{
    iterator it(getmax(), this);
    return it; 
}
bst::iterator bst::begin ()const{
    iterator it(getmin(), this);
    return it; 
}

bst::iterator bst::end () const{
    return iterator(nullptr, this);
}
bst::iterator bst::rend()const{
      return iterator(nullptr, this);
}
bst::Node* bst::getmin() const{
     Node * n= root;
    if(!n) return nullptr;
    while(n && n->left){
        n= n->left;
    }
    return n;
}
bst::Node* bst::getmax() const{
    Node * n= root;
    if(!n) return nullptr;
    while(n && n->right){
        n= n->right;
    }
    return n;
}
bool bst::empty() const{
    if(root == nullptr){
        return true;
    }else{
        if (root -> left == nullptr&& root -> right == nullptr){
            return true;
        }else{
            return false;
        }
    }
    return false;
}


bool match(bst::Card test, const bst& other){
     for(bst::iterator it = other.begin(); it != other.end(); ++it){
        if(test == *it){
            return true;
        }
    }
    return false;
}


void playGame ( bst& Alice, bst& Bob){
if(Alice.empty()||Bob.empty()){
    return;
}
bst::iterator alice = Alice.begin(); 
bst::iterator bob = Bob.rbegin();
bst trash;// keep all cards to be removed and then remove them at the end
bool newline= true;
   bool breaking= false; //find when to break out early- ie when there are no more matching cards or we have reached the end
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
    if(!trash.empty()){
      for(bst::iterator it =trash.begin();it != trash.end(); ++it)
        if(*it==*alice){
          breaking = true;
        }
    }
    if(breaking){
      break;
    }
    cout << "Alice picked matching card "<< *alice;
    trash.insert(*alice);
    ++alice;
    while(!match(*bob,Alice)){
      --bob;
      if(bob==Bob.rend()){
        break;
      }
    }
    if(bob==Bob.rend()){
        break;
      }
    if(!trash.empty()){
      for(bst::iterator it =trash.begin();it != trash.end(); ++it){
        if(*it==*bob){
          breaking = true;
        }
    }
    }
      
    if(breaking){
      break;
    }
    cout << "Bob picked matching card "<< *bob;
    trash.insert(*bob);
    --bob;
  
  }
  bst::iterator Trash =trash.begin();
  if(trash.empty()){
    newline = false;
  }
  while(Trash !=trash.end()){
      Alice.remove(*Trash);
      Bob.remove(*Trash);
      ++Trash;
  }
    cout<<endl;
}
void printDeck ( const bst& Alice, const bst& Bob){
    if(!Alice.empty()){
        cout << "Alice's cards: "<<endl;
        for(bst::iterator it = Alice.begin(); it != Alice.end(); ++it){
            cout << *it;
    }
    cout<<endl;
    }
    if(!Bob.empty()){
        cout << "Bob's cards: "<<endl;
        for(bst::iterator it = Bob.begin(); it != Bob.end(); ++it){
            cout << *it;
        }
    }
    
}
