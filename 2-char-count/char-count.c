// PID: 730875102
// I pledge the COMP211 honor code.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26
#define CHART_HEIGHT 10

static void count_characters(int counts[ALPHABET_SIZE]);
static int total_count(const int counts[ALPHABET_SIZE]);
static int max_count(const int counts[ALPHABET_SIZE]);
static void print_counts(const int counts[ALPHABET_SIZE]);
static void print_percents(const int counts[ALPHABET_SIZE], int total);
static void print_chart(const int counts[ALPHABET_SIZE], int max);

int main(void) {
    int counts[ALPHABET_SIZE] = {0};

    count_characters(counts);

    int total = total_count(counts);
    int max = max_count(counts);

    print_counts(counts);
    printf("\n");
    print_percents(counts, total);
    printf("\n");
    print_chart(counts, max);

    return EXIT_SUCCESS;
}

static void count_characters(int counts[ALPHABET_SIZE]) {
    int c;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            counts[tolower(c) - 'a']++;
        }
    }
}

static int total_count(const int counts[ALPHABET_SIZE]) {
    int total = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        total += counts[i];
    }

    return total;
}

static int max_count(const int counts[ALPHABET_SIZE]) {
    int max = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (counts[i] > max) {
            max = counts[i];
        }
    }

    return max;
}

static void print_counts(const int counts[ALPHABET_SIZE]) {
    printf("Counts:\n");

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (counts[i] > 0) {
            printf("%c: %d\n", 'a' + i, counts[i]);
        }
    }
}

static void print_percents(const int counts[ALPHABET_SIZE], int total) {
    printf("Percents:\n");

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (counts[i] > 0) {
            double percent = (double)counts[i] / total * 100.0;
            printf("%c: %.1f%%\n", 'a' + i, percent);
        }
    }
}

static void print_chart(const int counts[ALPHABET_SIZE], int max) {
    int heights[ALPHABET_SIZE];

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        heights[i] =
            (max > 0) ? (int)((double)counts[i] / max * CHART_HEIGHT) : 0;
    }

    printf("Chart:\n");

    for (int row = 0; row < CHART_HEIGHT; row++) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (heights[i] >= CHART_HEIGHT - row) {
                putchar('|');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        putchar('a' + i);
    }
    putchar('\n');
}
