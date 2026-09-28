#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Configuration Constants
const int DAYS = 6;
const int PERIODS = 6; // Adjust the number of periods per day here

// Global structures to hold sizes
int num_teachers;
int num_sections;

// Structures for readability
struct Assignment {
    int teacher_id;
};

// Workload matrix: workload[section][teacher] = number of periods required
vector<vector<int>> workload;

// 3D Timetable Grid: [day][period][section] -> stores assigned teacher ID (-1 if empty)
vector<vector<vector<int>>> timetable;

// Availability tracking arrays to prevent clashes instantly
vector<vector<vector<bool>>> teacher_busy; // [day][period][teacher]
vector<vector<vector<bool>>> section_busy; // [day][period][section]

// Backtracking function to find the schedule
bool solveTimetable(int day, int period, int section) {
    // Base Case 1: If we have filled all sections for this period, move to next period
    if (section == num_sections) {
        return solveTimetable(day, period + 1, 0);
    }

    // Base Case 2: If we have filled all periods for this day, move to next day
    if (period == PERIODS) {
        return solveTimetable(day + 1, 0, 0);
    }

    // Base Case 3: If all 6 days are successfully scheduled, we are done!
    if (day == DAYS) {
        return true;
    }

    // Check if this section even needs any more classes overall.
    // If it's already full or we want to try leaving a slot empty, we can check.
    // However, to satisfy total workload, we try assigning available teachers:
    
    bool needs_teacher = false;
    for (int t = 0; t < num_teachers; ++t) {
        if (workload[section][t] > 0) {
            needs_teacher = true;
            
            // Check Hard Constraints: Is the teacher free? Is the section free?
            if (!teacher_busy[day][period][t] && !section_busy[day][period][section]) {
                
                // 1. Make Assignment
                timetable[day][period][section] = t;
                workload[section][t]--;
                teacher_busy[day][period][t] = true;
                section_busy[day][period][section] = true;

                // 2. Recurse to the next section slot
                if (solveTimetable(day, period, section + 1)) {
                    return true; 
                }

                // 3. Backtrack (Undo assignment if it led to a dead end)
                timetable[day][period][section] = -1;
                workload[section][t]++;
                teacher_busy[day][period][t] = false;
                section_busy[day][period][section] = false;
            }
        }
    }

    // If this section doesn't require any more teachers at all, leave it empty and move on
    if (!needs_teacher) {
        timetable[day][period][section] = -1; // Free period for this section
        if (solveTimetable(day, period, section + 1)) {
            return true;
        }
    }

    return false; // Trigger backtracking
}

int main() {
    // 1. Input configuration
    cout << "Enter number of Teachers (n): ";
    cin >> num_teachers;
    cout << "Enter number of Sections (m): ";
    cin >> num_sections;

    // Initialize tracking dimensions
    workload.resize(num_sections, vector<int>(num_teachers));
    timetable.resize(DAYS, vector<vector<int>>(PERIODS, vector<int>(num_sections, -1)));
    teacher_busy.resize(DAYS, vector<vector<bool>>(PERIODS, vector<bool>(num_teachers, false)));
    section_busy.resize(DAYS, vector<vector<bool>>(PERIODS, vector<bool>(num_sections, false)));

    // 2. Input Workload Requirements
    cout << "\nEnter the workload matrix (Rows = Sections, Columns = Teachers):\n";
    cout << "Enter how many periods each teacher owes to each section over the 6 days:\n";
    for (int s = 0; s < num_sections; ++s) {
        for (int t = 0; t < num_teachers; ++t) {
            cout << "Section " << s << ", Teacher " << t << " periods: ";
            cin >> workload[s][t];
        }
    }

    // 3. Execute Solver
    cout << "\nGenerating clash-free timetable...\n";
    if (solveTimetable(0, 0, 0)) {
        cout << "\nSuccess! Timetable created successfully.\n";

        // 4. Print Results Grouped by Section
        string day_names[6] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        for (int s = 0; s < num_sections; ++s) {
            cout << "\n=========================================\n";
            cout << "          TIMETABLE FOR SECTION " << s << "\n";
            cout << "=========================================\n";
            
            // Print Period Header
            cout << "Day\t\t| ";
            for(int p = 0; p < PERIODS; ++p) cout << "P" << p+1 << "\t";
            cout << "\n-----------------------------------------\n";

            for (int d = 0; d < DAYS; ++d) {
                cout << day_names[d] << "\t| ";
                if(day_names[d].length() < 8) cout << "\t"; // Align formatting
                
                for (int p = 0; p < PERIODS; ++p) {
                    int t = timetable[d][p][s];
                    if (t == -1) {
                        cout << "FREE\t";
                    } else {
                        cout << "T" << t << "\t";
                    }
                }
                cout << "\n";
            }
        }
    } else {
        cout << "\nError: Could not generate a valid timetable. Constraints are structurally impossible.\n";
        cout << "Suggestions: Reduce total workload hours, add more periods per day, or increase teachers.\n";
    }

    return 0;
}
