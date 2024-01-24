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

    void remove(const Key & key)
    {
      bool found = false;
      for(auto& entry : data)
      {
        auto it = entry.find(key);
     
      if(it != entry.end())
      {
         entry.erase(it);
         found = true;
      }
    }
    if(!found)
    {
      throw invalid_argument("key not found");
    }
   }

   vector <Value> find(const Key& key)
   {
    bool found = false;
    vector <Value> result;
    for(auto& entry : data)
    {
      auto it = entry.find(key);

      if(it != entry.end())
      {
        result.push_back(it->second);
        found = true;
      }
    }
    if(!found)
    {
      throw invalid_argument("key not found");
    }
    return result;
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

      else if(command == "remove")
    {
       cout << "enter key: ";
       cin >> key;
       try
       {
        registry.remove(key);
       }
       catch(const invalid_argument& e)
       {
        std::cerr << e.what() << '\n';
       }
            
    }

     else if(command == "find")
     {
        cout << "enter key: ";
        cin >> key;
        try
        {
         vector <string> values = registry.find(key);
         cout << "values faund: ";
         for(auto& value : values)
        {
          cout << value << " ";
        }
        cout << endl;
        }
        catch(const invalid_argument& e)
        {
          std::cerr << e.what() << '\n';
        }
        
        
     }
 }
    
 return 0;

}