#include <main.h>
#include <stdlib.h>

/**
 * read_textfile - Reads and prints a text file to stdout
 * @filename: Pointer to a string containing the name of the file to read
 * @letters: Maximum number of letters to read and print
 *
 * Return: The actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	FILE *file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	char *buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	ssize_t count = fread(buffer, sizeof(char), letters, file);
	if (count == 0)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	ssize_t written = fwrite(buffer, sizeof(char), count, stdout);
	if (written != count)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	fclose(file);
	free(buffer);

	return (count);
}

