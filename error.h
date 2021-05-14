#include <iostream>

using namespace std;

typedef enum{
	INVARG = 0,
	OOM
}ErrorType;

string errorMsg[] =
{
    "Неверный аргумент", "Ошибка при выделении памяти"
};

void Error(ErrorType error){
	std::cerr << errorMsg[error] << std::endl;
}
