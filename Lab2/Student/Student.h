#pragma once

class Student
{
    char name[20];
    float math_grade, english_grade, history_grade;

    public:
        void set_name(char s[]);
        char* get_name();

        void set_math_grade(float g);
        float get_math_grade();

        void set_english_grade(float g);
        float get_english_grade();

        void set_history_grade(float g);
        float get_history_grade();

        float get_average_grade();
};
