#include <stdio.h>
#include <string.h>
int i;

typedef struct // ejercicio 1
{
	char name[50];
	int employees[5];
	
} Company;


void add_employee_data(Company* com, int year, int emp) // ejercicio 2
{
	com->employees[year - 2018] = emp;
}


int final_total_employees(Company com, int year) // ejercicio 3
{
	return com.employees[year - 2018];
}


void delete_employee_data(Company* com, int year) // ejercicio 4
{
	com->employees[year - 2018] = 0;
}


float calculate_average_employees(Company com) // ejercicio 5
{
	float prom = 0;
	
	for (i = 0; i < 5; i++)
		prom += com.employees[i];
	
	return prom / 5;
}


float general_average_employees(Company com[], int year, int comSize) // ejercicio 6
{
	float prom = 0;
	
	for (i = 0; i < comSize; i++)
		prom += com[i].employee[year - 2018];
	
	return prom / comSize;
}



int main()
{
	
	
	return 0;
}
