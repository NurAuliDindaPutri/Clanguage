#include <stdio.h>

int twoStacks(int maxSum, int a[], int n, int b[], int m) { //deklarasi fungsi dg nama twistacks yg menerima enam paramenter
    int sum = 0, count = 0, temp = 0, i = 0, j = 0; //untuk mendeklarasi bbrpa variabel yg akn digunakan dalam fungsi,sum untuk myimpna jumlah elemen dr stack,count untuk mnyimpn jmlh total elemen yg bs diambil dri kedua tumpukn,temp untuk penyimpnan sementra

    while (i < n && sum + a[i] <= maxSum) { //loop ini akn trs berjalan selama i < n,Jumlah saat ini (sum) ditambah elemen pada indeks i dalam a tidak melebihi batas maxSum.
        sum += a[i++]; // Elemen pada a[i] ditambahkan ke sum, dan i dinaikkan untuk pindah ke elemen berikutnya di a.
    }
    count = i; //nilai i ditetapkan ke count. Ini adalah nilai awal untuk jumlah elemen maksimum.

    while (j < m && i >= 0) {  //Looping kedua ini akan terus berjalan selama j < m dan tidak i < dari 0
        sum += b[j++]; // Menambahkan nilai b[j] ke sum dan meningkatkan j setiap kali loop berjalan.
        while (sum > maxSum && i > 0) { // looping nested. Looping ini akan terus berjalan selama sum lebih besar dari maxSum
            sum -= a[--i]; // ini akan mengurangi nilai a[i] dari sum dan mengurangi i setiap kali loop berjalan.
        }
        if (sum <= maxSum && i + j > count) { //Jika sum kurang dari atau sama dengan maxSum dan jumlah total elemen (i + j) lebih besar dari count
            count = i + j; //maka count akan diperbarui dengan nilai i + j.
        }
    }
    return count; //Mengembalikan nilai count setelah selesai menjalankan semua operasi di dalam fungsi.
}

int main() {
    int g; // Mendeklarasikan variabel g yang akan digunakan untuk menyimpan jumlah kasus uji.
    scanf("%d", &g);
    while (g--) { //Memulai loop while yang akan berjalan sebanyak g kali, yaitu sesuai dengan jumlah kasus uji yang diinputkan sebelumnya.
        int n, m, maxSum; //Mendeklarasikan variabel n, m, dan maxSum yang akan digunakan untuk menyimpan ukuran dua tumpukan (array) dan jumlah maksimum yang dapat ditambahkan dari kedua tumpukan tersebut.
        scanf("%d%d%d", &n, &m, &maxSum);
        int a[n], b[m]; // Mendeklarasikan dua array a dan b dengan ukuran sesuai dengan nilai n dan m yang telah diinputkan
        for (int i = 0; i < n; i++) { // Loop for untuk membaca nilai-nilai elemen dari tumpukan pertama (a) dan menyimpannya dalam array a.
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) { //Loop for untuk membaca nilai-nilai elemen dari tumpukan kedua
            scanf("%d", &b[i]); 
        }
        printf("%d\n", twoStacks(maxSum, a, n, b, m)); //Memanggil fungsi twoStacks dengan argumen jumlah maksimum yang dapat ditambahkan (maxSum),array tumpukan pertama (a), ukuran tumpukan pertama (n), array tumpukan kedua (b), dan ukuran tumpukan kedua (m). Hasil dari pemanggilan ini kemudian dicetak.
    }
    return 0; //Mengembalikan nilai 0 yang menandakan bahwa program telah berakhir dengan sukses.
}