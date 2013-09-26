/*
 * file.cpp
 *
 *  Created on: 25 Feb 2012
 *      Author: olibenu
 */

#include "file.h"

namespace rfcd
{

File::File(const string path)
{
	_refresh(path);
}

string File::getPath()
{
	return _path;
};

string File::setPath(const string path)
{
	_path = path;
	return _path;
};

int File::Lines()
{
	return _lines;
}

/*bool File::Rename(time_t stamp)
{
	string oldname = getName();
	ostringstream newname;
	newname << oldname << '.' << stamp;
	return Rename(newname.str());
};

bool File::Update(string newpath)
{
	//rename old path
	if (Rename(time(NULL)) == true)
	{
		//get from path to replace
		//system("wget -O oldpath newpath".c_str());
	}
	return false;
};*/


bool File::_refresh(const string path)
{
	_path = path;
	_file = new ifstream(_path.c_str());
	if (_file->is_open() != true)
	{
		_file = NULL;
		return false;
	}
	//no of lines
	_lines = 0;
	_contents.clear();
	string cur_line;
	//while (_file->eof() == false)
	while (getline(*_file, cur_line))
	{
		//string cur_line;
		//getline(*_file, cur_line);
		_contents.push_back(cur_line);
		_lines += 1;
	}
	_file->close();
	return true;
}


bool File::_rename(const string name)
{

}

}
