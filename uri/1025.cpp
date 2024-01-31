#include "bits/stdc++.h"
#include<iostream>


using namespace std;

#define MAX 65

// https://www.beecrowd.com.br/judge/pt/problems/view/1025
int main() {
    unsigned int Q, N, caseCount(0);

    cin >> Q >> N;
    while (Q != 0 || N != 0) {
        cout << "CASE# " << caseCount << ":" << endl;
        vector<int> marbles{(int) Q}, consults{(int) N};

        for (int i = 0; i < N; ++i) {
            cin >> marbles[i];
        }

        std::sort(marbles.begin(), marbles.end());

        for (int i = 0; i < Q; ++i) {
            cin >> consults[i];
        }


//        int current;
        // TODO: try to use current idea of sorted consults
        vector<pair<int, int>> hits;
        int count(0);
//        std::sort(consults.begin(), consults.end(), greater<>());
        for (auto i: marbles) {
            for (int j = 0; j < Q; ++j) {
                if (i == j) {
                    hits.emplace_back(j, i);
                    consults.erase(j);
                    break;
                }
            }
            count++;
        }

        for (auto hit: hits) {
            cout << hit.first "" << ""
        }


        cin >> Q >> N;
    }

    return 0;
}
