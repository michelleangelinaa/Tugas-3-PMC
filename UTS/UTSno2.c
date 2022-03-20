#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 1.602*pow(10,-19)
#define c 2.9979*pow(10,8)
#define mo 9.109*pow(10,-31)

float massarelativistik(float tegangan) {
    // V = mc^2 - moc^2,
    // maka V = c^2(m-mo)
    // sehingga m = mo + V/c^2
    float mass;
    mass = mo + (e*(tegangan*pow(10,6))/pow(c, 2));

    return mass;
}

float kecepatanrelativistik(float mass) {
    // m/mo = (1-(v/c)^2)(-1/2)
    // m/mo = 1/(1-(v/c)^2)^(1/2)
    // m^2/mo^2 = 1/(1-(v/c)^2)
    // m^2 * (1-(v/c)^2) = mo^2
    // (1-(v/c)^2) = (mo/m)^2
    // 1 - (mo/m)^2 = (v/c)^2
    // c^2 * (1 - (mo/m)^2) = v^2
    // c((1 - (mo/m)^2))^(1/2) = v

    float velocity;

    velocity = c*pow((1 - pow((mo/mass),2)), 0.5);

    return velocity;
}

void output(float data[10]) {
    for (int i = 0; i < 10; i++) {
        printf("Data %d\t: %.2e\n", i+1, data[i]);
    }
}

int main() {
    float ve[10]; // Array of kecepatan, 10 data
    float m[10]; // Array of mass, 10 data
    float V[10]; // Array of tegangan, 10 data
    int i;

    // REFERENSI: Praktikum EL2208 Modul 02 Praktikum Pemecahan Masalah dengan C
    FILE* fp;
    fp = fopen("tegangan.txt", "r");

    if (fp == NULL) {
        printf("File error.");
        return 0;
    }

    for (i=0; i<10; i++) {
        fscanf(fp, "%f", &V[i]);
    }

    // Print tegangan dari tegangan.txt
    printf("Data tegangan yang terbaca:\n");
    output(V);

    // Menghitung massa relativistik
    for (i = 0; i < 10; i++) {
        m[i] = massarelativistik(V[i]);
    }

    // Print massa relativistik
    printf("\nData massa relativistik dari data tegangan:\n");
    output(m);

    // Menghitung kecepatan relativistik
    for (i = 0; i < 10; i++) {
        ve[i] = kecepatanrelativistik(m[i]);
    }

    // Print kecepatan relativistik
    printf("\nData kecepatan relativistik dari data massa:\n");
    output(ve);

    fclose(fp);
    return 0;
}
