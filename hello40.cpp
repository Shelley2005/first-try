#include<bits/stdc++.h>
using namespace std;

class Student{
	private:
		string Id;
		string banji;
		string name;
		float score1;
		float score2;
		float score3;
		float total;
	public:
		friend ostream& operator<<(ostream&os, const Student &s);
		friend istream& operator>>(istream&is,  Student &s);
		string getName(){return name;}
		string getBanji(){return banji;}
		string getId(){return Id;}
		float getScore(){return total;}
};
ostream& operator <<(ostream&os, const Student&s)
{
	cout<<s.Id<<","<<s.banji<<","<<s.name<<","<<fixed<<setprecision(1)<<s.score1<<","<<fixed<<setprecision(1)<<s.score2<<","<<s.score3<<","<<s.total<<endl;
	return os;
}

istream& operator >>(istream&is,  Student&s)
{
	cout<<"Id "; cin>>s.Id;
	cout<<"class "; cin>>s.banji;
	cout<<"name "; cin>>s.name;
	cout<<"score1 "; cin>>s.score1;
	cout<<"score2 "; cin>>s.score2;
	cout<<"score3 "; cin>>s.score3;
	s.total = s.score1 + s.score2 + s.score3;
	return is;
}

class Total
{
	private:
		Student stu[5];
		string Id;
		int count;
	public:
		Total();
		void input();
		void output();
		void select();
		void delete1();
		void order();
		void setSelection(int i);
};

Total::Total()
{
	count = 0;
}

void Total::input()
{
	string str;
	while(1)
	{
		cin>>stu[count++];
		cout<<"continue?\n";
		cin>>str;
		if(str=="no")
			break;
	}
}

void Total::output()
{
	for(int i = 0;i<count;i++)
	{
		cout<<stu[i];
	}
}

void Total::select()
{
	string str;
	while(1)
	{
		int flag = 1;
		cin>>str;
		for(int i=0;i<count;i++)
		{
			if(stu[i].getId()==str||stu[i].getBanji()==str)
			{
				cout<<stu[i];
				flag = 0;
			}
		}
		if(flag==1)
		{
			cout<<"there is no eligible student \n";
		}
		cout<<"continue?\n";
		cin>>str;
		if(str=="no")
			break;
	}
}

void Total::order()
{
	Student stu1;
	for(int i= 0 ;i<count-1;i++)
	{
		for(int j=0;j<count-1-i;j++)
		{
			if(stu[j].getBanji()>stu[j+1].getBanji())
			{
				stu1 = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = stu1;
			}
			else if((stu[j].getBanji() == stu[j+1].getBanji())&&(stu[j].getScore()<stu[j+1].getScore()))
			{
				stu1 = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = stu1;
			}
		}
	}
	for(int i = 0;i<count;i++)
	{
		cout<<stu[i];
	}
}

void Total::delete1()
{
	string str;
	while(1)
	{
		cin>>str;
		for(int i = 0;i<count;i++)
		{
			if(stu[i].getName() == str || stu[i].getId() == str)
			{
				stu[i] = stu[count-1];
				count--;
			}
		}
		for(int i =0;i<count; i++)
		{
			cout<<stu[i];
		}
		cout<<"continue?\n";
		cin>>str;
		if(str=="no")
			break;
	}
}

void Total::setSelection(int i)
{
	if(i==1)
		input();
	else if(i==5)
		output();
	else if(i==3)
		select();
	else if(i==2)
		delete1();
	else if(i=4)
		order();
}

void Menu()
{
	cout<<"1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input your option\n";
}

int main()
{
	Total total1;
	while(1)
	{
		Menu();
		int i;
		cin>>i;
		switch(i)
		{
			case 1: total1.setSelection(i);
				break;
			case 2:
				total1.setSelection(i);
				break;
			case 3:
				total1.setSelection(i);
				break;
			case 4:
				total1.setSelection(i);
				break;
			case 5:
				total1.setSelection(i);
				break;
			case 6:
				return 0;
		}
	}
	return 0;
}



