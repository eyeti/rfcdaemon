/*
 * index.h
 *
 *  Created on: 12 Feb 2012
 *      Author: olibenu
 */

#ifndef INDEX_H_
#define INDEX_H_

#include "rfcd.h"

using namespace std;

namespace rfcd
{

class File;

class Rfc;

class Index : public File
{
public:
	Index(const string path);
	int getCount();
	Rfc getLast();
	Rfc getRfc(int number);

	//info: url, rfc count, last rfc
	//list: show all indexes we track (rfc-list = index text in raw form)
	//create: create folder (name), create rfc-ref.txt, add raw header
	//add: add an rfc to index

private:

};
}

#endif /* INDEX_H_ */
