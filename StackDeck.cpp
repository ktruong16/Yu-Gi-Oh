//
// Created by Minec on 11/30/2020.
//

#include "StackDeck.h"
StackDeck::StackDeck() : top(nullptr){

}
void StackDeck::push(Monsters newMonster){
    MonsterCard* tempPtr = nullptr;
    tempPtr = new MonsterCard;
    tempPtr->monster = newMonster;
    //first node in the list
    if(isEmpty()){
        top = tempPtr;
        tempPtr->next = nullptr;
    }
    //adding more nodes(monster cards)
    else{
        tempPtr->next = top;
        top = tempPtr;
    }
}
void StackDeck::pop(){
    MonsterCard* temp;
    if(isEmpty()){
        std::cout << "Error: Popping an empty stack" << std::endl;
        exit(1);
    }
    //takes out the top of the stack
    else{
        temp = top;
        top = top->next;
        temp->next = nullptr;
        delete temp;
    }
}
bool StackDeck::isEmpty(){
    return top == nullptr;
}
Monsters StackDeck::getMonster(){
    return top->monster;
}
void StackDeck::display(){
    MonsterCard* temp = top;
    while(temp != nullptr){
        std::cout << temp->monster << "->";
        temp = temp->next;
    }
}