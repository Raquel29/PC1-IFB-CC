#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char * argv[])
{
	setName("Checker for S or N case insensitive");
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();

	for(int i = 0; i < n; i++) {
		string ansString = ans.readWord();
		string oufString = ouf.readWord();
		if(ansString.size() > 1 || oufString.size() > 1)
			quitf(_pe, "expected char, got string instead");

		if(upperCase(ansString) != upperCase(oufString))
			quitf(_wa, "answer is incorrect");
	}
	quitf(_ok, "answer ok");
}
