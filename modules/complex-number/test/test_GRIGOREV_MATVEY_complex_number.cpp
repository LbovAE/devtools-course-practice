// Copyright 2022 Grigorev Matvey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Grigorev_Matvey_ComplexNumberTest, Init_Constructor) {
    // Arrange
    double re = 1.45;
    double im = 5.12;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_EQ(re, z.getRe());
    ASSERT_EQ(im, z.getIm());
}

TEST(Grigorev_Matvey_ComplexNumberTest, Copy_Constructor_1) {
    // Arrange
    double re = 12.234;
    double im = 63.1;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber x(z);

    // Assert
    ASSERT_EQ(re, x.getRe());
    ASSERT_EQ(im, x.getIm());
}

TEST(Grigorev_Matvey_ComplexNumberTest, Copy_Constructor_2) {
    // Arrange
    double re = 73.486;
    double im = 161.16;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber x = z;

    // Assert
    ASSERT_EQ(re, x.getRe());
    ASSERT_EQ(im, x.getIm());
}

TEST(Grigorev_Matvey_ComplexNumberTest, GetRe) {
    // Arrange
    double re = 231.46;
    double im = 934.486;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_EQ(re, z.getRe());
}

TEST(Grigorev_Matvey_ComplexNumberTest, GetIm) {
    // Arrange
    double re = 231.46;
    double im = 934.486;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_EQ(im, z.getIm());
}

TEST(Grigorev_Matvey_ComplexNumberTest, SetRe) {
    // Arrange
    double re = 231.46;
    double im = 934.486;
    double testRe = 35486.56;

    // Act
    ComplexNumber z(re, im);
    z.setRe(testRe);

    // Assert
    ASSERT_EQ(testRe, z.getRe());
}

TEST(Grigorev_Matvey_ComplexNumberTest, SetIm) {
    // Arrange
    double re = 231.46;
    double im = 934.486;
    double testIm = 6487.15;

    // Act
    ComplexNumber z(re, im);
    z.setIm(testIm);

    // Assert
    ASSERT_EQ(testIm, z.getIm());
}

TEST(Grigorev_Matvey_ComplexNumberTest, Operator_plus) {
    // Arrange
    double re1 = 231.46;
    double im1 = 934.486;
    double re2 = 23923.123;
    double im2 = 43.123;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber c = a + b;

    // Assert
    ASSERT_EQ(re1 + re2, c.getRe());
    ASSERT_EQ(im1 + im2, c.getIm());
}

TEST(Grigorev_Matvey_ComplexNumberTest, Operator_minus) {
    // Arrange
    double re1 = 231.46;
    double im1 = 934.486;
    double re2 = 23923.123;
    double im2 = 43.123;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber c = a - b;

    // Assert
    ASSERT_EQ(re1 - re2, c.getRe());
    ASSERT_EQ(im1 - im2, c.getIm());
}

TEST(Grigorev_Matvey_ComplexNumberTest, Operator_multpl) {
    // Arrange
    double re1 = 231.46;
    double im1 = 934.486;
    double re2 = 23923.123;
    double im2 = 43.123;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber c = a * b;

    // Assert
    ASSERT_EQ(re1 * re2 - im1 * im2, c.getRe());
    ASSERT_EQ(re1 * im2 + re2 * im1, c.getIm());
}

TEST(Grigorev_Matvey_ComplexNumberTest, Operator_eq) {
    // Arrange
    double re1 = 231.46;
    double im1 = 934.486;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re1, im1);

    // Assert
    ASSERT_TRUE(a == b);
}

TEST(Grigorev_Matvey_ComplexNumberTest, Operator_not_eq) {
    // Arrange
    double re1 = 231.46;
    double im1 = 934.486;
    double re2 = 23923.123;
    double im2 = 43.123;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);

    // Assert
    ASSERT_TRUE(a != b);
}
