#include<iostream>
#include<limits>

using namespace std;

int main()
{
    float epsilon = 1.0, zero = 0.9, Mmin = 1.0;

    //эпсилон
    
    while(1.0f + epsilon > 1.0f)
    {
        epsilon /= 2.0f;
    }

    cout << "Machine epsilon: " << epsilon*2.0f << endl;

    //ноль

    while (Mmin > zero)
    {
        Mmin = zero;
        if (zero/2.0f != 0) 
            {
                zero /= 2.0f;
            }
        
        else break;
    }  

    cout << "Machine zero: " << zero << endl;
    
    //плюс бесконечность
    
    float max = 2.1f, limit_plus_inf = 1.0f, plus_infinity = 1.0f;
    int counter_limit_max = -1, counter_max = 0;
    
    while (max > limit_plus_inf)
    {
            limit_plus_inf = max;        
            max *= 2.0f;
            counter_max++;
            counter_limit_max++;

            if (counter_max < 0)
            {
                break;
            }
        
    }  

    for(int i = 0; i < counter_limit_max; i++)
    {
        plus_infinity *= 2.0;
    }

    cout << "Max value: " << (plus_infinity-0.5)*2 << endl;   
    
    //минус бесконечность

    float min = -2.1f, limit_minus_inf = -1.0f, minus_infinity = -1.0f;
    int counter_limit_min = -1, counter_min = 0;
    
    while (min < limit_minus_inf)
    {
            limit_minus_inf = min;        
            min *= 2.0f;
            counter_min++;
            counter_limit_min++;

            if (counter_min < 0)
            {
                break;
            }
        
    }  
    
    for (int j = 0; j < counter_limit_min; j++)
    {
        minus_infinity *= 2.0f;
    }

    cout << "Min value: " << (minus_infinity+0.5)*2 << endl;
    return 0;
}
