#include "Student.h"
#include <string.h>

void Student::set_name(char s[])
{
    strcpy(name, s);
}

char* Student::get_name()
{
    return name;
}

void Student::set_math_grade(float g)
{
    if (g >= 0 && g <= 10)
        math_grade = g;
}

float Student::get_math_grade()
{
    return math_grade;
}

void Student::set_english_grade(float g)
{
    if (g >= 0 && g <= 10)
        english_grade = g;
}

float Student::get_english_grade()
{
    return english_grade;
}

void Student::set_history_grade(float g)
{
    if (g >= 0 && g <= 10)
        history_grade = g;
}

float Student::get_history_grade()
{
    return history_grade;
}

float Student::get_average_grade()
{
    return (math_grade + english_grade + history_grade) / 3;
}

