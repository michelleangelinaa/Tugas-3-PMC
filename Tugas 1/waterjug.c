/*
Nama   : Michelle Angelina
NIM    : 18320007
Tanggal: 19 Januari 2022
*/

//Input library
#include <stdio.h>
#include <stdlib.h>

//Kode Utama
int main() {
    //Kamus variabel
    int emb3 = 0; //Ember 3 L
    int emb5 = 0; //Ember 5 L
    int end = 0;
    int opt;

    printf("Selamat datang di program water jug\n");
    printf("Program akan berakhir bila terdapat ember yang berisi 4 Liter\n");


    while (!end) { //Selama end masih 0, !end = 1 karena end = 0
        printf("ember 3 liter: %d liter\n", emb3);
        printf("ember 5 liter: %d liter\n\n", emb5);
        printf("instruksi: \n");
        printf("1. Isi ember 3 liter\n");
        printf("2. Isi ember 5 liter\n");
        printf("3. Kosongkan ember 3 liter\n");
        printf("4. Kosongkan ember 5 liter\n");
        printf("5. Tuang isi ember 3 liter ke ember 5 liter\n");
        printf("6. Tuang isi ember 5 liter ke ember 3 liter\n");

        printf("Masukkan pilihan: ");
        scanf("%d", &opt);
        printf("\n");
        if (opt == 1) { //Isi ember 3 L penuh
            emb3 = 3;
        }
        else if (opt == 2) { //Isi ember 5 L penuh
            emb5 = 5;
        }
        else if (opt == 3) { //Kosong
            emb3 = 0;
        }
        else if (opt == 4) { //Kosong
            emb5 = 0;
        }
        else if (opt == 5) { //Tuang ke ember 5 Liter
            int maxPindah = 5 - emb5; //Slot air yang bisa dipindah
            int pindah;
            if (emb3 > maxPindah) { //Kalau di ember 3 Liter kelebihan air buat dipindah
                pindah = maxPindah; //Pindah sesuai maksimal air yang bisa dipindah
            }
            else {
                pindah = emb3; //Seluruh air dipindah ke ember 5 Liter
            }
            emb3 -= pindah; //Ember 3 Liter dikurangi pindahan
            emb5 += pindah; //Ember 5 Liter ditambahi pindahan

        }
        else if (opt == 6) { //Tuang ke ember 3 Liter
            int maxPindah = 3 - emb3; //Slot air yang bisa dipindah
            int pindah;
            if (emb5 > maxPindah) { //Kalau di ember 5 Liter kelebihan air buat dipindah
                pindah = maxPindah; //Pindah sesuai maksimal air yang bisa dipindah
            }
            else {
                pindah = emb5; //Seluruh air dipindah ke ember 3 Liter
            }
            emb3 += pindah; //Ember 3 Liter ditambahi pindahan
            emb5 -= pindah; //Ember 5 Liter dikurangi pindahan
        }


    if (emb5 == 4) { //Memenuhi syarat
        end = 1; //Proses selesai
    }
    }

    return 0; //end
}
