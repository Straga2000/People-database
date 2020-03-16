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
                cout<<"Aici merge\n";
                if(person_list[i] != NULL)
                {
                     counter++;
                }
            }
        }

        void print_database()
        {
            cout<<counter<<"\n";
            for(int i = 0; i < MAXPERS; i++)
                if(person_list[i] != NULL)
                    {
                        //cout<<i<<": ";
                        person_list[i]->print_person();
                    }
                    //person_list[i]->print_person();
                    //get_person(i);
            cout<<"\n";
        }

        bool year_comparator(person *a, person *b)
        {
            if (a == NULL)
                return false;

            if (b == NULL)
                return true;

            if (a != NULL && b != NULL)
            {
                int y1 = 0, y2 = 0;

                y1 = a->get_year();
                y2 = b->get_year();

                return (y1 > y2);
            }

            return false;
        }

        void print_database_by_year()
        {
            //cout<<year_comparator(person_list[1], person_list[2])<<" ";
            for(int i = 0; i < MAXPERS; i++)
                if(person_list[i] != NULL)
                    {
                        person_list[i]->print_person();
                    }
            cout<<"\n";
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


int main()
{
    database data;
    person *a = new person("Djan", 2002, 'M');
    data.add_person(a);
    a = new person("Marry", 1960, 'F');
    data.add_person(a);
    a = new person("John", 1990, 'M');
    data.add_person(a);

    data.delete_person("Marry");

    data.print_database();
    #data.~database();
    /*int v[MAXPERS];
    for(int i = 0; i < MAXPERS; i++)
        v[i] = (2 * i) % 20;

    sort(v, v + MAXPERS);
    for(int i = 0; i < MAXPERS; i++)
        cout<<v[i]<<" ";
*/
    //data.delete_person("Djan");
    //data.print_database();
    /*person *p = new person("perry", 1000, 'M');
    person a("danny", 2000, 'F');
    cout<<p->get_name();
    cout<<endl;
    cout<<a.get_name();*/
    //a.print_person();
}
