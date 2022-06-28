#pragma once
#include <iostream>
#include <string>
using namespace std;

class HashFunction {

public:
    HashFunction(int n, int r) : key_size(n), index_size(r) { };

    int hashing(int key);

private:
    int key_size;
    int index_size;

    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    int keysqbit;
    int keybit;
    int bin_key;
    int bin_keysq;
    int dec_to_bin(int n,int array[],int size);
    void check_bit(int n,int &tempbit);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};

