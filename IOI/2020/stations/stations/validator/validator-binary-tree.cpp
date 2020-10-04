#include "testlib.h"
using namespace std;

const int MAXR = 10;
const int MAXN = 1000;
const int MAXQ = 100000;
const int MAXK = 1000;

int main() {
	registerValidation();
	int r = inf.readInt(1, MAXR, "r");
	inf.readEoln();
	for (int i = 0; i < r; i++) {
		int n = inf.readInt(2, MAXN, "n");
		inf.readSpace();
		int k = inf.readInt(MAXK, MAXK, "k");
		inf.readEoln();
		for (int j = 0; j < n - 1; j++) {
			int u = inf.readInt(0, n - 1, "u_i");
			inf.readSpace();
			int v = inf.readInt(0, n - 1, "v_i");
			inf.readEoln();
			ensuref(u == j + 1 && v == j / 2 || v == j + 1 && u == j / 2, "subtask 2: edge %d is wrong", j);
		}
		int q = inf.readInt(1, MAXQ, "q");
	  inf.readEoln();
	  for (int j = 0; j < q; j++) {
	  	int s = inf.readInt(0, n - 1, "s_j");
	  	inf.readSpace();
	  	int t = inf.readInt(0, n - 1, "t_j");
	  	inf.readSpace();
	  	int ans = inf.readInt(0, n - 1, "ans_j");
	  	inf.readEoln();
	  }
	}
	inf.readInt(0, 0, "is_partial"); // check if non-partial scoring
	inf.readSpace();
	inf.readInt(0, INT_MAX, "seed");
	inf.readEoln();
	inf.readEof();
	return 0;
}
