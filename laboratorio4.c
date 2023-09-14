#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i;

typedef struct // ejercicio 1
{
	char name[50];
	int employees[5];
} Company;

// updates employee data of a specific year
void add_employee_data(Company* com, int year, int emp) // ejercicio 2
{
	com->employees[year - 2018] = emp;
}

// returns employee count of a specific year
int find_total_employees(Company* com, int year) // ejercicio 3
{
	return com->employees[year - 2018];
}

// deletes employee data of a specific Company on a specific year
void delete_employee_data(Company* com, int year) // ejercicio 4
{
	com->employees[year - 2018] = 0;
}

// calculates the average employees of a Company
float calculate_average_employees(Company* com) // ejercicio 5
{
	float prom = 0;
	
	for (i = 0; i < 5; i++)
		prom += com->employees[i];
	
	return prom / 5;
}

// calculates the average employees on a specific year across all companies
float general_average_employees(Company* com[], int year, int comSize) // ejercicio 6
{
	float prom = 0;
	
	for (i = 0; i < comSize; i++)
		prom += com[i]->employees[year - 2018];
	
	return prom / comSize;
}

// creates structure Company
Company* create_company(char name[], int emp[])
{
	Company *newCompany = (Company*)malloc(sizeof(Company));
	strcpy(newCompany->name, name);
	for (i=0; i<5; i++)
	{
		newCompany->employees[i] = emp[i];
	}
	
	return newCompany;
}

// lets you choose a company from the array
int select_company(Company* com[], int comSize)
{
	int election;
	printf("Select Company:\n");
	for (i = 0; i < comSize; i++)
	{
		printf("[%d] %s\n", i+1, com[i]->name);
	}
	printf("Election: ");
	scanf("%d",&election);
	
	return election;
}

int main()
{
	FILE *file = fopen("companies.txt", "r");
	
	if (file == NULL)
	{
		perror("ERROR couldn't open file\n'");
		return 1;
	}
	
	Company *companies[100];
	int companyCount = 0;

	char line[100];
	
	while(fgets(line, 100, file) != NULL)
	{
		char *token;
		token = strtok(line, ",");
		
		char newName[50];
		strcpy(newName, token);
		
		int newEmployees[5];
		for (i=0; i<5; i++)
		{
			newEmployees[i] = atoi(strtok(NULL, ","));
		}
		
		companies[companyCount] = create_company(newName, newEmployees);
		companyCount++;
	}
	
	fclose(file);
	
	
	int election, employeeData, yearToLook, selectedCompany;
	float employeeProm;
	
	do{
		printf("----Billionaire Simulator----\n");
		printf("[1] Add Employee Data\n[2] Find Total Employees\n[3] Delete Employee Data\n[4] Calculate Average Employees\n[5] General Average Employees\n[6] Exit\nElection: ");
		scanf("%d",&election);
		printf("\n");
		
		switch (election)
		{
			case 1: // add employee data
				selectedCompany = select_company(companies, companyCount);
				
				printf("Insert Year to Add Employees (2018-2022): ");
				scanf("%d",&yearToLook);
				
				printf("Insert Employee Data of %d: ",yearToLook);
				scanf("%d",&employeeData);
				
				add_employee_data(companies[selectedCompany-1], yearToLook, employeeData);
				break;
				
			case 2: // find total employees
				selectedCompany = select_company(companies, companyCount);
				
				printf("Insert Year to See Employee Data (2018-2022): ");
				scanf("%d",&yearToLook);
				
				employeeData = find_total_employees(companies[selectedCompany-1], yearToLook);
				printf("%s employees on %d: %d\n",companies[selectedCompany-1]->name, yearToLook, employeeData);
				break;
				
			case 3: // delete employee data
				selectedCompany = select_company(companies, companyCount);

				printf("Insert Year to Delete Employee Data (2018-2022): ");
				scanf("%d",&yearToLook);
				
				delete_employee_data(companies[selectedCompany-1], yearToLook);
				break;
				
			case 4: // calcualte average employees
				selectedCompany = select_company(companies, companyCount);
				
				employeeProm = calculate_average_employees(companies[selectedCompany-1]);
				
				printf("%s has an Average Quantity of Employees of: %f\n",companies[selectedCompany-1]->name, employeeProm);
				break;
				
			case 5: // general average employees
				printf("Insert Year to Calculate (2018-2022): ");
				scanf("%d",&yearToLook);
				
				employeeProm = general_average_employees(companies, yearToLook, companyCount);
				
				printf("On %d, the Companies at Large had an Average Quantity of Employees of: %f\n",yearToLook, employeeProm);
				break;
				
			case 6: // exit
				printf("BYE!\n");
				break;
		}
		printf("\n");
	} while (election != 6);
	
	return 0;
}
