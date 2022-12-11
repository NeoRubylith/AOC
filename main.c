#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt", "r");

    int vals[4];
    unsigned long long contained = 0, overlap = 0;

    while (!feof(input)) {
        fscanf(input, "%d-%d,%d-%d\n", &vals[0], &vals[1], &vals[2], &vals[3]);
        
		int c = (vals[0] >= vals[2] && vals[1] <= vals[3] )|| (vals[0] <= vals[2] && vals[1] >= vals[3]),
            o = (vals[0] >= vals[2] && vals[0] <= vals[3]) || (vals[1] >= vals[2] && vals[1] <= vals[3]);
        contained += c;
        overlap += o | c;
        
        printf("%d-%d, %d-%d", vals[0], vals[1], vals[2], vals[3]);
		if (c && o) {
			printf(" Both!\n");
		} else if (c) {
            printf(" Match!\n");
        } else if (o) {
            printf(" Overlap!\n");
        } else {
			printf(" No\n");
		}
    }

    printf("Contained: %llu\nOverlap: %llu\n", contained, overlap);
    fclose(input);
    return 0;
}