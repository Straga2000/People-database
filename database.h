#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include<iostream>
#include<algorithm>
#include<string.h>
#include<fstream>
using namespace std;

#define MAXPERS 100

class person
{
    private:

        char name[200], sex;
        int year;

    public:

        person(char *name_value, int birth, char sex_value)
        {
            strcpy(name, name_value);
            year = birth;
            sex = sex_value;
        }

        person(const person &pers)
        {
            strcpy(name, pers.name);
            year = pers.year;
            sex = pers.sex;
        }

        person operator = (person a)
        {
            strcpy(name, a.name);
            year = a.year;
            sex = a.sex;
        }

        char* get_name()
        {
            return name;
        }

        char get_sex()
        {
            return sex;
        }

        int get_year()
        {
            return year;
        }

        void set_name(char* name_value)
        {
            strcpy(name, name_value);
        }

        void set_sex(char sex_value)
        {
            sex = sex_value;
        }

        void set_year(int year_value)
        {
            year = year_value;
        }

        void print_person()
        {
            if (sex == 'M')
                cout<<"His name is "<<name<<", born in "<<year<<". He is male.\n";
            else
                cout<<"Her name is "<<name<<", born in "<<year<<". She is female.\n";

        }
};

class database
{
    private:
        person *person_list[MAXPERS];
        int counter;

    public:
        database()
        {
            counter = 0;
            for(int i = 0; i < MAXPERS; i++)
                person_list[i] = NULL;
        }

        ~database()
        {
            delete person_list;
        }

        void add_person(person *pers)
        {
            for(int i = 0; i < MAXPERS; i++)
                if(person_list[i] == NULL)
                    {
                        person_list[i] = pers;
                        break;
                    }
            counter++;
        }

        void get_person(int i)
        {
            person_list[i]->print_person();
        }

        void refresh_counter()
        {
            counter = 0;
            for(int i = 0; i < MAXPERS; i++)
            {
                //cout<<"Aici merge\n";
                if(person_list[i] != NULL)
                {
                     counter++;
                }
            }
        }

        void print_database()
        {
            //cout<<counter<<"\n";
            for(int i = 0; i < MAXPERS; i++)
                if(person_list[i] != NULL)
                    person_list[i]->print_person();
            cout<<"\n";
        }

        bool year_comparator(person *a, person *b)
        {
            return (a->get_year() > b->get_year());
        }

        bool name_comparator(person *a, person *b)
        {
            return (strcmp(a->get_name(), b->get_name()) > 0);
        }

        void sort_by_year()
        {
            for(int i = 0; i< MAXPERS; i++)
                for(int j = i; j < MAXPERS; j++)
                    if(person_list[i] != NULL && person_list[j] != NULL)
                        if (year_comparator(person_list[i], person_list[j]))
                            swap(person_list[i], person_list[j]);
        }

        void sort_by_name()
        {
            for(int i = 0; i< MAXPERS; i++)
                for(int j = i; j < MAXPERS; j++)
                    if(person_list[i] != NULL && person_list[j] != NULL)
                            if (name_comparator(person_list[i], person_list[j]))
                                swap(person_list[i], person_list[j]);
        }

        void print_database_by_year()
        {
            sort_by_year();
            print_database();
        }

        void print_database_by_name()
        {
            sort_by_name();
            print_database();
        }

        void delete_person(char *name_value)
        {
            for(int i = 0; i < MAXPERS; i++)
                if (person_list[i] != NULL && strcmp(person_list[i]->get_name(), name_value) == 0)
                    person_list[i] = NULL;

            refresh_counter();
        }

        void delete_person(int year)
        {
            for(int i = 0; i < MAXPERS; i++)
                if (person_list[i] != NULL && person_list[i]->get_year() == year)
                    person_list[i] = NULL;

            refresh_counter();
        }

        void delete_person(char sex)
        {
            for(int i = 0; i < MAXPERS; i++)
                if (person_list[i] != NULL && person_list[i]->get_sex() == sex)
                    person_list[i] = NULL;

            refresh_counter();
        }
};

#endif // DATABASE_H_INCLUDED
