#include <stdio.h>
#include <x86intrin.h>

#define len 512

int main() {
	FILE *input = fopen("input.txt", "r");

	char lines[3][len + 1];

	unsigned long long total = 0;
	while (fgets(lines[0], len, input) && fgets(lines[1], len, input) && fgets(lines[2], len, input)) {
		__m128i swapMask = {~(0LL), 0};
		for (int line = 0; line < 3; line++) {
			for (int i = 0, ch = 0; ch = (int)lines[line][i], ch != '\0' && ch != '\n'; i++) {
				swapMask[1] |= swapMask[0] & (long long)(1ULL << (ch - (ch > 0x5a ? 0x61 : 0x27)));
			}
			swapMask = _mm_cvtsi64_si128(_mm_extract_epi64(swapMask, 1));
		}
		total += _tzcnt_u64(_mm_cvtsi128_si64(swapMask)) + 1;
	}

	printf("%llu\n", total);
	fclose(input);
	return 0;
}
