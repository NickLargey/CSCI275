#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// POST: dictionary is filled from file and size is number of words
void fillDictionary(string* dictionary, int& size);
// POST: word is now lower case with no trailing punctuation
void cleanup(string& word);

int main() {
	// init varible for added words array len
	const int ADDED_LEN = 100;
	// init varible for dict array len
	int dictLen = 25000;
	// init counter for while loop
	int i = 0;
	// init fstream for input file
	fstream poem;
	// init vaiable for user to enter name of input file
	string pTitle;
	// init variable for string stream
	string line;
	// init array for words of dict
	string * words = new string [dictLen];
	// init array for words to add to dict
	string * addedWords = new string [ADDED_LEN];
	// init variable for current search word
	string searchWord;
	// init bool for loop condition
	bool addedFound;
	// init bool for loop condition
	bool found;
	// init variable for user to chose to enter searchWord into dict
	char added;

	// fill dictionary array array and resize dictLen
	fillDictionary(words, dictLen);
	// print length of array
	cout << "The length of the dictionary is " << dictLen << endl;
	// get user input file to check against
	cout << "Enter input file name: ";
	cin >> pTitle;
	poem.open(pTitle);
	// priming read of input file
	getline(poem, line);
	while (!poem.fail()) {
		// create string stream to seperate words of line
		istringstream linestring(line);
		// assign words from string stream to searchWord
		linestring >> searchWord;
		while (!linestring.fail()) {
			// remove punctuation and convert word to lowercase
			cleanup(searchWord);
			// check if word is already in dict
			found = binary_search(words, words + dictLen, searchWord);
			// check if word is a repeat of word already entered
			addedFound = binary_search(addedWords, addedWords + i, searchWord);
			// sort addedWords array
			sort(addedWords, addedWords + i);
			// if word is not in dict and addedWords array, prompt user if they would like to add it
			if (!found && !addedFound) {
				do {
					cout << "Did not find " << searchWord << endl; 
					cout << " Would you like to add it? (y/n) ";
					cin >> added;
					if (added == 'y') {
						addedWords[i] = searchWord;
						i++;
					}
				} while (added != 'y' && added != 'n');
				
			}
			// advance word from string stream
			linestring >> searchWord;
		}
		// get new line of input file
		getline(poem, line);
	}
	// print out words user chose to add
	cout << "List of words added to the dictionary: " << endl;
	for (int k = 0; k < i; k++) {
		cout << addedWords[k] << endl;
		words[dictLen + 1] = addedWords[k];
		dictLen++;
	}

	//print out new length of the dict
	cout << "Dictionary is now length: " << dictLen << endl;

	// delete dynamic arrays to prevent memory leaks
	delete[] words;
	delete[] addedWords;
	return 0;
}

// POST: dictionary is filled from file and size is number of words
void fillDictionary(string* dictionary, int& size) {
	// init variable for dict position
	int i = 0;
	// init variable for input file
	fstream wordList;
	// init variable for word
	string line;

	wordList.open("jumbledwords.txt");
	// loop through words in input file adding them to dict array
	getline(wordList, line);
	while (!wordList.fail()) {
		dictionary[i] = line;
		getline(wordList, line);
		i++;
	}
	// set size to i
	size = i;
	// sort dict for binary_search
	sort(dictionary, dictionary + size);
}

// POST: word is now lower case with no trailing punctuation
void cleanup(string& word) {	
	// init variable for new word format
	string tempWord;
	// loop through chars of word and strip non-alpha chars and convert to lowercase
	for(int i=0; i<word.length(); i++) {
		if (isalpha(word[i])) {
			tempWord += tolower(word[i]);
		}
	}
	// set word to new formatted word
	word = tempWord;
}
