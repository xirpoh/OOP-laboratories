#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int string_to_int(char s[]) 
{
    int n = strlen(s);
    int nr = 0;
    for (int i = 0; i < n; ++i) {
        nr = nr * 10 + (s[i] - '0');
    }
    return nr;
}

int main() 
{
    FILE* fp = fopen("in.txt", "r");
    char line[100];
    int sum = 0;
    while (fscanf(fp, "%s", line) > 0)
        sum += string_to_int(line);
    printf("%d", sum);

    return 0;
}
