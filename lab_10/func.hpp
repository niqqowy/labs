#pragma once
#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>


struct Node {
    int value;
    Node* next;
    Node(int val);
};

void printList(Node* head);

void sortByFirstDigit(Node*& head);

void duplicate(Node*& head);

void removeWithoutEight(Node*& head);

void append(Node*& head,int value);

bool onlyodd(int num);

int firstdigit(int num);

bool comparefirstdigit(int a,int b);

bool conteight(int num);

