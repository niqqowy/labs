#include "func.hpp"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_set>

const int max_n=5120;

bool rightlett(char ch) {
    ch = tolower(ch); 
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'|| ch == 'y';
}
int twolett(const std::string &word) {
    int count = 0;
    for (size_t i = 0; i < word.length() - 1; ++i) {
        if (rightlett(word[i]) && rightlett(word[i + 1])) {
            ++count;
            i++;
        }
    }
    return count;
}
std::set<std::string> read(const std::string &name) {
    std::set<std::string> Word;  
    std::ifstream inputFile(name);  

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return Word; 
    }

    std::string words;
    while (inputFile >> words) {
        Word.insert(words);  
    }
     
    return Word;
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
void check(const std::string& inputFilename, const std::string& outputFilename){
    std::set<std::string> Word = read(inputFilename);

    if (Word.empty()) {
        std::cout<<"file is empty"<<std::endl; 
    }

    std::vector<std::pair<int, std::string>> wordch; // скока пар гл/ слово само

   
    for (const auto &w : Word) {
        int numberrr = twolett(w);  
        wordch.push_back({numberrr, w}); 
    }

    std::sort(wordch.begin(), wordch.end(), std::greater<>());

    writeRes(wordch, outputFilename);
    


}



std::string tolowcase(std::string s){
    for (int i=0;i<s.length();i++){
        if('A'<=s[i] && s[i]<='Z'){
            s[i]+=32;
        }
    }
    return s;
}
char tolow(char c){
    if('A' <= c && c <= 'Z'){
        c+=32;
    }
    return c;
}
bool read2(int& n, std::string words[5120]){
    std::ifstream inn("input2.txt");
    if(!inn.is_open()){
        std::cerr<<"file is not open"<<std::endl;
        return false;
    }

    n=0;
    while(!inn.eof()){
        inn>>words[n];
        n++;
       
    }
    
    return true;
}
void write2(int& n, std::string words[5120]){
    for(int i=0;i<n;i++){
        std::cout<<"<"<< words[i]<<">"<<std::endl;
    }
}
bool isvow(char c){
    std::string vowel="aeiouy";
    if(vowel.find(tolow(c))!=std::string::npos)
        return true;
}
bool iswordwithequal(int n, std::string words[5120]){
    for(int i=0;i<n;i++){
        std::string vow="aeiouy";
        for(int j=0;j<vow.length();j++){
            int cnt=0;
            for(int k=0;k<words[i].length();k++){
                if(tolow(words[i][k]) == vow[j]){
                    cnt++;
                }
            }
            if(cnt>=2){
                return true;
            }
        }
    }
    return false;
}
void removecons(int n, std::string words[5120]){
    for (int i=0;i<n;i++){
        for (int j=0;j<words[i].length();j++){
            if(!isvow(words[i][j])){
                words[i].erase(j,1);
                j--;
            }
        }
    }

}
bool treech(const std::string& s){
    int coun=0;
    for(int i=0;i<s.length();i++){
        if(isvow(s[i])){
            coun++;
        }
    }
    return coun >=3;
}
void duplicats(std::string& s){
    for (int i=0;i<s.length();i++){
        if(isvow(s[i])){
            s.insert(i,1,s[i]);
            i++;
        }
    }
}
void sort(int n, std::string words[5120]){
    for (int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(tolowcase(words[i]) > tolowcase(words[j])){
                std::swap(words[j],words[i]);
            }
        }
    }
}




bool read3(int& m, std::string words[max_n]){
    std::ifstream innn("input3.txt");
    if(!innn.is_open()){
        std::cerr<<"file is not open"<<std::endl;
        return false;
    }

    m=0;
    while(!innn.eof()){
        innn>>words[m];
        m++;
       
    }
    
    return true;
}
int maxcount(int m, std::string words[5120]){
    int maxLength = 0;
    std::string longestWords[5120]; // Массив для хранения самых длинных слов
    int longestCount = 0; // Счётчик самых длинных слов

    // Проходим по всем словам
    for (int i = 0; i < m; ++i) {
        int wordLength = words[m].length();
        if (wordLength > maxLength) {
            // Если длина текущего слова больше максимальной, обновляем максимальную длину
            maxLength = wordLength;
            longestCount = 1;
            longestWords[0] = words[m]; // Записываем это слово
    }
        else if (wordLength == maxLength) {
            // Если длина слова равна максимальной, добавляем его в массив
            longestWords[longestCount++] = words[m];
        }
        
    }
    return longestCount;
}
std::string toLowerCase(const std::string& str) {
    std::string result = str;
    for (char &ch : result) {
        ch = std::tolower(ch);
    }
    return result;
}
std::string findMaxLengthWord(const std::vector<std::string>& words) {
    std::string maxWord;
    for (const std::string& word : words) {
        if (word.length() > maxWord.length()) {
            maxWord = word;
        }
    }
    return maxWord;
}
std::unordered_set<char> getLettersInWord(const std::string& word) {
    std::unordered_set<char> letters;
    for (char ch : word) {
        if (std::isalpha(ch)) {
            letters.insert(std::tolower(ch)); 
        }
    }
    return letters;
}
void writewordwithbr(const std::string& word, const std::unordered_set<char>& foundLetters, std::ofstream& outputFile) {
    std::string uppercaseWord = word;
    for (char &ch : uppercaseWord) {
        ch = std::toupper(ch);
    }

    outputFile << uppercaseWord << "(";
    bool first = true;
    for (char letter : foundLetters) {
        if (!first) {
            outputFile << ", "; 
        }
        outputFile << letter;
        first = false;
    }
    outputFile << ") ";
}
void processText(const std::vector<std::string>& words,const std::unordered_set<char>& maxWordLetters,std::ofstream& outputFile) {
    for (int i = 0; i < words.size(); i++) {
        std::string currentWord = words[i];
        std::unordered_set<char> foundLetters;
        std::string lowerWord = toLowerCase(currentWord);

        for (char ch : lowerWord) {
            if (std::isalpha(ch) && maxWordLetters.find(ch) == maxWordLetters.end()) {
            foundLetters.insert(ch);
            }
        }

        if (!foundLetters.empty()) {
            writewordwithbr(currentWord, foundLetters, outputFile);
        } 
        else {

        outputFile << currentWord << " ";
        }
    }
}
void readTextFromFile(const std::string& filename, std::string& text) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Ошибка открытия файла"<< std::endl;
        exit(1);
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    text = buffer.str();
}
std::vector<std::string> splitTextIntoWords(const std::string& text) {
    std::stringstream ss(text);
    std::string word;
    std::vector<std::string> wordsss;
    while (ss >> word) {
        wordsss.push_back(word);
    }
    return wordsss;
}