/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5 - P8.6
** File: 	8.6.cpp
** Description: Enter brief project description here.
**
** Author: 	Aaron Montgomery
** Date: 	11/19/2023
** -------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <fstream>

int main() {
	
	std::ifstream fs;
	
	fs.open("how_to_1\\worldpop.txt");
	
	std::string countryData;
	
	while (fs >> countryData) {
		std::cout << countryData << std::endl;
	}

	return 0;
}
