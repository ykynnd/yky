#include "List.h"
#include <iostream>
#include <string>
#include <cassert>

int main()
{
    List<int> lst1;
    assert(lst1.empty());
    assert(lst1.size() == 0);
    std::cout <<  "test1 passed." << std::endl;
    
    List<int> lst2 = {1, 2, 3};
    assert(lst2.size() == 3);
    assert(*lst2.begin() == 1);
    assert(*(++lst2.begin()) == 2);
    assert(*(--lst2.end()) == 3);
    std::cout << "test2 passed." << std::endl;
    
    List<int> lst3(lst2);
    assert(lst3.size() == 3);
    assert(*lst3.begin() == 1);
    assert(*(++lst3.begin()) == 2);
    assert(*(--lst3.end()) == 3);
    std::cout << "test3 passed." << std::endl;
    
    List<int> lst4;
    lst4 = lst2;
    assert(lst4.size() == 3);
    assert(*lst4.begin() == 1);
    assert(*(++lst4.begin()) == 2);
    assert(*(--lst4.end()) == 3);
    std::cout << "test4 passed." << std::endl;
    
    List<int> lst5;
    auto it = lst5.end();
    it = lst5.insert(it, 1);
    assert(lst5.size() == 1);
    it = lst5.insert(it, 2);
    assert(lst5.size() == 2);
    it = lst5.insert(it, 3);
    assert(lst5.size() == 3);
    assert(*lst5.begin() == 3);
    assert(*(++lst5.begin()) == 2);
    assert(*(--lst5.end()) == 1);
    std::cout << "test5 passed." << std::endl;
    
    lst5.erase(lst5.begin());
    assert(lst5.size() == 2);
    assert(*lst5.begin() == 2);
    assert(*(--lst5.end()) == 1);
    lst5.erase(lst5.begin());
    assert(lst5.size() == 1);
    assert(*lst5.begin() == 1);
    std::cout << "test6 passed." << std::endl;
    
    List<int> lst7;
    for (int i = 1; i < 4; ++i)
    {
        lst7.push_back(i);
    }
    assert(lst7.size() == 3);
    assert(*(--lst7.end()) == 3);
    lst7.pop_back();
    assert(lst7.size() == 2);
	assert(*(--lst7.end()) == 2);
	std::cout << "test7 passed." << std::endl;
   // for (auto it : lst)
    //{
      //  std::cout << it << std::endl;
    //}

   // for (auto it = lst.begin(); it != lst.end(); ++it)
    //{
     //   std::cout << *it << std::endl;
    //}

    //for (auto it = lst.begin(); it != lst.end(); it++)
   // {
      //  std::cout << *it << std::endl;
   // }

	//for (auto it = lst.end(); it != lst.end(); it--)
    	//{
   		//    std::cout << *it << std::endl;
   		//}

		//List<int> lst = {1, 2, 3, 4, 5};
      // for (auto &x : lst)
      // {
       //    std::cout << x << "\t";
      // }
      // std::cout << std::endl;

       // List<int> lst2 = std::move(lst);
        //List<int> lst2 = List<int> {5, 6};
//     for (auto &x : lst2)
//     {
//         std::cout << x << "\t";
//     }
//     std::cout << std::endl;

//     lst2 = std::move(lst);
//     for (auto &x : lst2)
//     {
//         std::cout << x << "\t";
//     }
//     std::cout << std::endl;

    return 0;
}
