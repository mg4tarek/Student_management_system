/*
 * funtions_prototype.h
 *  Created on: Aug 7, 2024
 *      Author: Mohamed Gamal
 */
/**************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef FUNCTIONS_PROTOTYPE_H_
#define FUNCTIONS_PROTOTYPE_H_

/***************************************************************/

struct student {
    int id;         // Student ID
    char name[50];  // Student Name
    int age;        // Student Age
    float gpa;      // Student GPA
};

// Define a structure to represent a node in a linked list
struct node {
    struct student data;  // Student data
    struct node *next;    // Pointer to the next node
};

/*******************************************************************/


void Enter_Student_Data(struct student *new_std);

void print_options(void);

void Menu_Options(void);

void addStudent(const struct student *const ptr);

void displayStudents(void);

void Enter_id(void);

void searchStudentByID(int id);

void updateStudent(int id);

void NEW_Data(struct student *new_std);

float calculateAverageGPA(void);

void searchHighestGPA(void);

void deleteStudent(int id);

void deleteAll(struct node **head);

/*******************************************************************/
#endif
