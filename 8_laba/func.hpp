#pragma once
#include <iostream>
#include <string>
#include <array>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>



bool rightlett(char ch);
void check(const std::string& inputFilename, const std::string& outputFilename);
int twolett(const std::string &word);
std::set<std::string> read(const std::string &name);
void writeRes(const std::vector<std::pair<int, std::string>> &wordPairs, const std::string &filename);
int twolettequal(const std::string &word);




bool read2(int& n, std::string words[5120]);
void write2(int& n, std::string words[5120]);
bool iswordwithequal(int n, std::string words[5120]);
void removecons(int n, std::string words[5120]);
bool treech(const std::string& s);
void duplicats(std::string& s);
void sort(int n, std::string words[5120]);
std::string tolowcase(std::string s);
char tolow(char c);
bool isvow(char c);

bool read3(int& m, std::string words[5120]);
int maxcount(int m, std::string words[5120]);



std::string toLowerCase(const std::string& str);
std::vector<std::string> findMaxLengthWord(const std::vector<std::string>& words);
std::unordered_set<char> getLettersInWord(const std::vector<std::string>& words);
void writewordwithbr(const std::string& word, const std::unordered_set<char>& foundLetters, std::ofstream& outputFile);
void processText(const std::vector<std::string>& words,const std::unordered_set<char>& maxWordLetters,std::ofstream& outputFile);
void check3(const std::string& inputFilee, const std::string& outputFilee);
void readTextFromFile(const std::string& filename, std::string& text);
std::vector<std::string> splitTextIntoWords(const std::string& text);