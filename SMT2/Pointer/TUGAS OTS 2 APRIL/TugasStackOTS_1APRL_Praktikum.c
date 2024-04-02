#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 //untuk mendefine maxsize dengan maksimal nilai 100

char stack[MAX_SIZE]; //medeklarasi array tipe data char dg ukuran max size,digunkn untuk mnyimpn data dlm stack
int top = -1; //digunkn untuk mengecek posisi plg ats dr stck,klau kosong nilai top jdi -1


void push(char c) { // dg pramnter c bertipe data chr untuk Menambahkan karakter ke stack
  if (top == MAX_SIZE - 1) { //untuk memeriksa apakah stack sudah penuh atau belum
    printf("Stack Overflow!\n");  //pesan dcetak kelayar
    return; //mengakhiri program
  }
  stack[++top] = c; //jika stack blm penuh,prmntr c dtmbhkn kdlm stck pd posisi top+1 dn nilai top diprbrui
}

// Menghapus karakter dari stack
char pop() {
  if (top == -1) { //kondisi utk memeriksa stck sdh kosong atau blm,artinya sctk sdh kosong
    printf("Stack Underflow!\n"); //maka dicetak pesan 
    return -1; //untuk mngmblikn nilai -1
  }
  return stack[top--]; //jk stck tdk kosong,karakter yg brda di plg ats stck,akn dihps dr stck dn nilai top dikurg 1
}

// Memeriksa apakah karakter adalah kurung buka
int isOpeningBracket(char c) { //deklarasi paramenter c bertipe chr dn mngmblikn nilai int
  return (c == '(' || c == '{' || c == '['); // fungsi untuk mngmblikn nilai 1 (true),jk krkrtr c adlh slh stu dr kurung trsbt.jkbkn mk mngmblikn nilai 0 (flse)
}

// Memeriksa apakah karakter adalah kurung tutup
int isClosingBracket(char c) {
  return (c == ')' || c == '}' || c == ']');
}

// Memeriksa apakah dua karakter adalah pasangan yang seimbang
int isMatchingPair(char a, char b) { //deklrasi dua prmntr a dn b brtpe chr dn mngmblikan nilai int
  return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')); //fungsi mngmblikn nilai 1(true),jk psngn krktr a dn b adlh psngn krg seimbng,jk tdk fgsi ini mngmblikn nilai 0(false)
}

// Fungsi untuk memeriksa keseimbangan tanda kurung
int isBalanced(char *str) { 
  int i; 
  for (i = 0; str[i] != '\0'; i++) { //ini akn ngeloop sbyk krkter pd indeks i smpai krkter null ditmukn 
    if (isOpeningBracket(str[i])) { //kondisi mmriksa apkh krkter dlm itersi mrupkn kurung buka
      push(str[i]); //jika iya krkter trsbut dimsukkn kdlm stack dg fungsi ini
    } else if (isClosingBracket(str[i])) { //kondisi ke2 untuk mmeriksa apkh krkter saat ini adlh kurung tutup,jk iya mk dlkukn pngecekn apkh krkter trsbut berpsngn krg buka trsbt
      if (top == -1 || !isMatchingPair(pop(), str[i])) { // dicek apkh stack kosong dan apkh krktr krg ttp saat ni mmliki psgn krg bka yg sesuai ap tdk
        return 0; 
      }
    }
  }
  return (top == -1); //diluar loop dilkukn pengcekn apkh stck kosong/tdk,jk ksong brrti smua  psgn kurung telah seimbang/sdh bnr
}

int main() {
  char str[MAX_SIZE]; //untuk mnyimpan string yg diinput user
  printf ("Masukkan urutan tanda kurung : "); //untuk mencetak pesan kelayar
  scanf("%s", str);

  if (isBalanced(str)) { //mmngil fungsi is balanced
    printf("YES\n"); //mencetak yes jika input benar
  } else {
    printf("NO\n"); //mencetak no jika input salah
  }

  return 0; //program diakhiri
}
