#include <stdio.h>
#include <string.h>

int str_compare(char a[], char b[]) {
    int len_a = strlen(a), len_b = strlen(b);
    if (len_a > len_b)
        return 1;
    if (len_a < len_b)
        return -1;
    
    for (int i = 0; i < len_a; i++) {
        if (a[i] == b[i])
            continue;
        
        if (a[i] < b[i])
            return 1;
        else
            return -1;
    }
    
    return 0;
}

int main()
{
    char sentence[100];
    char word[100][50];
    int word_count = 0;

    scanf("%[^\n]", sentence);

    char *w = strtok(sentence, " ");
    while (w) {
        strcpy(word[word_count++], w);
        w = strtok(NULL, " ");
    }
    
    for (int i = 0; i < word_count - 1; i++)
        for (int j = i + 1; j < word_count; j++)
            if (str_compare(word[i], word[j]) == -1) {
                char tmp[50];
                strcpy(tmp, word[i]);
                strcpy(word[i], word[j]);
                strcpy(word[j], tmp);
            }

    for (int i = 0; i < word_count; i++)
        printf("%s\n", word[i]);

    return 0;
}
