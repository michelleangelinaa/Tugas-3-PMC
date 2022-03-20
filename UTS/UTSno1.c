#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binaryconvert(int decimal) {
    // REFERENSI: https://www.javatpoint.com/c-program-to-convert-decimal-to-binary
    int binary[17]; // Biner yang digunakan adalah biner 16 bit
    int i;

    for (i = 0; decimal > 0; i++) {
        binary[i] = decimal % 2;

        // Pengurangan angka karena basenya 2
        decimal /= 2;
    }

    // Output
    for(i = i-1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    return binary[17];
}

int hexaconvert(long long decimal) {
    // REFERENSI: https://www.sanfoundry.com/c-program-convert-decimal-hex/
    long long hasilbagi;
    long sisa;
    char hex[10];
    int j;

    hasilbagi = decimal;

    while (hasilbagi != 0) {
        sisa = hasilbagi % 16; // Basis 16
        int j;

        if (sisa < 10) {
            hex[j] = 48 + sisa;
            ++j;
        }
        else {
            hex[j] = 55 + sisa;
            hasilbagi /= 16;
            ++j;
        }
    }

    // Output
    for (int i = j; i >= 0; i--) {
        printf("%c", hex[i]);
    }

    return hex;
}

int decimalconvert(int binary) {
    int dec = 0;
    int remain = 0;
    int i;

    while (binary != 0) {
        remain = binary % 10;
        binary /= 10;
        dec += remain * pow(2, i);
        i++;
    }

    return dec;
}

int main() {
    int digit[17];
    int a;
    int i;

    // Input nilai
    printf("Masukkan nilai digit kedua dan ketiga NIM Anda\nKemudian gabungkan tiga digit terakhir dari NIM Anda (misal: 13207021 -> 32021): ");
    scanf("%d",&digit);

    // Konversi
    printf("\nHasil konversi desimal ke biner: ");
    binaryconvert(digit);

    // Konversi ke 1's complement
    for (i = 0; i < 17; i++) {
        if (digit[i] == 0) {
            digit[i] = 1;
        }
        else {
            digit[i] = 0;
        }
    }

    int carry = 1; // Penambahan 1 ke biner
    // Konversi ke 2's complement
    for (i = 0; i < 17; i++) {
        if (digit[i] == 1 && carry == 1) {
            digit[i] = 0;
            carry = 1;
        }
        else if (digit[i] == 0 && carry == 1) {
            digit[i] = 1;
            carry = 0;
        }
        else {
            digit[i] = digit[i];
        }
    }

    printf("\nHasil konversi ke 2's Complement: %d", digit);

    // Mencari variabel A, a.k.a Least Significant Byte = 8 bit
    for (a = 7; a >= 0; a--) {
        a = a + (digit[a]*pow(10, a));
    }

    int deca = 0;
    deca = decimalconvert(a);

    // Operasi biner
    int x1, y1, x2, y2, x3, y3;

    x1 = 193; //10100101
    y1 = 239; // 11101111
    x2 = 219; // 11011011
    y2 = 243; // 11110011
    x3 = 47; // 00101111
    y3 = 165; // 10100101

    int op1;
    int op2;
    int op3;

    op1 = (deca & y1) ^ x1;
    op2 = (~(y2 >> 4) && 2) + deca;
    op3 = ((x3 >> 2) | y3) * deca;

    int pil = 0;
    // Pilihan menu untuk output tabel
    printf("\n\n1. (A&y)^x");
    printf("\n2. (~(y>>4)&&x)+A");
    printf("\n3. ((x>>2)|y)*A");
    printf("\nPilih jenis operasi (1/2/3): ");
    scanf("%d", &pil);

    if (pil == 1) {
        printf("Hasil (A&y)^x: %d", binaryconvert(op1));
    }

    else if (pil == 2) {
        printf("Hasil (~(y>>4)&&x)+A: %d", binaryconvert(op2));
    }

    else if (pil == 3) {
        printf("Hasil ((x>>2)|y)*A: %d", binaryconvert(op3));
    }

    else {
        printf("Pilihan tidak valid.");
    }

    printf("\n");
    return 0;
}
