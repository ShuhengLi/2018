//
// Created by Shuheng Li on 11/27/17.
//
#include "book.hpp"

Book::Book(std::string idc, std::string t, std::string a):idCode(idc), title(t), author(a){
    checkedOutBy = nullptr;
    requestedBy = nullptr;
    location = ON_SHELF;
}

int Book::getCheckOutLength(){
    return 0;
}

std::string Book::getIdCode(){
    return  idCode;
}
std::string Book::getTitle(){
    return title;
}

std::string Book::getAuthor(){
    return author;
}

Locale Book::getLocation(){
    return location;
}

void Book::setLocation(Locale l){
    location = l;
}

Patron* Book::getCheckedOutBy(){
    return checkedOutBy;
}

void Book::setCheckedOutBy(Patron* person){
    checkedOutBy = person;
}

Patron* Book::getRequestedBy(){
    return requestedBy;
}

void Book::setRequestedBy(Patron* person){
    requestedBy = person;
}

int Book::getDateCheckedOut(){
    return dateCheckedOut;
}

void Book::setDateCheckedOut(int date){
    dateCheckedOut = date;
}