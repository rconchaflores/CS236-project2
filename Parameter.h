#ifndef PARAMETER_H
#define PARAMETER_H
#include <string>

using namespace std;

class Parameter
{
private:
    string p;

public:
    Parameter(string p){
        this->p = p;
    }
    ~Parameter()= default;

    string getParameter(){
        return p;
    }
};

#endif // PARAMETER_H
