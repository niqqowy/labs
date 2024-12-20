#include "func.hpp"
#include <iostream>
#include <vector>


Node::Node(int val) : value(val), next(nullptr){}

void append(Node*& head,int value){
    if (!head){
        head = new Node(value);
    }
    else{
        Node* temp = head;
        while (temp->next){
            temp = temp->next;
        }
        temp->next = new Node(value);
    }
}

void removeWithoutEight(Node*& head) {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        int num = current->value;
        bool containsEight = false;
        while (num > 0) {
            if (num % 10 == 8) {
                containsEight = true;
                break;
            }
            num /= 10;
        }

        if (!containsEight) {
            if (prev) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } 
            else {
                head = current->next;
                delete current;
                current = head;
            }
        } 
        else {
            prev = current;
            current = current->next;
        }
    }
}

bool conteight(int num){
    while (num>0){
        if(num%10==8){
            return true;
        }
        num/=10;
    }
    return false;
}

void duplicate(Node*& head) {
    Node* current = head;
    while (current) {
        if(conteight(current->value)){
            Node* newNode= new Node(current->value);
            newNode->next=current->next;
            current->next=newNode;
            current=newNode;
        }
        current = current->next;
    }
}

void sortByFirstDigit(Node*& head) {
    if (!head) return;

    std::vector<Node*> nodes;
    Node* current = head;
    while (current) {
        nodes.push_back(current);
        current = current->next;
    }

    sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
        return firstdigit(b->value) < firstdigit(a->value);
    });

    head = nodes[0];
    current = head;
    for (size_t i = 1; i < nodes.size(); ++i) {
        current->next = nodes[i];
        current = current->next;
    }
    current->next = nullptr;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool onlyodd(int num){
    while(num>0){
        int digit=num%10;
        if(digit%2==0){
            return false;
        }
        num/=10;
    }
    return true;
}

bool iseight(int num){
    while(num>0){
        if(num%10==8){
            return true;
        }
        num/=10;
    }
    return false;
}

int firstdigit(int num){
    while(num>=10){
        num/=10;
    }
    return num;
}

bool comparefirstdigit(int a,int b){
    return firstdigit(a)>firstdigit(b);
}


