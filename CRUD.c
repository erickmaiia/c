#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Register
{
    int id;
    char name[50];
    int age;
};

struct Register *registers = NULL;
int num_registers = 0;
int max_registers = 0;

int main(void)
{
    void callFunc(int arg);
    void showMenu();
    int option;

    while (option != 7)
    {
        showMenu();
        printf("Write a option: ");
        scanf("%i", &option);
        callFunc(option);
    }

    return 0;
}

void callFunc(int arg)
{

    void createRegister();
    void readRegister();
    void updateRegister();
    void deleteRegister();
    void showRegisters();
    void saveRegisters();

    if (arg == 1)
    {
        createRegister();
    }
    else if (arg == 2)
    {
        readRegister();
    }
    else if (arg == 3)
    {
        updateRegister();
    }
    else if (arg == 4)
    {
        deleteRegister();
    }
    else if (arg == 5)
    {
        showRegisters();
    }
    else if (arg == 6)
    {
        saveRegisters();
        printf("Saved records");
    }
    else if (arg == 7)
    {
        printf("Exit...\n");
    }
    else
    {
        printf("Invalid option\n");
    }
}

void showMenu()
{
    printf("\nChoose an option:\n");
    printf("1 - Create register\n");
    printf("2 - Read register\n");
    printf("3 - Update register\n");
    printf("4 - Delete register\n");
    printf("5 - Show all registers\n");
    printf("6 - Save all registers\n");
    printf("7 - Exit...\n");
}

void createRegister()
{

    struct Register new_register;

    printf("\nWrite a name: ");
    scanf("%s", new_register.name);

    printf("Write a age: ");
    scanf("%d", &new_register.age);

    new_register.id = num_registers;

    if (num_registers >= max_registers)
    {
        max_registers = max_registers == 0 ? 1 : max_registers * 2;
        registers = (struct Register *)realloc(registers, max_registers * sizeof(struct Register));
    }

    registers[num_registers] = new_register;
    num_registers++;

    printf("\nRegister successfully created!\n");
}

void readRegister()
{
    int id;

    printf("\nEnter the ID of the record you want to read: ");
    scanf("%d", &id);

    if (id >= num_registers || id < 0)
    {
        printf("\nRegister not found.\n");
        return;
    }

    struct Register person = registers[id];

    printf("\nID: %d\n", person.id);
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
}

void updateRegister()
{
    int id;

    printf("\nEnter the ID of the record you want to update: ");
    scanf("%d", &id);

    if (id >= num_registers || id < 0)
    {
        printf("\nRegister not found.\n");
        return;
    }

    struct Register *person = &registers[id];

    printf("Enter the new name: ");
    scanf("%s", person->name);

    printf("Enter the new age: ");
    scanf("%d", &person->age);

    printf("\nRegistration successfully updated!\n");
}

void deleteRegister()
{
    int id;

    printf("\nEnter the ID of the record you want to delete: ");
    scanf("%d", &id);

    if (id >= num_registers || id < 0)
    {
        printf("\nRegister not found.\n");
        return;
    }

    for (int i = id; i < num_registers - 1; i++)
    {
        registers[i] = registers[i + 1];
    }

    num_registers--;

    printf("\nRegistration deleted successfully!\n");
}

void showRegisters()
{
    if (num_registers == 0)
    {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n");

    
    for (int i = 0; i < num_registers; i++)
    {
        struct Register person = registers[i];

        printf("ID: %d\n", person.id);
        printf("Name: %s\n", person.name);
        printf("Age: %d\n\n", person.age);
    }
}

void saveRegisters()
{
    FILE *file;
    file = fopen("registers.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    
    for (int i = 0; i < num_registers; i++)
    {
        fprintf(file, "%d %s %d\n", registers[i].id, registers[i].name, registers[i].age);
    }

    fclose(file);
}