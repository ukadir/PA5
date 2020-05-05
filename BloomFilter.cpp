#include "BloomFilter.h"
#include "HashFunctions.h"

/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    /* YOUR CODE HERE */
    for(unsigned int i = 0; i < this->K; i++) {
        unsigned int hash = hash_functions[0](s);
        int index = hash % this->M;
        this->bits[index] = true;
    }
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    /* YOUR CODE HERE */
    for(unsigned int i = 0; i < this->K; i++) {
        unsigned int hash = hash_functions[0](s);
        int index = hash % this->M;
        if(this->bits[index] == false)
            return false;
    }
    return true;
}
