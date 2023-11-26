#include <stdio.h>

int main() {
	int i, house;
    int M, x, y;
    scanf("%d %d %d", &M, &x, &y); // Read the number of cops (M), cops' speed (x), and search time (y)

    int cop_houses[M];
    for (i = 0; i < M; i++) {
        scanf("%d", &cop_houses[i]); // Read the house numbers where the cops are residing
    }

    int safe_houses = 0;

    for (house = 1; house <= 100; house++) {
        int safe = 1; // Assume the house is safe

        for (i = 0; i < M; i++) {
            // Calculate the range of houses a cop can cover
            int left_limit = cop_houses[i] - x * y;
            int right_limit = cop_houses[i] + x * y;

            // Check if the house is within the range that the cops can search
            if (house >= left_limit && house <= right_limit) {
                safe = 0; // The house is not safe
                break;
            }
        }

        safe_houses += safe;
    }

    printf("%d\n", safe_houses);

    return 0;
}


