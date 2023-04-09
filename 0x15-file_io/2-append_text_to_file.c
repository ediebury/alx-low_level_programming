#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: A pointer to the text to append.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         O/w - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	o = open(filename, O_WRONLY | O_APPEND);
	if (o == -1)
		return (-1);

	while (text_content[len])
		len++;

	w = write(o, text_content, len);
	if (w == -1)
	{
		close(o);
		return (-1);
	}

	close(o);

	return (1);
}

