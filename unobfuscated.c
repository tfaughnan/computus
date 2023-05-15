#include <stdio.h>
#include <stdlib.h>

struct date {
    int year;
    int month;
    int day;
};

/* "improved" anonymous gregorian */
struct date alg1(int y) {
    struct date easter;
    easter.year = y;

    int a = y % 19;
    int b = y / 100;
    int c = y % 100;
    int d = b / 4;
    int e = b % 4;
    int g = (8 * b + 13) / 25;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 19 * l) / 443;
    int n = (h + l - 7 * m + 90) / 25;
    int p = (h + l - 7 * m + 33 * n + 19) % 32;

    easter.month = n;
    easter.day = p;

    return easter;
}

/* gauss */
struct date alg2(int y) {
    struct date easter;
    easter.year = y;

    int a = y % 19;
    int b = y % 4;
    int c = y % 7;
    int k = y / 100;
    int p = (13 + 8 * k) / 25;
    int q = k / 4;
    int m = (15 - p + k - q) % 30;
    int n = (4 + k - q) % 7;
    int d = (19 * a + m) % 30;
    int e = (2 * b + 4 * c + 6 * d + n) % 7;

    easter.month = 3;
    easter.day = 22 + d + e;
    if (easter.day > 31) {
        easter.month++;
        easter.day %= 31;
    }

    return easter;
}

/* original anonymous gregorian */
struct date alg3(int y) {
    struct date easter;
    easter.year = y;

    int a = y % 19;
    int b = y / 100;
    int c = y % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;
    int n = (h + l - 7 * m + 114) / 31;
    int o = (h + l - 7 * m + 114) % 31;

    easter.month = n;
    easter.day = o + 1;

    return easter;
}


int main(int argc, char *argv[]) {
    /* TODO: should there be an acceptable range? e.g. 31-4999 */
    if (argc != 2) {
        printf("Usage: %s DATE\n", argv[0]);
    }

    int y = atoi(argv[1]);
    struct date easter = alg3(y);
    printf("%d-%02d-%02d\n", easter.year, easter.month, easter.day);

    return 0;
}
