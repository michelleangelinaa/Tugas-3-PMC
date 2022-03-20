#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define r 20*pow(10,3)
#define c 183007*pow(10,-12)
#define vin 5
#define tao r*c

int main() {
    // REFERENSI: https://www.tutorialspoint.com/c_standard_library/c_function_clock.htm
    // REFERENSI: https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-clock-determine-processor-time
    double waktu;
    waktu = clock()*pow(10,-3); // Milisekon

    printf("Nilai konstanta waktu adalah %.2e sekon\n", tao);

    double vt;
    while (vt != vin){
        vt = vin*( 1 - exp(-waktu/(tao)));
        printf("\nSaat t = %f s, Vout bernilai %.2f V", waktu, vt);

        // Supaya waktunya bergerak harus dipanggil terus menerus
        waktu = clock()*pow(10,-3);
    }

    return 0;
}
