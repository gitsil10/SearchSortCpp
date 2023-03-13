//
// Created by silva on 2023-03-11.
//

#ifndef SEARCHING_SEARCH_ENG_H
#define SEARCHING_SEARCH_ENG_H

#include "array_vector.h"

namespace SearchEngine {

    class Search {
    public:
        //destructor
        ~Search() {
            delete arrayVector;
        }
        //linear
        int linear(int *, int, int);
        int linear(double *, int, double);
        int linear(std::vector<int>*, int);
        int linear(std::vector<double>*, double);
        int sortedLinear(int*, int, int);
        int sortedLinear(double*, int, double);
        int sortedLinear(std::vector<int>*, int);
        int sortedLinear(std::vector<double>*, double);

    private:
        ArrayVector::array_vector *arrayVector = new ArrayVector::array_vector();

    };
    //linear
    int Search::linear(int *a, int n, int k) {
        for (int i{0}; i < n; i++) {
            if (k == *(a+i)) {
                return i;
            }
        }
        return -1;
    }
    int Search::linear(double *a, int n, double k) {
        for (int i{0}; i < n; i++) {
            if (k== *(a + i)) {
                return i;
            }
        }
        return -1;
    }
    int Search::linear(std::vector<int> *v, int k) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        linear(a, n, k);
    }
    int Search::linear(std::vector<double> *v, double k) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        linear(a, n, k);
    }
    //sorted
    int Search::sortedLinear(int *a, int n, int k) {
        for (int i{0}; i < n; i++) {
            if (k < *(a + i)) {
                return -1;
            } else if (k == *(a + i)) {
                return i;
            }
        }

        return -1;
    }
    int Search::sortedLinear(double *a, int n, double k) {
        for (int i{0}; i < n; i++) {
            if (k < *(a + i)) {
                return -1;
            } else if (k == *(a + i)) {
                return i;
            }
        }

        return -1;
    }
    int Search::sortedLinear(std::vector<int> *v, int k) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        sortedLinear(a, n, k);
    }
    int Search::sortedLinear(std::vector<double> *v, double k) {
        auto n{v->size()};
        auto *a{arrayVector->copyFromVector(v)};
        sortedLinear(a, n, k);
    }
    //

}

#endif //SEARCHING_SEARCH_ENG_H
