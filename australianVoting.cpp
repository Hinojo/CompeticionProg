#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_CANDIDATES = 20;
const int MAX_BALLOTS = 1000;

int numCases, numCandidates;
string candidate = "";

vector<vector<int>> voteArray(MAX_CANDIDATES, vector<int>(MAX_BALLOTS));
int main (){

    cin >> numCases;

    for (int i = 0; i < numCases; i++){
        cin >> numCandidates;

        for (int j = 0; j < numCandidates; j++){
            //cin.ignore();
            //getline(cin, candidate);
            cin >> candidate;
            cout << candidate;
        }
        
    }
}