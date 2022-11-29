#pragma once

// Include files
#include <string>
using namespace std;

/* ===================================================================== */
// Constants
const int STOPWORD_LIST_SIZE = 50;
const int INITIAL_ARRAY_SIZE = 100;

/* ===================================================================== */
// struct to store word + count combinations
struct wordItem
{
    string word;
    int count;
};
/* ===================================================================== */
/* ======================================================================
 * Function name: getIgnoreWords
 * Purpose: read stop word list from file and store into vector
 * @param ignoreWordFile - filename (the file storing ignore/stop words)
 * @param _vecIgnoreWords - store ignore words from the file (pass by reference)
 * @return - none
 * Note: The number of words is fixed to 50
 ========================================================================= */
void getIgnoreWords(const char* ignoreWordFileName, vector<string> &_vecIgnoreWords);

/* ======================================================================
 * Function name: isStopWord
 * Purpose: to see if a word is a stop word
 * @param word - a word (which you want to check if it is a stop word)
 * @param _vecIgnoreWords - the vector type of string storing ignore/stop words
 * @return - true (if word is a stop word), or false (otherwise)
 ========================================================================= */
bool isStopWord(string word, vector<string> &_vecIgnoreWords);

/* ======================================================================
 * Function name: getTotalNumberNonStopWords
 * Purpose: compute the total number of words saved in the words array (including repeated words)
 * @param list - an array of wordItems containing non-stopwords
 * @param length - the length of the words array
 * @return - the total number of words in the words array (including repeated words multiple times)
 ========================================================================= */
int getTotalNumberNonStopWords(wordItem list[], int length);

/* ======================================================================
 * Function name: arraySort
 * Purpose: sort an array of wordItems, decreasing, by their count fields
 * @param list - an array of wordItems to be sorted
 * @param length - the length of the words array
 ========================================================================= */
void arraySort(wordItem list[], int length);

/* ======================================================================
 * Function name: printTopN
 * Purpose: to print the top N high frequency words
 * @param wordItemList - a pointer that points to a *sorted* array of wordItems
 * @param topN - the number of top frequency words to print
 * @return none
 ========================================================================= */
void printTopN(wordItem wordItemList[], int topN);

/* ===================================================================== */
