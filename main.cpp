#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Party{
    int count = 1;
    string name;
};

int main() {

    int N;
    vector<Party> parties;

    cin >> N;

    for (int i = 0; i < N + 1; ++i) {
        string vote;
        getline(cin, vote);

        bool ex = false;
        int size = parties.size();

        for (int j = 0; j < size; ++j) {
            if (vote == parties[j].name){
                parties[j].count++;
                ex = true;
                break;
            }
        }

        if(!ex){
            Party party;
            party.name = vote;
            parties.push_back(party);
        }
    }

    int size = parties.size();
    for (int i = 1; i < size; ++i) {

        int j = 0, remJ = 0;

        Party buf;

        for (j = i - 1; j >= 0; --j) {
            if (parties[j].count > parties[i].count)
                break;
        }

        ++j;
        buf = parties[i];
        remJ = j;

        for (j = i - 1; j >= remJ; --j){
            parties[j + 1] = parties[j];
        }

        parties[remJ] = buf;
    }

    vector<vector<string>> str;
    int voteCountNow = 9000;
    for (int i = 0; i < size; ++i) {
        if (parties[i].name == "")
            continue;

        if (parties[i].count < voteCountNow){
            voteCountNow = parties[i].count;
            vector<string> vec;
            vec.push_back(parties[i].name);
            str.push_back(vec);
        } else {
            str[str.size() - 1].push_back(parties[i].name);
        }
    }

    size = str.size();
    for (int i = 0; i < size; ++i) {
        sort(str[i].begin(), str[i].end());

        for (auto & j : str[i]) {
            if (!j.empty())
                cout << j << endl;
        }
    }

    return 0;
}