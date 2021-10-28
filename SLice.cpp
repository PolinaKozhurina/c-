#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CSlice{
private:
    string slice;
    vector<int> line;
    int start, stop, step, size=0;
public:
    CSlice(vector<int> first_line): line(first_line){}
    void СSize()
    {
        for(int i=0;i<slice.size();i++)
        {
            size+=(slice[i]==':');
        }
    }
    int Check(string str){
        int i,k=0;
        for (i = 0; i < slice.size(); i++) {
            if (slice[i] != ' ') k++;
        }
        if (k==i)
            return 0;
        return 1;
    }
    void Input(string slice) {
        int counter = 0, c1 = 0, c2 = 0;
        string start_str, step_str, stop_str;
        Size();
        if (size == 0) {
            for (int i = 0; i < slice.size(); i++) {
                if (slice[i] != ':' && counter != 1) {
                    stop_str[c1] = slice[i];

                }
            }
            if (Check(stop_str))
                stop = stoi(stop_str);
            else
                stop = line.size();
            if (stop<0)
                stop=line.size()+stop;
            step=1;
            start=0;
        }
        if (size == 1) {
            for (int i = 0; i < slice.size(); i++) {
                if (slice[i] != ':' && counter != 1) {
                    start_str[c1] = slice[i];
                }
                if (slice[i] != ':')
                    counter++;
                if (slice[i] != ':' && counter == 1) {
                    stop_str[c1] = slice[i];
                }
            }
            if(Check(start_str))
                start = stoi(start_str);
            else start=0;
            if (start<0)
                start=line.size()+start;
            if(Check(stop_str))
                stop = stoi(start_str);
            else
                stop = line.size();
            if (stop<0)
                stop=line.size()+stop;
        }
        if (size == 2) {
            for (int i = 0; i < slice.size(); i++) {
                if (slice[i] != ':' && counter == 0) {
                    start_str[c1] = slice[i];
                }
                if (slice[i] != ':')
                    counter++;
                if (slice[i] != ':' && counter == 2) {
                    stop_str[c1] = slice[i];
                }
                if (slice[i] != ':' && counter == 1) {
                    step_str[c1] = slice[i];
                }
            }
            if(Check(start_str))
                start = stoi(start_str);
            else start=0;
            if (start<0)
                start=line.size()+start;
            if(Check(stop_str))
                stop = stoi(start_str);
            else
                stop = line.size();9
            if (stop<0)
                stop=line.size()+stop;
            if(Check(step_str))
                step = stoi(start_str);
        }
    }
    vector<int> Slice(string slice){ //мб здесь сделать все таки CSlice?
        Input(slice);
        vector<int> final_line,delete_number;
        for (int i = start; i < stop; i += step) {
            final_line.emplace_back(line[i]);
            delete_number.emplace_back(i);
        }
        if (step<0) {
            int j=0;
            for (int i=0;i<line.size();i++){
                if (i!=delete_number[j]){
                    line.erase(i);
                    j++;
                }
            }
            return line;
        }
        else
            return final_line;

    }
};
