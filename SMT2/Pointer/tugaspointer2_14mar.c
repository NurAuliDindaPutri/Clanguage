#include <stdio.h> // MENDECLARE LIBRARY
#include <stdlib.h>
#include <string.h>

// DECLARE MAKSIMUM DAN MINIMUM UNTUK TEXT LENGTH
#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

// MEMBUAT FUNGSI UNTUK MENAMPILKAN OUTPUT BERDASARKAN KONDISI LENGTH TEXT KURANG DARI
void lessThanRequired (){
    printf("The length of your text is less than specified, please update your text\n");
}

// MEMBUAT FUNGSI UNTUK MENAMPILKAN OUTPUT BERDASARKAN KONDISI LENGTH TEXT SAMA
void equalThanRequired (){
    printf("Thank you, Your text length is correct\n");
}

// MEMBUAT FUNGSI UNTUK MENAMPILKAN OUTPUT BERDASARKAN KONDISI LENGTH TEXT LEBIH DARI DARI
void moreThanRequired (){
    printf("Your text is too long, please reduce the text\n");
}

// // MEMBUAT FUNGSI UNTUK MELAKUKAN CEK TERHADAP LENGTH TEXT
int checkLenghtRequirement(char* text){ // Mendeclare karakter pointer text sebagai input
    int length = strlen(text); // menghitung length text menggunakan strlen
    if (length < MIN_LENGTH) // kondisional jika length kurang dari minimum length
        return 0; // mengembalikan nilai 0 ( text too short)
    else if (length == MIN_LENGTH) // kondisional jika length sama dengan minimum length
        return 1; // mengembalikan nilai 1 ( text is exact length )
    else if (length <= MAX_LENGTH)  // kondisional jika length kurang dari sama dengan maximum length
        return 2; // mengembalikan nilai 2 ( text is within the correct range)
    else // kondisional jika length lebih dari maximum length text
        return 3; // mengembalikan nilai 3 ( text is too long )
}

// mendeclare main program
int main() {
    int length, lengthOfText, selectOption; // mendeclare 3 variabel 
    FILE *fptr = NULL; // mendeclare file pointer ke next text file dengan deklarasi NULL
    char text[MAX_LENGTH]; // mendeclare karakter array text untuk alokasi tempat penyimpanan text dari file 

    fptr = fopen("file.txt", "r"); // pointer fptr yang dimaksud adalah untuk membuka file "file.txt"

    if(fptr == NULL){ // membuat kondisional jika file yang dituju tidak ditemukan, maka program mengeluarkan output "Error"
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr); // setelah file berhasil ditemukan dan dibuka, selanjutnya adalah membaca satu baris dari text yang ada dalam file 

    fclose(fptr); // lalu file ditutup

    selectOption = checkLenghtRequirement(text); // memanggil fungsi checklengthrequirement untuk mendapatkan jawaban mengenai termasuk di bagian mana jika diukur length textnya

    // memanggil fungsi untuk mengecek kembali text menggunakan array untuk berdasarkan length text status yang didapat dari fungsi checkLenghtRequirement.
    void (*functions[3])() = {lessThanRequired, equalThanRequired, moreThanRequired}; // 
    lengthOfText = (MIN_LENGTH * (selectOption == 0)) + (MIN_LENGTH * (selectOption == 2));
    functions[selectOption]();

    printf("\nThe Length is updated to %d", lengthOfText); // memberikan output ditambah hasil yang telah didapat dari fungsi lengthoftext (melalui proses pengecekan)

    return 0; // mengembalikan nilai tanda bahwa program telah berhasil dijalankan
}
