#pragma once

class Number
{
private:
    char *value;
    int base;
    bool sign;

public:
    Number(const char *value, int base); // where base is between 2 and 16
    ~Number();

    Number(const Number &n);
    Number(Number &&n);
    Number(const int);
    
    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const; // returns the number of digits for the current number
    int GetBase() const; // returns the current base

    char operator[] (int idx);

    friend Number operator+ (const Number &x, const Number &y);
    friend Number operator- (const Number &x, const Number &y);
    Number& operator+= (const Number &n);

    bool operator> (const Number &n);
    bool operator< (const Number &n);
    bool operator== (const Number &n);

    Number& operator= (const Number &n);
    Number& operator= (Number &&n);
    Number& operator= (const int n);
    Number& operator= (const char *s);

    void operator-- ();
    void operator-- (int);

private:
    int get_int() const;
};

int conv_dig2int(char d);
char conv_dig2chr(int d);

