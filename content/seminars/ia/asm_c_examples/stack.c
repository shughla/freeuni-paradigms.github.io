void overflow(int *i) {
	*i = *i+1;
	printf("%d\n", *i);
	printf("*****%u\n", i);
	overflow(i);
}

int main() {

	int i = 0;
	overflow(&i);
}

