#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED


#define MAXPERS 100

class database
{
    private:
        person *person_list[MAXPERS];
        int counter;

    public:
        database();
        ~database();

        void add_person(person *pers);
        void get_person(int i);

        void refresh_counter();

        void print_database();
        bool year_comparator(person *a, person *b);
        bool name_comparator(person *a, person *b);

        void sort_by_year();
        void sort_by_name();

        void print_database_by_year();
        void print_database_by_name();

        void delete_person(char *name_value);
        void delete_person(int year);
        void delete_person(char sex);

        friend ostream& operator <<(ostream& output, const database &d);
        friend istream& operator >>(istream& input, database &d);
};


database::database()
{
    counter = 0;
    for(int i = 0; i < MAXPERS; i++)
        person_list[i] = NULL;
}

database::~database()
{
    delete person_list;
}

///print_database method written with streams
ostream& operator <<(ostream& output, const database &d)
{

    for(int i = 0; i < MAXPERS; i++)
        if(d.person_list[i] != NULL)
            output<<*d.person_list[i];
}

///add_person method written with streams
istream& operator >>(istream& input, database &d)
{
    for(int i = 0; i < MAXPERS; i++)
        if(d.person_list[i] == NULL)
        {
            person *p = new person("unknown", 0, 'F');
            input>>*p;
            d.person_list[i] = p;
            break;
        }

    d.counter++;
}

void database::add_person(person *pers)
{
    for(int i = 0; i < MAXPERS; i++)
        if(person_list[i] == NULL)
        {
            person_list[i] = new person(*pers);
            break;
        }
    counter++;
}

void database::get_person(int i)
{
    person_list[i]->print_person();
}

void database::refresh_counter()
{
    counter = 0;
    for(int i = 0; i < MAXPERS; i++)
        if(person_list[i] != NULL)
            counter++;
}

void database::print_database()
{
    for(int i = 0; i < MAXPERS; i++)
        if(person_list[i] != NULL)
            person_list[i]->print_person();
    cout<<"\n";
}

bool database::year_comparator(person *a, person *b)
{
    return (a->get_year() > b->get_year());
}

bool database::name_comparator(person *a, person *b)
{
    return (strcmp(a->get_name(), b->get_name()) > 0);
}

void database::sort_by_year()
{
    for(int i = 0; i< MAXPERS; i++)
        for(int j = i; j < MAXPERS; j++)
            if(person_list[i] != NULL && person_list[j] != NULL)
                if (year_comparator(person_list[i], person_list[j]))
                    swap(person_list[i], person_list[j]);
}

void database::sort_by_name()
{
    for(int i = 0; i< MAXPERS; i++)
        for(int j = i; j < MAXPERS; j++)
            if(person_list[i] != NULL && person_list[j] != NULL)
                if (name_comparator(person_list[i], person_list[j]))
                    swap(person_list[i], person_list[j]);
}

void database::print_database_by_year()
{
    sort_by_year();
    cout<<*this;
}

void database::print_database_by_name()
{
    sort_by_name();
    cout<<*this;
}

void database::delete_person(char *name_value)
{
    for(int i = 0; i < MAXPERS; i++)
        if (person_list[i] != NULL)
            if(strcmp(person_list[i]->get_name(), name_value) == 0)
                person_list[i] = NULL;

    refresh_counter();
}

void database::delete_person(int year)
{
    for(int i = 0; i < MAXPERS; i++)
        if (person_list[i] != NULL)
            if(person_list[i]->get_year() == year)
                person_list[i] = NULL;

    refresh_counter();
}

void database::delete_person(char sex)
{
    for(int i = 0; i < MAXPERS; i++)
        if (person_list[i] != NULL)
            if(person_list[i]->get_sex() == sex)
                person_list[i] = NULL;

    refresh_counter();
}
#endif // DATABASE_H_INCLUDED
