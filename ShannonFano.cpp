#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

bool comp(pair<char, int> a, pair<char, int> b){
    return a.second < b.second;
}

void shafa(vector<pair<char, int>>::iterator first, vector<pair<char, int>>::iterator last, map<char, string> codeTable){
    int n = distance(first, last);
    cout << n;
}

int main(){
    string sentence;
    cout << "String to encode: ";
    getline(cin, sentence);
    set<char> wordSet(sentence.begin(), sentence.end());
    vector<pair<char, int>> freqTable;
    map<char, string> codeTable;

    for(auto i:wordSet){
        freqTable.push_back(make_pair(i, count(sentence.begin(), sentence.end(), i)));
        codeTable.emplace(i, "");
    }

    sort(freqTable.begin(), freqTable.end(), comp);

    for(auto i:freqTable){
        cout << i.first << " : " << i.second << endl;
    }

    shafa(freqTable.begin(), freqTable.end(), codeTable);


    return 0;
}