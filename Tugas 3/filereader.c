/*
Nama   : Michelle Angelina
NIM    : 18320007
Tanggal: 29 Januari 2022
*/

// Input library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* KAMUS */
    FILE *file;
    char filename[50];
    char pdfname[54];
    char jpgname[54];

    printf("Masukkan nama file (tanpa ekstensi/format): "); //Input nama file
    scanf("%s", filename); //Membaca file

    strcpy(pdfname, filename);
    strcpy(jpgname, filename);
    strcat(pdfname, ".pdf");
    strcat(jpgname, ".jpg");

    if (file = fopen(pdfname, "r")) {
        printf("Format file %s berupa pdf", filename);
    }
    else if (file = fopen(jpgname, "r")) {
        printf("Format file %s berupa jpg", filename);
    }
    else {
        printf("Format file %s unidentified", filename);
    }

    return 0;
}
