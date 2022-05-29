
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TrimStr(char *buf)
{
    if (!buf)
        return NULL;

    char *initialStart = buf;

    // trim start whitespaces
    while (buf != 0 && (*buf == ' ' || *buf == '\n' || *buf == '\r' || *buf == '\t'))
        buf++;

    // trim trailing whitespaces
    char *pEnd = initialStart + strlen(initialStart) - 1;
    while (pEnd > buf && (*pEnd == ' ' || *pEnd == '\n' || *pEnd == '\r' || *pEnd == '\t'))
        pEnd--;

        // printf("New size = %ld\n startPtr = %ld stopPtr = %ld", (size_t)(pEnd - buf + 1), (size_t)buf, (size_t)pEnd);
#if 1
    char *newLine = (char *)malloc((size_t)(pEnd - buf + 1));
    strncpy(newLine, buf, (size_t)(pEnd - buf + 1));
    // char *newLine = (char *)realloc(initialStart, 200);
#else
    // char *newLine = strdup(buf);
    char *newLine = strndup(buf, (size_t)(pEnd - buf) + 1);
#endif
    // free(initialStart);

    return newLine;
}

int main()
{
    // const char input[] = "    String for input!  \
    // ";
    const char input[] = "      \
    ";
    char *tempIn = (char *)malloc(sizeof(input));
    strncpy(tempIn, input, sizeof(input));
    printf("Input string=|%s|\n", input);
    printf("Trimmed=|%s|\n", TrimStr(tempIn));

    FILE *streamRd;
    FILE *streamWr;
    // char *line = NULL;
    // size_t len = 0;
    size_t len = 30;
    char *line = (char *)malloc(len);
    int lineSize;

    streamRd = fopen("/home/antonh/Desktop/my_projects/read_file_str_trim/file.txt", "r");
    if (!streamRd)
    {
        printf("RD File open error");
        return -1;
    }

    streamWr = fopen("/home/antonh/Desktop/my_projects/read_file_str_trim/fileOut.txt", "w");
    if (!streamWr)
    {
        printf("WR File open error");
        return -1;
    }

    while ((lineSize = getline(&line, &len, streamRd)) != -1)
    {
        printf("lineSize=%d lenAlloc=%ld line=%s\n", lineSize, len, line);
        char *newLine = TrimStr(line);
        fprintf(streamWr, "%s\n", newLine);
        free(newLine);
    }
    free(line);

    return 0;
}