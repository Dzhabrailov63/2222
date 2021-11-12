#pragma once


enum OPERATION
{
	OPERATION_SUM = 1,
	OPERATION_SUB,
	OPERATION_MUL,
	OPERATION_DIV,
	OPERATION_MUL_SCALAR,
	OPERATION_EXIT

};

int  input_x();
int  menu_text(CMyVector  v1);
void main_loop(CMyVector& v1, int N);