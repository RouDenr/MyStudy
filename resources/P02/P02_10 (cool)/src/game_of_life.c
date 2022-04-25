// "Copyright [2022] <kanishas, argentin, lesleemo>"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void show(void * u, int w, int h);
void evolve(void * u, int w, int h);
void game(int w, int h, int argc, char *argv[]);

int main(int argc, char *argv[]) {
  int w = 80, h = 25;
  if (argc != 3)
    game(w, h, argc, argv);
  return 0;
}

void show(void * u, int w, int h) {
  int(* deck)[w] = u;
  system("clear");
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      printf(deck[y][x] ? "*" : " ");
    }
    printf("\n");
  }
}

void evolve(void * u, int w, int h) {
  int(* deck)[w] = u;
  int mas[h][w];
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      int n = 0;
      for (int y1 = y - 1; y1 <= y + 1; y1++)
        for (int x1 = x - 1; x1 <= x + 1; x1++)
          if (deck[(y1 + h) % h][(x1 + w) % w])
            n += 1;
      if (deck[y][x]) n -= 1;
      mas[y][x] = (n == 3 || (n == 2 && deck[y][x]));
    }
  }
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      deck[y][x] = mas[y][x];
    }
  }
}

void game(int w, int h, int argc, char *argv[]) {
    int deck[h][w], speed = 1000000;
    FILE *file;
    file = fopen(argv[1], "r");
    printf("Выберете скорость от 1 до 5 :\n");
    scanf("%d", & speed);
    // if (speed != 0)
      speed = 1000000/speed;
    if (speed < 200000 || speed > 1000000) {
      printf("n/a\n");
    } else {
      while (1) {
        evolve(deck, w, h);
        show(deck, w, h);
        usleep(speed);
      }
    }
}
