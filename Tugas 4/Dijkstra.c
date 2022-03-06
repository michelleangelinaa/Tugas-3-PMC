#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INFINITY 9999 // Asumsikan jarak antar titik tidak pernah mencapai 9999
#define MAX 100 // Asumsikan titik checkpoint tidak mencapai 100

int main() {
    // KAMUS
    int node = 0;
    int i;
    int j;
    int jarak;

    // Input matriks jarak-jarak titik
    printf("Masukkan jumlah titik checkpoint: ");
    scanf("%d", &node);

    int matrix[node][node];

    matrix[0][0] = 0;
    for (i = 0; i < node; i++) {
        for (j = i+1; j < node; j++) {
            printf("Masukkan jarak tempuh dari titik %d ke %d: ", i+1, j+1);
            scanf("%d", &jarak);

            matrix[i][j] = matrix[j][i] = jarak;
            matrix[j][j] = 0;
        }
        printf("\n");
    }

    printf("\nJarak tempuh titik-titik: \n");
    for (i = 0; i < node; i++) {
        for (j = 0; j < node; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    int init = 0;

  // Matrix
  for (i = 0; i < node; i++) {
    for (j = 0; j < node; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][j] = INFINITY;
      }
      else {
        matrix[i][j] = matrix[i][j];
      }
    }
  }

  int dist[MAX], pred[MAX];
  int done[MAX], count, mindist, nextnode;

  for (i = 0; i < node; i++) {
    dist[i] = matrix[0][i];
    pred[i] = 0;
    done[i] = 0;
  }

  // Declare
  dist[0] = 0;
  done[0] = 1;
  count = 1;

  while (count < node-1) {
    mindist = INFINITY;

    for (i = 0; i < node; i++)
      if (dist[i] < mindist && !done[i]) {
        mindist = dist[i];
        nextnode = i;
      }

    // Perhitungan jarak
    done[nextnode] = 1;
    for (i = 0; i < node; i++)
      if (!done[i])
        if (mindist + matrix[nextnode][i] < dist[i]) {
          dist[i] = mindist + matrix[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Output
  for (i = 0; i < node; i++)
    if (i != 0) {
      printf("\nJarak tempuh terdekat dari 1 ke %d: %d", i+1, dist[i]);
    }

    return 0;
}
