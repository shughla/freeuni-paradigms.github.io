#include <stdio.h>

/**
აქ მოცემულია short, მაგრამ იგულისხმეთ, რომ სტრაქტის ზომა წინასწარ არ იცით
**/

short nthElement1(short* arrPtr, int n) {
	return arrPtr[n];
}

short nthElement2(short* arrPtr, int n) {
	return 0;
}

short nthElement3(short* arrPtr, int n) {
	return 0;
}


int main() {
	// შექმენით ასეთივე მასივი, ოღონდ []-ის გარეშე
	short arr[] = {3, 5, 6, 7};
	printf("first %s\n", nthElement1(arr, 3) == nthElement2(arr, 3) ? "passes" : "fails");
	printf("second %s\n", nthElement1(arr, 3) == nthElement3(arr, 3) ? "passes" : "fails");
}