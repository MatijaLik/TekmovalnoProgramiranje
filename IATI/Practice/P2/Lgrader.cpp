#include <iostream>
#include "guess.h"
using namespace std;

long long N;
int questionsCount=0;

int quest(long long n)
{
    questionsCount++;
    if (n==N) {return 0;}
    else
      if (n<N) {return 1;}
      else
        return 2;
}


void res(long long answer)
{
    cout << answer << " " << questionsCount << endl;
}

//void guess();

int main()
{
    cin >> N;
    guess();
}
