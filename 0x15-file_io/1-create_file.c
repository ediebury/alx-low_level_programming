#include "main.h"

/**
 * create_file - Creates a file with the specified permissions and content.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: On success, returns 1. On failure, returns -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written, content_length = 0;

	if (filename == NULL)
		return (-1);

	/* Get the length of the content string */
	if (text_content != NULL)
	{
		while (text_content[content_length])
			content_length++;
	}

	/* Create the file with rw------- permissions */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	/* Write the content to the file */
	if (text_content != NULL)
	{
		bytes_written = write(fd, text_content, content_length);
		if (bytes_written == -1 || bytes_written != content_length)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

