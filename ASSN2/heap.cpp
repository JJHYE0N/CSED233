#include "heap.h"
#include <iostream>
#include <string>

using namespace std;


MaxHeap::MaxHeap() {
    heap_size = 0;
    heap_arr = new int[100]; // Default array of size 100
}

string MaxHeap::printHeap(){
    string answer;
    for (int i = 0; i < heap_size; i++)
        answer += to_string(heap_arr[i]) + " ";
    return answer;
}

void MaxHeap::insertKey(int k) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    *(heap_arr + index) = k;

        int loop;
        if (0 < index && index <= 2) loop = 1;
        else if (2 < index && index <= 6) loop = 2;
        else if (6 < index && index <= 14) loop = 3;
        else if (14 < index && index <= 30) loop = 4;
        else if (30 < index && index <= 62) loop = 5;
        else if (62 < index && index <= 100) loop = 6;

        for (int j = 1; j <= loop; j++) {
            if (index >= j) {
                for (int k = 0; k <= index; k++) {
                    maxHeapProp(k);
                }
            }
        }

    heap_size += 1;
    index +=1;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void MaxHeap::deleteMax() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    heap_arr[0] = heap_arr[index-1];
    index-=1;
    heap_size-=1;
    int loop;
    if (0 < index && index <= 2) loop = 1;
    else if (2 < index && index <= 6) loop = 2;
    else if (6 < index && index <= 14) loop = 3;
    else if (14 < index && index <= 30) loop = 4;
    else if (30 < index && index <= 62) loop = 5;
    else if (62 < index && index <= 100) loop = 6;

    for (int j = 1; j <= loop; j++) {
        if (index >= j) {
            for (int k = 0; k <= index; k++) {
                maxHeapProp(k);
            }
        }
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void MaxHeap::maxHeapProp(int i) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int temp;
    if (i>=3) {
        if (i % 2 == 1) {
            if (heap_arr[i / 2] < heap_arr[i]) {
                temp = heap_arr[i / 2];
                heap_arr[i / 2] = heap_arr[i];
                heap_arr[i] = temp;
            }
        } else if (i % 2 == 0) {
            if (heap_arr[(i / 2) - 1] < heap_arr[i]) {
                temp = heap_arr[(i / 2) - 1];
                heap_arr[(i / 2) - 1] = heap_arr[i];
                heap_arr[i] = temp;
            }
        }
    }
    else {
        if (i==1 && heap_arr[i]>heap_arr[0]) {
                temp = heap_arr[i];
                heap_arr[i] = heap_arr[0];
                heap_arr[0] = temp;
            }
        else if (i==2 && heap_arr[i]>heap_arr[0]) {
                temp = heap_arr[i];
                heap_arr[i] = heap_arr[0];
                heap_arr[0] = temp;
        }
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}