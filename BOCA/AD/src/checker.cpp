#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 2;
const int MAX_N = 1000;

const double MIN_V = -1000;
const double MAX_V = 1000;

int n;
vector<double> x, y;

double euclidean_distance(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double check_ans(InStream &stream) {
    stream.readToken("Pontos: ");
    int a = stream.readInt(0, n - 1);
    stream.readToken(" e ");
    int b = stream.readInt(0, n - 1);
    ensuref(a != b, "a must be diferente from b");
    stream.readToken("Distancia: ");
    double dist =
        stream.readDouble(0, numeric_limits<double>::max(), "distance");
    ensuref(doubleCompare(dist, euclidean_distance(a, b), 1e-4),
            "distance informed is not equal to the calculated one");
    return dist;
}

int main(int argc, char *argv[]) {
    setName("Compare point distances");
    registerTestlibCmd(argc, argv);
    n = inf.readInt(MIN_V, MAX_V);
    x = inf.readDoubles(n, MIN_V, MAX_V);
    y = inf.readDoubles(n, MIN_V, MAX_V);
    double dist_j = check_ans(ans);
    double dist_p = check_ans(ouf);
    if (doubleCompare(dist_j, dist_p,1e-4)){
        quitf(_ok,"Ok, distance is equal");
    }
    else if(dist_j < dist_p){
        quitf(_wa,"Participant has a bigger distance");
    }
    quitf(_fail,"Fail: participant has better answer");
}