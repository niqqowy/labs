#include <func.hpp>
#include <iostream>
using namespace std;

using namespace test;

int main (){
    int n;
    cout<<"enter";
    cin>>n;

    vector<vector <int> > mat (n, vector<int>(n));


    read(mat,n);

    int maxi=MaxNum(mat,n);
    int mini=MinNum(mat,n);

    cout<<"max: "<< maxi;
    cout<<endl;
    cout<<"min: "<<mini;

    if(abs(sumnum(mini)-sumnum(maxi))<=2){
        sort_columns_by_sum(mat,n);

    }
    else{
        cout<<"err";
    }


    write(mat,n);
    return 0;

}




