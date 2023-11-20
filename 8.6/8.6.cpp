/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5 - P8.6
** File: 	8.6.cpp
** Description: Read worldpop.txt file, format the country name, and sum the population.
**
** Author: 	Aaron Montgomery
** Date: 	11/19/2023
** -------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	
	ifstream fs;
	
	fs.open("how_to_1\\worldpop.txt");
	
	char character;
	char nextCharacter;
	string countryName;
	double population = 0;
	string tempPopulation;

	// get each character from worldpop.txt file
	while (fs.get(character)) {
		
		if (character != ' ' && character != '\t') {
			
			countryName += character;
		}

		else {
			nextCharacter = fs.get();
			if (nextCharacter != ' ' && nextCharacter != '\t') {

				// if next char numerical
				// unget
				// read number
				if (isdigit(*(&nextCharacter))) {
					fs.unget();
					getline(fs, tempPopulation);

					// exclude European Union
					if (countryName != "European Union") {
						population += stoi(tempPopulation);
					}
					
					countryName = "";
				}
				
				else {
					countryName += character;
					fs.unget();
				}
			}

			else {
				fs.unget();
			}
		}
	}
	
	cout << "Total Population (except European Union): " << population << endl;
	return 0;
}
