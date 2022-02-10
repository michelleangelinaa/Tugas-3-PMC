/*
Nama: Michelle Angelina
NIM: 18320007
Tanggal: Kamis, 10 Februari 2022
*/

#include <stdio.h>
#include <stdlib.h>

struct kehadiran {
    char nama[100];
    int nim;
    int presence;
};

int main() {
    int n;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    if (n > 0) {
        struct kehadiran mhs[n];
        int i;
        for (i = 0; i<n; i++) {
            printf("Nama mahasiswa: ");
            scanf("%s", &mhs[i].nama);
            printf("NIM mahasiswa: ");
            scanf("%d", &mhs[i].nim);
            printf("Persentase kehadiran (tanpa tanda persen): ");
            scanf("%d", &mhs[i].presence);
            printf("\n");
        }

        printf("--------------------------------------------------\n");
        printf("Mahasiswa dengan kehadiran kurang dari 80%: \n");

        for (i = 0; i<n; i++) {
            if (mhs[i].presence < 80) {
                printf("%s ", mhs[i].nama);
                printf("%d\n", mhs[i].nim);
            }
        }

    }

    else {
        printf("Angka tidak valid.");
    }

    return 0;
}
