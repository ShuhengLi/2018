//
// Created by Shuheng Li on 11/27/17.
//
#include "Library.hpp"

Library::Library():currentDate(0){
}

void Library::addBook(Book* b){
    holdings.push_back(b);
}

void Library::addPatron(Patron* p){
    members.push_back(p);
}

std::string Library::checkOutBook(std::string pID, std::string bID){
    Patron *person;
    Book *book;
    for(int i = 0; i < members.size(); i++){
        if(members[i].getIdName() == pID){
            person = members[i];
            break;
        }
    }
    if(person == nullptr){
        return "patron not found";
    }

    for(int i = 0; i < holdings.size(); i++){
        if(holdings[i].getIdCode() == bID){
            book = holdings[i];
            break;
        }
    }
    if(book == nullptr){
        return "book not found";
    }

    if(book->getCheckedOutBy() == nullptr){
        if(book->getRequestedBy() != nullptr && book->getRequestedBy() != person){
            return "book on hold by other patron";
        }
        if(book->getRequestedBy() == person){
            book->setRequestedBy(nullptr);
        }
        book->setCheckedOutBy(person);
        book->setDateCheckedOut(currentDate);
        book->setLocation(CHECKED_OUT);
        person->addBook(book);
        return "check out successful";
    } else{
        return "book already checked out";
    }

}

std::string Library::returnBook(std::string bID){
    Book *book;
    for(int i = 0; i < holdings.size(); i++){
        if(holdings[i].getIdCode() == bID){
            book = holdings[i];
            break;
        }
    }
    if(book == nullptr){
        return "book not found";
    }

    if(book->getCheckedOutBy() == nullptr){
        return "book already in library";
    }

    Patron *patron, *request;
    patron = book->getCheckedOutBy();
    patron->removeBook(book);
    request = book->getRequestedBy();
    book->setCheckedOutBy(request);
    if(request == nullptr){
        book->setLocation(ON_SHELF);
    } else{
        book->setLocation(ON_HOLD_SHELF);
    }
    return "return successful";
}

std::string Library::requestBook(std::string pID, std::string bID){
    Book *book;
    for(int i = 0; i < holdings.size(); i++){
        if(holdings[i].getIdCode() == bID){
            book = holdings[i];
            break;
        }
    }
    if(book == nullptr){
        return "book not found";
    }

    Patron *patron;
    for(int i = 0; i < members.size(); i++){
        if(members[i].getIdName() == pID){
            patron= members[i];
            break;
        }
    }
    if(patron == nullptr){
        return "patron not found";
    }
    if(book->getRequestedBy() != nullptr){
        return "book already on hold";
    } else{
        book->setRequestedBy(patron);
        if(book->getLocation() == ON_SHELF){
            book->setLocation(ON_HOLD_SHELF);
        }
        return "request successful";
    }

}

std::string Library::payFine(std::string pID, double payment){
    Patron *patron;
    for(int i = 0; i < members.size(); i++){
        if(members[i].getIdName() == pID){
            patron= members[i];
            break;
        }
    }
    if(patron == nullptr){
        return "patron not found";
    }else{
        patron->amendFine(-payment);
        return "payment successful";
    };
}

void Library::incrementCurrentDate(){
    currentDate++;

    double fine = 0.1;
    for(int i = 0; i < members.size(); i++){
        Patron *patron = members[i];
        vector<*Book> books = patron->getCheckedOutBooks();
        for(int j = 0; j < books.size(); j++){
            Book *book = books[i];
            if (currentDate - book->getDateCheckedOut() > book->getCheckOutLength()){
                patron->amendFine(fine);
            }
        }
    }
}

Patron* Library::getPatron(std::string pID){
    for(int i = 0; i < members.size(); i++){
        if(members[i].getIdName() == pID){
            return members[i];
        }
    }
    return nullptr;

}

Book* Library::getBook(std::string bID){
    for(int i = 0; i < holdings.size(); i++){
        if(holdings[i].getIdCode() == bID){
            return holdings[i];
        }
    }
    return nullptr;
}
