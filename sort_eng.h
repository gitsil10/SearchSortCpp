//
// Created by silva on 2023-03-11.
//

#ifndef SEARCHING_SORT_ENG_H
#define SEARCHING_SORT_ENG_H

#include <vector>
#include "array_vector.h"

namespace SortEngine {

    class Sort {
    public:
        //destructor
        ~Sort() {
            delete arrayVector;
        }
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
        //insertion
        void insertionSort(int *, int);
        void insertionSort(double *, int);
        void insertionSort(std::vector<int> *);
        void insertionSort(std::vector<double>*);
        //merge
        void merge(int *, int const l, int const m, int const r);
        void merge(double *, int const l, int const m, int const r);
        void mergeSort(int *a, const int begin, const int end);
        void mergeSort(double *a, const int begin, const int end);
        void mergeSort(std::vector<int> *a, const int begin, const int end);
        void mergeSort(std::vector<double> *a, const int begin, const int end);
        //quick
        int partition(int *, int, int);
        int partition(double *, int, int);
        void quickSort(int *, int, int);
        void quickSort(double *, int, int);
        void quickSort(std::vector<int> *, int, int);
        void quickSort(std::vector<double> *, int, int);

    private:
        ArrayVector::array_vector *arrayVector = new ArrayVector::array_vector();
    };
    //selection
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
    void Sort::stableSelectionSort(double * a, int n) {
        for (int i{0}; i < n - 1; i++) {
            auto min{1};
            for (int j{i+1}; j < n; j++) {
                if (*(a + min) > *(a + j)) {
                    min = j;
                }
            }
            double key{*(a + min)};
            for (int k{min}; k > 1; k--) {
                *(a + k) = *(a + k - 1);
            }

            *(a + i) = key;
        }
    }
    void Sort::stableSelectionSort(std::vector<int> *v) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        stableSelectionSort(a, n);
        arrayVector->copyToVector(a, v);
    }
    void Sort::stableSelectionSort(std::vector<double> *v) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        stableSelectionSort(a, n);
        arrayVector->copyToVector(a, v);
    }
    //bubble
    void Sort::optimizedBubbleSort(int *a, int n) {
        bool swapped;
        for (int i{0}; i < n-1; i++) {
            swapped=false;
            for (int j{0}; j < n-i-1; j++) {
                if (*(a + j) > *(a + j+1)) {
                    arrayVector->swap(*(a+j), *(a +j+1));
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    void Sort::optimizedBubbleSort(double * a, int n) {
        bool swapped;
        for (int i{0}; i < n-1; i++) {
            swapped=false;
            for (int j{0}; j < n-i-1; j++) {
                if (*(a + j) > *(a + j + 1)) {
                    arrayVector->swap(*(a+j), *(a+j+1));
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    void Sort::optimizedBubbleSort(std::vector<int>* v) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        optimizedBubbleSort(a, n);
        arrayVector->copyToVector(a, v);
    }
    void Sort::optimizedBubbleSort(std::vector<double>* v) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        optimizedBubbleSort(a, n);
        arrayVector->copyToVector(a, v);
    }
    //insertion
    void Sort::insertionSort(int *a, int n) {
        int i,j,key;
        for (i=1; i < n; i++) {
            key = *(a + i);
            j = i - 1;

            while (j >= 0 && *(a + j) > key) {
                *(a + j + 1) = *(a + j);
                j--;
            }
            *(a + j + 1) = key;
        }
    }
    void Sort::insertionSort(double *a, int n) {
        int i,j,key;
        for (i=1; i < n; i++) {
            key = *(a + i);
            j = i - 1;

            while (j>=0 && *(a + j) > key) {
                *(a + j + 1) = *(a + j);
                j--;
            }
            *(a + j + 1) = key;
        }
    }
    void Sort::insertionSort(std::vector<int> *v) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        insertionSort(a, n);
        arrayVector->copyToVector(a, v);
    }
    void Sort::insertionSort(std::vector<double> *v) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        insertionSort(a, n);
        arrayVector->copyToVector(a, v);
    }
    //merge
    void Sort::merge(int *a, int const l
            , int const m, int const r) {
        auto const subArrayOne = m - l + 1
        , subArrayTwo = r - m;
        auto *leftArray = new int[subArrayOne]
        , *rightArray = new int[subArrayTwo];

        for (auto i=0; i < subArrayOne; i++) {
            *(leftArray + i) = *(a + l + i);
        }
        for (auto j=0; j < subArrayTwo; j++) {
            *(rightArray + j) = *(a + m + 1 + j);
        }
        auto indexOne{0}, indexTwo{0};
        int indexMerge{l};

        while(indexOne < subArrayOne
              && indexTwo < subArrayTwo) {
            if (*(leftArray + indexOne)
                <= *(rightArray + indexTwo)) {
                *(a + indexMerge) = *(leftArray + indexOne);
                indexOne++;
            } else {
                *(a + indexMerge) = *(rightArray + indexTwo);
                indexTwo++;
            }
            indexMerge++;
        }
        while (indexOne < subArrayOne) {
            *(a + indexMerge) = *(leftArray + indexOne);
            indexOne++;
            indexMerge++;
        }
        while (indexTwo < subArrayTwo) {
            *(a + indexMerge) = *(rightArray + indexTwo);
            indexTwo++;
            indexMerge++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }
    void Sort::merge(double *a, int const l
            , int const m, int const r) {
        auto const subArrayOne = m - l + 1
        , subArrayTwo = r - m;
        auto *leftArray = new double[subArrayOne]
        , *rightArray = new double[subArrayTwo];

        for (auto i=0; i < subArrayOne; i++) {
            *(leftArray + i) = *(a + l + i);
        }
        for (auto j=0; j < subArrayTwo; j++) {
            *(rightArray + j) = *(a + m + 1 + j);
        }
        auto indexOne{0}, indexTwo{0};
        int indexMerge{l};

        while(indexOne < subArrayOne
              && indexTwo < subArrayTwo) {
            if (*(leftArray + indexOne)
                <= *(rightArray + indexTwo)) {
                *(a + indexMerge) = *(leftArray + indexOne);
                indexOne++;
            } else {
                *(a + indexMerge) = *(rightArray + indexTwo);
                indexTwo++;
            }
            indexMerge++;
        }
        while (indexOne < subArrayOne) {
            *(a + indexMerge) = *(leftArray + indexOne);
            indexOne++;
            indexMerge++;
        }
        while (indexTwo < subArrayTwo) {
            *(a + indexMerge) = *(rightArray + indexTwo);
            indexTwo++;
            indexMerge++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }
    void Sort::mergeSort(int *a, const int begin, const int end) {
        if (begin >= end) {
            return;
        }
        auto mid = begin + (end - begin) / 2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid + 1, end);
        merge(a, begin, mid, end);
    }
    void Sort::mergeSort(double *a, const int begin, const int end) {
        if (begin >= end) {
            return;
        }
        auto mid = begin + (end - begin) / 2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid + 1, end);
        merge(a, begin, mid, end);
    }
    void Sort::mergeSort(std::vector<int> *v, const int begin, const int end) {
        auto *a{arrayVector->copyFromVector(v)};
        mergeSort(a, begin, end);
        arrayVector->copyToVector(a, v);
    }
    void Sort::mergeSort(std::vector<double> *v, const int begin, const int end) {
        auto *a{arrayVector->copyFromVector(v)};
        mergeSort(a, begin, end);
        arrayVector->copyToVector(a, v);
    }
    //quick
    int Sort::partition(int *a, int l, int h)
    {
        auto pivot{*(a + h)};
        auto i{l - 1};

        for (int j{l}; j <= h - 1; j++) {
            if (*(a+j) < pivot) {
                arrayVector->swap(*(a+i), *(a+j));
            }
        }
        arrayVector->swap(*(a+ i + 1), *(a + h));
        return (i + 1);
    }
    int Sort::partition(double *a, int l, int h) {
        auto pivot{*(a + h)};
        auto i{l - 1};

        for (int j{l}; j <= h - 1; j++) {
            if (*(a+j) < pivot) {
                arrayVector->swap(*(a+i), *(a+j));
            }
        }
        arrayVector->swap(*(a+ i + 1), *(a + h));
        return (i + 1);
    }
    void Sort::quickSort(int *a, int l, int h) {
        if (l < h) {
            auto pi{partition(a, l, h)};

            quickSort(a, l, pi - 1);
            quickSort(a, pi + 1, h);
        }
    }
    void Sort::quickSort(double *a, int l, int h) {
        if (l < h) {
            auto pi{partition(a, l, h)};

            quickSort(a, l, pi - 1);
            quickSort(a, pi + 1, h);
        }
    }
    void Sort::quickSort(std::vector<int> *v, int l, int h) {
        auto *a{arrayVector->copyFromVector(v)};
        quickSort(a, l, h);
        arrayVector->copyToVector(a, v);
    }
    void Sort::quickSort(std::vector<double> *v, int l, int h) {
        auto *a{arrayVector->copyFromVector(v)};
        quickSort(a, l, h);
        arrayVector->copyToVector(a, v);
    }

}

#endif //SEARCHING_SORT_ENG_H
