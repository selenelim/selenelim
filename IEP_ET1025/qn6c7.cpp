#include <iostream>
using namespace std;

#define SIZE 5

// Function prototypes
void enterData(double data[], int s);
void displayData(double data[], int s);
double findMax(double data[], int s);
int countZero(double data[], int s);

int main() {
    int i, zero_count;
    double data[SIZE], max;

    // Enter data
    enterData(data, SIZE);

    // Display data
    displayData(data, SIZE);

    // Find the maximum value
    max = findMax(data, SIZE);
    cout << "The maximum value is: " << max << endl;

    // Count zeros
    zero_count = countZero(data, SIZE);
    cout << "The number of zeros is: " << zero_count << endl;

    return 0;
}

void enterData(double data[], int s) {
    cout << "Enter " << s << " elements: ";
    for(int i = 0; i < s; i++) {
        cin >> data[i];
    }
}

void displayData(double data[], int s) {
    cout << "The elements are: ";
    for(int i = 0; i < s; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

double findMax(double data[], int s) {
    double max = data[0];
    for(int i = 1; i < s; i++) {
        if(data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

int countZero(double data[], int s) {
    int count = 0;
    for(int i = 0; i < s; i++) {
        if(data[i] == 0) {
            count++;
        }
    }
    return count;
}
