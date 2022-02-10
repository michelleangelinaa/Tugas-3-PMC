/*
Nama: Michelle Angelina
NIM: 18320007
Tanggal: Kamis, 10 Februari 2022
*/

#include <stdio.h>
#include <stdlib.h>

struct kehadiran {
    int num;
    char nama[64];
    int nim;
    float presence;
};

struct kehadiran mhs[50];
int urutan = 0;

void pilih(void) {
    printf("Menampilkan data mahasiswa atau menambahkan mahasiswa?: \n");
    printf("a: Menambah mahasiswa\n");
    printf("b: Menampilkan data mahasiswa\n");
}

void addmhs(void) {
    mhs[urutan].num = urutan+1;
    printf("Nama mahasiswa: ");
    scanf_s("%63s", &mhs[urutan].nama, 64);
    printf("NIM mahasiswa: ");
    scanf_s("%i", &mhs[urutan].nim);
    printf("Persentase kehadiran mahasiswa: ");
    scanf_s("%f", &mhs[urutan].presence);

    urutan++;

}

void tampilan(void) {
    int i;
    for (i=0; i<urutan; i++) {
        if (mhs[urutan].presence < 80) {
            printf("Mahasiswa dengan kehadiran di bawah 80%: \n");
            printf("Nama: %s \n", mhs[i].nama);
            printf("NIM: %i\n", mhs[i].nim);
            printf("---------------------------\n");
        }
        }
    }


int main() {
    char c;
    pilih();
    printf("---------------------\n");

    int TRUE = 1;

    while (TRUE) {
        c = getchar();

        if (c == 'a') {
            addmhs();
            break;
        }
        else if (c == 'b') {
            tampilan();
            break;
        }
        else {
            printf("masuk ke else");
            return 0;
        }
    }

    return 0;
}
