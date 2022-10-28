// Copyright 2022 Bystrov Andrey

#include <gtest/gtest.h>

#include <string>
#include <tuple>

#include "include/vigenere_cipher.h"

TEST(BYSTROV_ANDREY_VIGENERE_TEST, ConstructorWithoutParameters) {
  ASSERT_NO_THROW(VigenereCipher());
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, ConstructorWithTwoParameters) {
  ASSERT_NO_THROW(VigenereCipher("TEST", "QWER"));
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, ConstructorWithTwoParametersNotEqualSize) {
  ASSERT_ANY_THROW(VigenereCipher("TEST", ""));
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST,
     ConstructorWithTwoParametersWithNotAllowChar) {
  ASSERT_ANY_THROW(VigenereCipher("TE12", "QW12"));
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckDefaultValue) {
  VigenereCipher v;

  ASSERT_EQ(v.getOriginal(), "");
  ASSERT_EQ(v.getKey(), "");
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckCustomValue) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_EQ(v.getOriginal(), "TEST");
  ASSERT_EQ(v.getKey(), "QWER");
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckCipheringWithoutParameters) {
  VigenereCipher v;

  std::string cipher = v.cipher();

  ASSERT_EQ(cipher, "");
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckCipheringWithParameters) {
  VigenereCipher v("ATTACKATDAWN", "LEMONLEMONLE");

  std::string cipher = v.cipher();

  ASSERT_EQ(cipher, "LXFOPVEFRNHR");
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckSetOriginalEqualKey) {
  VigenereCipher v("TEST", "QWER");

  v.setOriginal("QQQQ");

  ASSERT_EQ(v.getOriginal(), "QQQQ");
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckSetOriginalNotEqualKey) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setOriginal("T"));
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckSetOriginalWithNotAllowedCharacter) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setOriginal("TE12"));
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckSetKeyEqualOriginal) {
  VigenereCipher v("TEST", "QWER");

  v.setKey("QQQQ");

  ASSERT_EQ(v.getKey(), "QQQQ");
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckSetKeyNotEqualOriginal) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setKey("Q"));
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckSetKeyWithNotAllowedCharacter) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setOriginal("QW12"));
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckSetPairWithEqualSize) {
  VigenereCipher v("TEST", "QWER");

  v.setPair("QWER", "TEST");

  ASSERT_EQ(v.getOriginal(), "QWER");
  ASSERT_EQ(v.getKey(), "TEST");
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckSetPairWithoutEqualSize) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setPair("TEST", "Q"));
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckSetPairWithNotAllowedCharacter) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setPair("TE12", "QW12"));
}

TEST(BYSTROV_ANDREY_VIGENERE_TEST, CheckCompare) {
  VigenereCipher v("ATTACKATDAWN", "LEMONLEMONLE");

  std::string cipher = v.cipher();

  ASSERT_EQ(v.getOriginal() + " - " + cipher, "ATTACKATDAWN - LXFOPVEFRNHR");
}
