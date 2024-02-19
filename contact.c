#include <stdio.h>

struct Contact
{
   char name[50];
   char phone[50];
   char email[50];
};

void addContact()
{
   FILE *file;
   file = fopen("contact.txt", "a");
   if (file == NULL)
   {
      printf("File does not exist or could not be created");
   }
   else
   {

      struct Contact contact;
      fflush(stdin);
      printf("Enter Name: ");
      fgets(contact.name, sizeof contact.name, stdin);

      printf("Enter Phone: ");
      fgets(contact.phone, sizeof contact.phone, stdin);

      printf("Enter Email: ");
      fgets(contact.email, sizeof contact.email, stdin);

      // write to the file
      fprintf(file, "%s%s%s\n", contact.name, contact.phone, contact.email);

      fclose(file);

      printf("Added to Contact Management System\n");
   }
}

void displayContacts()
{
   struct Contact contact;

   FILE *file;
   file = fopen("contact.txt", "r");
   if (file == NULL)
   {
      printf("File does not exist or could not be created");
   }
   else
   {

      printf("Contacts.\n");

      while (fscanf(file, " %[^\n] %[^\n] %[^\n]", contact.name, contact.phone, contact.email) != EOF)
      {
         printf("Name: %s\nPhone: %s\nEmial: %s\n\n", contact.name, contact.phone, contact.email);
      }

      fclose(file);
   }
}

int main()
{
   int choice;
   do
   {
      printf("\nContact Management System\n");
      printf("1. Add Contact\n");
      printf("2. Display Contacts\n");
      printf("3. Exit\n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         addContact();
         break;
      case 2:
         displayContacts();
         break;
      case 3:
         printf("Exiting...\n");
         break;
      default:
         printf("Invalid Choice. Please try again.\n");
      }

   } while (choice != 3);
}

// Introduction
// variables, data types
// operators
// conditional - if, else, switch
// loop - for, while, do while (recorded)
// array - 3
// string
// function
// structure
// file
// pointer
