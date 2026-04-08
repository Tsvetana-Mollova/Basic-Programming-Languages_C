/*
*7.	Да се напише програма, която намира последователност от числа в масив,които имат
*сума равна на число, въведено от  потребителя(ако има такава).
Примерен масив : 4,3,1,4,2,5,8  и число 11, изход:4,2,5
*/

#include <stdio.h>

int main() {
    int n, target_sum;
    printf("Vuvedete razmer na masiva: ");
    scanf("%d", &n);
    int arr[100];
    printf("Vuvedete elementi v masiva: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Vuvedete celevata suma: ");
    scanf("%d", &target_sum);

    for (int start = 0; start < n; start++)
    {
        int current_sum = 0;
        for (int end = start; end < n; end++)
        {
            current_sum += arr[end];
            if (current_sum == target_sum)
            {
                printf("Podmasiv s celevata suma %d: ", target_sum);
                for (int k = start; k <= end; k++)
                {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

//
// Created by Admin on 3/26/2026.
//