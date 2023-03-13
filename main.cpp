#include <iostream>
#include <vector>
#include "random_eng.h"
#include "search_eng.h"
#include "sort_eng.h"

int main() {
    auto lim{10000};
    RandomEngine::Engine *engine = new RandomEngine::Engine(lim);
    SortEngine::Sort *sort_engine = new SortEngine::Sort();
    SearchEngine::Search *search_engine = new SearchEngine::Search();

    int *arr=engine->getRandomInts();
    std::vector<int> *v = engine->getVectorInt();

    std::cout << "unsorted\n";
    for (int i=0; i < v->size(); i++) {
        std::cout << "i: " << i << "\tvector: " << v->at(i) << std::endl;
    }

    std::cout << "sorting\n";
    //sort_engine->stableSelectionSort(v);
    //sort_engine->optimizedBubbleSort(v);
    //sort_engine->insertionSort(v);
    //sort_engine->mergeSort(v, 0, v->size());
    //sort_engine->quickSort(v, 0, v->size());

    for (int i=0; i < v->size(); i++) {
        std::cout << "i: " << i << "\tvector: " << v->at(i) << std::endl;
    }
    std::cout << "sorted\n";

    srand(time(NULL));
    auto k{v->at(rand()%lim)};
    std::cout << "find: " << k
        <<  "\tindex: " << search_engine->linear(v, k);

    sort_engine->optimizedBubbleSort(v);
    std::cout << "\tsorted index: " << search_engine->sortedLinear(v, k) << std::endl;

    return 0;
}
