/*
 * main.cpp
 *
 *  Created on: 13 Apr 2012
 *      Author: olibenu
 */

#include "rfcd.h"

//using namespace GetOpt;

int main(int argc, char* argv[])
{
	cout << "RFC Daemon by olibenu (sf.net/users/olibenu)" << endl;

	if (argc == 1) //only 1 rfcd arg
	{
		//show help and do default
		/*
		 *  --object/-o		--action/-a		--more/-,
		 *
		 * 	index			info			-n <name>
		 * 	index			list			-n <name>
		 * 	index			create			-n <name>
		 *  index			add				-n <number>
		 *
		 * 	rfc				info			-n <number>
		 * 	rfc				obsolete		-n <number>
		 * 	rfc				get				-n <number>
		 *  rfc				list
		 */
		cout << "rfcd -o index -a info" << endl; //show info of an index (default is the rfceditor)

	}

	GetOpt::GetOpt_pp options(argc, argv);

	string object;
	//		   GetOpt::Option('short', "long", variable, "default" );
	options >> GetOpt::Option('o', "option", object, "index" );

	string action;
	options >> GetOpt::Option('a', "action", action, "info" );



	rfcd::Index* test = new rfcd::Index("/home/olibenu/eBooks/Rfc/rfc-ref.txt");
	//test->setParent("http://www.rfc-editor.org/in-notes/rfc-ref.txt");

	cout << "[" << test->getCount() << "] in ["<< test->getPath() << "]" << endl;

		rfcd::Rfc rfc_2616 = test->getRfc(2616);
	cout << "[" << rfc_2616.getNumber() << "] is [" << rfc_2616.getTitle() << "]" << endl;

	rfcd::Rfc rfc = test->getRfc(1392);
	cout << "[" << rfc.getNumber() << "] is [" << rfc.getTitle() << "]" << endl;

	rfc = test->getRfc(2119);
	cout << "[" << rfc.getNumber() << "] is [" << rfc.getTitle() << "]" << endl;

	rfcd::Rfc last_rfc = test->getLast();
	cout << "[" << last_rfc.getNumber() << "] is [" << last_rfc.getTitle() << "]" << endl;

	delete test;
	return 0;
}


