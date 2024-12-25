#include<iostream>
#include<string>
#include<vector>
using namespace std;
void menu(){

	cout<<"Enter the number beside the user to continue"<<endl;
	cout<<endl;
	cout<<"1. Passenger"<<endl;
	cout<<"2. Crew Member"<<endl;
	cout<<"3. Authorities"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"Enter your choice";
}
class passenger{
	public:
		void passenger_menu(){
			cout<<endl;
			cout<<"Passenger Menu- Enter the number specified below to carry out the respective function"<<endl;
			cout<<endl;
			cout<<"1. View flight details"<<endl;
			cout<<"2. Book a flight"<<endl;
			cout<<"3. Cancel a flight"<<endl;
			cout<<"4. Feedbacks"<<endl;
			cout<<"5. Exit"<<endl;
			cout<<"Enter your choice";
    }
};
class Flight {
	public:
		string airlineName;
		string departureAirport;
		string arrivalAirport;
	    string departureTime;
		string arrivalTime;
		string passengerName;
		
		Flight():
			airlineName("Unknown Airline"), 
			departureAirport("Unknown Departure"),
            arrivalAirport("Unknown Arrival"),
          	departureTime("00:00"),
          	arrivalTime("00:00"),
          	passengerName("No Passenger") {
    }

		Flight(string passengerName, string airlineName, string departureAirport,
            string arrivalAirport, string departureTime, string arrivalTime) {
			this->passengerName = passengerName;
			this->airlineName = airlineName;
			this->departureAirport = departureAirport;
			this->arrivalAirport = arrivalAirport;
			this->departureTime = departureTime;
			this->arrivalTime = arrivalTime;
        }
		void bookFlight() {
			cout << "Booking confirmed!" << endl;
			cout << "Passenger Name: " << this->passengerName << endl;
			cout << "Airline: " << this->airlineName << endl;
			cout << "Departure Airport: " << this->departureAirport << endl;
			cout << "Arrival Airport: " << this->arrivalAirport << endl;
			cout << "Departure Time: " << this->departureTime << endl;
			cout << "Arrival Time: " << this->arrivalTime << endl;
			cout << "------------------------------------" << endl;
		}
};
class cancel{
	public:
		int numBookings;
		string airlineName;
		string departureAirport;
		string arrivalAirport;
	    string departureTime;
		string arrivalTime;
		string passengerName;
		cancel() : 
				passengerName("No Passenger"),
                airlineName("Unknown Airline"),
                departureAirport("Unknown Departure"),
                arrivalAirport("Unknown Arrival"),
                departureTime("00:00"),
                arrivalTime("00:00") {}
		cancel(string passengerName, string airlineName, string departureAirport,string arrivalAirport, string departureTime, string arrivalTime):
			passengerName(passengerName), 
        	airlineName(airlineName), 
        	departureAirport(departureAirport), 
        	arrivalAirport(arrivalAirport), 
        	departureTime(departureTime), 
        	arrivalTime(arrivalTime) {}
		void cancelflight(){
			cout << "Cancellation confirmed!" << endl;
			cout << "Passenger Name: " << this->passengerName << endl;
			cout << "Airline: " << this->airlineName << endl;
			cout << "Departure Airport: " << this->departureAirport << endl;
			cout << "Arrival Airport: " << this->arrivalAirport << endl;
			cout << "Departure Time: " << this->departureTime << endl;
			cout << "Arrival Time: " << this->arrivalTime << endl;
			cout << "------------------------------------" << endl;
		}
};
class Feedback {
protected:
    string passengerName;
    string comments;

public:
    Feedback(string name, string comm) : passengerName(name), comments(comm) {}
    virtual void displayFeedback() {
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Comments: " << comments << endl;
    }
};
class PositiveFeedback : public Feedback {
public:
    PositiveFeedback(string name, string comm) : Feedback(name, comm) {}

    void displayFeedback() override {
        cout << "Positive Feedback" << endl;
        Feedback::displayFeedback();
    }
};
class NegativeFeedback : public Feedback {
public:
    NegativeFeedback(string name, string comm) : Feedback(name, comm) {}

    void displayFeedback() override {
        cout << "Negative Feedback" << endl;
        Feedback::displayFeedback();
    }
};
Feedback* inputFeedback() {
    string name, comments;
    char feedbackType;
    cout << "Enter the Name of Complainant: ";
    getline(cin, name);
    cout << "Enter comments: ";
    getline(cin, comments);
    cout << "Is the feedback positive (P) or negative (N)? ";
    cin >> feedbackType;
    cin.ignore(); 
    if (feedbackType == 'P' || feedbackType == 'p') {
        return new PositiveFeedback(name, comments);
    } else {
        return new NegativeFeedback(name, comments);
    }
}
class crew_member{
	public:
		void crew_member_menu(){
			cout<<endl;
			cout<<"Crew Member Menu- Enter the number specified below to carry out the respective function"<<endl;
			cout<<endl;
			cout<<"1. Enter Crew Member Information"<<endl;
			cout<<"2. Delete Crew Member Information"<<endl;
			cout<<"3. Feedbacks"<<endl;
			cout<<"4. Exit"<<endl;
			cout<<"Enter your choice: ";
		}
};
class crew_member_info: public crew_member{
	int C_ID;
	string C_Name;
	string C_Position;
	string Hire_Date;
	public:
		crew_member_info():C_ID(0),C_Name("No Name"),C_Position("No Name"),Hire_Date("No entered"){}
		crew_member_info(int id,string name,string position,string hire):C_ID(id),C_Name(name),C_Position(position),Hire_Date(hire){}
		crew_member_info(const crew_member_info &other):C_ID(other.C_ID),C_Name(other.C_Name),C_Position(other.C_Position),Hire_Date(other.Hire_Date){}
		
		void printinfo(){
			cout<<"Crew Member ID: "<<C_ID<<endl;
			cout<<"Crew Member Name: "<<C_Name<<endl;
			cout<<"Crew Member Position: "<<C_Position<<endl;
			cout<<"Crew Member hired on: "<<Hire_Date<<endl;
		}
		friend void crew_memberinfo(const crew_member &c);
};
void crew_memberinfo(crew_member_info &c){
	c.printinfo();
}
class delete_crew_member{
	public:
		int d_crew_no;
		int C_ID;
		string C_Name;
		string C_Position;
		string Hire_Date;
		delete_crew_member() : 
				C_ID(0),
                C_Name("Unknown Name"),
                C_Position("Unknown Position"),
                Hire_Date("Unknown Hire Date"){}
		delete_crew_member(int C_ID, string C_Name, string C_Position, string Hire_Date):
			C_ID(C_ID), 
        	C_Name(C_Name), 
        	C_Position(C_Position), 
        	Hire_Date(Hire_Date){}
		void delete_crew(){
			cout<<endl;
			cout << "Deletion confirmed!" << endl;
			cout << "Passenger Name: " << this->C_ID << endl;
			cout << "Airline: " << this->C_Name << endl;
			cout << "Departure Airport: " << this->C_Position << endl;
			cout << "Arrival Airport: " << this->Hire_Date << endl;
			cout << "------------------------------------" << endl;
		}
};
class authorities{
	public:
		void authorities_menu(){
			cout<<endl;
			cout<<"Authorities Menu- Enter the number specified below to carry out the respective function"<<endl;
			cout<<endl;
			cout<<"1. Enter Authorities Information"<<endl;
			cout<<"2. Delete Authorities Information"<<endl;
			cout<<"3. Feedbacks"<<endl;
			cout<<"4. Exit"<<endl;
			cout<<"Enter your choice: ";
		}
};
class authorities_info: public authorities{
	int a_no;
	int a_id;
	string a_name;
	string a_position;
	string a_department;
	string a_hire_date;
	public:
		authorities_info():
			a_id(0),
			a_name("Unknown Name"),
			a_position("Unknown Position"),
			a_department("Unknown Department"),
			a_hire_date("Unknown Hire Date"){}
		authorities_info(int a_id, string a_name, string a_position, string a_department, string a_hire_date):a_id(a_id),a_name(a_name),a_position(a_position),a_department(a_department),a_hire_date(a_hire_date){}
		void display_authorities() const{
			cout<<"Authority ID: "<<a_id<<endl;
			cout<<"Name of the Authority: "<<a_name<<endl;
			cout<<"Position of the Authority: "<<a_position<<endl;
			cout<<"Department of the Authority: "<<a_department<<endl;
			cout<<"Hire Date of the Authority: "<<a_hire_date<<endl;
		}	
		friend void a_info(const authorities_info& a);
};
void a_info(const authorities_info& a){
	a.display_authorities();
}
class delete_authorities{
	public:
		int a_id;
		string a_name;
		string a_position;
		string a_department;
		string a_hire_date;
		delete_authorities() : 
				a_id(0),
                a_name("Unknown Name"),
                a_position("Unknown Position"),
                a_department("Unknown Department"),
            	a_hire_date("Unknown Hire Date"){}
		delete_authorities(int a_id, string a_name, string a_position, string a_department, string a_hire_date):
			a_id(a_id), 
        	a_name(a_name), 
        	a_position(a_position), 
        	a_department(a_department),
        	a_hire_date(a_hire_date){}
		void d_authorities(){
			cout<<endl;
			cout << "Deletion confirmed!" << endl;
			cout << "Authority ID: " << this->a_id << endl;
			cout << "Auhtority Name: " << this->a_name <<endl;
			cout << "Position of the Authority: " << this->a_position << endl;
			cout <<"Department of the Authority: "<<this->a_department<<endl;
			cout << "Hire Date of the Authority: " << this->a_hire_date << endl;
			cout << "------------------------------------" << endl;
		}
};
int main(){
	cout<<"                            HORIZON WINGS"<<endl;
	cout<<"                        LET'S FLY AWAY IN STYLE"<<endl;
	cout<<"________________________________________________________________________"<<endl;
	cout<<endl;
	int choice;
	int p_choice;
	vector<Flight> bookings;
	do{
		menu();
		cin>>choice;
		switch(choice){
		case 1:{
			passenger p;
			do{
				p.passenger_menu();
				cin>>p_choice;
				switch(p_choice){
					case 1:{
						cout<<"__________________________________________________________________________________"<<endl;
						cout<<"|S.No.|   Airline Name    | Departure |    Arrival   |Departure Time|Arrival Time|"<<endl;
						cout<<"|    1|    Air India      | Bengaluru | Visakhapatnam|    10:00     |   12:00    |"<<endl;
						cout<<"|    2|     Indigo        |  Mumbai   |     Delhi    |    14:30     |   16:00    |"<<endl;
						cout<<"|    3|     Indigo        |  Patna    | Bhuvaneshwar |    16:30     |   20:15    |"<<endl;
						cout<<"|    4|    Spice Jet      | Hyderabad |   Chennai    |    05:30     |   03:00    |"<<endl;
						cout<<"|    5|     Vistara       |    Pune   |      Goa     |    14:30     |   15:30    |"<<endl;
						cout<<"|    6|      GoAir        | Ahemdabad |     Jaipur   |    16:00     |   17:30    |"<<endl;
						cout<<"|    7|     IndiGo        |   Delhi   |    Chennai   |    08:30     |   10:30    |"<<endl;
						cout<<"|    8|    Air India      |   Mumbai  |    Kolkata   |    15:15     |   17:15    |"<<endl; 
						cout<<"|    9|  Emirates         |   Dubai   |   New York   |    02:00     |   08:00    |"<<endl;
						cout<<"|   10|  Qatar Airways    |   Doha    |    London    |    23:55     |   05:30    |"<<endl;
						cout<<"|   11|  Cathay Pacific   | Hong Kong |    Mumbai    |    07:00     |   11:30    |"<<endl;
						cout<<"|   12| British Airways   |   London  |    Delhi     |    03:50     |   12:30    |"<<endl;
						cout<<"|   13|Singapore Airlines |  Singapore|    Delhi     |    10:45     |   12:15    |"<<endl;          
            			cout<<"|   14|Turkish Airlines   |   Istanbul|    Mumbai    |    17:30     |   06:45    |"<<endl;        
            			cout<<"|   15|American Airlines  |  New York |   Bengaluru  |    21:00     |   23:00    |"<<endl;
            			cout<<"|_____|___________________|___________|______________|______________|____________|"<<endl;
						break;
					}
					p.passenger_menu();
					cin>>p_choice;
					case 2:{
						int numBookings;
						string airlineName;
			    		string departureAirport;
			    		string arrivalAirport;
		        		string departureTime;
			    		string arrivalTime;
			    		string passengerName;
			    		cout << "\t\tWelcome to Booking Services\n";
						cout << "\t\t---------------------------\n";
						cout << "Enter the number of bookings: ";
						cin >> numBookings;
						cin.ignore();
						for (int i = 0; i < numBookings; ++i) {
							cout << "Booking #" << (i + 1) << endl;
							cout << "Enter passenger name: ";
							getline(cin,passengerName);
							cout << "Enter airline name: ";
							getline(cin,airlineName);
							cout << "Enter departure airport: ";
							getline(cin,departureAirport);
							cout << "Enter arrival airport: ";
							getline(cin,arrivalAirport);
							cout << "Enter departure time: ";
							getline(cin,departureTime);
							cout << "Enter arrival time: ";
							getline(cin,arrivalTime);
							Flight flight(passengerName,airlineName,departureAirport,arrivalAirport,departureTime,arrivalTime);
							bookings.push_back(flight);
							cout << endl; 
	            		}
	            		cout<<"Passenger Information"<<endl;
	            		for(int i=0;i<bookings.size();i++){
	            			bookings[i].bookFlight();
						}
						break;			
	        		}
	        		p.passenger_menu();
	        		cin>>p_choice;
	        		case 3:{
	        			int cancelBookings;
						string airlineName;
			    		string departureAirport;
			    		string arrivalAirport;
		        		string departureTime;
			    		string arrivalTime;
			    		string passengerName;
						cout<<"Enter number of flights to cancel: ";
						cin>>cancelBookings;
						cin.ignore();
						cancel ca[cancelBookings];
						for(int i=0;i<cancelBookings;++i){
							cout << "Canceling #" << (i + 1) << endl;
							cout << "Enter passenger name: ";
							getline(cin,passengerName);
							cout << "Enter airline name: ";
							getline(cin,airlineName);
							cout << "Enter departure airport: ";
							getline(cin,departureAirport);
							cout << "Enter arrival airport: ";
							getline(cin,arrivalAirport);
							cout << "Enter departure time: ";
							getline(cin,departureTime);
							cout << "Enter arrival time: ";
							getline(cin,arrivalTime);
							cout<<endl;
							ca[i] = cancel(passengerName,airlineName,departureAirport,arrivalAirport,departureTime,arrivalTime);
	    				}
	    				cout<<"Cancellation information \n";
	    				for(int i=0;i<cancelBookings;++i){
	    					ca[i].cancelflight();
						}
						break;
					}
					p.passenger_menu();
	        		cin>>p_choice;
					case 4:{
						int numFeedbacks;
	    				cout << "Enter the number of feedbacks: ";
	    				cin >> numFeedbacks;
	    				cin.ignore();
						Feedback* feedbacks[numFeedbacks];
						for (int i = 0; i < numFeedbacks; i++) {
	        				cout << "\nInput feedback " << (i + 1) << ":\n";
	        				feedbacks[i] = inputFeedback();
	    				}
						cout << "\nDisplaying Feedbacks:\n";
	    				for (int i = 0; i < numFeedbacks; i++) {
	        				feedbacks[i]->displayFeedback();
	        				cout << endl;
	        				delete feedbacks[i];
	    				}
						break;
					}
					p.passenger_menu();
	        		cin>>p_choice;
					case 5:{
						break;
					}
					default:{
						cout<<"Invalid choice, please try again."<<endl;
						break;
					}
	        		}
	        	}while(p_choice!=5);	
	   	}
		case 2:{
			int c_choice;
			crew_member_info c;
			do{
				c.crew_member_menu();
				cin>>c_choice;
				cout<<endl;
				switch(c_choice){
					case 1:{
						int crew_no;
						cout<<"Enter the number of crew_members:";
						cin>>crew_no;
						cin.ignore();
						crew_member_info c[crew_no];
						int C_ID;
						string C_Name;
						string C_Position;
						string Hire_Date;
						for(int i=0;i<crew_no;++i){
							cout<<"Enter the Crew Member ID: ";
							cin>>C_ID;
							cin.ignore();
							cout<<"Enter the Crew Member Name: ";
							getline(cin,C_Name);
							cout<<"Enter the Crew Member Position: ";
							getline(cin,C_Position);
							cout<<"Enter the Crew Member Hire Date: ";
							getline(cin,Hire_Date);
							cout<<"Information entered"<<endl;
							cout<<endl;
							c[i]=crew_member_info(C_ID,C_Name,C_Position,Hire_Date);
	    				}
	    				cout<<"Crew member information:\n";
	    				for(int i=0;i<crew_no;++i){
	    					crew_memberinfo(c[i]);
	    					cout<<"_______________________________________________"<<endl;
						}
						break;
					}
					case 2:{
						int d_crew_no;
						int C_ID;
						string C_Name;
						string C_Position;
						string Hire_Date;
						cout<<"Enter number of crew members to delete the information: ";
						cin>>d_crew_no;
						cin.ignore();
						delete_crew_member dc[d_crew_no];
						for(int i=0;i<d_crew_no;++i){
							cout << "Deleting Information #" << (i + 1) << endl;
							cout << "Enter Crew Member ID: ";
							cin>>C_ID;
							cin.ignore();
							cout << "Enter Crew Member Name: ";
							getline(cin,C_Name);
							cout << "Enter Crew Member Position: ";
							getline(cin,C_Position);
							cout << "Enter Crew Member Hire Date: ";
							getline(cin,Hire_Date);
							dc[i] = delete_crew_member(C_ID,C_Name,C_Position,Hire_Date);
							cout<<endl;
	    				}
	    				cout<<"Deleted Crew Member Information \n";
	    				for(int i=0;i<d_crew_no;++i){
	    					dc[i].delete_crew();
						}
						break;
					}
					
					case 3:{
						int numFeedbacks;
	    				cout << "Enter the number of feedbacks: ";
	    				cin >> numFeedbacks;
	    				cin.ignore();
						Feedback* feedbacks[numFeedbacks];
						for (int i = 0; i < numFeedbacks; i++) {
	        				cout << "\nInput feedback " << (i + 1) << ":\n";
	        				feedbacks[i] = inputFeedback();
	    				}
						cout << "\nDisplaying Feedbacks:\n";
	    				for (int i = 0; i < numFeedbacks; i++) {
	        				feedbacks[i]->displayFeedback();
	        				cout << endl;
	        				delete feedbacks[i];
	    				}
						break;
					}
				
					case 4:{
						break;
					}
					default:{
						cout<<"Invalid Choice please try again."<<endl;
						break;
					}
				}
			}while(c_choice!=4);		
		break;
		}
		case 3:{
			int a_choice;
			authorities_info a;
			do{
				a.authorities_menu();
				cin>>a_choice;
				cout<<endl;
				switch(a_choice){
					case 1:{
						int a_no;
						cout<<"Enter the number of authorities: ";
						cin>>a_no;
						cin.ignore();
						authorities_info a[a_no];
						int a_id;
						string a_name;
						string a_position;
						string a_department;
						string a_hire_date;
						for(int i=0;i<a_no;++i){
							cout<<"Enter the Authority ID: ";
							cin>>a_id;
							cin.ignore();
							cout<<"Enter the Authority Name: ";
							getline(cin,a_name);
							cout<<"Enter the Authority Position: ";
							getline(cin,a_position);
							cout<<"Enter the Authority Department: ";
							getline(cin,a_department);
							cout<<"Enter the Authority Hire Date: ";
							getline(cin,a_hire_date);
							cout<<"Information entered"<<endl;
							cout<<endl;
							a[i]=authorities_info(a_id,a_name,a_position,a_department,a_hire_date);
	    				}
	    				cout<<"Authoritirs information:\n";
	    				for(int i=0;i<a_no;++i){
	    					a_info(a[i]);
	    					cout<<"_________________________________________________"<<endl;
						}
						break;
					}
					a.authorities_menu();
					cin>>a_choice;
					case 2:{
						int a_no;
						int a_id;
						string a_name;
						string a_position;
						string a_department;
						string a_hire_date;
						cout<<"Enter the number of authorities to delete the information: ";
						cin>>a_no;
						cin.ignore();
						delete_authorities da[a_no];
						for(int i=0;i<a_no;++i){
							cout << "Deleting Information #" << (i + 1) << endl;
							cout << "Enter Authority ID: ";
							cin>>a_id;
							cin.ignore();
							cout << "Enter Authority Name: ";
							getline(cin,a_name);
							cout << "Enter Auhtority Position: ";
							getline(cin,a_position);
							cout << "Enter Authority Department: ";
							getline(cin,a_department);
							cout << "Enter Authority Hire Date: ";
							getline(cin,a_hire_date);
							cout<<endl;
							da[i] = delete_authorities(a_id,a_name,a_position,a_department,a_hire_date);
	    				}
	    				cout<<"Deleted Authority Information \n";
	    				for(int i=0;i<a_no;++i){
	    					da[i].d_authorities();
						}
						break;
					}	 
					case 3:{
						int numFeedbacks;
	    				cout << "Enter the number of feedbacks: ";
	    				cin >> numFeedbacks;
	    				cin.ignore();
						Feedback* feedbacks[numFeedbacks];
						for (int i = 0; i < numFeedbacks; i++) {
	        				cout << "\nInput feedback " << (i + 1) << ":\n";
	        				feedbacks[i] = inputFeedback();
	    				}
						cout << "\nDisplaying Feedbacks:\n";
	    				for (int i = 0; i < numFeedbacks; i++) {
	        				feedbacks[i]->displayFeedback();
	        				cout << endl;
	        				delete feedbacks[i];
	    				}
						break;
					}
					a.authorities_menu();
					cin>>a_choice;
					case 4:{
						break;
					}
					default:{
						cout<<"Invalid choice, please try again."<<endl;
						break;
					}
				}
			}while(a_choice!=4);
			break;
		}
		case 4:{
			break;
		}
		}
	}while(choice!=4);
}
