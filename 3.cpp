#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

vector<int> get_inputs(string line) {
  vector<int> inputs;
  vector<char> input;
  int length = strlen(line.c_str());

  for (int i = 0; i <= length; ++i) {
    if (line[i] == ' ' || i == length) {
      if (line[i - 1] != ' ') {
        inputs.push_back(atoi(string(input.begin(), input.end()).c_str()));
        input.clear();
      }
    } else {
      input.push_back(line[i]);
    }
  }

  return inputs;
}

int main() {
  ifstream file("3.input");
  string line;
  vector<int> inputs;
  int count = 0;

  while (getline(file, line)) {
    inputs = get_inputs(line);

    int a = inputs.back();
    inputs.pop_back();
    int b = inputs.back();
    inputs.pop_back();
    int c = inputs.back();
    inputs.pop_back();

    if ((a + b > c) && (b + c > a) && (c + a > b)) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
