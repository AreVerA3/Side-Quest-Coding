// COMPUTER INVENTORY SHOP 

#include<iostream> 
#include<conio.h>
#include<string>

using namespace std;

class Inventory {
	
	//private variables
	private:
		string name, price, quantity; 
		
	public:
		//setters - assigning user value to private variables
		void setName(string a){name = a;}
		void setPrice(string b){price = b;}
		void setQuantity(string c){quantity = c;}

		//getters - getting the values from private variables
		string getName(){return name;}
		string getPrice(){return price;}
		string getQuantity(){return quantity;}

};

//initializing functions with counter as parameter
void addProduct(int counter);
void deleteProduct(int counter);
void viewProduct(int counter);
void viewList(int counter);
void quit();


int counter=0;

//function for incrementing counter
void increment(int a){
	a++;
	counter=a;
}

//function for decrementing counter
void decrement(int a){
	a--;
	counter=a;
}


Inventory inventoryshop[10];

//main function
int main()
{
   string choice;
   //Main Menu
   system("CLS");
   
   cout<<"=========== COMPUTER SHOP INVENTORY ===========\n\n";
   cout<< "\t\tM A I N   M E N U\n\n";
   cout<<"[1] ADD PRODUCT\n";	
   cout<<"[2] DELETE PRODUCT\n";		
   cout<<"[3] VIEW SELECTED PRODUCT\n";	
   cout<<"[4] VIEW ALL PRODUCT\n";	
   cout<<"[5] QUIT\n\n";

   cout<<" ENTER CHOICE: ";
   getline(cin,choice);
   system("CLS");

   if(choice=="1")
   {
	//function call
	addProduct(counter); 
   }	
   	
   else if(choice=="2")
  {	
	deleteProduct(counter); 
  }

  else if(choice=="3")
  {
	viewProduct(counter); 	
  }
  
  else if(choice=="4")
  {
	viewList(counter); 	
  }
   
  else if(choice=="5")
  {
	quit();	 
  }

  else
  {
	//function call to self(main)
	main();  
  }
	
system("PAUSE");
return 0;
}


//add product funtion
void addProduct(int counter)
{
	std::string name;
	string price,quantity;
	int number, i;
	
	cout<<"Enter number of product you want to add: ";
	cin>> number;
	{
	 if(counter<10)
	 
	 {
		for (i=0; i<number; i++)
		{
			std::cout<< "\nEnter product name: "; 
			std::cin.ignore(100,'\n');
		    std::getline(std::cin,name);
		    
			cout<< "Enter product price: RM";
			getline(cin,price);
			
			cout<< "Enter product quantity: ";
			getline(cin,quantity);
			
			inventoryshop[counter].setName(name);
			inventoryshop[counter].setPrice(price);
			inventoryshop[counter].setQuantity(quantity);
			increment(counter);
			
		}
		    cout<< "\n===========PRODUCT ADDED SUCCESSFULLY!===========\n\n";
			
			system("PAUSE");
			main();
     }
		
	else
	{
		cout<< "===========YOU HAVE REACHED THE MAXIMUM NUMBER OF PRODUCT TO BE ADDED!===========\n\n ";
		system("PAUSE");
		main();
	}
   }
}

// delete product function
void deleteProduct(int counter){
	string name;
	int choice;
	
	
	cout<<"===========DELETE PRODUCT===========\n\n";
	if(counter==0)
	{
		cout<<"THERE IS NO PRODUCT TO DELETE!\n";
		system("PAUSE");
		main();
	}
	cout<<"Enter name of product that you would like to DELETE: ";
	getline(cin,name);

	for(int i=0;i<counter;i++)
	{
		//finding a match using for loop
		if(inventoryshop[i].getName()==name)
		{
			cout<< "\nPRODUCT DETAIL IS FOUND\n";
			cout<< "=================================\n";
			cout<< "Do you want to delete?\n\n[1]Yes\n[2]No\n";
			cout<< "\nEnter choice : ";
			cin>>choice;
			
			if(choice==1)
			{
				inventoryshop[i].setName(""); 
				inventoryshop[i].setPrice("");
				inventoryshop[i].setQuantity("");

				for(int a=i;a<counter;a++){
					
					inventoryshop[a] = inventoryshop[a+1];
				}
				
				//calling function to decrement counter
				decrement(counter); 
				cout<<"\n===========PRODUCT DETAILS DELETED!===========\n\n";
				system("PAUSE");
				main();
			}
			
			else
			{
				main();
			}
		}
	}
	
	cout<<"\n===========PRODUCT IS NOT IN THE LIST!===========\n\n";
	system("PAUSE");
	main();
	
}

// view product function
void viewProduct(int counter){
	string name;
	int choice;
	bool print = false; //boolean expression to decide which to print
	cout<<"===========SEARCH PRODUCT DETAILS===========\n\n";
	
	if(counter==0){
		cout<<"NO PRODUCT DETAILS TO DISPLAY!";
		system("PAUSE");
		main();
	}
	cout<<"Enter Name of the Product: ";
	getline(cin,name);
	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(inventoryshop[i].getName()==name){ 
			cout<<"\nPRODUCT DETAIL ARE FOUND!\n\n";
			cout<<"NAME: \n"<< inventoryshop[i].getName();
			cout<<"PRICE: RM \n"<< inventoryshop[i].getPrice();
			cout<<"QUANTITY: \n"<< inventoryshop[i].getQuantity();

			print = true;
		}
	}
	if(print){

		system("PAUSE");
		main();
	}

	else{
		cout<<"\n===========PRODUCT DETAIL ARE NOT FOUND!===========\n\n";
		system("PAUSE");
		main();		
	}
}

//view all products 
void viewList(int counter){
	
	cout<<"===========VIEW ALL PRODUCT===========\n\n";
	
	for(int i=0;i<counter;i++)
	{
		cout<<"PRODUCT DETAILS\n\n";
		cout<<"\nNAME: "<<inventoryshop[i].getName();
		cout<<"\nPRICE: RM "<<inventoryshop[i].getPrice();
		cout<<"\nQUANTITY: "<<inventoryshop[i].getQuantity();
	}
     
    cout<< "\n\n";
	system("PAUSE");
	main();
}

// quit program
void quit(){
	
	cout<< "\t===========QUIT FROM THE COMPUTER INVENTORY SHOP===========\n";
	_exit(1);
}
