#pragma once
#include <iostream>
#include <string>
#include <array>
#include <cctype>
#include <string>
#include <vector>
#include <set>



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


