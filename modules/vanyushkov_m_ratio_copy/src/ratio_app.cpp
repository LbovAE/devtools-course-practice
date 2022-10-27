// Copyright 2022 Lbov Alexander

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/ratio.h"
#include "include/ratio_app.h"

RatioApplication::RatioApplication() : message_("") {}

void RatioApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a ratio number calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <f_num> <f_den> " +
        "<s_num> <s_den> <operation>\n\n" +
        "Where all arguments are integer numbers, " +
        "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool RatioApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);
    if (*end) {
        throw std::string("Wrong number format!");
    }
    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string RatioApplication::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.f_num = parseInt(argv[1]);
        args.f_den = parseInt(argv[2]);
        args.s_num = parseInt(argv[3]);
        args.s_den = parseInt(argv[4]);
        args.oper = parseOperation(argv[5]);
    }
    catch (std::string& str) {
        return str;
    }
    Ratio f(args.f_num, args.f_den);
    Ratio s(args.s_num, args.s_den);
    Ratio res;
    std::ostringstream stream;
    switch (args.oper) {
    case '+':
        res = f + s;
        stream << "Numerator = " << res.get_numerator() << " "
            << "Denominator = " << res.get_denominator();
        break;
    case '-':
        res = f - s;
        stream << "Numerator = " << res.get_numerator() << " "
            << "Denominator = " << res.get_denominator();
        break;
    case '*':
        res = f * s;
        stream << "Numerator = " << res.get_numerator() << " "
            << "Denominator = " << res.get_denominator();
        break;
    case '/':
        try {
            res = f / s;
            stream << "Numerator = " << res.get_numerator() << " "
                << "Denominator = " << res.get_denominator();
            break;
        }
        catch (const char str[]) {
            return std::string(str);
        }
    }
    message_ = stream.str();
    return message_;
}
