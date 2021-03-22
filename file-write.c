#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 19
#define FILE_CONTENT_SIZE 4096

/*
	when using expression like: 
	rand() % x
	x-1 will be the max
*/

int generate_rand_char() {
	int c = rand() % 128;
	return c;
}

char generate_rand_letter() {
	char l = 65 + rand() % 26;
	return l;
}

int generate_rand_number() {
	int n = rand() % 11;
	return n;
}

char *generate_file_name() {
	// xxxx-xxxx-xxxx-xxxx = 19 chars
	char *name;
	char c;

	name = malloc(sizeof (char) * (FILE_NAME_SIZE+1));

	for (int i = 0; i <= FILE_NAME_SIZE; ++i)
	{
		if ((i % 5 == 0 || i == 4) && (i != 0 && i != 5))
		{
			strcat(name, "-");
		} else {
			c = generate_rand_letter();
			name[i] = c;
		}
	}
	return name;
}

char *generate_file_content() {
	char *content;
	char c;

	content = malloc(sizeof (char) * (FILE_CONTENT_SIZE+1));

	for (int i = 0; i <= FILE_CONTENT_SIZE; ++i)
	{
		c = generate_rand_letter();
		content[i] = c;
	}

	return content;
}

void write_file_to_disk() {
	char *file_name;
	char *text;

	file_name = calloc(FILE_NAME_SIZE + 1, 1);
	file_name = generate_file_name();
	printf("%s\n", file_name);

	text = calloc (FILE_CONTENT_SIZE + 1, 1);
	text = generate_file_content();

	FILE *file = fopen(file_name, "w");
	if (file == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	} else {
		fprintf(file, "%s", text);
		fclose(file);
	}

	free(file_name);
	free(text);
}

void press_any_key_to_continue() {
	char pause = getchar();
}

void main() {
	time_t t;
	srand((unsigned) time(&t));

	while (1) {
		write_file_to_disk();

		press_any_key_to_continue();
	}
}