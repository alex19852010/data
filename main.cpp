#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <exception>
#include <map>

using namespace std;

template <typename Key, typename Value>


class Registry
{
    private:
    vector <map <Key, Value>> data; 

    public:

    void add(const Key& key, const Value& value)
    {
      map <Key, Value> entry;
      entry[key] = value;
      data.push_back(entry);
    }

    void print()
    {
        for(const auto& entry : data)
        {
           for(const auto& pair : entry)
           {
             cout << "key: " << pair.first << " value: " << pair.second << endl;
           }
        }

    }



};

int main()
{
 Registry <int, string> registry;

 string command;
 double key;
 string value;

 while(1)
 {
    cout << "enter command: ";
    cin >> command;

    if(command == "add")
    {
      cout << "enter key: ";
      cin >> key;
      cout << "enter value: ";
      cin >> value;
      registry.add(key, value);
    }

    else if(command == "print")
    {
       registry.print();
    }

 }
    
 return 0;

}