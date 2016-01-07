#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>
#include <vector>
#include <string>
#include <list>

using namespace std;

template<class T>
void inverser(T first, T Last)
{
   int nb = distance(first, Last)/2;
   for (auto i = 0; i <= nb; i++)
   {
      iter_swap(first++, --Last);

   }
}

template<class T, class U>
T Trouver(T first, T Last,U val)
{
   for (auto n = first; n != Last; n++)
      if (*n == val)return n;
   return Last;
}

template<class T, class U>
auto  Trouver_si(T first, T Last, U val)
{
   for (auto &n = first; n != Last; n++)
      if ( val(*n))return n;
   return Last;
}

template<class T>
void pivoter_gauche(T first, T Last)
{
   auto nlast = --Last;
   auto LastV = *nlast;
   iter_swap(first, nlast);
   for (auto &n = first; n != prev(nlast); n++)
   {

      iter_swap(next(n), n);
   }
   *--nlast = LastV;

}



int main()
{
   float f[ 10 ];
   iota(begin(f), end(f), 0);

   vector<int> v( 9 );
   iota(begin(v), end(v), 0);

   list<string> s{"J'aime", "mon", "prof"};

   cout << "Inverser : " << endl;

   cout << "Float[] : ";
   inverser(begin(f), end(f));
   for (auto &n : f) cout << n;
   cout << endl;

   cout << "Vector<Int> : ";
   inverser(begin(v), end(v));
   for (auto &n : v) cout << n;
   cout << endl;

   cout << "list<string> : ";
   inverser(begin(s), end(s));
   for (auto &n : s) cout << n;
   cout << endl;

   cout << "Trouver : " << endl;

   cout << "Float[] : ";
   cout << *Trouver(begin(f), end(f),5);
   cout << endl;

   cout << "Vector<Int> : ";
   cout << *Trouver(begin(v), end(v),5);
   cout << endl;

   cout << "list<string> : ";
   cout << *Trouver(begin(s), end(s),"mon");
   cout << endl;

   cout << "Trouver_si : " << endl;

   cout << "Float[] : ";
   cout << *Trouver_si(begin(f), end(f), [](float n) {return n > 8;});
   cout << endl;

   cout << "Vector<Int> : ";
   cout << *Trouver_si(begin(v), end(v), [](int n) {return n % 6 == 0; });
   cout << endl;

   cout << "list<string> : ";
   cout << *Trouver_si(begin(s), end(s), [](string n) {return n.size() == 4; });
   cout << endl;

   cout << "pivoter_gauche : " << endl;

   cout << "Vector<Int> : ";
   pivoter_gauche(begin(v), end(v));
   for (auto &n : v) cout << n;
   cout << endl;
   

}