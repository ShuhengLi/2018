#include <iostream>
#include <iomanip>
#include <time.h>
long long fibonacciRecursive(int n);
long long  fibonacciIterative(int n);
int main() {
    int n = 100;
    for(int i = 0; i < n; i += 1){
        //Iterative method
        clock_t beginI = clock();
        auto I = fibonacciIterative(i);
        clock_t endI = clock();

        //Recursive method
        clock_t beginR = clock();
        auto R = fibonacciRecursive(i);
        clock_t endR = clock();

        //measure and printout as a table
        float durationI = float(endI - beginI) / CLOCKS_PER_SEC;
        float durationR = float(endR - beginR) / CLOCKS_PER_SEC;
        std::cout <<"N: "<< i << std::fixed << std::setprecision(6) << std::right<< std::setw(40)
                  << "IterateTime: "<< durationI << std::right << std::setw(40)
                  << "RecursiveTime: " << durationR << std::endl;
        //std::cout << "IterateNum: "<< I << "\nRecursiveNum: " << R<< std::endl;
    }
    return 0;
}

//cite from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
long long fibonacciRecursive(int n){
    if(!n){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }
}

//wrote by myself
long long fibonacciIterative(int n){
    if(!n){
        return 0;
    }
    long long prev = 0;
    long long current = 1;
    for(int i = 1; i < n; i++){
        long long temp = current;
        current += prev;
        prev = temp;
    }
    return current;
}
