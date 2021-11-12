#include "CMyVector.h"
#include "MyFunction.h"
#include "MyMenu.h"

using namespace std;

int main()
{
	int N; cout << "input N - "; cin >> N;
	CMyVector v1(N);
	filling_vector("filling CMyVector 1 please", v1);	

	main_loop(v1, N);
}


