#include <iostream>
#include <fstream>
#include <string>
#include "hash_function.h"
#include "shift_register.h"
#include "hash_table.h"

using namespace std;


HashTable::HashTable(int table_size, HashFunction *hf, ShiftRegister *sr) : table_size(table_size) {
    this->hf = hf;
    this->sr = sr;
    this->table = new int[this->table_size];
    this->states = new TableState[this->table_size];

    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    for(int i=0; i<table_size; i++) states[i] = EMPTY;
    num=0;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

HashTable::~HashTable() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    /*  Write your codes if you need  */

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

    delete[] this->table;
    delete[] this->states;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void HashTable::print_table(ostream &out) {
    for (int i=0; i < this->table_size; i++) {
        out << i << ": ";
        if (this->states[i] == EMPTY)
            out << "empty" << endl;
        else if (this->states[i] == DELETED)
            out << "deleted" << endl;
        else if (this->states[i] == OCCUPIED)
            out << this->table[i] << endl;
        else
            out << "unknown state" << endl;
    }
}

void HashTable::insert(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int base_h,h,d;
    int seq=0;

    base_h=hf->hashing(key);
    h=hf->hashing(key);

    if(num<table_size) {
        while (states[h]!=EMPTY) {
            d=sr->getSeqNumber(seq+1);
            h=(base_h+d)%table_size;
        }
        table[h] = key;
        states[h] = OCCUPIED;
        num += 1;
    }
    else if(num==table_size){
        table[num] = key;
        states[num] = OCCUPIED;
        num +=1;
    }
    return;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void HashTable::erase(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int base_h, h, d;
    int seq = 0;

    base_h = hf->hashing(key);
    h = hf->hashing(key);

    int idx = 0;
        while (table[h]!=key) {
            d=sr->getSeqNumber(seq+1);
            h=(base_h+d)%table_size;
            if(idx==table_size-1) {
                h=idx;
            }
            idx+=1;
        }
    states[h]=DELETED;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
