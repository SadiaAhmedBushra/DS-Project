void mainMenu();
void authorityMenu();
void customerMenu();
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//structure
struct Node
{
  // necessary datas
  int foodCodeData;
  int rating;
  string foodNameData;
  string customerContact;
  string customerName;
  string customerAddress;
  double customerPayment;
  string review;
  string deliveryStatus;
  double foodPriceData;
  vector<string> customerOrderList;
  // pointer for storing address of the next node
  Node *next;
};

// Insering food items to the menu
// follows singly linked list -- inserts at the last of the linked list
void InsertFoodItem(Node **headRef, int foodCode, string foodName, double foodPrice)
{
  // dynamically allocating memory for new node
  Node *newItem = new Node();
  // storing the datas
  newItem->foodCodeData = foodCode;
  newItem->foodNameData = foodName;
  newItem->foodPriceData = foodPrice;
  newItem->next = NULL;

  //if the list is empty, creating a new node and storing the data there
  if (*headRef == NULL)
  {
    *headRef = newItem;
    return;
  }

  //else the list is not empty then traversing to the last node

  Node *it = *headRef;
  while (it->next != NULL)
    it = it->next;
  //storing at the next of the last node
  it->next = newItem;
  return;
}

// search operation using food code as a key
int searchByFoodCode(Node **headRef, int foodCodeKey)
{
  Node *itCurrent = *headRef;
  // traversing from fisrt to last node
  while (itCurrent != NULL)
  {
    // if the data is found then return 1
    if (itCurrent->foodCodeData == foodCodeKey)
    {
      cout << endl
           << "The food item you searched for is found!!" << endl;
      cout << "Food code :" << itCurrent->foodCodeData << " "
           << "Food Name :" << itCurrent->foodNameData << " "
           << "Food Price :" << itCurrent->foodPriceData << endl;
      return 1;
    }

    itCurrent = itCurrent->next;
  }
  // if the data isn't found returns -1
  return -1;
}

// search operation using food name as a key
int searchByFoodName(Node **headRef, string foodNameKey)
{
  Node *itCurrent = *headRef;
  // traversing from fisrt to last node
  while (itCurrent != NULL)
  {
    // if the data is found then return 1
    if (itCurrent->foodNameData == foodNameKey)
    {
      cout << endl
           << "The food item you searched for is found!!" << endl;
      cout << "Food code :" << itCurrent->foodCodeData << " "
           << "Food Name :" << itCurrent->foodNameData << " "
           << "Food Price :" << itCurrent->foodPriceData << endl;
      return 1;
    }

    itCurrent = itCurrent->next;
  }
  // if the data isn't found returns -1
  return -1;
}

// deleting a food item using food code as a key
void deleteByFoodCode(Node **headref, int foodCodeKey)
{
  //storing the reference of the head
  Node *temp = *headref;
  //the previous is initially null
  Node *prev = NULL;

  //if the value to be deleted is head
  if (temp != NULL && temp->foodCodeData == foodCodeKey)
  {
    //making the next node the new head
    *headref = temp->next;
    // deleting
    delete temp;
    cout << "Food item deleted successfully" << endl;
    return;
  }
  else
  {
    //if the head is not the value to be deleted then traverse until reaching the value
    while (temp != NULL && temp->foodCodeData != foodCodeKey)
    {
      prev = temp;
      temp = temp->next;
    }

    if (temp == NULL)
    {
      //if the value to be deleted is not found, print message
      cout << "The food item is not found!" << endl;
      return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Food item deleted successfully" << endl;
  }
}

// deleting a food item using food name as a key
void deleteByFoodName(Node **headref, string foodNameKey)
{
  //storing the reference of the head
  Node *temp = *headref;
  //the previous is initially null
  Node *prev = NULL;

  //if the value to be deleted is head
  if (temp != NULL && temp->foodNameData == foodNameKey)
  { //making the next node the new head
    *headref = temp->next;
    // deleting

    delete temp;
    cout << "Food item deleted successfully" << endl;
    return;
  }
  else
  {
    //if the head is not the value to be deleted then traverse until reaching the value
    while (temp != NULL && temp->foodNameData != foodNameKey)
    {
      prev = temp;
      temp = temp->next;
    }

    if (temp == NULL)
    {
      //if the value to be deleted is not found, print message
      cout << "The food item is not found!" << endl;
      return;
    }
    //changing the previous's next
    prev->next = temp->next;

    delete temp;
    cout << "Food item deleted successfully" << endl;
  }
}

// // function for updating the code of a food item
void updateMenucode(Node **headRef, string foodNameKey, int newFoodCode)
{
  // creating an iterator for traversing, starts from the first node
  Node *itCurrent = *headRef;

  while (itCurrent != NULL)
  {
    // if the food name matches with the key, then update information
    if (itCurrent->foodNameData == foodNameKey)
    {
      itCurrent->foodCodeData = newFoodCode;

      // printing success message
      cout << endl
           << "Information updated successfully!" << endl
           << endl;

      // printing the updates
      cout << "Displaying the updated information: " << endl;

      cout << "Food Code :" << itCurrent->foodCodeData << " "
           << "Food Name :" << itCurrent->foodNameData << " "
           << "Food Price:" << itCurrent->foodPriceData << " " << endl
           << endl;
    }

    itCurrent = itCurrent->next;
  }
}

// function for updating the price of a food item
void updateMenuprice(Node **headRef, string foodNameKey, double newFoodPrice)
{
  // creating an iterator for traversing, starts from the first node
  Node *itCurrent = *headRef;

  while (itCurrent != NULL)
  {
    // if the food name matches with the key, then update information
    if (itCurrent->foodNameData == foodNameKey)
    {

      itCurrent->foodPriceData = newFoodPrice;

      // printing success message
      cout << endl
           << "Information updated successfully!" << endl
           << endl;

      // printing the updates
      cout << "Displaying the updated information: " << endl;

      cout << itCurrent->foodCodeData << " "
           << itCurrent->foodNameData << " "
           << itCurrent->foodPriceData << " " << endl
           << endl;
    }

    itCurrent = itCurrent->next;
  }
}

// function for displaying the menu
void showMenu(Node *it)
{
  cout << "\nMenu: \n";
  while (it != NULL)
  {
    cout << it->foodCodeData << " " << it->foodNameData << " " << it->foodPriceData << endl;
    it = it->next;
  }
  cout << endl;
}

// file name for menu
string getFileNameForMenu()
{
  string fileName;
  fileName = "InsertFoodItem file.txt";
  return fileName;
}

// file write operation for menu
void fileWriteOperationForMenu(struct Node **headRef)
{
  string fNameSave = getFileNameForMenu();
  ofstream WriteFile;
  Node *temp = *headRef;
  WriteFile.open(fNameSave, ios::app);
  // if the file is not opened yet
  if (!WriteFile)
  {
    cout << "File cannot be opened" << endl;
  }
  else
  {
    while (temp != NULL)
    {
      WriteFile << "Food Code  :" << temp->foodCodeData << " "
                << "Food Name :" << temp->foodNameData << " "
                << "Price :"
                << " " << temp->foodPriceData << "taka" << endl;
      temp = temp->next;
    }
    WriteFile.close();
  }
}

// file read operation for menu
void fileReadOperationForMenu()
{
  string fNameSave = getFileNameForMenu();

  ifstream ReadFile;
  ReadFile.open(fNameSave, ios::app);
  // if the file is not opened yet
  if (!ReadFile)
  {
    cout << "File could not be opened" << endl;
  }
  else
  {
    string line;
    while (!ReadFile.eof())
    {
      getline(ReadFile, line);
      if (ReadFile.eof())
        break;
      cout << line << endl;
    }
  }
  ReadFile.close();
}

// this search function is used in insertCustomerOrder function
double search(Node **headRef, string foodNameKey)
{
  Node *itCurrent = *headRef;
  // traversing from fisrt to last node
  while (itCurrent != NULL)
  {
    // if the data is found then return 1
    if (itCurrent->foodNameData == foodNameKey)
    {
      return itCurrent->foodPriceData;
    }

    itCurrent = itCurrent->next;
  }
  // if the data isn't found returns -1
  return 0.0;
}

// function for taking order
// follows queue -- implemented using singly linked list -- inserts at last
void insertCustomerOrder(Node **head_ref, string Name, string Address, string number, vector<string> &orderList)
{
  Node *newnode = new Node();
  newnode->customerName = Name;
  newnode->customerAddress = Address;
  newnode->customerContact = number;
  newnode->customerOrderList = orderList;

  double price;
  for (int i = 0; i < orderList.size(); i++)
  {
    price += search(head_ref, orderList[i]);
  }

  cout << "Total Cost of Your Food: " << price << endl;
  double vat = price * 0.15;
  cout << "15% Vat on this Amount = " << vat << endl;
  price = price + vat;
  cout << "Your Total Price Including Vat = " << price << "tk" << endl;

  if (price > 500)
  {
    price = price - (price * 0.2);
    cout << "Congratulations! You Are Getting 20% Discount" << endl;
  }
  price += 40;
  cout << "Total Payable Amount: " << price << "tk" << endl;

  newnode->next = NULL;

  if (*head_ref == NULL)
  {
    *head_ref = newnode;
    return;
  }

  Node *it = *head_ref;
  while (it->next != NULL)
  {
    it = it->next;
  }
  it->next = newnode;
  return;
}

// function for dequeue by confirming an order
void confirmAndDequeue(Node **head_ref)
{
  // temp holds the first node, that has to be dequeued
  Node *temp = *head_ref;
  string rtn;
  // if the queue is empty, then print error message
  if (temp == NULL)
    cout << "\n\nNo order in the queue right now!\n\n";

  else
  {
    // storing the information to be deleted in rtn to display later
    rtn = temp->customerName;
    *head_ref = temp->next;
    delete temp;
  }
  cout << "Order confirmed and being delivered to the customer " << rtn << ".\n";
}

// function for printing customer order and details
void showCustomerOrder(Node *it)
{
  cout << "\nCustomers details: \n";
  // if the queue is empty, prints error message
  if (it == NULL)
    cout << "No orders pending right now.";

  // traverse from first to last and prints
  while (it != NULL)
  {
    cout << "Customer Name:" << it->customerName << "\nCustomer Address:" << it->customerAddress << "\nCustomer phone number:" << it->customerContact << endl;
    cout << "Ordered items: " << endl;

    for (int i = 0; i < it->customerOrderList.size(); i++)
    {
      cout << i + 1 << "." << it->customerOrderList[i] << endl;
    }

    it = it->next;
  }
}

// file name for confirmation details file
string getCustomerDetailFileName()
{
  string fileName;
  fileName = "Insert customer details file.txt";
  return fileName;
}

// file for customer information write operation
void WriteCustomerDetails(struct Node **headRef)
{
  string fNameSave = getCustomerDetailFileName();
  ofstream WriteFile;
  Node *temp = *headRef;
  WriteFile.open(fNameSave, ios::app);
  // if the file is not opened yet
  if (!WriteFile)
  {
    cout << "File cannot be opened" << endl;
  }
  else
  {
    while (temp != NULL)
    {
      WriteFile << "Customer Name:" << temp->customerName << " "
                << "Address:" << temp->customerAddress << " "
                << "Contact:"
                << " " << temp->customerContact
                << "Ordered items: " << endl;
      for (int i = 0; i < temp->customerOrderList.size(); i++)
      {
        WriteFile << temp->customerOrderList[i] << "\nTotal price: " << temp->customerPayment << " tk\n\n";
      }
      temp = temp->next;
    }
    WriteFile.close();
  }
}

// read function for customer details
void ReadCustomerDetail()
{
  string fNameSave = getCustomerDetailFileName();

  ifstream ReadFile;
  ReadFile.open(fNameSave, ios::in);
  // if the file is not opened yet
  if (!ReadFile)
  {
    cout << "File could not be opened" << endl;
  }
  else
  {
    string line;
    while (!ReadFile.eof())
    {
      getline(ReadFile, line);
      if (ReadFile.eof())
        break;
      cout << line << endl;
    }
  }
  ReadFile.close();
}

// function for inserting delivery status by customer
// maintains a stack -- implemented using singly linked list -- inserts at first
void customerDeliveryStatusInput(Node **head_ref, string dStatus)
{
  Node *node = new Node();
  node->deliveryStatus = dStatus;
  node->next = *head_ref;
  *head_ref = node;
}
// file name for confirmation details file
string getConfirmationFileName()
{
  string fileName;
  fileName = "Confirmation Details File.txt";
  return fileName;
}

// write function for confirming order
void WriteConfirmationDetails(struct Node **headRef)
{
  string fNameSave = getConfirmationFileName();
  ofstream WriteFile;
  Node *temp = *headRef;
  WriteFile.open(fNameSave, ios::app);
  // if the file is not opened yet
  if (!WriteFile)
  {
    cout << "File cannot be opened" << endl;
  }
  else
  {
    // writing confirmation message for the customer
    WriteFile << "Order confimed for the customer Name: " << temp->customerName << " "
              << " Address: " << temp->customerAddress << " "
              << " Contact: "
              << " " << temp->customerContact
              << " Ordered items: " << endl;
    for (int i = 0; i < temp->customerOrderList.size(); i++)
    {
      WriteFile << temp->customerOrderList[i] << endl;
    }
    WriteFile << "Your food is being prepared and you will receive your delivery within 30 minutes. Please stay with us.\n\n";
  }
  WriteFile.close();
}

// write function for customer for delivery status
void WriteDeliveryStatus(struct Node **headRef)
{
  string fNameSave = getConfirmationFileName();
  ofstream WriteFile;
  Node *temp = *headRef;
  WriteFile.open(fNameSave, ios::app);
  // if the file is not opened yet
  if (!WriteFile)
  {
    cout << "File cannot be opened" << endl;
  }
  else
  {
    // customer's written delivery status will be stored
    WriteFile << "Delivery status:" << temp->deliveryStatus << " \n\n";

    WriteFile.close();
  }
}

// function for reading the confirmation details file
void ReadConfirmationDetails()
{
  string fNameSave = getConfirmationFileName();

  ifstream ReadFile;
  ReadFile.open(fNameSave, ios::in);
  // if the file is not opened yet
  if (!ReadFile)
  {
    cout << "File could not be opened" << endl;
  }
  else
  {
    string line;
    while (!ReadFile.eof())
    {
      getline(ReadFile, line);
      if (ReadFile.eof())
        break;
      cout << line << endl;
    }
  }
  ReadFile.close();
}

// function for inserting reviews and rating
// maintains a stack -- implemented using singly linked list -- inserts at first
void insrtReviewAndRatings(Node **head_ref, int Rating, string Review)
{
  Node *node = new Node();
  node->rating = Rating;
  node->review = Review;
  node->next = *head_ref;
  *head_ref = node;

  cout << "Thank you so much for your valuable review." << endl;
}

// file name for reviews and rating file
string getReviewRateFileName()
{
  string fileName;
  fileName = "Customer Review.txt";
  return fileName;
}

// write function for reviews and ratings
void WriteReviewAndRate(struct Node **headRef)
{
  string fNameSave = getReviewRateFileName();
  ofstream WriteFile;
  Node *temp = *headRef;
  WriteFile.open(fNameSave, ios::app);
  if (!WriteFile)
  {
    cout << "File cannot be opened" << endl;
  }
  else
  {
    while (temp != NULL)
    {
      WriteFile << "Customer Rating and Review  :" << temp->rating << " " << temp->review << endl;

      temp = temp->next;
    }
    WriteFile.close();
  }
}

// read function for review and rate
void ReadReviewAndRate()
{
  string fNameSave = getReviewRateFileName();

  ifstream ReadFile;
  ReadFile.open(fNameSave, ios::app);
  if (!ReadFile)
  {
    cout << "File could not be opened" << endl;
  }

  else
  {
    string line;
    while (!ReadFile.eof())
    {
      getline(ReadFile, line);
      if (ReadFile.eof())
        break;
      cout << line << endl;
    }
  }
  ReadFile.close();
}

//function for sorting the price of the menu in ascending order
struct Node *MergeSort_ascending(struct Node *a, struct Node *b)
{
  // dynamically allocating memory for new node
  Node *newnode = new Node();
  newnode->foodPriceData = 0;
  newnode->next = NULL;
  Node *last = newnode;
  //splitting the list into two sublists a and b
  //comparing each element present in sublist a to each element present in sublist b
  while (a != NULL && b != NULL)
  {
    if (a->foodPriceData < b->foodPriceData)
    {
      //the element in 'a' will be assigned to last if it's less than an element in 'b'
      last->next = a;
      a = a->next;
      last = last->next;
    }
    else
    {
      //the element in 'b' will be assigned to last if it's less than an element in 'a'
      last->next = b;
      b = b->next;
      last = last->next;
    }
    if (a != NULL)
    {
      last->next = a;
    }
    else if (b != NULL)
    {
      last->next = b;
    }
  }
  return newnode->next;
}

//splitting the nodes into front and back halves
void split_ascending(struct Node *head, struct Node **first, struct Node **last)
{
  //progressing with the fast and slow pointer strategy to find the mid point
  struct Node *slow = head;
  struct Node *fast = head->next;
  //advancing 'fast' to two nodes and 'slow' to one node untill 'fast' becomes NULL
  while (fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }
  //when 'slow' is before the midpoint in a list, split it into two halves
  *first = head;
  *last = slow->next;
  slow->next = NULL;
}

// sorts the linked list by changing next pointers
void accending_order(struct Node **head)
{
  struct Node *a;
  struct Node *b;
  if (*head == NULL || (*head)->next == NULL)
  {
    return;
  }
  // splits the head into two sublists a and b
  split_ascending(*head, &a, &b);
  accending_order(&a);
  accending_order(&b);
  //merges the two sorted lists together
  *head = MergeSort_ascending(a, b);
}

//function for sorting the price of the menu in descending order
struct Node *MergeSort_descending(struct Node *a, struct Node *b)
{
  // dynamically allocating memory for new node
  Node *newnode = new Node();
  newnode->foodPriceData = 0;
  newnode->next = NULL;
  Node *last = newnode;
  //splitting the list into two sublists
  //comparing the elements present in two sublists
  while (a != NULL && b != NULL)
  {
    if (a->foodPriceData > b->foodPriceData)
    {
      //the element in 'a' will be assigned to last if it's greater than an element in 'b'
      last->next = a;
      a = a->next;
      last = last->next;
    }
    else
    {
      //the element in 'b' will be assigned to last if it's greater than an element in 'a'
      last->next = b;
      b = b->next;
      last = last->next;
    }
    if (a != NULL)
    {
      last->next = a;
    }
    else if (b != NULL)
    {
      last->next = b;
    }
  }
  return newnode->next;
}

//splitting the nodes into front and back halves
void split_descending(struct Node *head, struct Node **first, struct Node **last)
{
  //progressing with the fast and slow pointer strategy to find the mid point
  struct Node *slow = head;
  struct Node *fast = head->next;
  //advancing 'fast' to two nodes and 'slow' to one node untill 'fast' becomes NULL
  while (fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }
  //when 'slow' is before the midpoint in a list, split it into two halves
  *first = head;
  *last = slow->next;
  slow->next = NULL;
}

// sorts the linked list by changing next pointers
void descending_order(struct Node **head)
{
  struct Node *a;
  struct Node *b;
  if (*head == NULL || (*head)->next == NULL)
  {
    return;
  }
  // splits the head into two sublists a and b
  split_descending(*head, &a, &b);
  descending_order(&a);
  descending_order(&b);
  //merges the two sorted lists together
  *head = MergeSort_descending(a, b);
}

// declaration of main menu
void mainMenu(Node *headR);

// defining authority menu
void authorityMenu(Node *headR)
{
  Node *head = NULL;
  head = headR;
  cout << "Please enter the password: ";
  int pass;
  cin >> pass;

  if (pass == 123)
  {
    cout << "\n\t\t\t\tWelcome to the authority menu!!!\t\t\t\n\n";
    while (1)
    {
      cout << "---------------------------------------------" << endl;
      cout << "Press 1 to insert food item.\n";
      cout << "Press 2 to search a food item.\n";
      cout << "Press 3 to delete a food item.\n";
      cout << "Press 4 to update food information.\n";
      cout << "Press 5 save and see final food list .\n";
      cout << "Press 6 to see orders.\n";
      cout << "Press 7 to dequeue and confirm.\n";
      cout << "Press 8 to see customer delivery confirmation.\n";
      cout << "Press 9 to see customer review.\n";
      cout << "Press 0 to return to the main menu.\n";
      cout << "---------------------------------------------\n";

      int opt;
      cout << "\nEnter any option: \n";
      cin >> opt;

      if (opt == 1)
      {
        cout << "Enter the code number of the food item: ";
        int fCode;
        cin >> fCode;

        cout << "Enter the name of the food item you want to add to the menu: ";
        string fName;
        cin.ignore();
        getline(cin, fName);

        cout << "Enter the price of the food item: ";
        double fPrice;
        cin >> fPrice;
        InsertFoodItem(&head, fCode, fName, fPrice);
        cout << "Food item inserted successfully" << endl;
        void show();
      }
      else if (opt == 2)
      {
        int moreOpt;
        cout << "Press 1 to search by food code.\n";
        cout << "Press 2 to search by food name.\n";
        cout << "Enter your choice: ";
        cin >> moreOpt;

        if (moreOpt == 1)
        {
          cout << "Enter the food code you want to search: ";
          int fCode;
          cin >> fCode;

          int val = searchByFoodCode(&head, fCode);
          if (val == -1)
          {
            cout << "\nThe food item you searched for is not found!\n\n";
            ;
          }
        }
        else if (moreOpt == 2)
        {
          cout << "Enter the food name you want to search: ";
          string fName;
          cin.ignore();
          getline(cin, fName);

          int val = searchByFoodName(&head, fName);
          if (val == -1)
          {
            cout << "\nThe food item you searched for is not found!\n\n";
          }
        }
      }

      else if (opt == 3)
      {
        cout << "Press 1 to delete by food code.\n";
        cout << "Press 2 to delete by food name.\n";
        int moreOpt;
        cout << "Enter your choice: ";
        cin >> moreOpt;

        if (moreOpt == 1)
        {
          cout << "Enter the food code you want to delete: ";
          int fCode;
          cin >> fCode;

          deleteByFoodCode(&head, fCode);
        }
        else if (moreOpt == 2)
        {
          cout << "Enter the food name you want to delete: ";
          string fName;
          cin.ignore();
          getline(cin, fName);

          deleteByFoodName(&head, fName);
        }
      }

      else if (opt == 4)
      {
        cout << "Press 1 to update food code.\n";
        cout << "Press 2 to update food price.\n";
        cout << "Enter your choice: ";

        int moreOpt;
        cin >> moreOpt;

        if (moreOpt == 1)
        {
          cout << "Enter the name of the food item you want to update: ";
          string fName;
          cin.ignore();
          getline(cin, fName);

          int val = searchByFoodName(&head, fName);
          if (val == 1)
          {
            cout << "\nPlease update the informations.\n\n";
            cout << "Enter the new code number of the food item: ";
            int fCode;
            cin >> fCode;

            updateMenucode(&head, fName, fCode);
          }
        }
        else if (moreOpt == 2)
        {
          cout << "Enter the name of the food item you want to update: ";
          string fName;
          cin.ignore();
          getline(cin, fName);

          int val = searchByFoodName(&head, fName);
          if (val == 1)
          {
            cout << "\nPlease update the informations.\n\n";
            cout << "Enter the new price of the food item: ";
            int fprice;
            cin >> fprice;

            updateMenuprice(&head, fName, fprice);
          }
        }
      }
      else if (opt == 5)
      {
        fileWriteOperationForMenu(&head);
        fileReadOperationForMenu();
      }
      else if (opt == 6)
      {
        showCustomerOrder(head);
      }
      else if (opt == 7)
      {
        if (head != NULL)
        {
          confirmAndDequeue(&head);

          cout << "Enter confirmation message for the customer with the customer name: ";
          string confirmMsg;
          cin.ignore();
          getline(cin, confirmMsg);
          WriteConfirmationDetails(&head);
        }
        else
        {
          cout << "No orders pending right now.";
          break;
        }
      }
      else if (opt == 8)
      {
        cout << "Check customer delivery status: \n";
        ReadConfirmationDetails();
      }
      else if (opt == 9)
      {
        ReadReviewAndRate();
      }
      else if (opt == 0)
      {
        mainMenu(head);
      }
    }
  }

  else
  {
    cout << "Wrong Password!!" << endl;
  }
}

// customer menu
void customerMenu(Node *headR)
{
  Node *head = NULL;
  head = headR;
  while (true)
  {
    cout << "---------------------------------------------" << endl;
    cout << "\nPress 1 to see the menu.\n";
    cout << "Press 2 to sort the menu.\n";
    cout << "Press 3 to order food.\n";
    cout << "Press 4 to see order confirmation status.\n";
    cout << "Press 5 to inform delivery status.\n";
    cout << "Press 6 to search for an item\n";
    cout << "Press 7 to review and rate.\n";
    cout << "Press 8 to see reviews and ratings.\n";
    cout << "Press 0 to return to main menu.\n";
    cout << "---------------------------------------------" << endl;

    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;
    cout << endl;

    if (choice == 1)
    {
      fileReadOperationForMenu();
    }

    else if (choice == 2)
    {
      int ans;
      cout << "\t\t\tIn which order do you want to see the sorted list?" << endl;
      cout << "\n\t\t1. Lowest price to highest price" << endl;
      cout << "\n\t\t2. Highest price to lowest price" << endl;
      cin >> ans;
      if (ans == 1)
      {
        accending_order(&head);
        showMenu(head);
      }
      else if (ans == 2)
      {
        descending_order(&head);
        showMenu(head);
      }
    }

    else if (choice == 3)
    {

      string customer_name;
      string customer_address;
      string customer_number;

      cin.ignore();
      cout << "Customer Name:" << endl;
      getline(cin, customer_name);

      cout << "Customer Address:" << endl;
      getline(cin, customer_address);

      cout << "Customer Contact Number:" << endl;
      getline(cin, customer_number);
      cout << "\nIf you order more then 500 tk then you will get additional 20% discount" << endl;
      cout << "\nEnter the Number of food items you want to order: ";
      int num;
      cin >> num;
      cout << "Enter food item names" << endl;
      vector<string> order_list(num);
      for (int i = 0; i < num; i++)
      {
        cout << (i + 1) << ". ";
        cin >> order_list[i];
      }

      insertCustomerOrder(&head, customer_name, customer_address, customer_number, order_list);

      // writing in file
      WriteCustomerDetails(&head);
    }
    else if (choice == 4)
    {
      cout << "Check if your order is confirmed or not.\n";
      ReadConfirmationDetails();
    }
    else if (choice == 5)
    {
      cout << "Write your delivery status here: ";
      cin.ignore();
      string delStatus;
      getline(cin, delStatus);
      customerDeliveryStatusInput(&head, delStatus);
      WriteDeliveryStatus(&head);
      cout << "Thanks for your update!\n\n";
    }
    else if (choice == 6)
    {
      cout << "Enter the food name you want to search: ";
      string fName;
      cin.ignore();
      getline(cin, fName);

      int val = searchByFoodName(&head, fName);
      if (val == -1)
      {
        cout << "\nThe food item you searched for is not found!\n\n";
      }
    }
    else if (choice == 7)
    {
      int Rate;
      cout << "Rate us out of Five!" << endl;
      cin >> Rate;

      string Rev;
      cout << "Enter your review: " << endl;
      cin.ignore();
      getline(cin, Rev);
      insrtReviewAndRatings(&head, Rate, Rev);
      WriteReviewAndRate(&head);
    }
    else if (choice == 8)
    {
      ReadReviewAndRate();
    }
    else if (choice == 0)
    {
      mainMenu(head);
    }
  }
}

void mainMenu(Node *headR)
{
  Node *head = NULL;
  head = headR;
  while (1)
  {
    cout << "\n\t\t\t\tWelcome to the food delivery management system\t\t\t\n\n";
    cout << "\t\t\t1. Authority Menu\t\t\t\n";
    cout << "\t\t\t2. Customer Menu\t\t\t\n";
    cout << "\t\t\t3. Exit\t\t\t\n";

    int choice;
    cout << "Enter you choice: ";
    cin >> choice;

    if (choice == 1)
    {
      authorityMenu(head);
    }
    else if (choice == 2)
    {
      cout << "\n\t\t\t\tWelcome to the customer menu!!!\t\t\t\n\n";
      customerMenu(head);
    }
    else
      exit(0);
  }
}

int main()
{
  Node *head = NULL;

  mainMenu(head);

  return 0;
}