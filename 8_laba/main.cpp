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
    std::string inputFilename = "input1.txt";
    std::string outputFilename = "output1.txt"; 
    check(inputFilename, outputFilename);




    
    int n;
    std::string words[5120];

    read2(n,words);
    
    if(iswordwithequal(n,words)){
        removecons(n,words);
    }
   
    else{
        for(int i=0;i<n;i++){
            if(treech(words[i])){
                duplicats(words[i]);
            }
        }
    }
    
    sort(n,words);
    write2(n,words);
    




    std::string text;
    readTextFromFile("input3.txt", text); 
    std::vector<std::string> wordss = splitTextIntoWords(text); 
    std::vector<std::string> maxLengthWord = findMaxLengthWord(wordss); 
    std::unordered_set<char> maxWordLetters = getLettersInWord(maxLengthWord); 
    std::ofstream outputFile("output3.txt");

    processText(wordss, maxWordLetters, outputFile); // Обработка текста и запись в файл

    return 0;
}





