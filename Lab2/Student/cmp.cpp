#include "Student.h"

int cmp_name(Student a, Student b)
{
    char* s1 = a.get_name();
    char* s2 = b.get_name();
    int i = 0;
    while (s1[i] && s2[i]) {
        if (s1[i] > s2[i]) return 1;
        if (s1[i] < s2[i]) return -1;
        i++;
    }

    if (s1[i] && !s2[i]) return 1;
    if (!s1[i] && s2[i]) return -1;
        
    return 0;
}

int cmp_grades(float grade_a, float grade_b)
{
    float d = grade_a - grade_b;
    return (d == 0) ? 0 : ((d > 0) ? 1 : -1);
}

int cmp_math_grade(Student a, Student b)
{
    return cmp_grades(a.get_math_grade(), b.get_math_grade());
}

int cmp_english_grade(Student a, Student b)
{
    return cmp_grades(a.get_english_grade(), b.get_english_grade());
}

int cmp_history_grade(Student a, Student b)
{
    return cmp_grades(a.get_history_grade(), b.get_history_grade());
}

int cmp_average_grade(Student a, Student b) 
{
    return cmp_grades(a.get_average_grade(), b.get_average_grade());
}
