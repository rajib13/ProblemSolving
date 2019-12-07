/*
    Assignment of Kepler Communications.
    Rajib Das
    rajib.das@uleth.ca
    437 982 4104

    PS: For detailed comments, please see the documentation.
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// As a data structure we are going to use a 2D vector.
vector<vector<int>> ranges;

// Interval data structure.
class IntervalDS{
public:
    
    IntervalDS(){
        ranges.clear();
    }

    void Add(int start, int end){
        if(ranges.size() == 0){
            // Empty data structure
            ranges.push_back({start, end});
        }
        else{
            /* Two boundary cases, e.g., original state [(5, 10)], Add (0, 5) (resp. Add(15, 20))
                which is left side or below (resp. right side or above) of the [(5, 10)]. So we 
                do not need to check the whole list. 
            */
            if(end < ranges[0][0] || start > ranges[ranges.size() - 1][1]){
                ranges.push_back({start, end});
            }
            else{
                for(int i = 0; i < ranges.size(); i++){
                    // General case
                    if(ranges[i][1] >= start && ranges[i][0] <= end){
                            ranges[i][0] = min(ranges[i][0], start);
                            ranges[i][1] = max(ranges[i][1], end);
                        }
                        
                    if(i < ranges.size() - 1){
                        // If two adjacent ranges can be merged.
                        if(ranges[i][1] >= ranges[i+1][0]){
                            ranges[i][1] = max(ranges[i][1], ranges[i+1][1]);
                            ranges.erase(ranges.begin() + (i+1));
                        }
                    }
                }
            }
        } 
    }

    void Delete(int start, int end){
        
        int rangeSize = ranges.size();
        for(int i = 0; i < rangeSize; i++){

            if(ranges[i][0] >= start && ranges[i][1] <= end){
                // If there is a full overlap, delete the range from the list.
                ranges.erase(ranges.begin() + (i));
                rangeSize--;
            }

            if(ranges[i][0] < start){
                // Update the list if there is small overlap.
                if(ranges[i][1] > end){
                    ranges.push_back({end, ranges[i][1]});
                }
                ranges[i][1] = min(ranges[i][1], start);
            }

            if(end  < ranges[i][1]){
                ranges[i][0] = max(ranges[i][0], end);
            }
        }

    }

    vector<vector<int>> Get(int start, int end){

        vector<vector<int>> res;
        for(int i = 0; i < ranges.size(); i++){
            // Find the overlapping element with the Get(a, b) and store them into a 2D list. 
            if(ranges[i][0] < end && ranges[i][1] > start){
                res.push_back({ranges[i][0], ranges[i][1]});
            }
        }
        return res;
    }
    /* The state of the data structure befor and after calling either of the Add, Delete,
    and Get functions. Here, we use built in sort function and that helps us to check the 
    given range with the list elements that are already present.  
    */
    void stateOfRanges(){
        
        cout << "State of the Data Structure : " << endl;
        if(ranges.size() == 0) 
            cout<< "Empty!" << endl;
        sort(ranges.begin(), ranges.end());
        cout<<"[";
        for(int i = 0; i < ranges.size(); i++){
            cout << "(" << ranges[i][0] << ", " << ranges[i][1] << ")";
            if(i != ranges.size() - 1)
                cout << ", ";
        }
        cout<<"]"<<endl;

    }
};

/*Driver function to initiate the program.*/
int main(){
    IntervalDS* obj = new IntervalDS();
    int choice;
    cout << "Choices "<< endl << "------------------------------" << endl;
    cout<< "Add \t \t 1" << endl << "Delete \t \t 2" << endl << "Get \t \t 3"<< 
    endl << "Exit \t \t 0" << endl;
    while(1){
        cout << endl << "Enter your choice: ";
        cin >> choice;
        
        if(choice == 0){
            break;
        }
        cout << "Enter a range (start end): " << endl;
        int start, end;
        cin >> start >> end;

        // If start is greater than end we swap them to make it right.
        if(start > end){
            start ^= end;
            end ^= start;
            start ^= end;
        }

        if(choice == 1){
            obj->stateOfRanges();

            obj->Add(start, end);

            obj->stateOfRanges();
        }
        else if (choice == 2){
            obj->stateOfRanges();
            
            obj->Delete(start, end);

            obj->stateOfRanges();
        }
        else if (choice == 3){
            obj->stateOfRanges();

            vector<vector<int>> intersect(obj->Get(start, end));
            cout << endl << "Intersected range(s) :" << endl << "["; 
            for(int i = 0; i < intersect.size(); i++){
                cout << "(" << intersect[i][0] << ", " << intersect[i][1] << ")";
            }
            cout << "]" << endl;
        }
    }
    return 0;
}