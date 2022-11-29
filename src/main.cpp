// ==========================================
// Created: September 24, 2018
// Jack Lambert
//
// Description: Counts unique words in a file
// outputs the top N most common words
// ==========================================

// Include files
#include "main.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* =====================================================================
Expected Inputs:
    argv[0]: main.cpp
    argv[1]: <number of words>
    argv[2]: <filename.txt>
    argv[3]: <ignorefilename.txt>
  ===================================================================== */
int main(int argc, char* argv[])
{
    /* ===============================================================
     Variable Allocation
     =============================================================== */
    vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE); // Vector of words to ignore
    const char *wordsFileName = argv[2]; //initialize filename as ifstream
    const char *ignoreWordsFileName = argv[3];
    int ArraySize = INITIAL_ARRAY_SIZE;
    wordItem* _list = new wordItem[ArraySize];  // dynamic pointer
    int _length = 0;
    int numDoublings = 0; // Tracks times the size of the array needs to be doubled
    string inputData;
    /* =============================================================== */

    // Checks if command line arguements are valid
    if (argc != 4)
    {
        cout << endl << "Usage: ";
        cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
        cout << endl;
        return 0;
    }
    // Calling function to read in stop words as a vector
    getIgnoreWords(ignoreWordsFileName, vecIgnoreWords);

    // Reading in Text file as a stream
    ifstream HungerGamesFile;
    HungerGamesFile.open(wordsFileName);
    if (HungerGamesFile.is_open())
    {
        cout << endl <<  "Input File Opened" << endl;
        while( HungerGamesFile >> inputData) // Reading in edited Hunger Games file
        {

            if ( _length >= ArraySize)
            {
                /* =======================================================
                 Dynamically allocating more room for array by doubleing the
                 array by creating a temporary array and deleting the old array
                 and reassigning
                 =========================================================*/
                ArraySize = 2*ArraySize;
                numDoublings++; // Counts the amount of array doublings
                wordItem *temp = new wordItem[ArraySize];
                for ( int k = 0; k < _length; k++)
                {
                    temp[k].count = _list[k].count;
                    temp[k].word = _list[k].word;
                }
                delete [] _list;
                _list = temp;
            }

            if ( isStopWord(inputData, vecIgnoreWords) == false )
            {
                for ( int i = 0; i <= _length; i++)
                {
                    if(_list[i].word == inputData )
                    {
                        _list[i].count = _list[i].count +1;
                        _length = _length-1;
                        break;
                    }
                    else if (i == _length)
                    {
                        _list[_length].word = inputData;// storing words in array of structs
                        _list[_length].count = 1;
                    }
                }
                _length++; // Location of word being read in as a stream from file
            }
        }
    }

    /* ================================================
     All Outputs that are required
     =================================================*/
    arraySort(_list, _length);
    printTopN(_list, atoi(argv[1]));

    cout << endl;
    cout << "Array doubled: " << numDoublings << endl;
    cout << endl;
    cout << "Unique non-ignore words: " << _length << endl;
    cout << endl;
    cout <<  "Total non-ignore words: ";
    cout << getTotalNumberNonStopWords(_list, _length) << endl;
    cout << endl;
    return 0;
}


/* ================================================================ */
void getIgnoreWords(const char* ignoreWordFileName, vector<string> &_vecIgnoreWords) // Stores the addesses of stop words in vector
{
    ifstream File;
    string FileData;
    File.open(ignoreWordFileName);

    if( File.is_open())
    {
        cout << endl << "Ignore Words File Opened"<<endl;
        while( getline(File,FileData))
        {
            stringstream ss(FileData);
            string Data;
            ss >> Data;
            _vecIgnoreWords.push_back(Data);
        }
    }
    else
    {
        cout << endl << "Ignore Words File Did Not Open"<<endl;
    }
    File.close();

}

/* ================================================================ */
bool isStopWord(string word, vector<string> &_vecIgnoreWords)
{
    for ( int i = 0; (unsigned)i < _vecIgnoreWords.size(); i++)
    {
        if ( word == _vecIgnoreWords[i] )
        {
            return true;
        }
    }
    return false;
}
/* ================================================================ */
int getTotalNumberNonStopWords(wordItem list[], int length)
{
    int tempNum = 0;
    for ( int i = 0; i < length; i++)
    {
        tempNum = tempNum + list[i].count;
    }
    return tempNum;
}
/* ================================================================ */
void arraySort(wordItem list[], int length)
{
    int temp_count,j; // Temporary var for count
    string temp_word; // Temporary var for word
    for(int i = 0; i < length; i++)
    {
        temp_count = list[i].count;
        temp_word = list[i].word;
        j = i-1; // so while loop will start at second indice

        while (j >= 0 && list[j].count < temp_count) // if left count is less than right
        {
            list[j+1] = list[j]; // Move right count left
            j = j-1;
        }
        list[j+1].count = temp_count;
        list[j+1].word = temp_word;
    }

}
/* ================================================================ */
void printTopN(wordItem wordItemList[], int topN)
{
    cout << endl << "Printing Top " << topN << " Most Frequent Non-ignore Words:" << endl;
    for (int i = 0; i < topN; i++)
    {
        cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
    }
}
/* =====================================================================
 End
 ===================================================================== */



