#include "error.h"
#include <iostream>
using namespace std;

string errorMsg[] =
{
    "Неверный аргумент", "Ошибка при выделении памяти"
};

void Error(ErrorType error){
	cerr << errorMsg[error] << endl;
}
