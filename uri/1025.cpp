#include "bits/stdc++.h"
#include<iostream>


using namespace std;

#define MAX 65

// https://www.beecrowd.com.br/judge/pt/problems/view/1025
int main() {
    unsigned int Q, N, caseCount(1);
    typedef pair<int, int> pairs;
    typedef tuple<bool, int, int> triple;


    vector<pairs> all_q_n;
    vector<vector<triple>> all_hits;


    cin >> N >> Q;
    while (Q != 0 || N != 0) {
        vector<int> marbles, consults;
        marbles.reserve(N);
        consults.reserve(Q);

        for (int i = 0; i < N; ++i) {
            int temp;
            cin >> temp;
            marbles.push_back(temp);
        }

        std::sort(marbles.begin(), marbles.end());

        for (int i = 0; i < Q; ++i) {
            int temp;
            cin >> temp;
            consults.push_back(temp);
        }

        cout << "CASE# " << caseCount << ":" << endl;

        // TODO: try to use current idea of sorted consults
//        int current;
//        std::sort(consults.begin(), consults.end(), greater<>());
        vector<triple> hits;
        for (int i = 0; i < Q; ++i) {
            int consult = consults[i];

            bool missed = true;
            for (int j = 0; j < N; ++j) {
                int marble = marbles[j];

                if (consult == marble) {
                    hits.emplace_back(true, consult, j + 1);
                    missed = false;
                    break;
                }
            }
            if (missed) {
                hits.emplace_back(false, consult, 0);
            }
        }

//        all_hits.push_back(std::move(hits));
//        all_q_n.emplace_back(Q, N);
        for (auto &hit: hits) {
            cout << get<1>(hit);
            if (get<0>(hit)) cout << " found at " << get<2>(hit) << endl;
            else cout << " not found" << endl;
        }

        cin >> N >> Q;
        caseCount++;
    }


//    for (int i = 0; i < all_q_n.size(); i++) {
//        auto &hits = all_hits[i];
//
//        cout << "CASE# " << i << ":" << endl;
//        for (auto &hit: hits) {
//            cout << hit.first << " found at " << hit.second << endl;
//        }
//
//    }

    return 0;
}
