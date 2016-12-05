#include <iostream>
#include <string>
#include <vector>
#include <set>

#define INPUT "L2, L5, L5, R5, L2, L4, R1, R1, L4, R2, R1, L1, L4, R1, L4, L4, R5, R3, R1, L1, R1, L5, L1, R5, L4, R2, L5, L3, L3, R3, L3, R4, R4, L2, L5, R1, R2, L2, L1, R3, R4, L193, R3, L5, R45, L1, R4, R79, L5, L5, R5, R1, L4, R3, R3, L4, R185, L5, L3, L1, R5, L2, R1, R3, R2, L3, L4, L2, R2, L3, L2, L2, L3, L5, R3, R4, L5, R1, R2, L2, R4, R3, L4, L3, L1, R3, R2, R1, R1, L3, R4, L5, R2, R1, R3, L3, L2, L2, R2, R1, R2, R3, L3, L3, R4, L4, R4, R4, R4, L3, L1, L2, R5, R2, R2, R2, L4, L3, L4, R4, L5, L4, R2, L4, L4, R4, R1, R5, L2, L4, L5, L3, L2, L4, L4, R3, L3, L4, R1, L2, R3, L2, R1, R2, R5, L4, L2, L1, L3, R2, R3, L2, L1, L5, L2, L1, R4"
// #define INPUT "R2, R2, R2"
// #define INPUT "R5, L5, R5, R3"
// #define INPUT "R2, L3"

using namespace std;

int normalizeAngle(int angle) {
  angle = angle % 360;

  if (angle < 0) {
    angle = angle + 360;
  }

  return angle;
}

int extract_steps(int &i) {
  vector<char> v;
  i++;

  while (INPUT[i] != ',') {
    v.push_back(INPUT[i]);
    i++;
  }

  return stoi(string(v.begin(), v.end()));
}

void calculate_blocks(int angle, int steps, int *vertical_blocks, int *horizontal_blocks) {
  switch(angle) {
    case 0:
      *vertical_blocks += steps;
      break;
    case 90:
      *horizontal_blocks += steps;
      break;
    case 180:
      *vertical_blocks -= steps;
      break;
    case 270:
      *horizontal_blocks -= steps;
      break;
  }

  return;
}

int main() {
  int angle = 0;
  int vertical_blocks = 0;
  int horizontal_blocks = 0;
  vector<int> vblocks;
  vector<int> hblocks;
  int vblock;
  int hblock;

  for(int i = 0; INPUT[i] != '\0'; i++) {
    if (INPUT[i] == 'L' || INPUT[i] == 'R') {
      if (INPUT[i] == 'L'){
        angle = normalizeAngle(angle - 90);
      } else if (INPUT[i] == 'R') {
        angle = normalizeAngle(angle + 90);
      }

      int steps = extract_steps(i);
      calculate_blocks(angle, steps, &vertical_blocks, &horizontal_blocks);
      vblock = abs(vertical_blocks);
      hblock = abs(horizontal_blocks);

      if ((find(vblocks.begin(), vblocks.end(), vblock) - vblocks.begin()) == (find(hblocks.begin(), hblocks.end(), bhblock) - hblocks.begin())) {
        cout << hblock + vblock << endl;
        return 0;
      } else {
        hblocks.insert(hblock);
        vblocks.insert(vblock);
      }
    }
  }

  return 0;
}
