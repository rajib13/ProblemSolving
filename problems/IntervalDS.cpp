#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> ranges;

class IntervalDS{
public:
    
    IntervalDS(){
        ranges.clear();
    }

    void Add(int start, int end){
        if(ranges.size() == 0){
            ranges.push_back({start, end});
        }
        else{
            if(end < ranges[0][0]){
                ranges.push_back({start, end});
            }
            else if(start > ranges[ranges.size() - 1][1]){
                ranges.push_back({start, end});
            }
            else{
                for(int i = 0; i < ranges.size(); i++){
                    if(ranges[i][1] >= start){
                        if(ranges[i][0] <= end){
                            ranges[i][0] = min(ranges[i][0], start);
                            ranges[i][1] = max(ranges[i][1], end);
                        }
                    }
                    if(i < ranges.size() - 1){
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
                ranges.erase(ranges.begin() + (i));
                rangeSize--;
            }

            if(ranges[i][0] < start){
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
            if(ranges[i][0] < end && ranges[i][1] > start){
                res.push_back({ranges[i][0], ranges[i][1]});
            }
        }
        return res;
    }

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