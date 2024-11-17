#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

double FindMedian(vector<int>& numbers) {
    size_t size = numbers.size();
    if (size == 0) {
        throw invalid_argument("Empty data set");
    }

    sort(numbers.begin(), numbers.end());                           // Sort the numbers to find the median

    
    if (size % 2 == 1) {                                            // if there is an odd number of elements it returns median
        return numbers[size / 2];
    }
    else {
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;   // if there is an even number of elements it returns average of the 2 middle numbers
    }
}

vector<int> readNumbersFromFile(const string& filename) {           // file name: numberstxt
    vector<int> numbers;                                            // list of numbers in the file: 1,10,12,23,34,45,56,67,78,89,90
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Could not open file");
    }

    string line;
    while (getline(file, line, ',')) {
        stringstream ss(line);
        int number;
        ss >> number;
        numbers.push_back(number);
    }

    file.close();
    return numbers;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    try {
        vector<int> numbers = readNumbersFromFile(filename);        // Read numbers from the file


        double median = FindMedian(numbers);                        // finds and displays the median
        cout << "The median is: " << median << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
