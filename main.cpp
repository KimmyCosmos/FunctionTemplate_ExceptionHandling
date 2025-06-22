#include <iostream>
#include <vector>
#include <stdexcept> // for std::out_of_range
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Finds the index of the minimum element in the unsorted portion of the vector
template<typename T>
unsigned min_index(const vector<T>& vals, unsigned index) {
    unsigned minIdx = index;
    for (unsigned i = index + 1; i < vals.size(); ++i) {
        if (vals[i] < vals[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

// Performs selection sort on the vector
template<typename T>
void selection_sort(vector<T>& vals) {
    for (unsigned i = 0; i < vals.size(); ++i) {
        unsigned minIdx = min_index(vals, i);
        if (i != minIdx) {
            T temp = vals[i];
            vals[i] = vals[minIdx];
            vals[minIdx] = temp;
        }
    }
}

// Returns element at index, throws if out of range
template<typename T>
T getElement(const vector<T> vals, int index) {
    if (index < 0 || index >= static_cast<int>(vals.size())) {
        throw std::out_of_range("Index is out of range.");
    }
    return vals.at(index);
}

// Provided: generates vector of random length and chars
vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++) {
        vals.push_back(c);
        c++;
    }
    return vals;
}

// Provided and slightly modified: main function with try/catch block
int main(){
    // Part B
    srand(static_cast<unsigned>(time(0)));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;

    while (--numOfRuns >= 0) {
        cout << "Enter a number: ";
        cin >> index;

        try {
            curChar = getElement(vals, index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch (const std::out_of_range& excpt) {
            cout << "out of range exception occured" << endl;
        }
    }

    return 0;
}
