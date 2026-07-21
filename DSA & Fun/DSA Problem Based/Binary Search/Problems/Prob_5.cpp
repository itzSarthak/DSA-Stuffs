
/*   
        ** Book Allocation Problem 
        // we need to minimise the maximum no
        // of pages allocated to students .

         Let the test case for two students
         10           20 30 40         max = 90
         10 20        30 40            max = 70
         10 20 30     40               max = 60

         so the answer here is third case (60) .

         The search space :
         s = max(A[])    when books and students are same.            
         e = sum(A[])    when only one student is there .

         why binary search ?
             agar hum mid no of books ko allocate nhi kar paa rhe hain
             to usse kam ko bhi nahi kar paaenge.
    

         For each mid we need to find weather it is a possible soultion
         and based upon that we reduces our search space .
  

    bool isPossible(int A[],int N,int M,int mid)
    {
        int books = 0,count = 0;
        for(int i=0;i<N;i++)
        {
            if(books + A[i] <= mid)
                books+=A[i];

            else
            {
                count++;
                books = A[i];

                if(count >= M)
                    return false;
            }
        }
        return true;
    }
*/


// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1