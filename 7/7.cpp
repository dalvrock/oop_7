#include <iostream>
#include <list>
#include <fstream>
#include <iterator>
#include "Timer.h"

#define NUMBS_COUNT 20

using namespace std;

void filedata();
void print_list(list <int> lst);
template <typename T> void file(list<T>* lst);
template <typename T> void key(list<T>* lst);

void filedata()
{
	ofstream fout;
	string name;

	cout << "����i�� i�'� �����: ";
	cin >> name;

	fout.open(name);

	if (!fout.is_open())
	{
		throw "���i��� i�'� �����!";
	}
	for (int i = 0, k; i < NUMBS_COUNT; i++)
	{
		k = rand() % 100;
		fout << k << " ";
		if (!(i % 50) && i != 0) fout << "\n";
	}

	fout.close();
}

void print_list(list <int> lst)
{
	list <int> ::iterator it;
	for (it = lst.begin(); it != lst.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}

template <typename T> void file(list<T>* lst)
{
	ifstream file;
	string name;
	int j;

	cout << "����i�� i�'� �����: ";
	cin >> name;

	file.open(name);

	if (!file.is_open())
	{
		throw "���i��� i�'� �����!";
	}
	while (file)
	{
		file >> j;
		lst->push_back(j);
	}

	lst->pop_back();
	print_list(*lst);
}

template <typename T> void key(list<T>* lst)
{
	cout << "����i�� �i�i �����: ";

	for (int l=0;l<NUMBS_COUNT; l++)
	{
		cin >> l;
		lst->push_back(l);
	}

	print_list(*lst);
}


int main()
{
	setlocale(LC_ALL, "ukr");

	int i;
	Timer t;
	list<int>* lst = new list<int>;

	cout << "���� ����� ������� �����: " << endl;
	cout << "1) � �����;\n2) � ����i�����;" << endl;
	cin >> i;

	switch (i)
	{
	case 1:
		filedata();
		file(lst);
		break;
	case 2:
		key(lst);
		break;
	default:
		cout << "�������!" << endl;
		break;
	}

	cout << "\n��� ������: " << t.elapsed() << "���" << endl;
}

