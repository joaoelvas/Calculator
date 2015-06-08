#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int main(int argc, char *argv[])
{
	int counter = 1;
	int mem[MAX_SIZE];
	int control = -1;
	initialize(mem, MAX_SIZE-1);

	while(counter < argc - 1) {

		if (strcasecmp(argv[counter],"store") == 0) {
			control = 1;
		} else if (strcasecmp(argv[counter],"print") == 0) {
			control = 2;
		} else if (strcasecmp(argv[counter],"copy") == 0) {
			control = 3;
		} else if (strcasecmp(argv[counter],"add") == 0) {
			control = 4;
		} else if (strcasecmp(argv[counter],"sub") == 0) {
			control = 5;
		} else if (strcasecmp(argv[counter],"mul") == 0) {
			control = 6;
		} else if (strcasecmp(argv[counter],"div") == 0) {
			control = 7;
		} else if (strcasecmp(argv[counter],"mod") == 0) {
			control = 8;
		} else if (strcasecmp(argv[counter],"fact") == 0) {
			control = 9;
		} else if (strcasecmp(argv[counter],"equals") == 0) {
			control = 10;
		}



		switch(control) {
			case 1 : store(atoi(argv[counter+1]),atoi(argv[counter+2]), mem);
				break;
			case 2 : print(atoi(argv[counter+1]), mem); 
					 counter--;
				break;
			case 3 : copy(atoi(argv[counter+1]),atoi(argv[counter+2]), mem);
				break;
			case 4 : add(atoi(argv[counter+1]),atoi(argv[counter+2]), mem);
				break;
			case 5 : sub(atoi(argv[counter+1]),atoi(argv[counter+2]), mem);
				break;
			case 6 : mul(atoi(argv[counter+1]),atoi(argv[counter+2]), mem);
				break;
			case 7 : divi(atoi(argv[counter+1]),atoi(argv[counter+2]), mem);
				break;
			case 8 : mod(atoi(argv[counter+1]),atoi(argv[counter+2]), mem);
				break;
			case 9 : fact(atoi(argv[counter+1]),atoi(argv[counter+2]), mem);
				break;
			case 10 : equal(atoi(argv[counter+1]),atoi(argv[counter+2]), mem);
				break;
		}

		counter = counter + 3;
	}


	return 0;
}

initialize(int *m, int max) {
	while(max >= 0) {
		*(m + max) = 0;
		max--;
	}
}

store(int i, int x, int *m) {
	*(m + i) = x;
}

print(int i, int *m) {
	printf("%d\n", *(m+i));
}

copy(int m1, int m2, int *m) {
	*(m + m1) = *(m + m2);
}

add(int m1, int m2, int *m) {
	*(m + m1) += *(m + m2);
}

sub(int m1, int m2, int *m) {
	*(m + m1) -= *(m + m2);
}

mul(int m1, int m2, int *m) {
	*(m + m1) *= (*(m + m2));
}

divi(int m1, int m2, int *m) {
	if((*(m + m2)) == 0) {
		*(m + m1) = 0; } else {
	*(m + m1) /= (*(m + m2)); }
}

mod(int m1, int m2, int *m) {
	if((*(m + m2)) == 0) {
		*(m + m1) = 0; } else {
	*(m + m1) %= (*(m + m2)); }
}

fact(int m1, int m2, int *m) {
	if((*(m + m2)) < 0) {
		*(m + m1) = 0; } else {
	*(m + m1) = factorial(*(m + m2)); }
}

int factorial(int n) {
	while(n != 1) {
		return (n * factorial(n-1));
	}
	 return 1;
}

equal(int m1, int m2, int *m) {
 	if((*(m + m1)) == (*(m + m2))) {
 		*(m + m1) = 1;
 	} else *(m + m1) = 0;
}