#include <iostream>
using namespace std;

// Event Ticketing System
int events[5][4] = {{101, 100, 100, 50},    // first column is the event id
                   {102, 150, 120, 75},     // second column is total seats
                   {103, 200, 0, 100},		//third column available seats
                   {104, 80, 35, 120},		// fourth column is ticket price
                   {105, 300, 0, 200}};
void display_menu() {
    cout << "1. Display all available events\n";
    cout << "2. Display sold seats and profit for an event\n";
    cout << "3. Check availability of an event\n";
    cout << "4. Display detailed information on all events\n";
    cout << "5. Display all sold-out events\n";
    cout << "6. Exit\n";
}
void display_available_events() {
    cout << "Available Events:\n";
    for (int i = 0; i < 5; i++) {
        if (events[i][2] > 0) { //  available seats should be > 0
            cout << "Event ID: \n" << events[i][0] 
                 << ", Available Seats: \n" << events[i][2]
                 << ", Ticket Price: \n" << events[i][3] << "\n";
        }
    }
}
void display_sold_seats_and_profit() {
    int event_id;
    cout << "Enter Event ID: ";
    cin >> event_id;
    
    for (int i = 0; i < 5; i++) {
        if (events[i][0] == event_id) {
            int sold_seats = events[i][1] - events[i][2];      // Total - Available = Sold
            int profit = sold_seats * events[i][3];           // Sold * Price = Profit
            
            cout << "Event ID: " << event_id << "\n";
            cout << "Total Seats: " << events[i][1] << "\n";
            cout << "Sold Seats: " << sold_seats << "\n";
            cout << "Profit: $" << profit << "\n";
            return;
        }
    }
    cout << "Event not found.\n";
}
void check_event_availability() {
    int event_id;
    cout << "Enter Event ID: ";
    cin >> event_id;
    
    for (int i = 0; i < 5; i++) {
        if (events[i][0] == event_id) {
            if (events[i][2] > 0) {
                cout << "Event ID: " << event_id << " is available with " 
                     << events[i][2] << " seats remaining.\n";
            } else {
                cout << "Event ID: " << event_id << " is sold out.\n";
            }
            return;
        }
    }
    cout << "Event not found.\n";
}
void display_all_events_info() {
    cout << "Detailed Information for All Events:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Event ID: " << events[i][0] << "\n";
        cout << "Total Seats: " << events[i][1] << "\n";
        cout << "Available Seats: " << events[i][2] << "\n";
        cout << "Ticket Price: $" << events[i][3] << "\n";
        cout << "------------------------\n";
    }
}
void display_sold_out_events() {
    cout << "Sold-Out Events:\n";
    bool found_sold_out = false;
    
    for (int i = 0; i < 5; i++) {
        if (events[i][2] == 0) { // If available seats = 0
            cout << "Event ID: " << events[i][0] 
                 << ", Total Seats: " << events[i][1]
                 << ", Ticket Price: $" << events[i][3] << "\n";
            found_sold_out = true;
        }
    }
    if (!found_sold_out) {
        cout << "No sold-out events found.\n";
    }
}

void menu() {		
int choice = 0;  

	while (choice != 6) {
    	display_menu();
    		cout << "Enter your choice: ";
    	cin >> choice;
    		if (choice == 1) {
    			display_available_events();
   	} 		else if (choice == 2) {
        		display_sold_seats_and_profit();
    } 		else if (choice == 3) {
        		check_event_availability();
    } 		else if (choice == 4) {
        		display_all_events_info();
    } 		else if (choice == 5) {
        		display_sold_out_events();
    } 		else if (choice == 6) {
        		cout << "Exit\n";
    } 		else {
        		cout << "Invalid choice. Please try again.\n";
    }
}
}
int main() {
    menu();
    return 0;
}
