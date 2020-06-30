#include <iostream>
#include <set>

using namespace std;

int main(){
    string sentence;
    cout << "String to encode: ";
    getline(cin, sentence);
    set<char> wordSet(sentence.begin(), sentence.end());
    cout << sentence;
    return 0;
}