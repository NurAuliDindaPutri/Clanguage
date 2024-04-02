#include <stdio.h>
#include <stdlib.h>

// Definisikan struktur batu
struct Stone { 
    struct Stone* link;
    char* alphabet;
};

int main() {
    // Inisialisasi batu-batu
    struct Stone l1, l2, l3, l4, l5, l6, l7, l8, l9;

    // Inisialisasi huruf pada masing-masing batu
    l1.link = NULL;
    l1.alphabet = "F";

    l2.link = NULL;
    l2.alphabet = "M";

    l3.link = NULL;
    l3.alphabet = "A";

    l4.link = NULL;
    l4.alphabet = "I";

    l5.link = NULL;
    l5.alphabet = "K";

    l6.link = NULL;
    l6.alphabet = "T";

    l7.link = NULL;
    l7.alphabet = "N";

    l8.link = NULL;
    l8.alphabet = "O";

    l9.link = NULL;
    l9.alphabet = "R";

    // Hubungkan batu-batu sesuai arah panah
    l3.link = &l6;
    l6.link = &l9;
    l9.link = &l4;
    l4.link = &l7;
    l7.link = &l1;
    l1.link = &l8;
    l8.link = &l2;
    l2.link = &l5;
    l5.link = &l3;

    // Akses data dari l3
    printf("%s", l3.link->link->link->alphabet); //I
    printf("%s", l3.link->link->link->link->alphabet); //N
    printf("%s", l3.link->link->link->link->link->alphabet); //F
    printf("%s", l3.link->link->link->link->link->link->alphabet); //O
    printf("%s", l3.link->link->alphabet); //R
    printf("%s", l3.link->link->link->link->link->link->link->alphabet); //M
    printf("%s", l3.alphabet); //A
    printf("%s", l3.link->alphabet); //T
    printf("%s", l3.link->link->link->alphabet); //I
    printf("%s", l3.link->link->link->link->link->link->link->link->alphabet); //K
    printf("%s", l3.alphabet); //A

    printf("\n");
}
