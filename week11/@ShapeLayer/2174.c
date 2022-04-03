#include <stdio.h>

struct Robot {
  int x;
  int y;
  int direction; // n0 w1 s2 e3
};

int main() {
  int a, b, n, m;
  scanf("%d %d %d %d", &a, &b, &n, &m);
  int map[101][101] = { 0 };
  struct Robot robots[100];
  for (int i = 0; i < n; i++) {
    char z;
    struct Robot gets;
    scanf("%d %d %c", &gets.x, &gets.y, &z);
    if (z == 'N') gets.direction = 0;
    else if (z == 'W') gets.direction = 1;
    else if (z == 'S') gets.direction = 2;
    else gets.direction = 3;
    robots[i] = gets;
    map[gets.y][gets.x] = i+1;
  }
  for (int i = 0; i < m; i++) {
    int targets, repeats;
    char opers;
    scanf("%d %c %d", &targets, &opers, &repeats);
    if (opers == 'L') {
      for (int j = 0; j < repeats; j++) {
        robots[targets-1].direction++;
        robots[targets-1].direction %= 4;
      }
    } else if (opers == 'R') {
      for (int j = 0; j < repeats; j++) {
        robots[targets-1].direction--;
        robots[targets-1].direction += 4;
        robots[targets-1].direction %= 4;
      }
    } else {
      for (int j = 0; j < repeats; j++) {
        map[robots[targets-1].y][robots[targets-1].x] = 0;
        int dir = robots[targets-1].direction;
        if (dir == 0) robots[targets-1].y++; // north
        else if (dir == 1) robots[targets-1].x--; // west
        else if (dir == 2) robots[targets-1].y--; // south
        else robots[targets-1].x++; // east
        int x = robots[targets-1].x;
        int y = robots[targets-1].y;
        if (x <= 0 || x > a || y <= 0 || y > b) {
          printf("Robot %d crashes into the wall\n", targets);
          return 0;
        }
        if (map[robots[targets-1].y][robots[targets-1].x] != 0) {
          printf("Robot %d crashes into robot %d\n", targets, map[robots[targets-1].y][robots[targets-1].x]);
          return 0;
        }
        map[robots[targets-1].y][robots[targets-1].x] = targets;
      }
    }
  }
  printf("OK\n");
  return 0;
}