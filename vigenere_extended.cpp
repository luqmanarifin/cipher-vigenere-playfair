#include <bits/stdc++.h>

using namespace std;

#define byte unsigned char
#define MAX_KEY_LENGTH 30

byte* encrypt(byte* plain, byte* key) {
  int length = strlen((char*) plain);
  int keylen = strlen((char*) key);
  byte* cipher = new byte[length];
  cout << "panjang plain " << length << endl;
  for(int i = 0; i < length; i++) {
    cipher[i] = (plain[i] + key[i % keylen]) % 256;
  }
  return cipher;
}

byte* decrypt(byte* cipher, byte* key) {
  int length = strlen((char*) cipher);
  int keylen = strlen((char*) key);
  byte* plain = new byte[length];
  for(int i = 0; i < length; i++) {
    plain[i] = (cipher[i] - key[i % keylen] + 256) % 256;
  }
  return plain;
}

byte* read_text(int argc, char** argv) {
  ifstream ifs(argv[2], ios::binary | ios::ate);
  ifstream::pos_type length = ifs.tellg();
  
  int len = (int) length;
  cout << "panjang " << len << endl;

  char* buffer = new char[len];
  ifs.seekg(0, ios::beg);
  ifs.read(buffer, len);
  cout << "panjang buffer " << strlen(buffer) << endl; 
  return (byte*) buffer;
}

byte* read_key() {
  char* key = new char[MAX_KEY_LENGTH];
  cout << "Enter key: ";
  gets(key);
  return (byte*) key;
}

void flush_to_file(byte* output) {
  char* name = new char[MAX_KEY_LENGTH * MAX_KEY_LENGTH];
  cout << "Enter name file: ";
  gets(name);

  ofstream file;
  file.open(name);
  int len = strlen((char*) output);
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

  byte* str = new byte[MAX_KEY_LENGTH];
  byte* key = new byte[MAX_KEY_LENGTH];

  if(strcmp(argv[1], "encrypt") == 0) { 
    str = read_text(argc, argv);
    key = read_key();
    byte* cipher = (byte*) encrypt(str, key);
    flush_to_file(cipher);
  } else {
    str = read_text(argc, argv);
    key = read_key();
    byte* plain = (byte*) decrypt(str, key);
    flush_to_file(plain);
  }

  return 0;
}
