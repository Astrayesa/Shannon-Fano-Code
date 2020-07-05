#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

bool comp(pair<char, int> a, pair<char, int> b){
    return a.second < b.second;
}

// int freqSum(vector<pair<char, int>>::iterator first, vector<pair<char, int>>::iterator last){
//     int sum = 0;
//     for(auto i = first; i != last; i++){
//         sum += i->second;
//     }
//     return sum;
// }

vector<pair<char, int>>::iterator pivElm(vector<pair<char, int>>::iterator first, vector<pair<char, int>>::iterator last){
    vector<int> val;
    int cnt = 0;
    for(auto i = first; i != last; i++){
        val.push_back(cnt += i->second);
    }
    int idx = distance(val.begin(), upper_bound(val.begin(), val.end(), (*val.rbegin())/2));
    auto pivot = first + idx;
    return pivot;
}

void addSymbol(vector<pair<char, int>>::iterator first, vector<pair<char, int>>::iterator last, map<char, string> &codeTable, string s){
    for(auto i = first; i != last; i++){
        codeTable[i->first].append(s);
    }
}

void shafa(vector<pair<char, int>>::iterator first, vector<pair<char, int>>::iterator last, map<char, string> &codeTable){
    int dis = distance(first, last);
    if(dis > 1){
        auto pivotElement = pivElm(first, last);
        addSymbol(first, pivotElement, codeTable, "0");
        shafa(first, pivotElement, codeTable);
        addSymbol(pivotElement, last, codeTable, "1");
        shafa(pivotElement, last, codeTable);
    }
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

    for(auto i:codeTable){
        cout << i.first << " : " << i.second << endl;
    }

    return 0;
}