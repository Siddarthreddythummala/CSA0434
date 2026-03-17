#include <stdio.h>
#include <string.h>

int main() {
    char line[100], word[20];

    FILE *fp = fopen("sample.txt", "r");

    printf("Enter word to search: ");
    scanf("%s", word);

    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, word))
            printf("Matched Line: %s", line);
    }

    fclose(fp);
    return 0;
}
