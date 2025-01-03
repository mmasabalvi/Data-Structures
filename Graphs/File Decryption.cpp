#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    stringstream ss;
    char aChar;
    while (cin.get(aChar)) ss << aChar;
    string contents = ss.str();
    stringstream simulatedFile(contents);
    map<string, int> frequencyMap; map<int, string> orderedFrequencies; map<string, int> sortedMap;
    string token, freqOrder;
    int uniqueTokenCount = 0;
    while (!simulatedFile.eof()) {
        do { simulatedFile.get(aChar); } while ((!simulatedFile.eof()) && ((aChar == ' ') || (aChar == '\n')));
        if (!simulatedFile.eof()) {
            token.clear();
            while ((!simulatedFile.eof()) && ((aChar != ' ') && (aChar != '\n'))) {
                token += aChar; simulatedFile.get(aChar);
            }
            if (!frequencyMap[token]) { frequencyMap[token] = 0; uniqueTokenCount++; }
            frequencyMap[token]++;
        }
    }
    for (int i = 0; i < uniqueTokenCount; i++) {
        int maxFreq = 0;
        for (auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
            if (maxFreq < itr->second) { freqOrder = itr->first; maxFreq = itr->second; }
        }
        orderedFrequencies.insert({ i,freqOrder });
        sortedMap.insert({ freqOrder,i });
        frequencyMap[freqOrder] = 0;
    }
    stringstream output;
    for (int i = 0; i < (int)orderedFrequencies.size(); i++) output << orderedFrequencies[i] << " ";
    output << "\n**********\n";
    simulatedFile.clear(); simulatedFile.seekg(0, ios::beg);
    while (!simulatedFile.eof()) {
        do { simulatedFile.get(aChar); } while ((!simulatedFile.eof()) && ((aChar == ' ') || (aChar == '\n')));
        if (!simulatedFile.eof()) {
            token.clear();
            while ((!simulatedFile.eof()) && ((aChar != ' ') && (aChar != '\n'))) {
                token += aChar; simulatedFile.get(aChar);
            }
            output << sortedMap[token] + 1 << " ";
        }
    }
    output << "\n";
    string outStr = output.str();
    stringstream simulatedFile2(outStr);
    string token2; char aChar2; int location = 0, totalCount = 1; map<int, int> decodingLocations; map<int, string> sortedMap2; bool before = true;
    while (!simulatedFile2.eof()) {
        do { simulatedFile2.get(aChar2); } while ((!simulatedFile2.eof()) && ((aChar2 == ' ') || (aChar2 == '\n')));
        if (!simulatedFile2.eof()) {
            if (before) {
                token2.clear();
                while ((!simulatedFile2.eof()) && ((aChar2 != ' ') && (aChar2 != '\n'))) {
                    token2 += aChar2; simulatedFile2.get(aChar2);
                    if (aChar2 == '*') {
                        for (int i = 0; i < 7; i++) { simulatedFile2 >> aChar2; }
                        before = false; totalCount = 1; break;
                    }
                }
                if (before) { sortedMap2.insert({ totalCount,token2 }); totalCount++; }
            }
            else {
                while (simulatedFile2 >> location) { decodingLocations.insert({ totalCount,location }); totalCount++; }
            }
        }
    }
    for (int i = 1; i < totalCount - 1; i++) cout << sortedMap2[decodingLocations[i]] << " ";
    cout << sortedMap2[decodingLocations[totalCount - 1]];
    return 0;
}
