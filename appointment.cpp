#include <iostream>
using namespace std;

struct Appointment {
    int start, end;
    Appointment* next;
};

class Schedule {
    Appointment* head;

public:
    Schedule() { head = nullptr; }

    void displaySlots() {
        if (!head) {
            cout << "All slots are free.\n";
            return;
        }
        Appointment* temp = head;
        cout << "Booked slots:\n";
        while (temp) {
            cout << temp->start << " - " << temp->end << endl;
            temp = temp->next;
        }
    }

    void bookAppointment(int start, int end) {
        Appointment* newAppt = new Appointment{start, end, nullptr};
        if (!head || start < head->start) {
            newAppt->next = head;
            head = newAppt;
            cout << "Appointment booked.\n";
            return;
        }
        
        Appointment* temp = head;
        while (temp->next && temp->next->start < start)
            temp = temp->next;
        
        newAppt->next = temp->next;
        temp->next = newAppt;
        cout << "Appointment booked.\n";
    }

    void cancelAppointment(int start) {
        if (!head) {
            cout << "No appointments booked.\n";
            return;
        }
        if (head->start == start) {
            Appointment* temp = head;
            head = head->next;
            delete temp;
            cout << "Appointment canceled.\n";
            return;
        }

        Appointment* temp = head;
        while (temp->next && temp->next->start != start)
            temp = temp->next;
        
        if (!temp->next) {
            cout << "Appointment not found.\n";
            return;
        }

        Appointment* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << "Appointment canceled.\n";
    }

    void sortAppointments() {
        if (!head || !head->next) return;
        for (Appointment* i = head; i->next; i = i->next)
            for (Appointment* j = head; j->next; j = j->next)
                if (j->start > j->next->start)
                    swap(j->start, j->next->start), swap(j->end, j->next->end);
    }

    void sortUsingPointerManipulation() {
        if (!head || !head->next) return;
        Appointment *sorted = nullptr, *current = head;
        
        while (current) {
            Appointment* next = current->next;
            if (!sorted || sorted->start > current->start) {
                current->next = sorted;
                sorted = current;
            } else {
                Appointment* temp = sorted;
                while (temp->next && temp->next->start < current->start)
                    temp = temp->next;
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }
};

int main() {
    Schedule s;
    int choice, start, end;
    
    do {
        cout << "\n1. Display free slots\n2. Book appointment\n3. Cancel appointment\n4. Sort list by time\n5. Sort using pointer manipulation\n0. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: s.displaySlots(); break;
            case 2: cout << "Enter start and end time: "; cin >> start >> end; s.bookAppointment(start, end); break;
            case 3: cout << "Enter start time to cancel: "; cin >> start; s.cancelAppointment(start); break;
            case 4: s.sortAppointments(); cout << "Appointments sorted.\n"; break;
            case 5: s.sortUsingPointerManipulation(); cout << "Appointments sorted using pointer manipulation.\n"; break;
        }
    } while (choice != 0);

    return 0;
}
