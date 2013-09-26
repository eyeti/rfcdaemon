/*
 * rfc.h
 *
 *  Created on: 12 Feb 2012
 *      Author: olibenu
 */

#ifndef RFC_H_
#define RFC_H_

#include "rfcd.h"

using namespace std;

namespace rfcd
{

class File;

class Rfc : public File
{
public:
	string/*int*/ getNumber();
	string/*int*/ getObsoleted();
	string getAuthor();
	string getTitle();
	string getDate();
	static Rfc Parse(string line);

protected:

private:
	string _raw_line;
	string/*int*/ _no, _obsoleted;
	string _author, _title, _date;
};
}

#endif /* RFC_H_ */
