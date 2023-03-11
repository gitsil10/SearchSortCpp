#include <iostream>
#include <vector>
#include "random_eng.h"
#include "search_eng.h"
#include "sort_eng.h"

int main() {
    RandomEngine::Engine *engine = new RandomEngine::Engine();
    SortEngine::Sort *sort_engine = new SortEngine::Sort();

    int *arr=engine->getRandomInts();

    std::vector<int> *v = engine->getVectorInt();

    std::cout << "unsorted\n";
    for (int i=0; i < v->size(); i++) {
        std::cout << "i: " << i << "\tarray: " << *(arr +i) << std::endl;
            //<< " \t\tvector: " << v->at(i) << std::endl;
    }

    std::cout << "sorting\n";
    sort_engine->optimizedBubbleSort(arr, engine->getSize());

    for (int i=0; i < v->size(); i++) {
        std::cout << "i: " << i << "\tarray: " << *(arr +i) << std::endl;
                  //<< " \t\tvector: " << v->at(i) << std::endl;
    }

    std::cout << "sorted\n";
    return 0;
}
