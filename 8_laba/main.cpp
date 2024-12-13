#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <utility>  // Для std::pair
#include "func.hpp"

int main() {
    std::set<std::string> Words = read("input.txt");

    if (Words.empty()) {
        return -1;  
    }

    std::vector<std::pair<int, std::string>> wordch; // скока пар гл/ слово само

   
    for (const auto &w : Words) {
        int pairCount = countpair(w);  
        wordch.push_back({pairCount, w}); 
    }

    std::sort(wordch.begin(), wordch.end(), std::greater<>());

    writeRes(wordch,"output.txt");


    return 0;
}





