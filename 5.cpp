#include <iostream>
#include <string.h>
#include <openssl/md5.h>
#include <set>

using namespace std;

#define HEXDIGITS "0123456789ABCDEF"

// Copied from somewhere
char* hexDigest(unsigned char *digest, char *digest_str) {
  for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
    digest_str[i*2]   = HEXDIGITS[(digest[i] >> 4) & 0xF];
    digest_str[i*2+1] = HEXDIGITS[digest[i] & 0xF];
  }
  digest_str[MD5_DIGEST_LENGTH * 2] = '\0';

  return digest_str;
}


int main() {
  unsigned char digest[MD5_DIGEST_LENGTH];
  char digest_str[2 * MD5_DIGEST_LENGTH + 1];
  string input = "ojvtpuvg";
  int count = 0;
  char output[8];
  set<int> positions;

  for (int i = 0; count < 8; i++) {
    string intermediate = input + to_string(i);
    MD5((const unsigned char*)intermediate.c_str(), strlen(intermediate.c_str()), digest);
    hexDigest(digest, digest_str);

    bool valid = true;

    for (int j = 0; j < 5; j++) {
      if (digest_str[j] != '0') {
        valid = false;
      }
    }

    if (!(digest_str[5] >= '0' && digest_str[5] <= '7')) {
      valid = false;
    }

    if (valid && positions.find(digest_str[5]) == positions.end()) {
      cout << digest_str[5] << ' ' << digest_str[6] << endl;

      output[digest_str[5] - '0'] = digest_str[6];
      positions.insert(digest_str[5]);
      count++;
    }
  }

  for (int i = 0; i < 8; i++) {
    cout << output[i];
  }

  cout << endl;

  return 0;
}
