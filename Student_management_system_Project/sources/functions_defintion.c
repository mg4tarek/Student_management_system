/*
 * functions_prototype.c
 *  Created on: Aug 7, 2024
 *      Author: Mohamed Gamal
 */
/************************************************************/
#include "funtions_prototype.h"

struct node *head = NULL;
struct student _std;
int id;
/************************************************************/


void Menu_Options(void)
{
	int shouldExit = 0;

	while (!shouldExit)
	{
		print_options();

		int choice;
		printf("Enter choice:  ");

		if (scanf("%d", &choice) != 1)
		{
			while (getchar() != '\n');
			printf("-----------------------------------------\n");
			printf("Invalid input. Please enter a number.\n");
			printf("-----------------------------------------\n");
			continue;
		}

		printf("\n");

		switch (choice)
		{
		case 1: // done
			Enter_Student_Data(&_std);
			addStudent(&_std);
			break;
		case 2: // done
			displayStudents();
			break;
		case 3: // done
			Enter_id();
			searchStudentByID(id);
			break;
		case 4: // done
			Enter_id();
			NEW_Data(&_std);
			updateStudent(id);
			break;
		case 5: // done
			Enter_id();
			deleteStudent(id);
			break;
		case 6: // done
			calculateAverageGPA();
			break;
		case 7: // done but
			searchHighestGPA();
			break;
		case 8:
			deleteAll(&head);
			shouldExit = 1;
			break;
		default:
			printf("-----------------------------------------\n");
			printf("Invalid choice. Try again.\n");
			printf("-----------------------------------------\n");
			break;
		}
	}
}



/************************************************************/

void deleteAll(struct node **head)
{

	struct node *current = *head;
	struct node *nextNode;

	while (current != NULL)
	{
		nextNode = current->next;
		free(current);
		current = nextNode;
	}

	*head = NULL;
}


/************************************************************/



void searchHighestGPA(void)
{
	if( head == NULL)
	{
		printf("-----------------------------------------\n");
		printf("There are no students.\n");
		printf("-----------------------------------------\n");
		return;
	}

	struct node *current = head;

	float max = head->data.gpa;

	while( current != NULL )
	{
		if( (float)current->data.gpa > (float)max )
		{
			max = current->data.gpa;
		}
		current = current->next;
	}

	current = head;
	printf("-----------------------------------------\n");
	while(current != NULL)
	{
		if((float)current->data.gpa == (float)max)
		{
			printf("[ ID: %d, Name: %s, Age: %d, GPA: %.2f ]\n",current->data.id,current->data.name,
					current->data.age,current->data.gpa);
		}
		current = current->next;
	}
	printf("-----------------------------------------\n");

	return;

}
/************************************************************/
void deleteStudent(int id)
{

	if( head == NULL)
	{
		printf("-----------------------------------------\n");
		printf("Student not found !\n");
		printf("-----------------------------------------\n");
		return;
	}

	struct node *current = NULL;
	struct node *prev = NULL;

	if( head->data.id == id )
	{
		current = head;
		head = head->next;
		printf("-----------------------------------------\n");
		printf("Student with iD %d is deleted Successfully\n",current->data.id);
		printf("-----------------------------------------\n");
		free(current);
		return;
	}

	current = head->next;
	prev = head;

	while(current != NULL)
	{
		if( current->data.id ==  id)
		{
			printf("-----------------------------------------\n");
			printf("Student with iD %d is deleted Successfully\n",current->data.id);
			printf("-----------------------------------------\n");
			prev->next = current->next;
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
	printf("-----------------------------------------\n");
	printf("Student not found !\n");
	printf("-----------------------------------------\n");
	return;
}


/*************************************************************/

float calculateAverageGPA(void)
{

	if( head == NULL)
	{
		printf("-----------------------------------------\n");
		printf("Average GPA = 0.0\n");
		printf("-----------------------------------------\n");
		return 0.0;
	}

	struct node *current = head;
	int num = 0;
	float AverageGPA = 0;

	while( current != NULL )
	{
		AverageGPA = AverageGPA + current->data.gpa;
		current = current->next;
		++num;
	}
	AverageGPA = (float)AverageGPA / num;
	printf("-----------------------------------------\n");
	printf("Average GPA = %.2f\n",AverageGPA);
	printf("-----------------------------------------\n");

	return AverageGPA;

}
/************************************************************/

void NEW_Data(struct student *ptr_std)
{
	if( head==NULL )
	{
		printf("-----------------------------------------\n");
		printf("Student not found !\n");
		printf("-----------------------------------------\n");

		return;
	}
	printf("-----------------------------------------\n");
	printf("Enter new name: ");
	scanf("%s",ptr_std->name);
	printf("\n");
	printf("Enter new age: ");
	scanf("%d",&ptr_std->age);
	printf("\n");
	printf("Enter new gpa: ");
	scanf("%f",&ptr_std->gpa);
	printf("\n");
	printf("-----------------------------------------\n");
}

/***********************************************************/
void updateStudent(int id)
{

	if( head == NULL)
	{
		printf("-----------------------------------------\n");
		printf("Student not found !\n");
		printf("-----------------------------------------\n");
		return;
	}

	struct node *current = head;

	while(current != NULL)
	{
		if( current->data.id ==  id)
		{

			strcpy(current->data.name,_std.name) ;
			current->data.age = _std.age;
			current->data.gpa = _std.gpa;

			return;
		}
		current = current->next;
	}

	printf("Student not found !\n");
	return;

}

/************************************************************/

void Enter_id(void)
{

	printf("Enter student id to search: ");
	scanf("%d",&id);
	printf("\n");
}


/************************************************************/

void searchStudentByID(int id)
{

	if( head == NULL)
	{
		printf("-----------------------------------------\n");
		printf("Student not found !\n");
		printf("-----------------------------------------\n");
		return;
	}

	struct node *current = head;

	while(current != NULL)
	{
		if( current->data.id ==  id)
		{
			printf("-----------------------------------------\n");

			printf("[ ID: %d, Name: %s, Age: %d, GPA: %.2f ]\n",current->data.id,current->data.name,
					current->data.age,current->data.gpa);
			printf("-----------------------------------------\n");

			return;
		}
		current = current->next;
	}
	printf("-----------------------------------------\n");
	printf("Student not found !\n");
	printf("-----------------------------------------\n");

	return;

}

/************************************************************/

void displayStudents(void)
{
	if(head ==NULL)
	{
		printf("-----------------------------------------\n");
		printf("No students are present. \n");
		printf("-----------------------------------------\n");
		return;
	}

	struct node *current = head;
	printf("-----------------------------------------\n");

	while(current != NULL)
	{
		printf("[ ID: %d, Name: %s, Age: %d, GPA: %.2f ]\n",current->data.id,current->data.name,
				current->data.age,current->data.gpa);
		current = current->next;
	}
	printf("-----------------------------------------\n");

}

/************************************************************/


void Enter_Student_Data(struct student *new_std)
{
	printf("-----------------------------------------\n");
	printf("Enter studend id: ");
	scanf("%d",&new_std->id);
	printf("\n");
	printf("Enter name: ");
	scanf("%s",new_std->name);
	printf("\n");
	printf("Enter age: ");
	scanf("%d",&new_std->age);
	printf("\n");
	printf("Enter gpa: ");
	scanf("%f",&new_std->gpa);
	printf("\n");
	printf("-----------------------------------------\n");

}

/***********************************************************/

void addStudent(const struct student *const ptr)
{


	struct node *current = head;

	while( current != NULL )
	{
		if(ptr->id == current->data.id )
		{
			printf("-----------------------------------------\n");
			printf("id is already exist, please try again.\n");
			printf("-----------------------------------------\n");
			return;
		}
		current = current->next;
	}

	struct node *link = (struct node*)malloc(sizeof(struct node));
	if( link == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	current = head;


	link->data.id = ptr->id;
	strcpy(link->data.name,ptr->name) ;
	link->data.age = ptr->age;
	link->data.gpa = ptr->gpa;

	link->next = NULL;

	if(head == NULL)
	{
		head = link;
		return;
	}


	while( current->next != NULL )
	{
		current = current->next;
	}
	current->next = link;

	return;
}

/***********************************************************/

void print_options(void)
{
	printf("\n1. Add Student\n");
	printf("2. Display Students\n");
	printf("3. Search Student by ID\n");
	printf("4. Update Student Information\n");
	printf("5. Delete Student\n");
	printf("6. Calculate Average GPA\n");
	printf("7. Search for Student with Highest GPA\n");
	printf("8. Exit\n");
}

/***********************************************************/



