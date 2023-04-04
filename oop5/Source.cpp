#include <iostream>
using namespace std;

class F_Class
{
public:
	F_Class()
	{
		cout << "Const F_class" << endl;
	}

	virtual void print_smt()
	{
		cout << "virtual void print_smt() on the first class" << endl;
	}

	void print_smt_not_virt()
	{
		cout << "void print_smt_not_virt() on the first class" << endl;
	}

	virtual string ClassName()
	{
		return "F_Class";
	}

	virtual bool IsA(const string& who)
	{
		return (who == "F_Class");
	}


	virtual ~F_Class()
	{
		cout << "Dest F_Class" << endl;
	}
};

class S_Class: public F_Class
{
public:
	S_Class()
	{
		cout <<"Const S_class" << endl;
	}

	void print_smt() override
	{
		cout << "void print_smt() on the second class" << endl;
	}

	void print_smt_not_virt()
	{
		cout << "void print_smt_not_virt() on the second class" << endl;
	}

	string ClassName()
	{
		return "S_Class";
	}

	bool IsA(const string& who)
	{
		return (who == "S_Class") || (F_Class::IsA(who));
	}

	~S_Class()
	{
		cout << "Dest S_class" << endl;
	}
};

class Base
{
protected:
	int id;
public:
	Base()
	{
		cout<< "Base()\n";
		id = 0;
	}

	Base(int id)
	{
		cout << "Base(int id)\n";
		this->id = id;
	}

	Base(const Base& b)
	{
		cout << "Base(const Base& b)\n";
		id = b.id;
	}

	virtual bool IsA(const string& who)
	{
		return (who == "Base");
	}

	virtual void unique()
	{
		cout << "nothing";
	}

	~Base()
	{
		cout << "~Base()\n";
	}
};

class Desc: public Base
{
private:
	int model;
public:
	Desc()
	{
		cout << "Desc()\n";
	}

	Desc(int id, int model)
	{
		cout << "Desc(int id)\n";
		this->id = id;
		this->model = model;
	}

	Desc(const Desc& d)
	{
		cout << "Desc(const Desc& d)\n";
		id = d.id;
		model = d.model;
	}

	bool IsA(const string& who)
	{
		return (who == "Desc") || (Base::IsA(who));
	}
	void unique_desc()
	{
		cout << "I'm Desc\n";
	}

	~Desc()
	{
		cout << "~Desc()\n";
	}
};

class OtherDesc : public Base
{
private:
	int model;
public:
	OtherDesc()
	{
		cout << "OtherDesc()\n";
	}

	OtherDesc(int id, int model)
	{
		cout << "OtherDesc(int id)\n";
		this->id = id;
		this->model = model;
	}

	OtherDesc(const OtherDesc& d)
	{
		cout << "OtherDesc(const OtherDesc& d)\n";
		id = d.id;
		model = d.model;
	}

	bool IsA(const string& who)
	{
		return (who == "OtherDesc") || (Base::IsA(who));
	}

	void unique_odesc()
	{
		; cout << "I'm oDesc\n";
	}

	~OtherDesc()
	{
		cout << "~OtherDesc()\n";
	}
};


#pragma region functions with returning Base objects
Base Base_func1()
{
	Base b;
	cout << "func1\n\n\n";
	return b;
}

Base* Base_func2()
{
	Base b;
	cout << "func2\n\n\n";
	return &b;
}

Base& Base_func3()
{
	Base b;
	cout << "func3\n\n\n";
	return b;
}

Base Base_func4()
{
	Base *b1 = new Base();
	cout << "func4\n\n\n";
	return *b1;
}

Base* Base_func5()
{
	Base* b1 = new Base();
	cout << "func5\n\n\n";
	return b1;
}

Base& Base_func6()
{
	Base* b1 = new Base();
	cout << "func5\n\n\n";
	return *b1;
}
#pragma endregion

void for_dynamic(Base* obj)
{
	Desc* d1 = dynamic_cast<Desc*>(obj);
	if (d1)
	{
		// obj является указателем на класс Desc, мы можем вызывать методы Desc
		d1->unique_desc();
	}
	else
	{
		// obj не является указателем на класс Desc, мы не можем вызывать методы Desc
		cout << "obj не является указателем на класс Desc\n";
	}
}



#pragma region func with parametrs
void func1(Base obj)
{
	cout << "func1\n\n";
}

void func2(Base *obj)
{
	cout << "func2\n\n";
}
void func3(Base &obj)
{
	cout << "func3\n\n";
}
#pragma endregion

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
menu:
	cout << "\n1.Демонстрация методов\n2.Демонстрация методов\n3.Демонстрация функций с возвращением объектов( статическое создание)";
	cout << "\n4.Демонстрация функций с возвращением объектов(динамическое создание)\n5.Демонстрация передачи объектов как параметров в функции";
	cout<< "\n6.Проверка на принадлежность к классу\n7.Dynamic_cast\n8.Static_cast and IsA\n9. unique_ptr\n10.shared_ptr\n0.Выход из программы\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		system("cls"); //виртуальные функции
		F_Class* f = new S_Class();
		S_Class* s = new S_Class();
		f->print_smt();
		s->print_smt();


		delete f;
		delete s;
		goto menu;
		break;
	}
	case 2:
	{
		system("cls"); //невиртуальные функции
		F_Class* f = new S_Class();
		S_Class* s = new S_Class();
		f->print_smt_not_virt();
		s->print_smt_not_virt();


		delete f;
		delete s;
		goto menu;
		break;
		
	}
	case 3:
	{
		system("cls");
		Base b1 = Base_func1();
		
		Base *b2 = Base_func2();
		
		Base& b3 = Base_func3();
		
		goto menu;
		break;
	}
	case 4:
	{
		system("cls"); 
		Base b1 = Base_func4();

		Base *b2 = Base_func5();

		Base& b3 = Base_func6();

		goto menu;
		break;
	}
	case 5:
	{
		system("cls");
		cout<< "При стат создании объектов\n";
		Base b1;
		func1(b1);
		func2(&b1);
		func3(b1);
		
		cout << "\n\nПри динам создании объектов\n";
		Base* b2 = new Base();
		func1(*b2);
		func2(b2);
		func3(*b2);

		delete b2;
		goto menu;
		break;
	}
	case 6:
	{
		system("cls");


		Desc* d1 = new Desc();
		if (dynamic_cast<Desc*>(d1))
		{
			cout << "d1 is Desc\n";
		}
		else
		{
			cout << "d1 isn't Desc\n\n";
		}

		goto menu;
		break;
	}
	case 7:
	{
		system("cls");
		Base* b1 = new Desc();
		Base* b2 = new OtherDesc();

		cout << "Передаем объект Desc\n";
		for_dynamic(b1);
		cout << "Передаем объект OtherDesc\n";
		for_dynamic(b2);

		delete b1;
		delete b2;
		goto menu;
		break;
	}
	case 8:
	{
		srand(time(NULL));
		system("cls");
		Base* array[10];
		for (int i = 0; i < 10; i++)
		{
			int tmp = rand();
			if (tmp > 16000)
			{
				//cout << "tmp = " << tmp << "\n\n";
				array[i] = new Desc();
			}
			else
			{
				//cout << "tmp = " << tmp << "\n\n";
				array[i] = new OtherDesc();
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (array[i]->IsA("Desc"))
				static_cast<Desc*>(array[i])->unique_desc();
			else cout << "It is not Desc\n";
		}
		for (int i = 0; i < 10; i++)
		{
			delete array[i];
		}
		goto menu;
		break;
	}
	case 9:
	{
		system("cls");
		{
			unique_ptr<Base> based(new Base());
		}
		goto menu;
		break;
	}
	case 10:
	{
		system("cls");
		cout << ("{\n");
		{
			shared_ptr<Base> based(new Base());
			{
				cout << ("{\n");
				shared_ptr<Base> based1 = based;
			}
			cout << ("}\n");
		}
		cout << ("}\n");
		goto menu;
		break;
	}
	case 0:
	{
		system("cls");


		goto menu;
		break;
	}
	}
}