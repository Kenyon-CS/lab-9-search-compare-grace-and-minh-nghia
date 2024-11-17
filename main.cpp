#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Sequential search
int seq_search(vector<int> &keys, int key, int &numCmp) {
    numCmp = 0;
    for (size_t i = 0; i < keys.size(); ++i) {
        numCmp++;
        if (keys[i] == key) {
            return i; // returns the index of the key when it is found
        }
    }
    return -1; // returns -1 if key isn't found in the search
  
}

// Sequential search with start and stop range
int seq_search(vector<int> &keys, int key, int start, int stop, int &numCmp) {

}

// Binary search
int bin_search(vector<int> &keys, int key, int &numCmp) {

}

// Enhanced binary search: switches to sequential search if remaining range is < 15
int bin2_search(vector<int> &keys, int key, int &numCmp) {

}

// Test the search algorithms
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create a vector of 100,000 integers
 
    // Sort the vector using STL sort

    // Generate 50 random numbers from the data (guaranteed to be in the array)

    // Generate 50 random numbers (may or may not be in the array)

    // Test each search algorithm, output results

    return 0;
}
