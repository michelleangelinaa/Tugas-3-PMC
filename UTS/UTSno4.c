#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataPenduduk {
    int NIK;
    char NamaLengkap[50];
    char TempatLahir[50];
    int TanggalLahir;
    int umur;
    char JenisKelamin[50];
    char GolonganDarah[50];
    char StatusPerkawinan[50];
    char Pekerjaan[50];
} DataPenduduk;

typedef struct ListDataPenduduk {
    DataPenduduk buffer[1000];
    int tail;
} ListDataPenduduk;

void printData(DataPenduduk D) {
    printf("\n---Data Penduduk----\n");
    printf("NIK: %d\n", D.NIK);
    printf("Nama Lengkap: %s\n", D.NamaLengkap);
    printf("tempat lahir: %s\n", D.TempatLahir);
    printf("Tanggal Lahir (DDMMYYYY): %d\n", D.TanggalLahir);
    printf("Umur: %d\n", D.umur);
    printf("Jenis Kelamin: %s\n", D.JenisKelamin);
    printf("Golongan Darah: %s\n", D.GolonganDarah);
    printf("Status Perkawinan: %s\n", D.StatusPerkawinan);
    printf("Pekerjaan: %s\n", D.Pekerjaan);
}

DataPenduduk addData() {
    DataPenduduk tempData;
    char tempNIK[50];
    char tempNama[50];
    char tempTempatLahir[50];
    char tempTanggalLahir[50];
    char tempUmur[50];
    char tempjenisKelamin[50];
    char tempGolonganDarah[50];
    char tempStatusPerkawinan[50];
    char tempPekerjaan[50];



    printf("NIK: ");
    scanf(" %[^\n]s", &tempNIK);
    // printf("%d", atoi(tempNIK));
    printf("Nama Lengkap: ");
    scanf(" %[^\n]s", &tempNama);
    printf("Tempat lahir: ");
    scanf(" %[^\n]s", &tempTempatLahir);
    printf("Tanggal Lahir (DD/MM/YY): ");
    scanf(" %[^\n]s", &tempTanggalLahir);
    printf("Umur: ");
    scanf(" %[^\n]s", &tempUmur);
    printf("Jenis Kelamin: ");
    scanf(" %[^\n]s", &tempjenisKelamin);
    printf("Golongan Darah: ");
    scanf(" %[^\n]s", &tempGolonganDarah);
    printf("Status Perkawinan: ");
    scanf(" %[^\n]s", &tempStatusPerkawinan);
    printf("Pekerjaan: ");
    scanf(" %[^\n]s", &tempPekerjaan);

    tempData.NIK = atoi(tempNIK);
    // printf("%d", atoi(tempNIK));
    strcpy(tempData.NamaLengkap, tempNama);
    strcpy(tempData.TempatLahir, tempTempatLahir);
    tempData.TanggalLahir = atoi(tempTanggalLahir);
    strcpy(tempData.JenisKelamin, tempjenisKelamin);
    strcpy(tempData.GolonganDarah, tempGolonganDarah);
    strcpy(tempData.StatusPerkawinan, tempStatusPerkawinan);
    strcpy(tempData.Pekerjaan, tempPekerjaan);
    tempData.umur = atoi(tempUmur);

    // printf("----");
    // printData(tempData);
    // printf("Nama Lengkap: %s\n", tempData.NamaLengkap);
    // printf("tempat lahir: %s\n", tempData.TempatLahir);
    // printf("Tanggal Lahir (DD/MM/YY): %s\n", tempData.TanggalLahir);
    // printf("Umur: %d\n", tempData.umur);
    // printf("Jenis Kelamin: %s\n", tempData.JenisKelamin);
    // printf("Golongan Darah: %s\n", tempData.GolonganDarah);
    // printf("Status Perkawinan: %s\n", tempData.StatusPerkawinan);
    // printf("Pekerjaan: %s\n", tempData.Pekerjaan);
    return tempData;




}

void create(DataPenduduk D, ListDataPenduduk *LD) {
    (*LD).buffer[++(*LD).tail] = D;
}

int searchIndex(ListDataPenduduk LD, int NIK, char *Nama, int Umur) {
    for (int i=0; i<1000; i++) {
        if (NIK == LD.buffer[i].NIK && strcmp(Nama, LD.buffer[i].NamaLengkap) == 0 && Umur == LD.buffer[i].umur) {
            return i;
        }
    }
    return -1;
}

void readFile(char *filename, ListDataPenduduk *LD) {
    FILE* fp = fopen(filename, "r");

    if (!fp) {
        printf("File not exists\n");
    }
    else {
        {
        DataPenduduk tempData;
        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            // Memisahkan data dari file eksternal
            char* value = strtok(buffer, ";");

            while (value) {
                // Column 1
                if (column == 0) {

                }
                if (column == 1) {
                    tempData.NIK = atoi(value);
                }

                // Column 2
                if (column == 2) {
                    strcpy(tempData.NamaLengkap, value);
                }

                // Column 3
                if (column == 3) {
                    strcpy(tempData.TempatLahir, value);
                }
                if (column == 4) {
                    tempData.TanggalLahir = atoi(value);
                }
                if (column == 5) {
                    tempData.umur = atoi(value);
                }
                if (column == 6) {
                    strcpy(tempData.JenisKelamin, value);
                }
                if (column == 7) {
                    strcpy(tempData.GolonganDarah, value);
                }
                if (column == 8) {
                    strcpy(tempData.StatusPerkawinan, value);
                }
                if (column == 9) {
                    strcpy(tempData.Pekerjaan, value);
                }

                value = strtok(NULL, ";");
                column++;
            }
            create(tempData, LD);

            printf("\n");
        }

        // Close file
        fclose(fp);
    }
    }
}

void delete(int idx, ListDataPenduduk *LD) {
    for (int i=idx; i<(*LD).tail; i++) {
    (*LD).buffer[idx] = (*LD).buffer[idx+1];
    }
    (*LD).tail++;
}
void update(int idx, ListDataPenduduk *LD) {
    DataPenduduk tempData = addData();
    (*LD).buffer[idx] = tempData;
}



int main() {
    DataPenduduk D;
    ListDataPenduduk LD;
    LD.tail = -1;
    int opt = -1;

    while (opt != 0) {
    printf("\nSelamat datang di Data Kependudukan\n");
    printf("Input fitur:\n");
    printf("0. Keluar \n");
    printf("1. Tambahkan data(create)\n");
    printf("2. Hapus data(delete)\n");
    printf("3. Update data(update)\n");
    printf("4. Import data(csv)\n");
    printf("5. Pencarian data(search)\n");
    scanf(" %d", &opt);
    if (opt == 0) {
        printf("Keluar\n");
    }
    else if (opt == 1) {
        printf("Tambahkan Data Baru\n");
        D = addData();
        create(D, &LD);
    }
    else if (opt == 2) {
        printf("Hapus Data\n");
        printf("Masukkan data\n");
        int idx;
        int NIK;
        char Nama[50];
        int Umur;

        //input;
        printf("NIK: ");
        scanf("%d", &NIK);
        printf("Nama Lengkap: ");
        scanf(" %[^\n]s", &Nama);
        printf("Umur: ");
        scanf("%d", &Umur);

        idx = searchIndex(LD, NIK, Nama, Umur);
        delete(idx, &LD);
    }
    else if (opt == 3) {
        printf("Update Data\n");
        printf("Masukkan data lama\n");
        int idx;
        int NIK;
        char Nama[50];
        int Umur;

        //input;
        printf("NIK: ");
        scanf("%d", &NIK);
        printf("Nama Lengkap: ");
        scanf(" %[^\n]s", &Nama);
        printf("Umur: ");
        scanf("%d", &Umur);

        idx = searchIndex(LD, NIK, Nama, Umur);
        printf("\nMasukkan Data Baru\n");
        update(idx, &LD);
    }
    else if (opt == 4) {
        printf("Import Data\n");
        char filename[100];
        printf("Masukkan nama file: ");
        scanf(" %[^\n]s", &filename);
        readFile(filename, &LD);
    }
    else if (opt == 5) {
        int idx;
        int NIK;
        char Nama[50];
        int Umur;

        //input;
        printf("NIK: ");
        scanf("%d", &NIK);
        printf("Nama Lengkap: ");
        scanf(" %[^\n]s", &Nama);
        printf("Umur: ");
        scanf("%d", &Umur);

        idx = searchIndex(LD, NIK, Nama, Umur);
        if (idx != -1) {
        printData(LD.buffer[idx]); }
        else {
            printf("Data tidak ditemukan\n");
        }
    }
    else {
        printf("input salah \n");
    }
    }

    return 0;
}
