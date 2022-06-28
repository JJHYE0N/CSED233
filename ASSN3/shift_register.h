#pragma once
#include <iostream>
#include <string>
using namespace std;

class ShiftRegister {

public:
    ShiftRegister(int m, int k, int d) : M(m), k(k), initial_seed(d) { };

    int getSeqNumber(int idx); // idx starts from 1

private:
    int M;
    int k;
    int initial_seed;

    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    string binary_d;
    string binary_k;
    string xor_binary_d;
    string xor_binary_k;
    int decimal_d;
    int size_d;
    int size_k;
    int bit;

    int to_decimal(string arr);
    string to_binary(int n,int &size);
    string binary_xor (string arr1,string arr2);
    double _sqrt(int num);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};

