/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5 - P8.2
** File: 	8.2.cpp
** Description: Check the spelling of words against a dictionary.
**
** Author: 	Aaron Montgomery
** Date: 	11/19/2023
** -------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main() {
	
	std::vector<std::string> words; // vector for dictionary words
	
	std::ifstream fs; // file stream object to read text from file
	
	fs.open("words"); // open dictionary file
	
	std::string word;
	
	// read each word in words file into words string vector
	while (fs >> word) {
		words.push_back(word);
	}
	
	fs.close();
	
	fs.open("data"); // open data file
	
	bool isWordExistsInWords; // set to true if data string is found in words string vector
	
	// read each word in data file
	while (getline(fs, word)) {

		isWordExistsInWords = false;

		// loop each word in words string vector
		for (int i = 0; i < words.size(); i++) {
			
			// compare each string read from data file to each word in words string vector
			// set isWordExistsInWords to true if found
			if (word == words[i]) {
				isWordExistsInWords = true;
				break;
			}
		}
		
		// print word if word not in words string vector
		if (!isWordExistsInWords) {
			std::cout << word << std::endl;
		}
	}
	
	fs.close();
	
	return 0;
}
