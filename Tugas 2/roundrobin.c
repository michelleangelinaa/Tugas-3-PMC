/*
Nama   : Michelle Angelina
NIM    : 18320007
Tanggal: 26 Januari 2022
*/

//Input library
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* KAMUS */
    int waktu;
    int n;
    printf("Masukkan jumlah proses: ");
    scanf("%d", &n);
    int end = 0;

    int input [n][3];

    int i;
    int j;

    int antrian [n];


    waktu = 0;
    int nextKuantum = 100;

    int currentInput = -1;

    /* Ini buat masukin -1*/
    for (i=0; i<n; i++) {
            antrian[i] = -1;

    }

    printf("Masukkan waktu datang dan durasi eksekusi setiap baris bergantian:\n");
    for (i=0; i<n; i++) {
        input[i][0] = i;
        for (j=1; j<3; j++) {
            scanf("%d", &input[i][j]);

        }
    }
/*
    for (i=0; i<n; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }
*/

    for (i=0; i<n; i++) {
        if (input[i][1] == 0) {
            for (j=0; j<n; j++) {
                if (antrian[j] == -1) {
                    antrian[j] = input[i][0];

                    currentInput += 1;

                    break;
                }
            }

        }

    printf("\n --------------------------------------------------------------------------------------------- \n");
    printf("Waktu = %d \n", waktu);
    printf("Kuantum selanjutnya = %d \n", nextKuantum);


    printf("\n --------------------------------------- ANTRIAN ---------------------------------------------- \n");
     for (i=0; i<n; i++) {
            if (antrian[i] != -1) {
           printf("P%d ", antrian[i]);
            }
    }

    printf("\n --------------------- PROSES | WAKTU DATANG | SISA DURASI UNTUK EKSEKUSI --------------------- \n");
    for (i=0; i<n; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", input[i][j]);
            printf("||");
        }
        printf("\n");
    }

   if (antrian[0] == -1 && currentInput == n-1) {
        end = 1;
    }
    printf("///////////////////////////////////////////////////////////////////////////////////////////////\n\n\n");
    }







    while (!end) {


    int index = antrian[0];
    int durasi = input[index][2];

    int a = nextKuantum;
    int b = input[index][2] + waktu;

    int p;
/*
    printf("b = %d", b);
    printf("currentInput = %d", currentInput);
*/
    int c;
    if (currentInput >= n-1) {
        c = 99999;
        p = 0;
    }
    else {
    c = input[currentInput+1][1];
    p = input[currentInput+1][0];
    }
/*
    printf("p = %d", p);
    printf("min = %d", c);
*/
//Asumsikan waktu masuk proses tidak pernah sama dengan durasi eksekusi proses lain
//Asumsikan waktu masuk proses tidak sama dengan satu sama lainnya
//Asumsikan waktu datang dan durasi tidak pernah ada yang sama

    if (a < b && a < c) {
           // printf("here1");
        // Pengurangan waktu proses
        input[index][2] -= (nextKuantum - waktu);
        // update waktu
        waktu = nextKuantum;
        // update nextKuantum
        nextKuantum += 100;
        // Geser proses
        int pindah = antrian[0];
        for (i=0; i<n; i++) {
            if (antrian[i+1] == -1) {
                antrian[i] = pindah;
                break;
            }
            else {
                antrian[i] = antrian[i+1];
            }
        }
    }

    else if (b <= a && b < c){
           // printf("here2 \n");
         //   printf("index = %d \n", index);
        // Pengurangan waktu proses
        input[index][2] = 0;
        // update waktu
        waktu += durasi;
        // printf("durasi = %d\n", durasi);
        // update nextKuantum
        nextKuantum = waktu + 100;
        // Geser
        for (i=0; i<n; i++) {
            if ((antrian[i+1] == -1) || (i == n-1)) {
                antrian[i] = -1;
                break;
            }
            else {
                antrian[i] = antrian[i+1];
            }
        }
    }

    else {

        // Pengurangan waktu proses
        input[index][2] -= (c - waktu);

        // update waktu
        waktu = c;
        //Update antrian
        for (i=0; i<n; i++) {
            if (antrian[i] == -1) {
                antrian[i] = p;

                currentInput += 1;

                break;
            }
        }
    }

    printf("\n ---------------------------------------------------------------------------------------------- \n");
    printf("Waktu = %d \n", waktu);
    printf("Kuantum selanjutnya = %d \n", nextKuantum);

    printf("\n --------------------------------------- ANTRIAN ---------------------------------------------- \n");
    for (i=0; i<n; i++) {
            if (antrian[i] != -1) {
           printf("P%d ", antrian[i]);
            }
    }

    printf("\n --------------------- PROSES | WAKTU DATANG | SISA DURASI UNTUK EKSEKUSI --------------------- \n");
    for (i=0; i<n; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", input[i][j]);
            printf("||");
        }
        printf("\n");
    }

    if (antrian[0] == -1 && currentInput == n-1) {
        end = 1;
    }
    printf("///////////////////////////////////////////////////////////////////////////////////////////////\n\n\n");
    }


	return 0;
}
