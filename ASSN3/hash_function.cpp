#include "hash_function.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int HashFunction::hashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int keysq=key*key;
    keybit=0;
    keysqbit=0;
    check_bit(key,keybit);
    int array[keybit];
    bin_key = dec_to_bin(key,array,keybit);
    check_bit(keysq,keysqbit);

    int array_sq[keysqbit];
    bin_keysq = dec_to_bin(keysq,array_sq,keysqbit);

    int arr[2*key_size];
    int i,j;
    if(keysqbit<2*key_size) {
        for(i=0; i<2*key_size-keysqbit; i++)
        {
            arr[i]=0;
        }
        for(j=0; j<keysqbit; j++)
        {
            arr[i]=array_sq[j];
            i+=1;
        }
    }
    else {
        for(i=0; i<keysqbit; i++)
        {
            arr[i]=array_sq[i];
        }
    }

    int sum=0;
    int levels=1;

    int target=((2*key_size+1)-index_size)/2;
    for (int i=target+index_size-1; i>=target; i--) {
        sum+=arr[i]*levels;
        levels*=2;
    }
    return sum;

    //return -1;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
int HashFunction::dec_to_bin(int n,int array[],int size) {
    int result=0;
    int k=size-1;
    for(int i=1 ; n>=1 ; i*=10){
        result += (n%2)*i;
        array[k]=n%2;
        n/=2;
        k--;
    }
    return result;
}

void HashFunction::check_bit(int n,int &tempbit) {
    int temp=n;
    while(temp>=1) {
        temp/=2;
        tempbit+=1;
    }
}

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
