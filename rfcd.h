/*
 * rfcd.h
 *
 *  Created on: 17 Feb 2012
 *      Author: olibenu
 */

#ifndef RFCD_H_
#define RFCD_H_

#include <iostream>

#include "getopt_pp/getopt_pp.h"

#include "file.h"
#include "index.h"
#include "rfc.h"

using namespace std;

namespace rfcd
{

const string URL_INDEX = "http://www.rfc-editor.org/in-notes/rfc-ref.txt";
const string URL_RFC = "http://www.rfc-editor.org/rfc/rfc"; //& ---.txt e.g http://www.rfc-editor.org/rfc/rfc4289.txt
const string URL_HOME = ".";

const int	 INDEX_HEADERS = 3;
const string HEADER[INDEX_HEADERS] =
{
		" Number | Obsoleted |        Reference",
		"        |     By    |          ",
		"--------+-----------+-----------------------------------------------------------"
};
const string INDEX_FORMAT		= "RFC0003 |   RFC0010 | Crocker, S., \"Documentation conventions\", RFC 3, April 1969.";
const int INDEX_NUMBER			= 0;
const int INDEX_NUMBER_LENGTH	= 7;
const int INDEX_NUMBER_LENGTH_WORD		= 3;
const int INDEX_NUMBER_LENGTH_NUMBER	= 4;
const int INDEX_OBSOLETED		= 12;
const int INDEX_OBSOLETED_LENGTH= 7;
const int INDEX_REFERENCE		= 22;

}

#endif /* RFCD_H_ */
