#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <locale>
#include <sstream>


void initArray(int* array);
std::string getFileName(std::string);
void countLetters(std::ifstream &, int *);
void outputLetters(std::ofstream &, int *);
void printArray(int* array);

const std::string INPUT = "Please input read file name :";
const std::string OUTPUT= "Please input wirte file name :";
const int SIZE = 26;

int main() {
    int *count = new int[SIZE];
    initArray(count);
    std::ifstream inputFile(getFileName(INPUT).c_str());
    if(!inputFile){
        std::cerr<<"File doesn't exist, program exit!" << std::endl;
        exit(1);
    }
    while(inputFile.peek() != EOF){
        countLetters(inputFile, count);
        std::ofstream outFile;
        outputLetters(outFile, count);
        outFile.close();

    }
    inputFile.close();
    delete[] count;
    return 0;
}

void initArray(int* array){
    for(int i = 0; i < SIZE; i++){
        array[i] = 0;
    }
    return;
}

std::string getFileName(std::string info){
    std::string  fileName;
    std::cout << info << std::endl;
    std::getline(std::cin, fileName);
    return fileName;
}

void countLetters(std::ifstream &file, int *array){
    char x;
    while(file.get(x)){
        if(x == '\n'){
            return;
        }
        x = tolower(x);
        if(x >= 'a' && x<= 'z'){
            array[x - 'a']++;
        }
    }
}

void outputLetters(std::ofstream &file, int *array){
    file.open(getFileName(OUTPUT).c_str());
    if (!file){
        std::cerr<<"Can not create this file, program exit!" << std::endl;
        exit(1);
    }
    for(int i = 0; i < SIZE; i++){
        std::stringstream ss;
        ss << char('a' + i) << std::setw(4) << ":" <<std::setw(4) << array[i] << '\n';
        file << ss.rdbuf();
        array[i] = 0;
    }
    return;
}

void printArray(int* array){
    for(int i = 0; i < SIZE; i++){
        std::cout << " "<< i << " : "<< array[i] << std::endl;
    }
    return;
}
