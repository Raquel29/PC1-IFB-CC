#include <iostream>
#include <sstream>
#include <vector>

#include "testlib.h"

using namespace std;
using ll = long long;

const int MAX_SAMPLES = 200000;
const int MAX_VAL = 10000000;

const vector<int> arrojados = {2, 3, 5, 7, 23, 29, 31, 37, 53, 59, 71, 73, 79, 233, 239, 293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797, 2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793, 3797, 5939, 7193, 7331, 7333, 7393, 23333, 23339, 23399, 23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393, 59399, 71933, 73331, 73939, 233993, 239933, 293999, 373379, 373393, 593933, 593993, 719333, 739391, 739393, 739397, 739399, 2339933, 2399333, 2939999, 3733799, 5939333, 7393913, 7393931, 7393933};

vector<string> sample_tests
{
	// AC
	"11\n1\n2\n7\n10\n11\n22\n23\n123\n173\n233\n2393\n"
};

vector<string> manual_tests()
{
	vector<string> tests;

	const int n = (int) arrojados.size();

	//gerando todos os primos arrojados
	ostringstream os1;
	os1 << n << '\n';
	for(auto i : arrojados)
		os1 << i << '\n';
	tests.push_back(os1.str());

	//gerando tle (maior numero primo menor que 1e7 = 9999991)
	ostringstream os2;
	os2 << MAX_SAMPLES << '\n';
	for(int i = 0; i < MAX_SAMPLES; i++)
		os2 << "9999991\n";
	tests.push_back(os2.str());

	//gerando tle (maior primo arrojado)
	ostringstream os22;
	os22 << MAX_SAMPLES << '\n';
	for(int i = 0; i < MAX_SAMPLES; i++)
		os22 << arrojados[n - 1] << "\n";
	tests.push_back(os22.str());

	//gerando tle (maior numero possivel do testcase = 1e7)
	ostringstream os3;
	os3 << MAX_SAMPLES << '\n';
	for(int i = 0; i < MAX_SAMPLES; i++)
		os3 << MAX_VAL << "\n";
	tests.push_back(os3.str());

	//gerando os MAX_VALUES primeiros numeros
	ostringstream os4;
	os4 << MAX_SAMPLES << '\n';
	for(int i = 1; i <= MAX_SAMPLES; i++)
		os4 << i << "\n";
	tests.push_back(os4.str());

	//gerando os MAX_VALUES ultimos numeros
	ostringstream os5;
	os5 << MAX_SAMPLES << '\n';
	for(int i = 1, j = MAX_VAL; i <= MAX_SAMPLES; i++, j--)
		os5 << j << "\n";
	tests.push_back(os5.str());

	//gerando varios primos arrojados aleatoriamente
	ostringstream os6;
	os6 << MAX_SAMPLES << '\n';
	for(int i = 1; i <= MAX_SAMPLES; i++)
		os6 << arrojados[rnd.next(0, n - 1)] << "\n";
	tests.push_back(os6.str());

	return tests;
};

vector<string> generate_test(int qtd)
{
	vector<string> tests;

	for(int i = 0; i < 43; i++) {
		ostringstream os;
		os << qtd << '\n';
		for(int j = 0; j < qtd; j++) {
			int A = rnd.next(1, MAX_VAL);
			if(rnd.next(1, 100) <= 10) {
				//10% das vezes escolher um arrojado
				int n = (int) arrojados.size();
				A = arrojados[rnd.next(0, n - 1)];
			}
			os << A << '\n';
		}
		tests.push_back(os.str());
	}

	return tests;
}

void append(vector<string>& dest, const vector<string>& orig)
{
	dest.insert(dest.end(), orig.begin(), orig.end());
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	string cmd = argc > 1 ? argv[1] : "random";
	vector<string> tests;
	size_t test = 0;

	if (cmd == "samples") {
		tests.insert(tests.end(), sample_tests.begin(), sample_tests.end());
	} else if (cmd == "manual") {
		tests = manual_tests();
		test += sample_tests.size();
	} else {
		int N = argc > 2 ? stoi(argv[2]) : MAX_SAMPLES;
		test += sample_tests.size();
		test += manual_tests().size();
		append(tests, generate_test(N));
	}

	for (const auto& t : tests) {
		startTest(++test);
		cout << t;
	}
}
