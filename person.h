#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#endif // PERSON_H_INCLUDED

#include<iostream>
#include<algorithm>
#include<string.h>
#include<fstream>
using namespace std;

class person
{
    private:

        char name[200], sex;
        int year;

    public:

        person(char *name_value, int birth, char sex_value);
        person(const person &pers);
        operator = (person a);

        char* get_name();
        char get_sex();
        int get_year();

        void set_name(char* name_value);
        void set_sex(char sex_value);
        void set_year(int year_value);

        void print_person();

        friend ostream& operator <<(ostream& output, const person &p);
        friend istream& operator >>(istream& input, person &p);
};

ostream& operator <<(ostream& output, const person &p)
{
    output<<p.name<<" "<<p.year<<" "<<p.sex<<"\n";
}

istream& operator >>(istream& input, person &p)
{
    input>>p.name;
    input>>p.year;
    input>>p.sex;
};

person::person(char *name_value, int birth, char sex_value)
{
    strcpy(name, name_value);
    year = birth;
    sex = sex_value;
}

person::person(const person &pers)
{
    strcpy(name, pers.name);
    year = pers.year;
    sex = pers.sex;
}

person::operator = (person a)
{
    strcpy(name, a.get_name());
    year = a.get_year();
    sex = a.get_sex();
}

char* person::get_name()
{
    return name;
}

char person::get_sex()
{
    return sex;
}

int person::get_year()
{
    return year;
}

void person::set_name(char* name_value)
{
    strcpy(name, name_value);
}

void person::set_sex(char sex_value)
{
    sex = sex_value;
}

void person::set_year(int year_value)
{
    year = year_value;
}

void person::print_person()
{
    if (sex == 'M')
        cout<<"His name is "<<name<<", born in "<<year<<". He is male.\n";
    else
        cout<<"Her name is "<<name<<", born in "<<year<<". She is female.\n";

}
