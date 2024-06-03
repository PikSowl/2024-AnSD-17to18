#include <iostream>
#include <random>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::vector;


#define capacity 10
#define eCount 20


void lab_17(){
    int elements[eCount];
    int stored[eCount][eCount];
    int numStored[eCount] = {};
    int boxes[eCount] = {};
    int best_fit, curent_fit, destination;
    int size = 1;

    std::random_device r;
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution<int> sizeDist(1, int(capacity/1.3));

    for (int & i : elements)
        i = sizeDist(randomEngine);


    cout << '(';
    for (int i = 0; eCount > i + 1; i++)
        cout << elements[i] << ", ";
    cout << elements[eCount - 1] << ')' << endl;

    for (int element : elements){
        best_fit = capacity;
        for (int j = 0; boxes[j] != 0; j++){
            curent_fit = capacity - element - boxes[j];
            if (curent_fit < best_fit && curent_fit >= 0) {
                best_fit = capacity - element - boxes[j];
                destination = j;
            }
        }
        if (best_fit == capacity) {
            for (size = 1; boxes[size-1] != 0; size++){}
            destination = size - 1;
        }
        boxes[destination] +=  element;
        stored[destination][numStored[destination]] = element;
        ++numStored[destination];
    }

    for (int i = 0; i < size; i++){
        cout << "box number "<< i+1 <<" (";
        for (int j = 0; j + 1 < numStored[i]; j++){
            cout << stored[i][j] << ", ";
        }
        cout << stored[i][numStored[i] - 1] << ')' << endl;
    }
    cout << endl << "In total " << size << " boxes";
}

void lab_18(){
    int n = 10;
    int arr[n];
    int sum;

    std::random_device r;
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution<int> d20(1, 20);

    for (int & i : arr){
        i = d20(randomEngine);
        cout << i << ' ';
    }        

    cout << endl << "Input goal number:";
    cin >> sum;

    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    if(dp[n][sum]) cout << "There is a solution";
    else cout << "There isn't a solution";
}

int main() {
    int lab_num;
    cout << "Chose lab number (options: 17, 18):";
    cin >> lab_num;
    while (true) {
        switch (lab_num) {
            case 17:
                lab_17();
                return 0;
            case 18:
                lab_18();
                return 0;
            default:
                cout << "wrong input" << endl << "Chose lab number:";
                cin >> lab_num;
                break;
        }
    }
}
