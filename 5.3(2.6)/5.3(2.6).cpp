#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

void add_element(list<int>& lst, int key)
{
    lst.push_front(key);  
}

void fill_list(list<int>& lst, int quantity)
{
    srand(time(NULL));
    for (int i = 0; i < quantity; i++)
    {
        int key = rand() % 100;
        add_element(lst, key);
    }
}

void print_list(const list<int>& lst)
{
    for (int num : lst)
    {
        cout << num << " ";
    }
    cout << endl;
}

double find_min_sum(const list<int>& lst)
{
    auto top = lst.begin();
    auto end = lst.rbegin();
    double min = *top + *end;
    int halfSize = lst.size() / 2;

    for (int i = 0; i < halfSize; ++i)
    {
        double current_sum = *top + *end;
        if (current_sum < min) min = current_sum;
        ++top;
        ++end;
    }
    return min;
}

int main()
{
    int n = 0;
    cout << "Enter value of n :" << endl;
    cin >> n;

    list<int> lst;
    fill_list(lst, 2 * n);
    print_list(lst);

    cout << "Min element = " << find_min_sum(lst) << endl;
    return 0;
}