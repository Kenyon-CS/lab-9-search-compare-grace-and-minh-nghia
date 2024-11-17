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
    numCmp = 0;
    for (int i = start; i <= stop; ++i) {
        numCmp++;
        if (keys[i] == key) {
            return i; // returns the index of where the key was found
        }
    }
    return -1; // returns if the search didn't find the key

}

// Binary search
int bin_search(vector<int> &keys, int key, int &numCmp) {
    int left = 0, right = keys.size() - 1;
    numCmp = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        numCmp++;
        if (keys[mid] == key) {
            return mid; // returns index once key is found
        } else if (keys[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; //returns if key is never found

}

// Enhanced binary search: switches to sequential search if remaining range is < 15
int bin2_search(vector<int> &keys, int key, int &numCmp) {
    int left = 0, right = keys.size() - 1;
        numCmp = 0;

        while (left <= right) {
            if (right - left + 1 < 15) { // Switch to sequential search
                return seq_search(keys, key, left, right, numCmp);
            }

            int mid = left + (right - left) / 2;
            numCmp++;
            if (keys[mid] == key) {
                return mid; 
            } else if (keys[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; 
}

// Test the search algorithms
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create a vector of 100,000 integers
    vector<int> keys(100000);
    for (int &key : keys) {
        key = rand() % 10000000;
    }
 
    // Sort the vector using STL sort
    sort(keys.begin(), keys.end());

    // Generate 50 random numbers from the data (guaranteed to be in the array)
    vector<int> foundKeys(50);
    for (int &key : foundKeys) {
        key = keys[rand() % keys.size()];
    }

    // Generate 50 random numbers (may or may not be in the array)
    vector<int> randomKeys(50);
    for (int &key : randomKeys) {
        key = rand() % 10000000;
    }

    // Test each search algorithm, output results

    return 0;
}
