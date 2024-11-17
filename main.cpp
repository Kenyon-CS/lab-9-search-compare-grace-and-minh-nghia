#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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
int bin_search(const vector<int>& keys, int key, int& numComparisons) {
    int left = 0, right = keys.size() - 1;
    numComparisons = 0;

    while (left <= right) {
        numComparisons++;
        int mid = (right + left) / 2;

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

// Enhanced binary search: switches to sequential search if remaining range is < 15
int bin2_search(const vector<int>& keys, int key, int& numComparisons) {
    int left = 0, right = keys.size() - 1;
    numComparisons = 0;

    while (right - left + 1 > 15) { // Switch to sequential search if range size <= 15
        numComparisons++;
        int mid = (right + left) / 2;

        if (keys[mid] == key) {
            return mid;
        } else if (keys[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    for (int i = left; i <= right; ++i) {//sequential search for the remaining range
        numComparisons++;
        if (keys[i] == key) {
            return i; 
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
    cout << setw(10) << "Search" << setw(10) << "Found" << setw(15) << "Seq. search" << setw(15) << "Bin search" << setw(20) << "Enhanced search" << endl;//headers for output
    for (int key : foundKeys) {
        int index, numCmpSeq, numCmpBin, numCmpBin2;
        index = seq_search(keys, key, numCmpSeq);
        index = bin_search(keys, key, numCmpBin);
        index = bin2_search(keys, key, numCmpBin2);
        cout << setw(10) << key << setw(10) << (index != -1 ? keys[index] : -1)<< setw(15) << numCmpSeq << setw(15) << numCmpBin<< setw(20) << numCmpBin2 << endl;
    }
    for (int key : randomKeys) {
        int index, numCmpSeq, numCmpBin, numCmpBin2;
        index = seq_search(keys, key, numCmpSeq);
        index = bin_search(keys, key, numCmpBin);
        index = bin2_search(keys, key, numCmpBin2);
        cout << setw(10) << key << setw(10) << (index != -1 ? keys[index] : -1)<< setw(15) << numCmpSeq << setw(15) << numCmpBin<< setw(20) << numCmpBin2 << endl;
    }

    return 0;
}

