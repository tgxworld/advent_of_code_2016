#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<char, int> x, pair<char, int> y) {
  return x.second > y.second || (x.second == y.second && x.first < y.first);
}

char decipher(char letter, int steps) {
  int remainder = steps % 26;
  int steps_to_wrap = 122 - int(letter);

  if (remainder > steps_to_wrap) {
    remainder = remainder - steps_to_wrap;
    return char(96 + remainder);
  } else {
    return char(int(letter) + remainder);
  }
}

int main() {
  ifstream file("4.input");
  // ifstream file("4.test.input");
  string input;
  string line;
  int sum = 0;
  map<char, int> hash;
  vector<string> inputs;

  while (getline(file, line)) {
    istringstream str(line);

    while (getline(str, input, '-')) {
      if (input.find_first_of('[') != string::npos) {
        vector<char> sector_id_inputs;
        vector<char> checksum_inputs;

        int i = 0;

        while (input[i] != '[') {
          sector_id_inputs.push_back(input[i]);
          i++;
        }

        i++;

        while(input[i] != ']') {
          checksum_inputs.push_back(input[i]);
          i++;
        }

        int sector_id = atoi(string(sector_id_inputs.begin(), sector_id_inputs.end()).c_str());
        string checksum = string(checksum_inputs.begin(), checksum_inputs.end());

        int j = 0;
        vector<pair<char, int>> values;

        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
          values.push_back(make_pair(itr->first, itr->second));
        }

        // for (auto itr = values.begin(); itr != values.end(); itr++) {
        //   cout << "before sort " << itr-> first << " " << itr->second << endl;
        // }

        sort(values.begin(), values.end(), compare);

        // for (auto itr = values.begin(); itr != values.end(); itr++) {
        //   cout << "after sort " << itr-> first << " " << itr->second << endl;
        // }

        auto values_itr = values.begin();
        auto checksum_inputs_itr = checksum_inputs.begin();
        bool match = true;

        while (checksum_inputs_itr != checksum_inputs.end()) {
          if (values_itr->first != *checksum_inputs_itr) {
            match = false;
          }

          values_itr++;
          checksum_inputs_itr++;
        }

        if (match) {
          sum += sector_id;
        }

        for (auto itr = inputs.begin(); itr != inputs.end(); itr++) {
          for (int x = 0; x < strlen((*itr).c_str()); x++) {
            cout << decipher((*itr)[x], sector_id);
          }

          cout << " ";
        }

        cout << sector_id;
        cout << endl;

        hash.clear();
        inputs.clear();
      } else {
        inputs.push_back(input);

        int i = 0;

        while (input[i] != '\0') {
          if (hash.find(input[i]) == hash.end()) {
            hash[input[i]] = 1;
          } else {
            hash[input[i]] += 1;
          }

          i++;
        }
      }
    }
  }

  cout << sum << endl;

  return 0;
}
