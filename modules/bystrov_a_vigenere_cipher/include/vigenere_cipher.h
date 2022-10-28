// Copyright 2022 Bystrov Andrey

#ifndef MODULES_BYSTROV_A_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
#define MODULES_BYSTROV_A_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_

#include <string>

class VigenereCipher {
  std::string m_original;
  std::string m_key;

 public:
  VigenereCipher();
  VigenereCipher(const std::string& original, const std::string& key);

  const std::string& getOriginal() const;
  const std::string& getKey() const;
  const std::string getCompare() const;

  void setOriginal(const std::string& original);
  void setKey(const std::string& key);

  void setPair(const std::string& original, const std::string& key);

  std::string cipher() const;
};

#endif  // MODULES_BYSTROV_A_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
