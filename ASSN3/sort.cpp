#include "sort.h"
#include <iostream>
#include <fstream>
#include <string>


sortAlg::sortAlg() {
    arr_size = 0;
    arr = new int[100]; // Each test case will be less than 100 values
}

using namespace std;

void sortAlg::printArray(ofstream &fout) {
    string answer;
    for (int i = 0; i < arr_size - 1; i++)
        answer += to_string(arr[i]) + " ";
    answer += to_string(arr[arr_size - 1]);
    fout << answer << endl;
}


void sortAlg::selectionSort(ofstream &fout) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    int min;
    int temp;
    for (int i = 0; i < arr_size - 1; i++) {
        min = i;
        for(int j = i; j < arr_size; j++) {
            if(arr[min]>arr[j]) min = j;
        }
        temp = arr[i];
        arr[i]=arr[min];
        arr[min]=temp;

        printArray(fout); // DO NOT ERASE THIS LINE
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void sortAlg::merge(int left, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int temp[20];
    for (int i=0; i<arr_size; i++) {
        temp[i]=arr[i];
    }
    int i = left;
    int mid = (left+right)/2;
    int j = mid+1;
    int k = left;

    if(right==arr_size-1) {
        //i=left;
        mid=right-1;
        j=right;
        //k=left;
    }
    if(right>arr_size-1) {
        right = arr_size - 1;
    }

    while (i<=mid && j<= right) {
        if(arr[i]<=arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i>mid) {
        for (int t = j; t<=right; t++) {
            temp[k]=arr[t];
            k++;
        }
    }
    else {
        for (int t = i; t<=mid; t++) {
            temp[k]=arr[t];
            k++;
        }
    }

    for(int i=left; i<=right; i++) {
        arr[i] = temp[i];
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void sortAlg::mergeSort(ofstream &fout, int left, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (left < right) {
        int level = 2;
        int last_sort = 1;
        while (level<arr_size||last_sort==1) {
            if (level>arr_size) {last_sort=0;}

            for (int i = 0; i < arr_size; i += level) {
                merge(i,i+level-1);
                if (i!=arr_size-1&&(right-i+1>level/2)&&last_sort==1) printArray(fout);
            }
            level*=2;
        }
        printArray(fout);// DO NOT ERASE THIS LINE
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

}
