#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("sample.txt", "w");
    fprintf(fp, "OS Lab Program");
    fclose(fp);

    fp = fopen("sample.txt", "r");

    printf("File Content:\n");
    while((ch = fgetc(fp)) != EOF)
        printf("%c", ch);

    fclose(fp);

    return 0;
}
