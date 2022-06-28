#include "shift_register.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int ShiftRegister::getSeqNumber(int idx) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    size_d=0;
    bit= _sqrt(M);

    binary_k = to_binary(k,size_k);
    if(size_k<bit) {
        for(int j=1;j<=bit-size_k;j++) {
            xor_binary_k+="0";
        }
    }
    xor_binary_k+=binary_k;

    for (int i=1; i<=idx; i++) {
        if (i==1) {
            decimal_d = initial_seed;
        }
        else if (i>1){
            decimal_d*=2;
            if(decimal_d>=M) {
                decimal_d-=M;
                binary_d = to_binary(decimal_d,size_d);
                xor_binary_d="";

                if(size_d<bit) {
                    for(int j=1;j<=bit-size_d;j++) {
                        xor_binary_d+="0";
                    }
                }
                xor_binary_d+=binary_d;
                binary_d=binary_xor(xor_binary_d,xor_binary_k);
                decimal_d=to_decimal(binary_d);
            }
        }
        if(i==idx) {
            return decimal_d;
        }
    }
    return -1;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

string ShiftRegister::to_binary(int num,int &size)
{
    string str;
    size=0;
    while (num != 0){
        str += ( num % 2 == 0 ? "0" : "1" );
        num /= 2;
        size+=1;
    }
    return str;
}

int ShiftRegister::to_decimal(string arr) {
    int dec_bin;
    if (arr.length()!=0) {
        dec_bin = stoi(arr);
    }
    else dec_bin=0;

    int r=1;
    int sum=0;
    while (dec_bin>0) {
        if(dec_bin%2) {
            sum+=r;
        }
        r*=2;
        dec_bin/=10;
    }
    return sum;
}

string ShiftRegister::binary_xor (string arr1,string arr2) {
    string arr;
    for (int i=0; i<bit; i++) {
        if(arr1[i]!=arr2[i]) {
            arr+="1";
        }
    }
    return arr;
}

double ShiftRegister::_sqrt(int num)
{
    double a=0;
    double b=0;
    a=num/2;
    for (;a!=b;)
    {
        b=a;
        a=((num/b)+b)/2;
    }
    return a;
}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
