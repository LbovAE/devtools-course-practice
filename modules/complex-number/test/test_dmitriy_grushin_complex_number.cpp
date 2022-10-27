// Copyright 2022 Grushin Dmitriy
#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

TEST(Dmitriy_Grushin_ComplexNumberTest, Start) {
  double re = 1.0;
  double im = 2.0;

  ComplexNumber z(re, im);

  EXPECT_DOUBLE_EQ(1.0, z.getRe());
  EXPECT_DOUBLE_EQ(2.0, z.getIm());
}

TEST(Dmitriy_Grushin_ComplexNumberTest, Plus) {
  double re = 2.0;
  double im = 1.0;

  double re1 = 1.0;
  double im1 = -2.0;

  ComplexNumber z(re, im);
  ComplexNumber z1(re1, im1);

  ComplexNumber sum = z + z1;

  EXPECT_DOUBLE_EQ(3.0, sum.getRe());
  EXPECT_DOUBLE_EQ(-1.0, sum.getIm());
}

TEST(Dmitriy_Grushin_ComplexNumberTest, Minus) {
  double re = 2.0;
  double im = 1.0;

  double re1 = 1.0;
  double im1 = 2.0;


  ComplexNumber z(re, im);
  ComplexNumber z1(re1, im1);

  ComplexNumber diff = z - z1;

  EXPECT_DOUBLE_EQ(1.0, diff.getRe());
  EXPECT_DOUBLE_EQ(-1.0, diff.getIm());
}

TEST(Dmitriy_Grushin_ComplexNumberTest, Division) {
  double re = 3.0;
  double im = 4.0;

  double re1 = 3.0;
  double im1 = 4.0;

  ComplexNumber z(re, im);
  ComplexNumber z1(re1, im1);

  ComplexNumber div = z / z1;

  EXPECT_DOUBLE_EQ(1.0, div.getRe());
  EXPECT_DOUBLE_EQ(0.0, div.getIm());
}

TEST(Dmitriy_Grushin_ComplexNumberTest, Multiplication) {
  double re = 2.0;
  double im = 3.0;

  double re1 = 1.0;
  double im1 = 4.0;

  ComplexNumber z(re, im);
  ComplexNumber z1(re1, im1);

  ComplexNumber mult = z * z1;

  EXPECT_DOUBLE_EQ(-10.0, mult.getRe());
  EXPECT_DOUBLE_EQ(11.0, mult.getIm());
}
