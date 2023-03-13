//
// Created by silva on 2023-03-12.
//

#ifndef SEARCHING_ARRAY_VECTOR_H
#define SEARCHING_ARRAY_VECTOR_H

#include <malloc.h>
#include <vector>

namespace ArrayVector {

    class array_vector {
    public:
        //process
        void swap(int&,int&);
        void swap(double&,double&);
        //collection
        //vector translator
        int* copyFromVector(std::vector<int>*);
        double* copyFromVector(std::vector<double>*);
        //array translator
        void copyToVector(int*, std::vector<int>*);
        void copyToVector(double*, std::vector<double>*);
    };
    //process
    void array_vector::swap(int &a, int &b) {
        int temp=a;
        a=b;
        b=temp;
    }
    void array_vector::swap(double &a, double &b) {
        double temp = a;
        a=b;
        b=temp;
    }
    //translator
    int* array_vector::copyFromVector(std::vector<int> *v) {
        if (v->size()) {
            int *a = (int*)(malloc(v->size()*sizeof(int)));
            for (int i{0}; i < v->size(); i++) {
                *(a + i) = v->at(i);
            }
            return a;
        }
        return nullptr;
    }
    double* array_vector::copyFromVector(std::vector<double> *v) {
        if (v->size()) {
            double *a = (double*)(malloc(v->size()*sizeof(double)));
            for (int i{0}; i < v->size(); i++) {
                *(a + i) = v->at(i);
            }

            return a;
        }
        return nullptr;
    }
    void array_vector::copyToVector(int *a, std::vector<int> *v) {
        if (v->size()) {
            const auto size{v->size()};
            v->clear();
            for (int i=0; i < size; i++) {
                v->push_back(*(a+i));
            }
        }
    }
    void array_vector::copyToVector(double *a, std::vector<double> *v) {
        if (v->size()) {
            const auto size{v->size()};
            v->clear();
            for (int i=0; i < size; i++) {
                v->push_back(*(a+i));
            }
        }
    }

}

#endif //SEARCHING_ARRAY_VECTOR_H
