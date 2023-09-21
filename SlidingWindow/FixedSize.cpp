// Sliding Window Fixed Size

/*
    ## Template for Fixed size Sliding window

    int i=0,j=0;
    int k;          ** k denotes window size

    while(j < arr.size())
    {
        ** Calculations
        if(j-i+1 == k)        ** window size hit
        {
            ** Determine the Answer from Calculations.
            ** Slide the Window.
        }
        j++;
    }
    return res;

        ** Calculations  - - > Depend on Problem.
        ** Sliding the Window - - > Delete Calculation for i and move i.

*/
