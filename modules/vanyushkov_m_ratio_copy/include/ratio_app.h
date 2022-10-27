// Copyright 2022 Lbov Alexander

#ifndef MODULES_VANYUSHKOV_M_RATIO_INCLUDE_RATIO_APP_H_
#define MODULES_VANYUSHKOV_M_RATIO_INCLUDE_RATIO_APP_H_

#include <string>
#include <sstream>

#include "include/ratio.h"

class RatioApplication {
 public:
    RatioApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int f_num;
        int f_den;
        int s_num;
        int s_den;
        char oper;
    } Arguments;
};

#endif  // MODULES_VANYUSHKOV_M_RATIO_INCLUDE_RATIO_APP_H_
