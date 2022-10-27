// Copyright 2022 Gavrilov Leonid

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Gavrilov_Leon_Test, DefaultConstructor) {
  ComplexNumber a;
  ASSERT_EQ(a.getRe(), 0);
  ASSERT_EQ(a.getIm(), 0);
}

TEST(Gavrilov_Leon_Test, TwoParamConstructor) {
  ComplexNumber a(2.5, 5.0);
  ASSERT_EQ(a.getRe(), 2.5);
  ASSERT_EQ(a.getIm(), 5.0);
}

TEST(Gavrilov_Leon_Test, CopyConstructor) {
  ComplexNumber a(2.5, 5.0);
  ComplexNumber b(a);
  ASSERT_EQ(b.getRe(), 2.5);
  ASSERT_EQ(b.getIm(), 5.0);
}

TEST(Gavrilov_Leon_Test, AssignmentOperator) {
  ComplexNumber a(2.5, 5.0);
  ComplexNumber b;
  b = a;
  ASSERT_EQ(b.getRe(), 2.5);
  ASSERT_EQ(b.getIm(), 5.0);
}

TEST(Gavrilov_Leon_Test, GetReMethod) {
  ComplexNumber a(2.5, 5.0);
  ASSERT_EQ(a.getRe(), 2.5);
}

TEST(Gavrilov_Leon_Test, GetImMethod) {
  ComplexNumber a(2.5, 5.0);
  ASSERT_EQ(a.getIm(), 5.0);
}

TEST(Gavrilov_Leon_Test, SetReMethod) {
  ComplexNumber a(2.5, 5.0);
  a.setRe(-3.0);
  ASSERT_EQ(a.getRe(), -3.0);
}

TEST(Gavrilov_Leon_Test, SetImMethod) {
  ComplexNumber a(2.5, 5.0);
  a.setIm(10.5);
  ASSERT_EQ(a.getIm(), 10.5);
}

TEST(Gavrilov_Leon_Test, PlusOperator) {
  ComplexNumber a(2.5, 5.0);
  ComplexNumber b(-3.0, 10.5);
  ComplexNumber c = a + b;
  ASSERT_EQ(c.getRe(), -0.5);
  ASSERT_EQ(c.getIm(), 15.5);
}

TEST(Gavrilov_Leon_Test, MinusOperator) {
  ComplexNumber a(2.5, 5.0);
  ComplexNumber b(-3.0, 10.5);
  ComplexNumber c = a - b;
  ASSERT_EQ(c.getRe(), 5.5);
  ASSERT_EQ(c.getIm(), -5.5);
}

TEST(Gavrilov_Leon_Test, MultiplyOperator) {
  ComplexNumber a(2.5, 5.0);
  ComplexNumber b(-3.0, 10.5);
  ComplexNumber c = a * b;
  ASSERT_EQ(c.getRe(), -60.0);
  ASSERT_EQ(c.getIm(), 11.25);
}

TEST(Gavrilov_Leon_Test, DivisionOperatorThrow) {
  ComplexNumber a(2.5, 5.0);
  ComplexNumber b;
  ASSERT_ANY_THROW(a / b);
}

TEST(Gavrilov_Leon_Test, DivisionOperator) {
  ComplexNumber a(2.5, 5.0);
  ComplexNumber b(-3.0, 10.5);
  ComplexNumber c = a / b;

  ASSERT_NEAR(c.getRe(), 0.37735, 0.00001);
  ASSERT_NEAR(c.getIm(), -0.34591, 0.00001);
}

TEST(Gavrilov_Leon_Test, EqualsOperator) {
  ComplexNumber a(2.5, 5.0);
  ComplexNumber b(2.5, 5.0);
  ASSERT_TRUE(a == b);
}

TEST(Gavrilov_Leon_Test, NotEqualsOperator) {
  ComplexNumber a(2.5, 5.0);
  ComplexNumber b(-3.0, 10.5);
  ASSERT_FALSE(a == b);
}
