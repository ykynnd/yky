#include <iostream>
#include <cstring>

class Chicken
{
    private:
        int age = 24;
        char *name = nullptr;
    public:
        Chicken(){};
        Chicken(int _age) : age(_age) {};
        Chicken(int _age, const char *_name) : age(_age), name(nullptr)
        {
            if(_name)
		     {
		     int len = strlen(_name) + 1;
             name = new char[len];
             for (int i = 0; i < len; i++)
                 name[i] = _name[i];
       		 }
        };
        Chicken &operator=(const Chicken &_c)
        {
        	if (this == &_c)
        		return *this;
        	if (name) 
			{
                delete[] name;
            }
            age = _c.age;
            if (_c.name) 
			{
                int len = strlen(_c.name) + 1;
                name = new char[len];
                for (int i = 0; i < len; i++) 
				{
                    name[i] = _c.name[i];
                }
            } else {
                name = nullptr;
            }
            return *this;
        }
        	
		Chicken(const Chicken &_c) : age(_c.age), name(nullptr)
    	{
       		if (_c.name) 
			{
           		int len = strlen(_c.name) + 1;
            	name = new char[len];
            	for (int i = 0; i < len; i++) 
				{
                name[i] = _c.name[i];
            	}
        	}
		 	else {
            name = nullptr;
        	}
   		}
        ~Chicken()
        {
            if (name != nullptr)
                delete[] name;
        }
        void setAge(int _age)
        {
            age = _age;
        }
        void setName(const char *_name)
        {
            if(name != nullptr)
                delete[] name;
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        }

        const char *getName() const
        {
            return name;
        }

        const int &getAge() const
        {
            return age;
        }
                              
};

int main()
{
    Chicken c(24, "Kunkun");
    std::cout << "Hi, everyone! My name is " << c.getName() << ", I am " << c.getAge() << " years old." << std::endl;
    return 0;
}