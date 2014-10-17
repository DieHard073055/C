#include<stdio.h>
#include<string.h>

struct tag
{
	char lname[20];
	char fname[20];
	int age;
	float rate;

};	 

struct tag my_struct;

void show_name (struct tag *p);

int main()
{
	struct tag * st_ptr;
	st_ptr = &my_struct;
	strcpy(my_struct.lname,"Jonny");
	strcpy(my_struct.fname,"David");
	printf("%s %s",my_struct.fname,my_struct.lname);
	my_struct.age = 23;
	show_name(st_ptr);
}
void show_name(struct tag *p)
{

	printf("First Name %s %s\n\n",p->fname,p->lname);
	printf("age %i",p->age);




}

