// rpn.h

#ifndef RPN_H
#define RPN_H

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

double ComputePolishNotationFunction(const std::string& str, double x = 0);

#ifdef __cplusplus
}
#endif

#endif // RPN_H
