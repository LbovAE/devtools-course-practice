// Copyright 2022 Khristina Motyl

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Khristina_Motyl_Test, Create) {
    double re = 2.0;
    double im = 5.0;
    ComplexNumber cn1(re, im);

    EXPECT_EQ(cn1.getRe(), 2.0);
    EXPECT_EQ(cn1.getIm(), 5.0);
}

TEST(Khristina_Motyl_Test, Compare) {
    double real1 = 3.0;
    double imag1 = 1.0;
    ComplexNumber c1(real1, imag1);

    double real2 = 3.0;
    double imag2 = 1.0;
    ComplexNumber c2(real2, imag2);

    EXPECT_EQ(c1, c2);
}

TEST(Khristina_Motyl_Test, Substract) {
    double re1 = 5.0;
    double im1 = 1.0;
    double re2 = 2.0;
    double im2 = 1.5;

    ComplexNumber tmp1(re1, im1);
    ComplexNumber tmp2(re2, im2);

    ComplexNumber Subtraction = tmp1 - tmp2;

    EXPECT_EQ(re1 - re2, Subtraction.getRe());
    EXPECT_EQ(im1 - im2, Subtraction.getIm());
}

TEST(Khristina_Motyl_Test, Multiply) {
    double re1 = 5.0;
    double im1 = 1.0;
    double re2 = 2.0;
    double im2 = 1.5;

    ComplexNumber tmp1(re1, im1);
    ComplexNumber tmp2(re2, im2);

    ComplexNumber Subtraction = tmp1 * tmp2;

    EXPECT_EQ(8.5, Subtraction.getRe());
    EXPECT_EQ(9.5, Subtraction.getIm());
}

TEST(Khristina_Motyl_Test, Divide) {
    double re1 = 5.0;
    double im1 = 1.0;
    double re2 = 2.0;
    double im2 = 1.5;

    ComplexNumber tmp1(re1, im1);
    ComplexNumber tmp2(re2, im2);

    ComplexNumber Subtraction = tmp1 / tmp2;

    EXPECT_DOUBLE_EQ(1.84, Subtraction.getRe());
    EXPECT_DOUBLE_EQ(-0.88, Subtraction.getIm());
}

TEST(Khristina_Motyl_Test, Sum) {
    double re1 = 5.0;
    double im1 = 1.0;
    double re2 = 2.0;
    double im2 = 1.5;

    ComplexNumber tmp1(re1, im1);
    ComplexNumber tmp2(re2, im2);

    ComplexNumber Subtraction = tmp1 / tmp2;

    EXPECT_DOUBLE_EQ(1.84, Subtraction.getRe());
    EXPECT_DOUBLE_EQ(-0.88, Subtraction.getIm());
}
