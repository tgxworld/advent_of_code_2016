#include <iostream>
#include <string.h>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<char, int> &i, const pair<char, int> &j) {
  return i.second < j.second;
}

int main() {
  ifstream file("4.input");
  string input;
  int sum = 0;
  std::map<char, int> hash;

  while (getline(file, input, '-')) {
    if (input.find("[") != string::npos) {
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

      for (auto itr = values.begin(); itr != values.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
      }

      sort(values.begin(), values.end(), compare);

      for (auto itr = values.begin(); itr != values.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
      }

      return 0;
    } else {
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

  return 0;
}
