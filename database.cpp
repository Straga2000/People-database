#include "person.h"
#include "database.h"

int main()
{
    int n = -1, age = 0;
    char name[200], sex = 'F';
    database data;

    cout<<"0. Exit\n1. Add person\n2. Delete by name\n3. Delete by age\n4. Delete by sex\n5. Print ordered by name\n6. Print ordered by age\n\n";

    while(n)
    {
        /// uncomment for having the menu every iteration
        ///cout<<"\n0. Exit\n1. Add person\n2. Delete by name\n3. Delete by age\n4. Delete by sex\n5. Print ordered by name\n6. Print ordered by age\n\n";

        cin>>n;

        if(n == 0)
            break;

        if(n == 1)
        {
            cout<<"Give name, age, sex\n";
            cin>>data;
        }

        if(n == 2)
        {
            cout<<"Give name\n";
            cin.get(); ///it is needed to get the '\n' part
                        ///compile without it if it works
            cin.getline(name, 200);
            data.delete_person(name);
        }

        if(n == 3)
        {
            cout<<"Give age\n";
            cin>>age;
            data.delete_person(age);
        }

        if(n == 4)
        {
            cout<<"Give sex\n";
            cin>>sex;
            data.delete_person(sex);
        }

        if(n == 5)
            data.print_database_by_name();

        if(n == 6)
            data.print_database_by_year();
    }
}
