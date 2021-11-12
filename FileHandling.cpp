/*
 * FileHandling.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: WindowsUser
 */
//Name: Tristin Proctor
//UCINetID: tproctor
//Description: Functions that each perform a different task: User enters a file name,
//checking if there's a file name with the same name as the user's input,
//inputing the pyramid's height and transferring the output to the user's text file.

#include "FileHandling.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

void Start::run() {
	slate = namingFile();
	check(slate);
	height = pyramidHeight();
	fileTransfer(height, slate);
}
string Start::namingFile() {
	cout << "Enter File Name: ";
	cin >> fName;
	sName = fName + addOn;
	plus = "src/" +fName + addOn;
	return plus;
}
void Start::check(string checking) {
	char newName[checking.size() + 1];
	strcpy(newName, checking.c_str());
	if (remove(newName) != 0) {
		perror("File does not exist, creating new file");
	} else {
		puts("File exists, overriding file");
	}
}
int Start::pyramidHeight() {
	cout << endl << "Pyramid Level Height: ";
	cin >> row;
	row = row + 1;
	return row;
}
void Start::fileTransfer(int row, string fileName) {
	ofstream file;
	file.open(fileName);
	for (int i = 1, j = 0, k = 0; i <= row; i++, j = 0, k = 0) {
		file << endl;
		for (int a = 1; a <= row - i; a++) {
			file << " ";
		}
		if (i != row) {
			while (j != 2 * i - 1) {
				file << "-";
				j++;
			}
		} else {
			file << " ";
			while (j != 2 * i - 3) {
				file << "-";
				j++;
			}
		}
		file << endl;
		for (int b = 2; b <= row - i; b++) {
			file << " ";
		}
		if (i != row) {
			if (i == 1) {
				while (k != 2 * i) {
					file << "| ";
					k++;
				}
			} else {
				while (k != i + 1) {
					file << "| ";
					k++;
				}
			}
		}
	}
	file.close();
	cout << endl << "Check " << sName;
}
