/*
 * FileHandling.h
 *
 *  Created on: Nov 21, 2019
 *      Author: WindowsUser
 */
//Name: Tristin Proctor
//UCINetID: tproctor
//Description: A Class that holds the values and the functions

#ifndef FILEHANDLING_H_
#define FILEHANDLING_H_
#include <string>
using namespace std;

class Start {
	private:
		int row;
		int height;
		string slate;
		string fName;
		string addOn = ".txt";
		string plus;
		string sName;
		char newName;
	public:
		void run();
		string namingFile();
		void check(string checking);
		int pyramidHeight();
		void fileTransfer(int row, string fileName);
};

#endif /* FILEHANDLING_H_ */