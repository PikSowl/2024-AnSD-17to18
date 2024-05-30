#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::swap;
using std::endl;
using std::vector;

void lab_17(){
 cout << "Sprosi che po proshe";
}

void lab_18(){
    int n = 5;
    int arr[n];
    int sum;

    cout << "Input array:";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Input goal number:";
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
    if(dp[n][sum]) cout << "there is a solution";
    else cout << "there isn't a solution";
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

