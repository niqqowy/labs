#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#include <cmath>

using namespace std;



namespace test {
    void read(vector<vector<int> > &matrix, int& n);

    void write(vector <vector <int> > matrix,int& n);

    int sumnum(int num);

    int MaxNum(vector<vector <int> > matrix,int& n);
    int MinNum(vector<vector <int> > matrix,int& n);

    void sort_columns_by_sum(vector<vector< int> >& matrix, int n);
}


