#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define WIDTH 80
#define HEIGHT 25

#define MIN_SPEED 100
#define MAX_SPEED 5000

int input(int*, int*, int*, int*, int*, int*);
int initialize_field(int*);
int get_int(char, int*);
void update(int*, int*);
int get_cell(const int*, int, int);
void set_cell(int*, int, int, int);
int neighbours_count(int*, int, int);
void switch_fields(int*, int*);
void draw(int*, int*, int, int, int);

int main() {
    int work = 1;
    int is_pause = 1;
    int tick = 0;
    int ticks_per_frame = MIN_SPEED;
    int cursorX = WIDTH / 2 - 1;
    int cursorY = HEIGHT / 2;

    int field0[HEIGHT * WIDTH] = {0};
    int field1[HEIGHT * WIDTH] = {0};

    // ввод с файла
    int status = 0;
    char temp_char;
    printf("Press ENTER to start");
    if (scanf("%c", &temp_char) == EOF) {
        work = 0;
    } else {
        if (temp_char == 'i') {
            status = initialize_field(field0);
        }
    }
    if (!freopen("/dev/tty", "r", stdin) || status != 0)
        work = 0;

    // инициализация ncurses
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, 1);
    keypad(stdscr, 1);
    cbreak();

    // основной цикл игры
    while (work) {
        input(field0, &work, &is_pause, &cursorX, &cursorY, &ticks_per_frame);

        if (!is_pause && tick == ticks_per_frame) {
            update(field0, field1);
            tick = 0;
        }

        erase();

        draw(field0, &is_pause, cursorX, cursorY, ticks_per_frame);

        refresh();

        tick++;
        if (tick > ticks_per_frame)
            tick = ticks_per_frame;
    }

    endwin();

    return 0;
}

int initialize_field(int* field) {
    int size_x = 0, size_y = 0;
    char key = -1;
    int status = get_int(' ', &size_x);

    if (status == 0)
        status = get_int('\n', &size_y);

    if (status == 0 && size_x <= WIDTH && size_y <= HEIGHT) {
        for (int y = 0; y < size_y; y++) {
            for (int x = 0; x < size_x; x++) {
                int cell;
                scanf("%c", &key);

                if (x == size_x - 1 && y != size_y - 1 && getchar() != '\n') {
                    status = 1;
                }

                if (key == EOF)
                    status = -1;

                if (key == '*')
                    cell = 1;
                else
                    cell = 0;

                set_cell(field, (WIDTH - size_x) / 2 + x, (HEIGHT - size_y) / 2 + y, cell);
            }
        }
    }
    return status;
}

int input(int* field, int* work, int* is_pause, int* cursorX, int* cursorY, int* ticks_per_frame) {
    int status = 0;
    int key = getch();

    if (key == 'q' || key == 4) {
        *work = 0;
    } else if (key == ' ') {
        *is_pause = !*is_pause;
    }

    if (*is_pause) {
        if (key == 260)
            *cursorX = (*cursorX - 1 + WIDTH) % WIDTH;

        else if (key == 261)
            *cursorX = (*cursorX + 1 + WIDTH) % WIDTH;

        else if (key == 259)
            *cursorY = (*cursorY - 1 + HEIGHT) % HEIGHT;

        else if (key == 258)
            *cursorY = (*cursorY + 1 + HEIGHT) % HEIGHT;

        else if (key == 10)
            set_cell(field, *cursorX, *cursorY, !get_cell(field, *cursorX, *cursorY));

    } else {
        if (key == 61 && *ticks_per_frame > MIN_SPEED) {
            *ticks_per_frame /= 1.1;

            if (*ticks_per_frame < MIN_SPEED)
                *ticks_per_frame = MIN_SPEED;

        } else if (key == 45 && *ticks_per_frame < MAX_SPEED) {
            *ticks_per_frame *= 1.1;

            if (*ticks_per_frame > MAX_SPEED)
                *ticks_per_frame = MAX_SPEED;
        }
    }

    return status;
}

int get_int(char delimiter, int* res) {
    int result = 0;
    int temp_status = scanf("%d", res);
    int temp_end = getchar();

    if (temp_status != 1 || temp_end != delimiter)
        result = 1;

    if (temp_status == EOF || temp_end == EOF)
        result = -1;

    return result;
}

void update(int* fieldOld, int* fieldNew) {
    int count;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            count = neighbours_count(fieldOld, x, y);

            set_cell(fieldNew, x, y, 0);
            if (get_cell(fieldOld, x, y)) {
                if (count < 2 || count > 3)
                    set_cell(fieldNew, x, y, 0);

                else
                    set_cell(fieldNew, x, y, 1);

            } else {
                if (count == 3)
                    set_cell(fieldNew, x, y, 1);
            }
        }
    }
    switch_fields(fieldOld, fieldNew);
}

int get_cell(const int* field, int x, int y) {
    x = (x + WIDTH) % WIDTH;
    y = (y + HEIGHT) % HEIGHT;

    return field[y * WIDTH + x];
}

void set_cell(int* field, int x, int y, int value) {
    x = (x + WIDTH) % WIDTH;
    y = (y + HEIGHT) % HEIGHT;

    field[y * WIDTH + x] = value;
}

int neighbours_count(int* field, int c_x, int c_y) {
    int count = 0;

    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (!(x == 0 && y == 0)) {
                count += get_cell(field, c_x + x, c_y + y);
            }
        }
    }
    return count;
}

void switch_fields(int* field1, int* field2) {
    for (int i = 0; i < HEIGHT * WIDTH; i++) {
        int temp = field1[i];
        field1[i] = field2[i];
        field2[i] = temp;
    }
}

void draw(int* field, int* is_pause, int cursorX, int cursorY, int delay) {
    mvprintw(0, 0, "Speed: %d", (MAX_SPEED - delay + MIN_SPEED) / 50);

    for (int i = 0; i < WIDTH + 2; i++) {
        mvprintw(1, i, "-");
        mvprintw(HEIGHT + 2, i, "-");
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (get_cell(field, x, y)) {
                mvprintw(y + 2, x + 1, "*");
            } else {
                mvprintw(y + 2, x + 1, " ");
            }
        }
    }
    if (*is_pause) {
        mvprintw(cursorY + 2, cursorX + 1, "-");

        mvprintw(HEIGHT + 3, 0, "SPACE - Run");
        mvprintw(HEIGHT + 6, 0, "Arrows - Move cursor");
        mvprintw(HEIGHT + 6, 40, "ENTER - Switch cell state");
    } else {
        mvprintw(HEIGHT + 3, 0, "SPACE - Pause");
    }
    mvprintw(HEIGHT + 3, 40, "Q - Exit");
    mvprintw(HEIGHT + 4, 0, "-/+ - Change game speed");
}
