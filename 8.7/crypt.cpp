/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5 - P8.7
** File: 	crypt.cpp
** Description: Use an encryption key to decrypt text from a file.
**
** Author: 	Aaron Montgomery
** Date: 	11/19/2023
** -------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

// function from Assignment 4
// modified to work with vector<char>
vector<char> getStringDistinct(vector<char> input, int input_size) {

    //int input_array_current_size = 5;
    //int input_array[5] = { 1, 0, 2, 0, 2 };
    vector<char> symbols;
    //vector<int> count;

    for (int i = 0; i < input_size; i++) {
        if (symbols.size() == 0) {
            symbols.push_back(input[i]);
            //count.push_back(1);
        }

        else {
            bool isInputInSymbols = false;
            int index = -1;
            for (int j = 0; j < input_size; j++) {
                if (symbols.size() > j && input[i] == symbols[j]) {
                    isInputInSymbols = true;
                    index = j;
                    break;
                }

            }

            //if (isInputInSymbols) {
                //count[index] = ++count[index];
            //}

            //else {
                //symbols.push_back(input[i]);
                //count.push_back(1);
            //}
        }
    }
    
    return symbols;
}

int main(int argc, char* argv[]) {
	
	// convert keywordArgument to string for comparison
    string keywordArgument = argv[3];

	// all letters of alphabet
    vector<char> lettersOfAlphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	if (keywordArgument != "-k") {

        // if keyword supplied
        
        // convert string keywordArgument to vector<char>
        vector<char> input;
        for (int i = 2; i < keywordArgument.size(); i++) {
            input.push_back(keywordArgument[i]);
        }
        
        // convert vector<char> to string keyword
        vector<char> keywordVector = getStringDistinct(input, input.size());
        string keyword = "";
        for (int i = 0; i < keywordVector.size(); i++) {
            keyword += keywordVector[i];
        }

		// append the other letters of the alphabet in reverse order
        string keywordModified = keyword;
        bool isInKeywordModified;
        for (int i = lettersOfAlphabet.size() - 1; i >= 0; i--) {
            isInKeywordModified = false;
            for (int j = 0; j < keyword.size(); j++) {
                if (keyword[j] == lettersOfAlphabet[i]) {
                    isInKeywordModified = true;
                    break;
                }
            }

            if (!isInKeywordModified) {
                keywordModified += lettersOfAlphabet[i];
            }
        }

        // decrypt encrypt.txt
		
        fstream fs;
		
		fs.open("encrypt.txt");
		
        string in;
		
		// read encrypted string from encrypt.txt
        fs >> in;

        // determine the index of each character
        vector<int> indices;
        for (int i = 0; i < in.length(); i++) {

            for (int j = 0; j < keywordModified.length(); j++) {
                if (in[i] == keywordModified[j]) {
                    indices.push_back(j);
                }
            }
        }

        fs.close();

        // build string using correct indices of characters of the alphabet
        string decryptedValue = "";
        for (int i = 0; i < indices.size(); i++) {
            decryptedValue += lettersOfAlphabet[indices[i]];
        }

        // write decypted string to output.txt
        fs.open("output.txt");
        fs << decryptedValue;
        fs.close();
    }

	else {

		// error keyword not supplied
        cout << "Error: keyword not supplied" << endl;
	}
	
	return 0;
}

// crypt -d -kFEATHER encrypt.txt output.txt
