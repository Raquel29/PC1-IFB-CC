#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAX_SAMPLES = 200000;
const int MAX_VAL = 10000000;

int main(int argc, char* argv[])
{
	registerValidation(argc, argv);
	int n = inf.readInt(1, MAX_SAMPLES, "n");
	inf.readEoln();
	for(int i = 0; i < n; i++) {
		inf.readInt(1, MAX_VAL, "n_i");
		inf.readEoln();
	}
	inf.readEof();
}
