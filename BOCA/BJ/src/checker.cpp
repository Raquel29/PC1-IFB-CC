#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);

    auto pans = ouf.readToken("Sim|Nao", "A resposta deve ser 'Sim' ou 'Nao'");
    auto jans = ans.readToken("Sim|Nao", "A resposta deve ser 'Sim' ou 'Nao'");

    if (pans != jans)
        quitf(_wa, "%s != %s", pans.c_str(), jans.c_str());
    else
        quitf(_ok, "The solution is correct."); 
}
