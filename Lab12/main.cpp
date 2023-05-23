#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum tip {
    prieten, cunoscut, coleg
};

class Contact
{
protected:
    string nume;
public:
    tip t;
    Contact(string n, tip _t) {
        nume = n;
        t = _t;
    }
    virtual string getNume()
    {
        return nume;
    }
};

class Prieten : public Contact
{
public:
    string data, telefon, adresa;
};

class Cunoscut : public Contact
{
public:
    string telefon;
};

class Coleg : public Contact
{
public:
    string telefon, firma, adresa;
};

class Agenda
{
private:
    vector<Contact*> agenda;

public:
    Agenda();
    bool find(string n) 
    {
        for (int i = 0; i < agenda.size(); i++)
            if (agenda[i]->getNume() == n) return 1;
        return 0;
    }

    vector<Prieten*> getFriends()
    {
        vector<Prieten*> p;
        for (int i = 0; i < agenda.size(); i++)
            if (agenda[i]->t == prieten) p.push_back((Prieten*)agenda[i]);
        return p;
    }

    void deleteContact(string n)
    {
        for (int i = 0; i < agenda.size(); i++)
            if (agenda[i]->getNume() == n) {
                break;
            }
    }

    void add(Contact* c)
    {
        agenda.push_back(c);
    }
};

int main()
{
    return 0;
}
