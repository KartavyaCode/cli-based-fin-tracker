#include <iostream>
#include <string>
#include <cmath>

// Global variables (not a good practice, to fix)
int monthlyBudget = 0;
int totalExpenses = 0;
int expenseAmount;
int categoryNumber;
int mainMenuSelection;

std::string newLine = "\n";

std::string userMenuOptions[5] = {"1. Set Monthly Budget", "2. Add an Expense", "3. View Balance", "4. Show Spending Summary", "5. Exit"};
std::string categoryType[5] = {"1. Food", "2. Education", "3. Family", "4. Personal", "5. Others"};

// Declaring functions
void mainMenu();
void mainMenuLogic();
void setMonthlyBudget();
void editMonthlyBudget();
void logExpense();
void currentBal();
int spendSum();
int exit();

// Main function
int main()
{
   std::cout << "Welcome to FinTrack Buddy 👋. Your personal expense management system! 💰\n";
   std::cout << newLine;
   mainMenu();
   return 0;
}

// Functionality

void mainMenu()
{
   std::cout << "Choose any one of the options\n"
             << newLine;
   std::cout << userMenuOptions[0] << newLine;
   std::cout << userMenuOptions[1] << newLine;
   std::cout << userMenuOptions[2] << newLine;
   std::cout << userMenuOptions[3] << newLine;
   std::cout << userMenuOptions[4] << newLine;
   std::cout << newLine;
   std::cout << "Enter your choice: ";
   std::cin >> mainMenuSelection;

   // checking for valid responses
   while (true)
   { // basically helps in looping the code forever
      if (std::cin.fail())
      {
         std::cin.clear();
         std::cin.ignore(10000, '\n');
         std::cout << "Invalid input. Please enter a valid response.\n";
         std::cout << newLine;
      }
      else if (mainMenuSelection >= 0 && mainMenuSelection <= 5)
      {
         std::cout << newLine;
         mainMenuLogic();
      }
      else
      {
         std::cout << "Number out of range. Please enter a valid number.\n";
         std::cout << newLine;
      }
   }
}

void mainMenuLogic()
{
   switch (mainMenuSelection)
   {
   case 1:
      std::cout << "Selected " << userMenuOptions[0] << newLine;
      std::cout << newLine;
      setMonthlyBudget();
      break;
   case 2:
      std::cout << "Selected " << userMenuOptions[1] << newLine;
      std::cout << newLine;
      logExpense();
      break;
   case 3:
      std::cout << "Selected " << userMenuOptions[2] << newLine;
      std::cout << newLine;
      currentBal();
      break;
   case 4:
      std::cout << "Selected " << userMenuOptions[3] << newLine;
      std::cout << newLine;
      // spendSum();
      break;
   case 5:
      std::cout << "Selected " << userMenuOptions[4] << newLine;
      std::cout << newLine;
      exit();
      break;
      // do I need to add a default case here? --> not really cause I've addressed the case of invalid input cases above
   }
}

void setMonthlyBudget()
{
   if (monthlyBudget == 0)
      {
         std::cout << "What should be the budget for this month?" << newLine << "Rs. "; // just unable to add an extra line after this gets outputted
         std::cin >> monthlyBudget;
         std::cout << "The budget for the current month is Rs. " << monthlyBudget;exit(); // kind of like a break statemetn in this case for an if-else (goto a function)
      }
   else
   {
      editMonthlyBudget();
   }
}

void editMonthlyBudget(){
      std::string editBudget;
      std::cout << "A budget amount has already been added. Do you want to edit the current monthly budget? (y/n): " << newLine;
      std::cin >> editBudget;
      if (editBudget == "n")
      {
         exit();
      }
      else
      {
         std::cout << "Editing current budget...What should be the budget for this month?" << newLine << "Rs. ";
         std::cin >> monthlyBudget;
         std::cout << newLine;
         std::cout << "The budget for the current month is Rs. " << monthlyBudget;
      }
      exit();
   }

void logExpense()
{
   std::cout << "Enter the expense amount." << newLine << "Rs. ";
   std::cin >> expenseAmount;
   std::cout << newLine;
   std::cout << "List of categories\n";
   std::cout << categoryType[0] << newLine;
   std::cout << categoryType[1] << newLine;
   std::cout << categoryType[2] << newLine;
   std::cout << categoryType[3] << newLine;
   std::cout << categoryType[4] << newLine;
   std::cout << newLine;
   std::cout << "Enter category number: " << newLine;
   std::cin >> categoryNumber; // the logic gets flawed somewhere here
   std::cout << "Expense added of Rs. " << expenseAmount << " in category " << categoryType[categoryNumber-1];
   exit();
}

void currentBal(){
   totalExpenses = totalExpenses + expenseAmount;
   std::cout << totalExpenses << newLine;
   std::cout << newLine;
   if (totalExpenses > monthlyBudget){
     std::cout << "You ran out of money!" << newLine;
   }else{
     std::cout << "You have a total of Rs. " << (monthlyBudget - totalExpenses) << " remaining in your fin track buddy BUDGET account." << newLine;
   }
   exit();
}

int exit()
{
   std::string menuBack;
   std::cout << newLine;
   std::cout << "Back to menu? (y/n): ";
   std::cin >> menuBack;
   std::cout << newLine;

   if (menuBack == "y")
   {
      std::cout << "Taking back to the menu..." << newLine;
      std::cout << newLine << newLine;
      mainMenu();
   }
   else
   {
      std::cout << "You can exit by hitting the key combination 'CTRL+C'" << newLine; // this needs to be fixed, the application should be get exited out by itself in such a case. Something like a break but for if-else
   }
   return 0;
}
