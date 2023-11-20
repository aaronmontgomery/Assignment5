/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5 - P8.10
** File: 	8.10.cpp
** Description: Encrypt or decrypt using character pairs in a playfair cipher.
**
** Author: 	Aaron Montgomery
** Date: 	11/19/2023
** -------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>

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

            if (isInputInSymbols) {
                //count[index] = ++count[index];
            }

            else {
                symbols.push_back(input[i]);
                //count.push_back(1);
            }
        }
    }

    return symbols;
}

// swap letter pairs to encrypt or decrypt the board
void encryptDecrypt(vector<vector<char>>& board) {
    
    char tempChar = board[0][2];
    board[0][2] = board[0][4];
    board[0][4] = tempChar;

    tempChar = board[2][2];
    board[2][2] = board[2][4];
    board[2][4] = tempChar;
}

int main() {
    
    const vector<char> lettersOfAlphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' }; // 'J'
    
    cout << "Input: ";
    
    //string keyword = "HELLO";
    string keyword;
    cin >> keyword;

    //vector<char> keywordVector = { 'H', 'E', 'L', 'L', 'O' };
    vector<char> keywordVector;
    for (int i = 0; i < keyword.length(); i++) {
        keywordVector.push_back(keyword[i]);
    }

    // get string with distinct characters
    keywordVector = getStringDistinct(keywordVector, keywordVector.size());
    
    string keywordModified = "";
    for (int i = 0; i < keywordVector.size(); i++) {
        keywordModified += keywordVector[i];
    }
    
    // append letterOfAlphabet to keywordModified
    bool isInKeywordModified;
    for (int i = 0; i < lettersOfAlphabet.size(); i++) {
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
    
    // fill 5 X 5 square
    int count = 0;
    vector<vector<char>> board;
    for (int i = 0; i < 5; i++) {
        
        vector<char> inner;
        
        int k = count + 5;
        for (int j = count; j < k; j++) {
            inner.push_back(keywordModified[count]);
            count++;
        }
        
        board.push_back(inner);
    }
    
    // swap letters
    encryptDecrypt(board);
    encryptDecrypt(board);
    return 0;
}
