#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    string token;
    char aChar;
    stringstream ss;
    string freqOrder;

    //Read all input from standard input into a single stringstream
    while (cin.get(aChar)) 
    {
        ss << aChar;
    }

    //Prepare to process the input as if reading from a file
    map<string, int> frequencyMap;
    map<int, string> orderedFrequencies;
    map<string, int> sortedMap;
    int uniqueTokenCount = 0;

    //Simulate file reading logic exactly as in the original program
    string contents = ss.str();
    stringstream simulatedFile(contents);

    while (!simulatedFile.eof()) 
    {
        do
        {
            simulatedFile.get(aChar);
        } 
        while ((!simulatedFile.eof()) && ((aChar == ' ') || (aChar == '\n')));

        if (!simulatedFile.eof())
        {
            token.clear();
            while ((!simulatedFile.eof()) && ((aChar != ' ') && (aChar != '\n')))
            {
                token += aChar;
                simulatedFile.get(aChar);
            }

            //Storing tokens alongside their frequencies in the map
            if (!frequencyMap[token])
            {
                frequencyMap[token] = 0;
                uniqueTokenCount++;
            }
            frequencyMap[token]++;
        }
    }

    //Creating iterator to go through map
    map<string, int>::iterator itr;
    int prevMax = 0;

    for (int i = 0; i < uniqueTokenCount; i++)
    {
        int maxFreq = 0;

        //Iterating through map
        for (itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++)
        {
            //Finding token with highest frequency
            if (maxFreq < itr->second)
            {
                freqOrder = itr->first;
                maxFreq = itr->second;
            }
        }

        //Putting highest frequency token in a different sorted map
        orderedFrequencies.insert(pair<int, string>(i, freqOrder));
        sortedMap.insert(pair<string, int>(freqOrder, i));

        //Removing token from map so it looks for second highest frequency
        frequencyMap[freqOrder] = 0;
        prevMax = maxFreq;
    }

    //Outputting
    for (int i = 0; i < orderedFrequencies.size(); i++)
    {
        cout << orderedFrequencies[i] << " ";
    }
    cout << endl;
    cout << "**********" << endl;

    //Second pass to output token positions based on frequency rank
    simulatedFile.clear();                                      //Clear flags
    simulatedFile.seekg(0, ios::beg);                           //Rewind simulated file

    while (!simulatedFile.eof())
    {
        do
        {
            simulatedFile.get(aChar);
        } 
        while ((!simulatedFile.eof()) && ((aChar == ' ') || (aChar == '\n')));


        if (!simulatedFile.eof())
        {
            token.clear();

            while ((!simulatedFile.eof()) && ((aChar != ' ') && (aChar != '\n')))
            {
                token += aChar;
                simulatedFile.get(aChar);
            }

            cout << sortedMap[token] + 1 << " ";
        }
    }

    cout << endl;
    return 0;
}

