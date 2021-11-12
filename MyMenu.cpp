#include "CMyVector.h"
#include "MyMenu.h"
#include "MyFunction.h"


int input_x()
{
	int x; cout << "input x - ";
	while (!(bool)(cin >> x))
	{
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return x;
}

int menu_text(CMyVector v1)
{
	system("cls");

	cout << OPERATION::OPERATION_SUM << ". OPERATION_SUM " << endl;
	cout << OPERATION::OPERATION_SUB << ". OPERATION_SUB " << endl;
	cout << OPERATION::OPERATION_MUL << ". OPERATION_MUL " << endl;
	cout << OPERATION::OPERATION_DIV << ". OPERATION_DIV " << endl;
	cout << OPERATION::OPERATION_MUL_SCALAR << ". OPERATION_MUL_SCALAR " << endl;
	cout << OPERATION::OPERATION_EXIT << ". OPERATION_EXIT " << endl << endl;

	cout << "v1: "; cout << v1;
	cout << endl << endl;

	cout << "enter operation number: ";


	int n;  cin >> n;

	// .....

	return n;
}


void main_loop(CMyVector& v1, int N)
{
	try
	{
		bool flag = true;

		while (flag)
		{
			switch (menu_text(v1))
			{
			case OPERATION::OPERATION_SUM:
			{
				CMyVector v2(N);
				filling_vector("filling CMyVector 2 please", v2);
				CMyVector rez_v = v1 + v2;
				cout << rez_v;
				system("pause");
			}break;
			case OPERATION::OPERATION_SUB:
			{
				CMyVector v2(N);
				filling_vector("filling CMyVector 2 please", v2);
				CMyVector rez_v = v1 - v2;
				cout << rez_v;
				system("pause");
			}break;
			case OPERATION::OPERATION_MUL:
			{
				CMyVector v2(N);
				filling_vector("filling CMyVector 2 please", v2);
				CMyVector rez_v = v1 * v2;
				cout << rez_v;
				system("pause");
			}break;
			case OPERATION::OPERATION_DIV:
			{
				int x = input_x();

				CMyVector rez_v = v1 / x;
				cout << rez_v;
				system("pause");
			}break;

			case OPERATION::OPERATION_MUL_SCALAR:
			{
				CMyVector v2(N);

				int x = input_x();

				CMyVector rez_v = v1 * x;
				cout << rez_v;
				system("pause");
			}break;
			case OPERATION::OPERATION_EXIT:
			{
				flag = false;
			}break;
			}
		}
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

}