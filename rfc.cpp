/*
 * rfc.cpp
 *
 *  Created on: 7 Apr 2012
 *      Author: olibenu
 */

#include "rfc.h"

namespace rfcd
{
string Rfc::getNumber()
{
	return _no;
};

string Rfc::getObsoleted()
{
	return _obsoleted;
};

string Rfc::getAuthor()
{
	return _author;
};

string Rfc::getTitle()
{
	return _title;
};

string Rfc::getDate()
{
	return _date;
};

Rfc Rfc::Parse(string line)
{
	Rfc returned;
	returned._raw_line = line;
	//set defaults
	returned._no = line.substr(
			(INDEX_NUMBER + INDEX_NUMBER_LENGTH_WORD),
			INDEX_NUMBER_LENGTH_NUMBER
			);
	returned._obsoleted = line.substr(
					(INDEX_OBSOLETED + INDEX_NUMBER_LENGTH_WORD),
					INDEX_NUMBER_LENGTH_NUMBER
					);
	string _reference;
	_reference = line.substr(INDEX_REFERENCE, line.length() - INDEX_REFERENCE);
		int reference_length = _reference.length();
		int appos_pos = _reference.find('\"'); //find first "
	returned._author = _reference.substr(0, appos_pos - 2); //-2 removes ', '
		int first_appos_pos = _reference.find('\"');
		int last_appos_pos = _reference.find_last_of('\"');
	returned._title = _reference.substr(first_appos_pos + 1, last_appos_pos - first_appos_pos - 1); //+1&-1 removes "
		int last_comma_pos = _reference.find_last_of(',');
	returned._date = _reference.substr(last_comma_pos + 2, reference_length - (last_comma_pos + 2) - 2); //+2 removes ', ', -1 removes .
	return returned;
};

}


