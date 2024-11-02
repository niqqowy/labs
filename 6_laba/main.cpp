#include <iostream>
#include <vector>
using namespace std;



//используются для задания 1(кроме read)
bool SameDigit(int number) {
    if(number>=0 && number<=9){
        return false;
    }
    
    int lastDigit = number % 10; 
    while (number > 0) {
        if (number % 10 != lastDigit) {
            return false; 
        }
        number /= 10; 
    }
    return true; 
}

void writetask1(vector<int> numbers,int n){
    sort(numbers.begin(),numbers.end(),greater<int>());
    for (int number : numbers){
        cout<<number<<" ";
    }
}

void read(vector<int>& numbers, int& n){
    numbers.clear();
    cout<<"введите элементы последовательности: ";
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        numbers.push_back(number);
    }
    

}

int counter(vector<int> numbers){
    int countr=0;
    for(int number:numbers){
        if(SameDigit(number)){
            countr++;
        }
    }
    return countr;
}


//используются для задания 2
int SumNumbers(int c){
    int S=0;
    int a;
    while(c>0){
        a=c%10;
        S+=a;
        c/=10;

    }
    return S;
}

int LowestNumber(int y){
    int lownum=INT_MAX;
    int w;
    while(y>0){
        w=y%10;
        if(lownum>w){
            lownum=w;
        }
        y/=10;
    }
    return lownum;
}

bool compare(int a,int b){
    if (SumNumbers(b) == SumNumbers(a)){
        if(LowestNumber(b)==LowestNumber(a)){
            return b<a;
        }
        return LowestNumber(b) < LowestNumber(a);
    }
    return SumNumbers(b)<SumNumbers(a);
}

void sort(vector<int>& arr,bool comparator(int a,int b)){
    int cou=1;
    while(cou!=0){
        cou=0;
        for(int i=0;i+1<arr.size();i++){
            if(comparator(arr[i],arr[i+1])){
                int vv=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=vv;
                cou++;
            }
        }
    }

}

void write(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


//
void readmatrix(vector< vector<int> >& matrix,int& n,int& m){
    cout<<"введите кол-во строк: ";
    cin>>n;
    cout<<"введите кол-во столбцов: ";
    cin>>m;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
}

int SearchColomnWMax(vector< vector<int> >& matrix,int n,int m){
    int colomn=0;
    long long Max_product=LLONG_MIN;
    for(int j=0;j<m;j++){
        long long product=1;
        for(int i=0;i<n;i++){
            product*=matrix[i][j];

        }
        if (product>Max_product){
            Max_product=product;
            colomn=j;
        }
    }
    return colomn;
}

void newmatrix(vector< vector<int> >& matrix,int colomn){
    for(int i=0;i<matrix.size();i++){
        matrix[i][colomn]-=3;
    }
}

void writematrix(vector< vector<int> >& matrix,int n,int m){
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
        
    }
}


//
bool j7(int x){
    int S=0;
    while(x>0){
        S+=x%10;
        x/=10;
    }
    if(S%7==0){
        return true;
    }
    return false;
}
bool if2same(int nummm){
    if(0<=nummm && nummm<=9){
        return false;
    }
    int dg;
    int counterrr=0;
    dg=nummm%10;
    while(nummm>0){
        if(dg==nummm%10){
            counterrr++;
        }
        nummm/=10;
    }
    if (counterrr>=2){
        return true;
    }
    return false;

}
bool ify2k(int numberrrrrr){
    int digitCount[10]={0};

    while(numberrrrrr>0){
        int digit= numberrrrrr%10;
        digitCount[digit]++;
        if(digitCount[digit]>1){
            return true;
        }
        numberrrrrr /=10;
    }
    return false;
}


int main(){

    cout<<"Задание 1 "<<endl;
    vector<int> numbers;
    int n;
    cout<<"введите количество элементов последовательности: ";
    cin>>n;
    if (n>0 && n<=10000){
        read(numbers,n);

        if (counter(numbers)>=3){
            writetask1(numbers,n);
        }
        else{
            cout<<"в последовательности менее 3 чисел с одинаковыми цифрами";
            cout<<" "<<endl;
        }
    }
    else{
        cout<<"n не удовлетворяет условию";
    }
    cout<<" "<<endl;
    
    cout<<"Задание 2 "<<endl;
    vector<int> numbers2;
    cout<<"введите количество элементов последовательности: ";
    int max2;
    cin>>max2;
    if (n>0 && n<=1000){
        read(numbers2,max2);
        sort(numbers2,compare);
        write(numbers2,max2);
    }
    else{
        cout<<"n не удовлетворяет условию";
    }


    cout<<" "<<endl;
    cout<<"Задание 3 "<<endl;
    int gg;
    int mm;
    vector< vector<int> > matrix(gg,vector<int> (mm));
    readmatrix(matrix,gg,mm);

    int clmn=SearchColomnWMax(matrix,gg,mm);

    
    newmatrix(matrix,clmn);
    cout<<"Матрица: ";
    writematrix(matrix,gg,mm);
    cout<<"искомый столбец"<<clmn;


    cout<<" "<<endl;
    cout<<"Задание 4 "<<endl;
    int max3;
    cout << "Enter amount of numbers ";
    cin >> max3;
    int arr[2*max3];
    for (int i = 0; i < max3; i++) {
        cin >> arr[i];
    }

    int ji = 0;
    for (int i = 0; i < max3; i++) {
        if (!j7(arr[i])) {
            arr[ji++] = arr[i];
         }
    }
    max3 = ji;

    

    for (int i=0;i<max3;i++){
        if(ify2k(arr[i])){
            max3++;
            for(int j=max3-1;j>i;j--){
                arr[j]=arr[j-1];
            }
            i++;
        }

    }
    for(int i=0;i<max3;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}



