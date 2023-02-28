#include "Student.h"
#include "cmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    Student s1, s2;
    s1.set_name((char*)"Vlad");
    s2.set_name((char*)"Mihai");

    s1.set_math_grade(8.2);
    s2.set_math_grade(9.2);
    printf("%s|math_grade: %f\n",   s1.get_name(), s1.get_math_grade());
    printf("%s|math_grade: %f\n\n", s2.get_name(), s2.get_math_grade());

    s1.set_english_grade(9.1);
    s2.set_english_grade(9.1);
    printf("%s|english_grade: %f\n",   s1.get_name(), s1.get_english_grade());
    printf("%s|english_grade: %f\n\n", s2.get_name(), s2.get_english_grade());

    s1.set_history_grade(9);
    s2.set_history_grade(8.5);
    printf("%s|history_grade: %f\n",   s1.get_name(), s1.get_history_grade());
    printf("%s|history_grade: %f\n\n", s2.get_name(), s2.get_history_grade());

    printf("%s|average_grade: %f\n",   s1.get_name(), s1.get_average_grade());
    printf("%s|average_grade: %f\n\n", s2.get_name(), s2.get_average_grade());

    printf("cmp_name: %d\n",          cmp_name(s1, s2));
    printf("cmp_math_grade: %d\n",    cmp_math_grade(s1, s2));
    printf("cmp_english_grade: %d\n", cmp_english_grade(s1, s2));
    printf("cmp_history_grade: %d\n", cmp_history_grade(s1, s2));
    printf("cmp_average_grade: %d\n\n", cmp_average_grade(s1, s2));


    srand(time(0));
    int students_count = 5;
    Student * S = new Student[students_count];
    S[0].set_math_grade(4.5);
    S[1].set_math_grade(8.2);
    S[2].set_math_grade(9.9);
    S[3].set_math_grade(8.8);
    S[4].set_math_grade(3.3);

    for (int i = 0; i < students_count - 1; i++) {
        for (int j = i + 1; j < students_count; j++)
            if (cmp_math_grade(S[i], S[j]) == 1) {
                Student tmp = S[i];
                S[i] = S[j];
                S[j] = tmp;
            }
    }

    for (int i = 0; i < students_count; i++)
        printf("%f ", S[i].get_math_grade());

    delete[] S;
    return 0;
}
