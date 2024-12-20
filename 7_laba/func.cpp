#include <func.hpp>

using namespace std;
using namespace test;

int sumnum(int num){
    int s=0;
    int a;
    num=abs(num);
    while(num>0){
        a=num%10;
        s+=a;
        num/=10;
    }
    return s;
}

void read (vector<vector <int> >& matrix,int& n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
}

void write (vector<vector <int> > matrix,int& n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int MaxNum(vector<vector <int> > matrix,int& n){
    int max=INT_MIN;
    
    for (int i=0;i<n;i++){
         for (int j=0;j<n;j++){
            if (matrix[i][j]>max){
                max=matrix[i][j];
            }

         }

    }
    return max;
}

int MinNum(vector<vector <int> > matrix,int& n){
    int min=INT_MAX;
    
    for (int i=0;i<n;i++){
         for (int j=0;j<n;j++){
            if (matrix[i][j]<min){
                min=matrix[i][j];
            }

         }

    }
    return min;
}


void sort_columns_by_sum(vector<vector< int> >& matrix, int n) {
    vector<int> column_sums(n, 0);
    
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            column_sums[j] += matrix[i][j];
        }
    }

    vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;

    sort(indices.begin(), indices.end(), [&column_sums](int i, int j) {
        return column_sums[i] < column_sums[j];
    });

    vector<vector<int > > sorted_matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sorted_matrix[i][j] = matrix[i][indices[j]];
        }
    }

    matrix = sorted_matrix;
}


