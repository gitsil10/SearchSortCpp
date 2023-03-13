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



    return 0;
}
