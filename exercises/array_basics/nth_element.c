#include <stdio.h>

/**
აქ მოცემულია short, მაგრამ იგულისხმეთ, რომ სტრაქტის ზომა წინასწარ არ იცით
**/

short nthElement1(short* arrPtr, int n) {
	
}

/**
გამოიყენეთ pointer არითმეტიკა
**/
short nthElement2(short* arrPtr, int n) {
	
}

/**
დაკასტეთ პოინტერი და ხელით გააკეთეთ არითმეტიკა
*/
short nthElement3(short* arrPtr, int n) {

}


int main() {
	// შექმენით ასეთივე მასივი, ოღონდ []-ის გარეშე
	short arr[] = {3, 5, 6, 7};
	printf("second %s\n", nthElement1(arr, 3) == nthElement2(arr, 3) ? "passes" : "fails");
	printf("third %s\n", nthElement1(arr, 3) == nthElement3(arr, 3) ? "passes" : "fails");
}