#include <iostream>
#include <set>
#include <string>
using namespace std;

struct key
{
    string name;
    string number1;
    string number2;
    string number3;
    string number4;
    string number5;
    key (string name, string const&number1 = string(), string const&number2 = string(), string const&number3 = string(), string const&number4 = string(), string const&number5  = string()): name(name), number1(number1), number2 (number2), number3 (number3), number4 (number4), number5 (number5) {}
};
class phone_book
{
private:
    set <key*> book;
public:
    void add_person ( string name, string const&number1 = string(), string const&number2 = string(), string const&number3 = string(), string const&number4 = string(), string const&number5  = string())
    {
        book.insert(new key ( name, number1, number2,  number3,  number4,  number5 ));
    }
    key* find1 ( string name )
    {
        for ( set<key*>::iterator it = book.begin(), s = book.end(); it!=s ;)
            if ( (*it)->name == name )
                return (*it);
            else it++;
        return NULL;
    }
    void dell ( string name )
    {
        key* x =  find1 ( name );
        book.erase( find1 ( name ) );
        delete x;
    }
    void prin_all ()
    {
        for ( set<key*>::iterator it = book.begin(); it!=book.end(); it++){
            cout<<(*it)->name<<" ";
            if ((*it)->number1.empty()!=true )
                cout<<(*it)->number1<<" ";
            if ((*it)->number2.empty()!=true )
                cout<<(*it)->number2<<" ";
            if ((*it)->number3.empty()!=true )
                cout<<(*it)->number3<<" ";
            if ((*it)->number4.empty()!=true )
                cout<<(*it)->number4<<" ";
            if ((*it)->number5.empty()!=true )
                cout<<(*it)->number5;
            cout<<endl;
        }
        }
        phone_book () {}
~phone_book ()
        {
        for ( set<key*>::iterator it = book.begin(); it!=book.end(); it++){
            delete *it;
        }
           book.clear();
        }
   };
int main()
{
    phone_book sk;
    sk.add_person("grisha",  "89117292300");
    sk.add_person("artur",  "86543216546", "89348267524");
    sk.add_person("dima", "84952147651", "880256275694", "887835468");
    cout<<sk.find1("grisha")->number1<<endl;
    sk.dell("artur");
    sk.prin_all();
    return 0;
    }
