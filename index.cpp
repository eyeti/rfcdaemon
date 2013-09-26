/*
 * index.cpp
 *
 *  Created on: 26 Mar 2012
 *      Author: olibenu
 */

#include "index.h"

namespace rfcd
{

Index::Index(string path)
{
	//setPath(path);
	_refresh(path);
}

int Index::getCount()
{
	int temp = Lines();
	if (temp != 0)
	{
		return (temp - INDEX_HEADERS);
	}
	else return temp;
}

Rfc Index::getLast() //TODO: last rfc in index
{
	//cout << _contents.back() << endl;
	Rfc current;
	//vector <string>::iterator j = _contents.end();
	//--j;
	//--j;
	//current = Rfc::Parse(*j);
	current = Rfc::Parse(_contents.back());
	return current;
};

Rfc Index::getRfc(int number)
{
	Rfc current;
	for (int i = INDEX_HEADERS + 1; i <= _lines; i++)
	{
		for (vector <string>::iterator j = _contents.begin(); j != _contents.end(); ++j)
		{
			current = Rfc::Parse(*j);
			ostringstream i_to_s;
			i_to_s << number;
			if (current.getNumber() == i_to_s.str())
			{
				return current;
			}
		}
	}
	return current;
};

}
