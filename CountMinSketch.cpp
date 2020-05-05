#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"
#include <iostream>
#include <algorithm>

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    /* YOUR CODE HERE */
    for(unsigned int i = 0; i < this->K; i++) {
        unsigned int hash = hash_functions[i](s);
        int index = hash % this->M;
        this->count[i][index]++;
    }
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    /* YOUR CODE HERE */
    vector<unsigned int> counts;
    for(unsigned int function = 0; function < this->K; function++) {
        unsigned int hash = hash_functions[function](s);
        int index = hash % this->M;
        counts.push_back(this->count[function][index]);
    }

    unsigned int min = *min_element(counts.begin(), counts.end());
    return min;
}
