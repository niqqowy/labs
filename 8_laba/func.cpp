#include "func.hpp"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>


bool isVowel(char ch) {
    ch = tolower(ch); 
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}


int countpair(const std::string &word) {
    int count = 0;
    for (size_t i = 0; i < word.length() - 1; ++i) {
        if (isVowel(word[i]) && isVowel(word[i + 1])) {
            ++count;
        }
    }
    return count;
}


std::set<std::string> read(const std::string &name) {
    std::set<std::string> Words;  
    std::ifstream inputFile(name);  

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return Words; 
    }

    std::string word;
    while (inputFile >> word) {
        Words.insert(word);  
    }
     
    return Words;
}


void writeRes(const std::vector<std::pair<int, std::string>> &wordPairs, const std::string &filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка при создании файла!" << std::endl;
        return;
    }

    int N = wordPairs.size();
    if (N > 2000) {
        N = 2000;
    }

    // Записываем первые N элементов в файл
    for (int i = 0; i < N; ++i) {
        outputFile << wordPairs[i].second << " " << wordPairs[i].first << std::endl;
    }

}


