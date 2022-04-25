#include <stdio.h>
#include <stdlib.h>

#define rows 25
#define cols 80

int input(int data[][cols]);
void output(int data[][cols]);
void new_generation(int data[][cols], int buf[][cols]);
int copy_mtr(int data[][cols], int buf[][cols]);
int count_cells(int data[][cols], int i, int j);

int main(int argc, char *argv[]) {
    int data[rows][cols], buf[rows][cols];
    int ok = 1;
    float flag;
    char sec[100];

    if (argc != 2) {
      flag = 0.5;
    } else {
      if ((sscanf(argv[1], "%f", &flag)) != 1)
        ok = 0;
    }
    if (!input(data))
      ok = 0;

    if (!ok) {
      printf("n/a");
      return 0;
    }

    sprintf(sec, "sleep %f", flag);
    output(data);

    while (1) {
      new_generation(data, buf);
      if (!copy_mtr(buf, data)) {
        output(data);
        break;
      }
      output(data);

      system(sec);
      system("clear");
    }


    return 0;
}

int copy_mtr(int data[][cols], int buf[][cols]) {
  int count = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      buf[i][j] = data[i][j];
      if (buf[i][j])
        count++;

    }
  }
  return count;
}

int count_cells(int data[][cols], int i, int j) {
  int count = 0, _x, _y;
  int x = i - 1;
  for (int xc = 0 ; xc < 3 ; xc++) {
    int y = j - 1;
    for (int yc = 0 ; yc < 3 ; yc++) {
      _x = x, _y = y;
      if (x < 0)
        x = rows + x;
      if (y < 0)
        y = cols + y;
      if (data[x % rows][y % cols])
        count++;
      x = _x, y = _y;
      y++;
    }
    x++;
  }
  return count;
}

void new_generation(int data[][cols], int buf[][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int status = count_cells(data, i, j);
      if (status < 3 || status > 4 || (!data[i][j] && status == 4)) {
        buf[i][j] = 0;
      } else {
        buf[i][j] = 1;
      }
    }
  }
}

int input(int data[][cols]) {
  int ok = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if ((scanf("%9.4s", &data[i][j])) != 1)
        ok = 0;
    }
  }
  return ok;
}

void output(int data[][cols]) {
  // read(0, NULL, 10);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (data[i][j] != 0) {
        printf("o");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
