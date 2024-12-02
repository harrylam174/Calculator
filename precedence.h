#include <string>
using namespace std;

enum class operatorRank {
    FUNCTION = 5,
    BRACKET = 4,
    EXPONENTIAL = 3,
    DIVISION = 2, MULTIPLICATION = 2,
    ADDITION = 1, SUBTRACTION = 1
};

class Precedence {
private:
    static operatorRank identifyOperator(string op);
public:
    static bool isGreaterPrecedence(string op1, string op2);
};



