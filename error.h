using namespace std;

typedef enum{
	INVARG = 0,
	OOM
}ErrorType;

void Error(ErrorType error);
