#include "testlib.h"
#include <string>

using std::string;
using std::to_string;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    auto N = inf.readInt(1, 100, "N");
    inf.readSpace();

    auto M = inf.readInt(1, 100, "M");
    inf.readEoln();

    string pattern = "[MW]{" + to_string(M) + "," + to_string(M) + "}";
    int ms = 0, ws = 0;

    while (N--)
    {
        auto line = inf.readToken(pattern, "A[i]");
        inf.readEoln();

        for (auto c : line)
            c == 'M' ? ++ms : ++ws;
    }

    ensuref(ws == 1, "We must have just one Waldo");

    inf.readEof();
}
