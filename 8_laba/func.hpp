#pragma once
#include <iostream>
#include <string>
#include <array>
#include <cctype>
#include <string>
#include <vector>
#include <set>


bool isVowel(char ch);

int countpair(const std::string &word);

std::set<std::string> read(const std::string &name);

void writeRes(const std::vector<std::pair<int, std::string>> &wordPairs, const std::string &filename);

