#include <error.h>
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
	cerr << errorMsg[error] << endl;
}
