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

bool is_triangle(int a, int b, int c) {
  return (a + b > c) && (b + c > a) && (c + a > b);
}

int main() {
  ifstream file("3-2.input");
  string line;
  vector<int> inputs;
  vector<int> inputs_2;
  vector<int> inputs_3;
  int count = 0;

  while (getline(file, line)) {
    inputs = get_inputs(line);
    getline(file, line);
    inputs_2 = get_inputs(line);
    getline(file, line);
    inputs_3 = get_inputs(line);

    for (int i = 0; i < 3; ++i) {
      int a = inputs.back();
      inputs.pop_back();
      int b = inputs_2.back();
      inputs_2.pop_back();
      int c = inputs_3.back();
      inputs_3.pop_back();

      if (is_triangle(a, b, c)) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}
