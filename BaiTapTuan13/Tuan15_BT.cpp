#include <iostream>
#include <string>
using namespace std;
class person
{
private:
	int id;
	string name;
	string gender;
	person *next;

public:
	person(int _id = 0, string _name = "unknow", string _gender = "unknow", person *_next = NULL)
	{
		id = _id;
		name = _name;
		gender = _gender;
		next = _next;
	}
	person(const person &per1)
	{
		id = per1.id;
		name = per1.name;
		gender = per1.gender;
		next = per1.next;
	}
	~person() { next = NULL; }
	void input_pers(int &id, string &name, string &gender)
	{
		cout << " Nhap ma dinh danh :";
		cin >> id;
		cout << " Nhap ho ten :";
		cin.ignore(1);
		getline(cin, name);
		cout << " Nhap gioi tinh:";
		getline(cin, gender);
		this->name = name;
		this->id = id;
		this->gender = gender;
	}
	void swap(person &per2)
	{
		person tmp = *this;
		*this = per2;
		per2 = tmp;
	}
	friend class listofperson;
};
class listofperson
{
	person *firstpers;

public:
	void lopers_Init(listofperson *lofpers)
	{
		lofpers->firstpers = 0;
	}
	void add_pers(listofperson *lofpers, int id, string name, string gender)
	{
		person *newpers = new person;
		newpers->id = id;
		newpers->name = name;
		newpers->gender = gender;
		newpers->next = lofpers->firstpers;
		lofpers->firstpers = newpers;
	}
	void add_pers_Final_input(listofperson *lofpers)
	{
		int id;
		string name;
		string gender;
		person persIn;
		persIn.input_pers(id, name, gender);
		person *newpers = new person;
		newpers->id = id;
		newpers->name = name;
		newpers->gender = gender;
		person *node = lofpers->firstpers;
		while (node->next != 0)
		{
			node = node->next;
		}
		newpers->next = node->next;
		node->next = newpers;
	}
	int lofperson_Length(listofperson *lofpers)
	{
		person *node = lofpers->firstpers;
		int i = 0;
		while (node != 0)
		{
			i++;
			node = node->next;
		}
		return i;
	}
	void lofpers_Display(listofperson *lofpers)
	{
		person *node = lofpers->firstpers;
		int i = lofperson_Length(lofpers);
		cout << "\nDo dai cua list:\t" << i;
		if (lofpers->firstpers == 0)
			cout << "\nList rong \n\n";
		else
		{
			while (node != 0)
			{
				cout << "\nNguoi thu" << i << "\n";
				cout << "\nId:\t\t" << node->id;
				cout << "\nName:\t\t" << node->name;
				cout << "\nGender:\t\t" << node->gender << endl;
				node = node->next;
				i--;
			}
			cout << endl;
		}
	}
	person *lofperson_Search(listofperson *lofpers, string name)
	{
		person *node = lofpers->firstpers;

		while (node != 0)
		{
			if (node->name == name)
			{
				return node;
			}
			else
				node = node->next;
		}
		return 0;
	}
	void lofpers_RemoveAfter(person *node)
	{
		person *obsoleteNOde = node->next;
		node->next = obsoleteNOde->next;
		delete obsoleteNOde;
	}
	// sap xep theo thu tu tang dan id
	void sortListPerson(listofperson *lofpers)
	{
		for (person *node = lofpers->firstpers; node != NULL; node = node->next)
		{
			for (person *node1 = node->next; node1 != NULL; node1 = node1->next)
			{
				if (node->id > node1->id)
				{
					int temp = node1->id;
					node->id = node1->id;
					node1->id = temp;
				}
			}
		}
	}
};
class student : public person
{
private:
	int stuID;
	string clas;

public:
};
int main()
{
	listofperson lofpers;
	lofpers.lopers_Init(&lofpers);
	lofpers.add_pers(&lofpers, 1, " Giang", "female");
	lofpers.add_pers(&lofpers, 2, " Tan", "female");
	lofpers.add_pers(&lofpers, 3, " Huy", "female");
	lofpers.add_pers_Final_input(&lofpers);
	lofpers.add_pers_Final_input(&lofpers);
	lofpers.sortListPerson(&lofpers);
	cout << "Noi dung cua list" << endl;
	lofpers.lofpers_Display(&lofpers);
	cout << "NOi dung cua list sau lenh xoa" << endl;
	lofpers.lofpers_RemoveAfter(lofpers.lofperson_Search(&lofpers, " Giang"));
	lofpers.lofpers_Display(&lofpers);
	return 0;
}