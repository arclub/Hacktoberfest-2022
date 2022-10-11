#include<iostream>
#include<conio.h>
using namespace std;
class queue // Queue Class For Storing Data
{
	public:
		int age,blood,heart,covid;
		string name,gender;
		queue *next_add;
};
class list // Linked List Class For Storing Nodes.
{
	private:
		queue *head = NULL;
	public:
		void insert();
		void display();
		void count();
};
	void list::insert()
	{
		system("cls");
		int a,b,h,c;
		string n,g;
		// Take Patient Information.
		cout<<"\n\t\t\t\tNew Patient";
		cout<<"\n\n Name : ";
		cin>>n;
		cout<<"\n\n Age : ";
		cin>>a;
		cout<<"\n\n Gender : ";
		cin>>g;
		cout<<"\n\n Blood Sugar (1 for Positive 0 for Negtive) : ";
		cin>>b;
		cout<<"\n\n Heart Decease (1 for Positive 0 for Negtive) : ";
		cin>>h;
		cout<<"\n\n COVID-19 (1 for Positive 0 for Negtive) : ";
		cin>>c;
		// Insert Record into Node.
		queue *new_node = new queue;
		new_node -> name = n;
		new_node -> age = a;
		new_node -> gender = g;
		new_node -> blood = b;
		new_node -> heart = h;
		new_node -> covid = c;
		new_node -> next_add = NULL;
		// Add Node into Linked List.
		if(head == NULL)
		head = new_node;
		else
		{
			// Check Last Node.
			queue *ptr = head;
			while(ptr -> next_add != NULL)
			{
				ptr = ptr -> next_add;
			}
			ptr -> next_add = new_node;
		}
		cout<<"\n\n Patient Information Inserted Successfully...";
	}
	void list::display()
	{
		system("cls");
		cout<<"\n\t\t\t\tDisplay All Information";
		queue *ptr = head;
		while(ptr != NULL)
		{
			cout<<"\n\n Name : "<<ptr -> name;
			cout<<"\n\n Age : "<<ptr -> age;
			cout<<"\n\n Gender : "<<ptr -> gender;
			(ptr -> blood == 1) ? cout<<"\n\n Blood Sugar : Positive" : cout<<"\n\n Blood Sugar : Negtive";
			(ptr -> heart == 1) ? cout<<"\n\n Heart Decease : Positive" : cout<<"\n\n Heart Decease : Negtive";
			(ptr -> covid == 1) ? cout<<"\n\n COVID-19 : Positive" : cout<<"\n\n COVID-19 : Negtive";
			cout<<"\n\n **************************************";
			ptr = ptr -> next_add;
		}
	}
	void list::count()
	{
		int m=0,f=0,k=0,o=0,b=0,h=0,c=0,r=0;
		cout<<"\n\n\n\t\t\t\tCounted Information";
		queue *ptr = head;
		while(ptr != NULL)
		{
			if(ptr -> gender == "Male" || ptr -> gender == "male")
			m++;
			else
			f++;
			if(ptr -> age < 15)
			k++;
			else if(ptr -> age > 50)
			o++;
			if(ptr -> blood == 1)
			b++;
			if(ptr -> heart == 1)
			h++;
			if(ptr -> covid == 1)
			c++;
			if(ptr -> blood == 1 && ptr -> heart == 1 && ptr -> covid == 1 && ptr -> age > 50)
			r++;
			ptr = ptr -> next_add;
		}
		cout<<"\n\n Number Of Male Patients : "<<m;
		cout<<"\n\n Number Of Female Patients : "<<f;
		cout<<"\n\n Number Of Kids Patients : "<<k;
		cout<<"\n\n Number Of Patients Have Age Over 50 : "<<o;
		cout<<"\n\n Number Of Patients Have Blood Sugar Decease : "<<b;
		cout<<"\n\n Number Of Patients Have Heart Decease : "<<h;
		cout<<"\n\n Number Of Patients Have COVID-19 : "<<c;
		cout<<"\n\n Number Of High Risk Patients : "<<r;
	}
main() // Main Function
{
	list l;
	char choice;
	// Call Insert Function.
	do
	{
		l.insert();
		cout<<"\n\n Do You Want Add Another Patient (Y,N) : ";
		cin>>choice;
	}while(choice == 'y' || choice == 'Y');
	// Call Display Function.
	l.display(); 
	// Call Count Information Function.
	l.count();
	getch();
	return 0;
}

