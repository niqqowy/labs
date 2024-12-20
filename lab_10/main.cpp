#include <iostream>
#include "func.hpp"
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>



int main() {
    std::cout<<"hi"<<std::endl;
    Node* head = nullptr;
    int num;


    while (std::cin >> num) {
        append(head, num);
    }

    bool hasOddThreeDigit = false;
    Node* current = head;
    while (current) {
        if (current->value >= 100 && current->value <= 999 && onlyodd(current->value)) {
            hasOddThreeDigit = true;
            break;
        }
        current = current->next;
    }

    if (!hasOddThreeDigit) {
        sortByFirstDigit(head);
    }
    else {
        removeWithoutEight(head);
        duplicate(head);
    }

    printList(head);

    return 0;
}





