#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CSlice {
public:
    vector<int> line;
    int start=0, stop=0, step=0, size = 0,j=0,l=0;
    CSlice(int size_vector){
        line.reserve(size_vector);
    }  //тут какие то вообще проблемс с импользованием векторов как членов класса, изучала я это сто лет и решила так сделать 
    void CSize(string slice)
    {
        for (int i = 0; i < slice.length(); i++)
        {
            size +=(slice[i] == ':');
        }
        if (size>2){
            cout<<"Error"<<endl;
            exit(1);}
    }
    void Input(string slice) {
        int counter = 0;
        string start_str, step_str, stop_str;
        CSize(slice);
        if (size == 0) {
            for (int i = 0; i < slice.length(); i++) {
                if (slice[i] != ':' && counter != 1) {
                    stop_str.push_back(slice[i]);
                }
            }
            if (stop_str.length())
                stop = stoi(stop_str);
            else
                stop = line.size();
            if (stop < 0)
                stop = line.size() + stop;
            step = 1;
            start = 0;
        }
        if (size == 1) {
            for (int i = 0; i < slice.length(); i++) {
                if (slice[i] != ':' && counter != 1) {
                    start_str.push_back(slice[i]);
                }
                if (slice[i] == ':')
                    counter++;
                if (slice[i] != ':' && counter == 1) {
                    stop_str.push_back(slice[i]);
                }
            }
            if (start_str.length())
                start = stoi(start_str);
            else start = 0;
            if (start < 0)
                start = line.size() + start;
            if (stop_str.length())
                stop = stoi(stop_str);
            else
                stop = line.size();
            if (stop < 0)
                stop = line.size() + stop;
                step=1;
        }
        if (size == 2) {
            for (int i = 0; i < slice.length(); i++) {
                if (slice[i] != ':' && counter == 0) {
                    start_str.push_back(slice[i]);
                }
                if (slice[i] == ':')
                    counter++;
                if (slice[i] != ':' && counter == 1) {
                    stop_str.push_back(slice[i]);
                }
                if (slice[i] != ':' && counter == 2) {
                    step_str.push_back(slice[i]);
                }
            }
            if (!(start_str.length() && stop_str.length())) j++;
            if (start_str.length())
                start = stoi(start_str);
            else start = 0;
            if (start < 0)
                start = line.size() + start;
            if (stop_str.length())
                stop = stoi(stop_str);
            else {stop=line.size(); l++;}
            if (stop < 0)
                stop = line.size() + stop;
            if (step_str.length())
                step = stoi(step_str);
                else step =1;
          
        }
    }
    CSlice Slice(string slice) { //мб здесь сделать все таки CSlice? ок пока так
        Input(slice);
        CSlice final_line(0);
        if (size == 0)
        {
            (final_line.line).emplace_back(line[stop]);
        return final_line;
        }
        if (step > 0){
        for (int i = start; i < stop; i += step) {
            (final_line.line).emplace_back(line[i]);
        }
        }
           if (step < 0){
               if (j)
                   {reverse(line.begin(), line.end());
                   for (int i = start; i < stop; i += abs(step)) {
            (final_line.line).emplace_back(line[i]);
                       
                   }
               }
           if (l && !j) {
           for (int i = start; i >-1; i +=step) {
            (final_line.line).emplace_back(line[i-1]);
        }reverse(final_line.line.begin(), final_line.line.end());
           }
           if (!l && !j){
           for (int i = stop+1; i<start+1; i +=abs(step)) {
            (final_line.line).emplace_back(line[i]);
           }
            reverse(final_line.line.begin(), final_line.line.end());
           }
           }
            return final_line;
            

    }
    void Print()
    {
        cout<<"[";
        for (int i = 0; i < line.size(); i++){
            cout << line[i];
            if(i<line.size()-1)
            cout <<",";
            
        }
        cout <<"]"<< endl;

    }
     ~CSlice() {}
};
int main() {
    CSlice hate(6),final(1);
    hate.line={0,1,2,3,4,5,6,7,8,9};
    hate.Print();
    final=hate.Slice("::-1"); //ну питон и такое себе 
    final.Print();
}
