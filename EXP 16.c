#include <stdio.h>

struct emp {
    int id;
    char name[20];
};

int main() {
    struct emp e;
    FILE *fp;

    fp = fopen("emp.dat", "wb+");

    printf("Enter ID and Name: ");
    scanf("%d %s", &e.id, e.name);

    fwrite(&e, sizeof(e), 1, fp);
    rewind(fp);
    fread(&e, sizeof(e), 1, fp);

    printf("Employee ID: %d\n", e.id);
    printf("Employee Name: %s\n", e.name);

    fclose(fp);
    return 0;
}
