#include <stdio.h>
int main()
{

    int num, option;
    int n, temp1 = 0;
    int temp2 = 0;
    int r,k,p,l;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    int lb = 0, ub = n - 1;
    int mid, N,m;
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Choose option:\n1)Bubble Sort\n2)Insertion Sort\n3)Unknown Sort\n4)Binary Search\n5)Selection Sort\n6)Counting Sort\n7)Linear Search\n");
    printf("Enter your choice: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp1 = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp1;
                    temp2 = temp2 + 1;
                    for (int i = 0; i < n; i++)
                    {
                        printf(" %d ", arr[i]);
                    }
                    printf("\n");
                }

                else if (arr[j] < arr[j + 1])
                {
                    continue;
                }
            }
            if (temp2 == 0)
            {
                printf("This is the best case with Time complexity O(n)\n");
                break;
            }
        }
        printf("The sorted array in ascending order is: ");

        for (int i = 0; i < n; i++)
        {
            printf(" %d ", arr[i]);
        }
        printf("\n Time complexity O(n^2)\n");

        break;

    case 2:

        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[i] >= arr[j])
                {
                    printf("\n");
                    for (int i = 0; i < n; i++)
                    {
                        printf(" %d ", arr[i]);
                    }
                    printf("\n Temp=NULL\n");
                    continue;
                }
                else if (arr[i] < arr[j])
                {
                    temp1 = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp1;
                    printf("\n");
                    for (int i = 0; i < n; i++)
                    {
                        printf(" %d ", arr[i]);
                    }
                    printf("\n Temp=%d\n", temp1);
                    i--;
                }
            }
        }
        printf("The final sorted array is: ");
        for (int i = 0; i < n; i++)
        {
            printf(" %d ", arr[i]);
        }
        printf("\nThe time complexity is O(n^2)\n");

        break;

    case 3:
        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp1 = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp1;

                    continue;
                }
                for (int k = 0; k < n; k++)
                {
                    printf(" %d ", arr[k]);
                }

                printf("\n ");
            }
        }

        printf("The sorted array in ascending order is: ");

        for (int k = 0; k < n; k++)
        {
            printf(" %d ", arr[k]);
        }
        printf("\n");
        break;

    case 4:

        printf("Enter the number to be searched: ");
        scanf("%d", &N);
        int mid;
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            printf(" mid:%d \n", arr[mid]);
            if (arr[mid] == N)
            {
                printf("hit at position %d with time complexity O(log n)\n", mid + 1);
                break;
            }
            else if (arr[mid] < N)
            {

                lb = mid + 1;
                for (int i = lb; i <= ub; i++)
                {
                    printf(" %d ", arr[i]);
                    printf("\t");
                }
                printf("\n");
            }
            else if (arr[mid] > N)
            {
                ub = mid - 1;
                for (int i = lb; i <= ub; i++)
                {
                    printf(" %d ", arr[i]);
                    printf("\t");
                }
                printf("\n");
            }
        }
        if (lb > ub)
        {
            printf("The querried element is not in the given array\nTime complexity O(log n)");
        }

        break;

    case 5:
        for (int i = 0; i < n; i++)
        {
            temp2 = arr[i];
            for (int j = i + 1; j < n - 1; j++)
            {

                if (arr[j] < arr[j + 1] && arr[j] <= temp2)
                {
                    temp2 = j;
                }
                else if (arr[j + 1] < arr[j] && arr[j + 1] <= temp2)
                {
                    temp2 = j + 1;
                }
            }

            if (temp2 < arr[i])
            {
                temp1 = arr[i];
                arr[i] = arr[temp2];
                arr[temp2] = temp1;
            }
            for (int i = 0; i < n; i++)
            {
                printf(" %d ", arr[i]);
            }
            printf("\n\n");
        }
        printf("The time complexity is O(n^2)\n");

        break;
    case 6:

        printf("Enter the range: ");
        scanf("%d", &r);
        int csort[r];
        // initialise all to 0
        for (int i = 0; i <= r; i++)
        {
            csort[i] = 0;
        }
        // counting algo
        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == i)
                {
                    csort[i]++;
                }
            }
        }
        for (int i = 0; i <= r; i++)
        {
            printf(" %d ", csort[i]);
        }
        printf("\n");

        // sorting algo
        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j < csort[i]; j++)
            {
                printf(" %d ", i);
            }
        }
        printf("\nThe Time Complexity is O(n+r)\n");

        break;

        
   
    }

    return 0;
}