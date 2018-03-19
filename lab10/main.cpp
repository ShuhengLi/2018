#include <iostream>
#include <iomanip>
#include <time.h>
#include <map>
long long fibonacciRecursive(int n);
long long  fibonacciIterative(int n);
std::map<int, long long> m;
int main() {
    int n = 100;
    m[0] = 0;
    m[1] = 1;
    std::cout << "Measure as NANOSECONDS" << std::endl << std::endl;
    for(int i = 0; i < n; i += 1){
        //Iterative method
        auto beginI = std::chrono::steady_clock::now();
        auto I = fibonacciIterative(i);
        auto endI = std::chrono::steady_clock::now();

        //Recursive method
        auto beginR = std::chrono::steady_clock::now();
        auto R = fibonacciRecursive(i);
        auto endR = std::chrono::steady_clock::now();

        //measure and printout as a table
        auto durationI = std::chrono::duration_cast<std::chrono::nanoseconds>(endI - beginI).count();
        auto durationR = std::chrono::duration_cast<std::chrono::nanoseconds>(endR - beginR).count();
        std::cout <<"N: "<< i << std::right<< std::setw(40)
                  << "IterateTime: "<< durationI << std::right << std::setw(40)
                  << "RecursiveTime: " << durationR << std::endl;
        //std::cout << "IterateNum: "<< I << "\nRecursiveNum: " << R<< std::endl;
    }
    return 0;
}

//cite from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
long long fibonacciRecursive(int n){
    if(m.find(n) != m.end()){
        return m[n];
    }else{
        auto res = fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
        m[n] = res;
        return res;
    }
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
