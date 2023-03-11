//
// Created by silva on 2023-03-11.
//

#ifndef SEARCHING_RANDOM_ENG_H
#define SEARCHING_RANDOM_ENG_H

#include <iostream>
#include <vector>
#include <random>

namespace RandomEngine {

    class Engine {
    public:
        Engine():Engine(INIT_MIN, INIT_MAX, INIT_SIZE){}
        Engine(int size):Engine(INIT_MIN, INIT_MAX, size){}
        Engine(int min, int max):Engine(min, max, INIT_SIZE){}
        Engine(int min, int max, int size) {
            setMin(min);
            setMax(max);
            setSize(size);
        }
        //variable
        unsigned long getSize() const;
        unsigned long getRandomInt();
        double getRandomDouble();
        //containers
        int *getRandomInts();
        double *getRandomDoubles();
        std::vector<int> *getVectorInt();
        std::vector<double> *getVectorDouble();
    private:
        static const unsigned int INIT_MIN{0}, INIT_MAX{100000}, INIT_SIZE{1000000};
        std::default_random_engine eng;
        int min, max;
        unsigned long size;
        //process
        void *createArray();
        void swap(int &, int &);
        void swapMinMax();
        void setMin(int);
        int getMin() const;
        void setMax(int);
        int getMax() const;
        void setSize(unsigned long);
    };
    //public
    //variables
    unsigned long Engine::getRandomInt() {
        swapMinMax();
        std::uniform_int_distribution<unsigned long> dist(getMin(),getMax());
        return dist(eng);
    }
    double Engine::getRandomDouble() {
        swapMinMax();
        std::uniform_real_distribution<double> dist(getMin(), getMax());
        return dist(eng);
    }
    //collections
    //arrays
    int *Engine::getRandomInts() {
        int *ints = getSize() > 0 ? (int*)(malloc(getSize()*sizeof(int))) : nullptr;

        if (ints) {
            for (int i=0; i < getSize(); i++) {
                *(ints + i) = getRandomInt();
            }
        }

        return ints;
    }
    double *Engine::getRandomDoubles() {
        double *doubles = getSize() > 0 ? (double*)(malloc(getSize()*sizeof(double))) : nullptr;

        if (doubles) {
            for (int i=0; i < getSize(); i++) {
                *(doubles + i) = getRandomDouble();
            }
        }

        return doubles;
    }
    std::vector<int> *Engine::getVectorInt() {
        std::vector<int> *vector = new std::vector<int>;
        for (int i=0; i < getSize(); i++) {
            vector->push_back(getRandomInt());
        }

        return vector;
    }
    std::vector<double> *Engine::getVectorDouble() {
        std::vector<double> *vector = new std::vector<double>;
        for (int i=0; i < getSize(); i++) {
            vector->push_back(getRandomDouble());
        }

        return vector;
    }
    //primitive-process
    void Engine::swap(int &a, int &b) {
        int temp=a;
        a=b;
        b=temp;
    }
    void Engine::swapMinMax() {
        if (getMin() > getMax()) {
            swap(min, max);
        }
    }
    void Engine::setMin(int min) { this->min=min; }
    int Engine::getMin() const { return this->min; }
    void Engine::setMax(int max) { this->max=max; }
    int Engine::getMax() const { return this->max; }
    void Engine::setSize(unsigned long size) { this->size=size; }
    unsigned long Engine::getSize() const { return this->size; }

/*
    class RandomArray {
    private:
        static const int INIT_SIZE{10000000};
        unsigned int size;
        int *randArray();
        void print(int *);
        void stableSelectionSort(int *);
        void static swap(int &, int &);
        void optimizedBubbleSort(int *);
        void insertionSort(int *);
        void merge(int *, int const, int const, int const);
        void mergeSort(int *, int const, int const);
        static int comp(const void *a, const void *b) {
            return (*(int*)a - *(int*)b);
        }
    public:
        Algo(unsigned int size=INIT_SIZE) {
            setSize(size);
        }
        void setSize(unsigned int size);
        unsigned int getSize();
        void printRandom();
        void timedRandom();
        void timedSelection();
        void timedBubble();
        void timedInsertion();
        void timedMerge();
        void timedQSort();
        void timedSort();
    };
    void Algo::setSize(unsigned int size) {
        this->size = size;
    }
    unsigned int Algo::getSize() {
        return this->size;
    }
    int *Algo::randArray() {
        std::uniform_int_distribution<size_t> dist(0,size);
        std::default_random_engine eng;
        int *arr=(int*)(malloc(getSize()*sizeof(int)));
        for (int i=0; i < getSize(); i++) {
            *(arr + i) = dist(eng);//1+ rand() % size;
        }
        return arr;
    }
    void Algo::print(int *a) {
        if (!a) exit(1);
        for (int i=0; i < getSize(); i++) {
            printf("index: %d data: %d\n", i, *(a+i));
        }
    }
    void Algo::stableSelectionSort(int *a) {
        for (int i = 0; i < getSize() - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < getSize(); j++) {
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
    void Algo::swap(int &a, int &b) {
        int temp=a;
        a=b;
        b=temp;
    }
    void Algo::optimizedBubbleSort(int *a) {
        bool swapped;
        for (int i{0}; i < getSize()-1; i++) {
            swapped=false;
            for (int j{0}; j < getSize()-i-1; j++) {
                if (*(a + j) > *(a + j+1)) {
                    swap(*(a+j), *(a +j+1));
                    swapped = true;
                }
            }
            if (swapped == false) {
                break;
            }
        }
    }
    void Algo::insertionSort(int *a) {
        int i,j,key;
        for (i=1; i < getSize(); i++) {
            key = *(a + i);
            j = i - 1;

            while (j >= 0 && *(a + j) > key) {
                *(a + j + 1) = *(a + j);
                j--;
            }
            *(a + j + 1) = key;
        }
    }
    void Algo::merge(int *a, int const l
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
    void Algo::mergeSort(int *a, const int begin, const int end) {
        if (begin >= end) {
            return;
        }
        auto mid = begin + (end - begin) / 2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid + 1, end);
        merge(a, begin, mid, end);
    }

    void Algo::printRandom() {
        int *arr = randArray();
        auto start = std::chrono::system_clock::now();
        print(arr);
        auto end = std::chrono::system_clock::now();
        std::cout << "PrintRandom " << getSize() << " : "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    }
    void Algo::timedRandom() {
        auto start = std::chrono::system_clock::now();
        int *arr = randArray();
        auto end = std::chrono::system_clock::now();
        std::cout << "Generating array of " << getSize() << " random numbers:\t"
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
        delete[] arr;
    }
    void Algo::timedSelection() {
        int *arr = randArray();
        auto start = std::chrono::system_clock::now();
        stableSelectionSort(arr);
        auto end = std::chrono::system_clock::now();
        std::cout << "Stable Selection Sort:\t"
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
        delete[] arr;
    }
    void Algo::timedBubble() {
        int *arr = randArray();
        auto start = std::chrono::system_clock::now();
        optimizedBubbleSort(arr);
        auto end = std::chrono::system_clock::now();
        std::cout << "Optimized Bubble Sort:\t"
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
        delete[] arr;
    }
    void Algo::timedInsertion() {
        int *arr = randArray();
        auto start = std::chrono::system_clock::now();
        insertionSort(arr);
        auto end = std::chrono::system_clock::now();
        std::cout << "Insertion Sort:\t"
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
        delete[] arr;
    }
    void Algo::timedMerge() {
        int *arr = randArray();
        auto start = std::chrono::system_clock::now();
        mergeSort(arr, 0, getSize());
        auto end = std::chrono::system_clock::now();
        std::cout << "Merge Sort:\t"
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
        delete[] arr;
    }
    void Algo::timedQSort() {
        int *arr = randArray();
        auto start = std::chrono::system_clock::now();
        mergeSort(arr, 0, getSize());
        qsort(arr, getSize(), sizeof(int), comp);
        auto end = std::chrono::system_clock::now();
        std::cout << "Q Sort:\t"
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
        delete[] arr;
    }
    void Algo::timedSort() {
        int *arr = randArray();
        auto start = std::chrono::system_clock::now();
        mergeSort(arr, 0, getSize());
        qsort(arr, getSize(), sizeof(int), comp);
        std::sort(arr, arr + getSize());
        auto end = std::chrono::system_clock::now();
        std::cout << "Sort:\t"
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
        delete[] arr;
    }
*/
}

#endif //SEARCHING_RANDOM_ENG_H
