//Simple Bus reservation system

#include<iostream>
#include<string.h>

using namespace std;

static int a = 0;

class depot
{
	char busno[6],driver[15],arrival[5],depart[5],from[15],to[15],seat[8][4][15];	

	public:
		void install();
		void allot();
		void empty();
		void show();
		void available();
	        void position(int i);
};

depot bus[10];

void dot(char ch)
{
  cout<<endl;
  for (int i=80;i>0;i--)
  cout<<ch;
  cout<<endl;
}
//Entry of bus details
void depot::install()
{
	cout<<"Enter Bus Number : ";cin>>bus[a].busno;
	cout<<"\nEnter Driver Name : ";cin>>bus[a].driver;
	cout<<"\nFrom : ";cin>>bus[a].from;
	cout<<"\nTo : ";cin>>bus[a].to;
	cout<<"\nEnter Arrival Time : ";cin>>bus[a].arrival;
	cout<<"\nEnter Departure Time : ";cin>>bus[a].depart;
	bus[a].empty();
	a++;
}


//To show all seats are epmpty before allotment to a passenger
void depot::empty()
{
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<4; j++)
		{
			strcpy(bus[a].seat[i][j],"Empty");
		}
	}
}


//Shows all the seats in the bus
void depot::show()
{
	int n;
	char number[6];
	cout<<"Enter the Bus number : ";
	cin>>number;
	for(n = 0; n<=a; n++)
	{
		if(strcmp(bus[n].busno, number)==0)
		
			break;
		
	}
	
	while(n<=a)
	{
		dot('*');
		cout<<"Bus Number : "<<bus[n].busno;
		cout<<"\nDriver Name : "<<bus[n].driver;
		cout<<"\nFrom : "<<bus[n].from;
		cout<<"\nTo : "<<bus[n].to;
		cout<<"\nArrival Time : "<<bus[n].arrival;
		cout<<"\nDeparture Time : "<<bus[n].depart;
		dot('*');
		
		bus[0].position(n);
		int q = 1;
		for (int i=0; i<8; i++)
		{
			for(int j=0;j<4;j++)
			{
				q++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
				cout<<"\nThe seat no "<<(q-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
			}
		}
		break;
	}
	if(n>a)
	cout<<"Enter correct bus no ";
}


//positon of the seat
void depot::position(int l)
{
  int r=0,t=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
    	r++;
        if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
        	cout.width(5);
            cout.fill(' ');
            cout<<r<<".";
            cout.width(10);
            cout.fill(' ');
            cout<<bus[l].seat[i][j];
            t++;
        }
        else
        {
        	cout.width(5);
        	cout.fill(' ');
        	cout<<r<<".";
        	cout.width(10);
        	cout.fill(' ');
       	    cout<<bus[l].seat[i][j];
        }
      }
    }
    cout<<"\n\nThere are "<<t<<" seats empty in Bus No: "<<bus[l].busno;
}


//Shows all buses in the depot 
void depot::available()
{
	for(int n = 0; n<a;n++)
	{
		dot('*');
		cout<<"\nBus Number : "<<bus[n].busno;
		cout<<"\nDriver Name : "<<bus[n].driver;
		cout<<"\nFrom : "<<bus[n].from;
		cout<<"\nTo : "<<bus[n].to;
		cout<<"\nArrival Time : "<<bus[n].arrival;
		cout<<"\nDeparture Time : "<<bus[n].depart;
		dot('*');
	}
}

//Allotment of seats to passengers
void depot::allot()
{
	int seat;
    char number[5];
    top:
    cout<<"Bus no: ";
    cin>>number;
    int n;
    for(n=0;n<=a;n++)
    {
    	if(strcmp(bus[n].busno, number)==0)
    	break;
    }
    while(n<=a)
    {
    	cout<<"\nSeat Number: ";
    	cin>>seat;
    	if(seat>32)
    	{
        	cout<<"\nThere are only 32 seats available in this bus.";
    	}
    	else
    	{
    		if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
        	{
        		cout<<"Enter passanger's name: ";
        		cin>>bus[n].seat[seat/4][(seat%4)-1];
        		break;
        	} 
    	else
        cout<<"The seat no. is already reserved.\n";
        }
    }
    if(n>a)
    {
        cout<<"Enter correct bus no.\n";
        goto top;
    }
}


int main()
{
	int c;
	while(1)
	{
		dot('*');
		cout<<"\n Welcome to your bus depot";
		cout<<"\n1. Create new bus entry";
		cout<<"\n2. Reservations";
		cout<<"\n3. Show bus details";
		cout<<"\n4. Buses Available";
		cout<<"\n5. Exit";
		cout<<"\n ENTER YOUR CHOICE: \n";
		
		cin>>c;
		dot('*');
		
		switch(c)
		{
			case 1:
				bus[a].install();
				break;
			case 2:
				bus[a].allot();
				break;
			case 3:
				bus[a].show();
				break;
			case 4:
				bus[a].available();
				break;
			case 5:
				exit(0);
		}
	}
	
	return 0;
}
