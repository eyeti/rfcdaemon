/*
 * file.h
 *
 *  Created on: 12 Feb 2012
 *      Author: olibenu
 */

#ifndef FILE_H_
#define FILE_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace rfcd
{

///
/// File I/O operations
///
class File
{
public:
	File(const string path="rfc-ref.txt");
	string getPath();
	string setPath(const string path);

	int Lines();
	/*bool Rename(string newname);
	bool Rename(time_t stamp);*/

protected:
	//string _readline(int index); //TODO: make searches faster
	bool _refresh(const string path);
	bool _rename(const string name);
	vector <string> _contents;
	int _lines;

private:
	const static char _seperator = '/';
	ifstream* _file;
	string _path;
};
}

#endif /* FILE_H_ */
