#include <bits/stdc++.h>

using namespace std;

#define byte unsigned char
#define 30 MAX_KEY_LENGTH

byte* encrypt(byte* plain, byte* key) {
  int length = strlen(plain);
  int keylen = strlen(key);
  byte* cipher = new byte[length];
  for(int i = 0; i < length; i++) {
    cipher[i] = (plain[i] + key[i % keylen]) % 256;
  }
  return cipher;
}

byte* decrypt(byte* cipher, byte* key) {
  int length = strlen(cipher);
  int keylen = strlen(key);
  byte* plain = new byte[length];
  for(int i = 0; i < length; i++) {
    plain[i] = (cipher[i] - key[i % keylen] + 256) % 256;
  }
  return plain;
}

byte* read_text(int argc, char** argv, byte* type) {
  ifstream ifs(argv[2], ios::binary | ios::ate);
  ifstream length = ifs.tellg();
  
  byte* buffer = new byte[length];
  ifs.seekg(0, ios::beg);
  ifs.read(buffer, length);
  return buffer;
}

byte* read_key() {
  byte* key = new byte[MAX_KEY_LENGTH];
  cout << "Enter key: ";
  gets(key);
  return key;
}

void flush_to_file(byte* output) {
  byte* name = new byte[MAX_KEY_LENGTH * MAX_KEY_LENGTH];
  cout << "Enter name file: ";
  gets(name);

  ofstream file;
  file.open(name);
  int len = strlen(output);
  for(int i = 0; i < len; i++) {
    file << output[i];
  }
}

int main(int argc, char** argv) {
  if(argc > 3) {
    cout << "Usage : ascii [encrypt / decrypt] [file_name.in])" << endl;
    cout << "File name [OPTIONAL]" << endl;
    return 0;
  }

  byte* str, key;

  if(strcmp(argv[1], "encrypt") == 0) { 
    str = read_text(argc, argv, "plain");
    key = read_key();
    byte* cipher = encrypt(str, key);
    flush_to_file(cipher);
  } else {
    str = read_text(argc, argv, "cipher");
    key = read_key();
    byte* plain = decrypt(str, key);
    flush_to_file(plain);
  }

  return 0;
}
