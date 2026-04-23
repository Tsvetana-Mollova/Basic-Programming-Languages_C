/*
 *4з. В училището на Ели има 1 ≤ N ≤ 100,000 човека. Някои от тях се познават с други,
 *като Ели знае, че съществуват 1 ≤ M ≤ 1,000,000 такива приятелства. Тя иска да напише програма,
 *която бързо отговаря кои са приятелите на даден човек. Ако хората се подават с номера като цяло число,
 *както и приятелите им изведете при поискан човек колко приятели има. (ако 1 е приятел с 3
 *то и 3 е приятел с 1).
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;

    printf("Vavedi broi hora N i broi priatelstva M:\n");
    scanf("%d %d", &N, &M);

    int *degree = (int *)calloc(N + 1, sizeof(int));
    if (degree == NULL) {
        printf("Greshka pri zadelqne na pamet.\n");
        return 1;
    }

    int *U = (int *)malloc(M * sizeof(int));
    int *V = (int *)malloc(M * sizeof(int));
    if (U == NULL || V == NULL) {
        printf("Greshka pri zadelqne na pamet.\n");
        free(degree);
        return 1;
    }

    printf("Vavedi %d priatelstva po dve chisla (a b):\n", M);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        U[i] = a;
        V[i] = b;

        degree[a]++;
        degree[b]++;
    }

    int *start = (int *)malloc((N + 2) * sizeof(int));
    if (start == NULL) {
        printf("Greshka pri zadelqne na pamet.\n");
        free(degree);
        free(U);
        free(V);
        return 1;
    }

    start[1] = 0;
    for (int i = 2; i <= N + 1; i++) {
        start[i] = start[i - 1] + degree[i - 1];
    }

    int *friends = (int *)malloc((2 * M) * sizeof(int));
    if (friends == NULL) {
        printf("Greshka pri zadelqne na pamet.\n");
        free(degree);
        free(U);
        free(V);
        free(start);
        return 1;
    }

    int *current = (int *)malloc((N + 1) * sizeof(int));
    if (current == NULL) {
        printf("Greshka pri zadelqne na pamet.\n");
        free(degree);
        free(U);
        free(V);
        free(start);
        free(friends);
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        current[i] = start[i];
    }

    for (int i = 0; i < M; i++) {
        int a = U[i];
        int b = V[i];

        friends[current[a]++] = b;
        friends[current[b]++] = a;
    }

    int Q;
    printf("Kolko zapitvaniq iskash da napravish?\n");
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        int person;
        printf("Vavedi nomer na chovek:\n");
        scanf("%d", &person);

        if (person < 1 || person > N) {
            printf("Nevqrn nomer na chovek.\n");
            continue;
        }

        int count = degree[person];
        printf("Chovek %d ima %d priqteli.\n", person, count);

        if (count == 0) {
            printf("Toi/tya nqma priqteli.\n");
        } else {
            printf("Priatelite sa: ");
            for (int i = start[person]; i < start[person + 1]; i++) {
                printf("%d ", friends[i]);
            }
            printf("\n");
        }
    }

    free(degree);
    free(U);
    free(V);
    free(start);
    free(friends);
    free(current);

    return 0;
}