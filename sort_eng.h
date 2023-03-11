//
// Created by silva on 2023-03-11.
//

#ifndef SEARCHING_SORT_ENG_H
#define SEARCHING_SORT_ENG_H

#include <vector>

namespace SortEngine {

    class Sort {
    public:
        //selection sort
        void stableSelectionSort(int *, int);
        void stableSelectionSort(double*, int);
        void stableSelectionSort(std::vector<int> *);
        void stableSelectionSort(std::vector<double> *);
        //bubble sort
        void optimizedBubbleSort(int *, int);
        void optimizedBubbleSort(double *, int);
        void optimizedBubbleSort(std::vector<int>*);
        void optimizedBubbleSort(std::vector<double>*);
    private:
        void swap(int&,int&);
    };
    void Sort::swap(int &a, int &b) {
        int temp=a;
        a=b;
        b=temp;
    }
    void Sort::stableSelectionSort(int *a, int n) {
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (*(a + min) > *(a + j)) {
                    min = j;
                }
            }

            int key = *(a + min);
            for(int k=min;k>i;k--) {
                *(a + k) = *(a + k - 1);
            }

            *(a + i) = key;
        }
    }
    void Sort::optimizedBubbleSort(int *a, int n) {
        bool swapped;
        for (int i{0}; i < n-1; i++) {
            swapped=false;
            for (int j{0}; j < n-i-1; j++) {
                if (*(a + j) > *(a + j+1)) {
                    swap(*(a+j), *(a +j+1));
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
}

#endif //SEARCHING_SORT_ENG_H
